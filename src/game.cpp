#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <unistd.h>

#include "game.hpp"
#include "game_state.hpp"
#include "game_state_start.hpp"

#include "logger.hpp"

Game::Game()
   : m_texture_map("../assets/", ".png"),
     m_font_map("../assets/fonts/", ".ttf"),
     m_log("Game"),
     m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game"),
     // m_bounds(m_window.getPosition().x, m_window.getPosition().y,
     //         WINDOW_WIDTH, WINDOW_HEIGHT)
     m_local_bounds(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)
{
   // @TODO dahlbergs: This may want to be a config setting
   m_window.setKeyRepeatEnabled(false);
}

Game::~Game()
{
   while(!m_states.empty())
   {
      PopState();
   }
}

void Game::PushState(GameState* state)
{
   this->m_states.push(state);
   return;
}

void Game::PopState()
{
   delete this->m_states.top();
   this->m_states.pop();

   return;
}

void Game::ChangeState(GameState* state)
{
   if(!this->m_states.empty())
   {
      PopState();
   }

   PushState(state);

   return;
}

GameState* Game::PeekState()
{
   if(this->m_states.empty()) { return nullptr; }
   return this->m_states.top();
}

void Game::RunGameLoop()
{
   sf::Clock clock;
   m_game_clock.restart();

   // @TODO dahlbergs: I don't like this, consider changing
   PushState(new GameStateStart(this));

   while(m_window.isOpen())
   {
      sf::Time elapsed = clock.restart();
      float dt = elapsed.asSeconds();

      if(PeekState() == nullptr)
      {
         break;
      }

      sf::Event event;

      while(m_window.pollEvent(event))
      {
         switch(event.type)
         {
         case sf::Event::Closed:
            m_window.close();
            return;
         case sf::Event::KeyPressed:
         case sf::Event::KeyReleased:
         case sf::Event::MouseMoved:
         case sf::Event::MouseButtonPressed:
         case sf::Event::MouseButtonReleased:
            PeekState()->handleInput(event);
            break;
         default:
            break;
         }
      }

      PeekState()->update(dt);
      PeekState()->draw(dt);

      this->m_window.display();

      float framerate = 60.0;

      while(clock.getElapsedTime().asMilliseconds() < (1000.0 / framerate))
      {
         usleep(1);
      }
   }
}


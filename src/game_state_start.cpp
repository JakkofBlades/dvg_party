#include "game_state_start.hpp"

#include <iostream>

GameStateStart::GameStateStart(Game* game)
   : m_log("GameStateStart")
{
   m_game = game;

   auto window_bounds = m_game->window()->getSize();

   m_background.setTexture(m_game->texture_map()->GetTexture("white_bg"));
   m_background.setColor(sf::Color(0, 255, 0));

   m_splash_text.setFont(m_game->font_map()->GetFont("athena_of_the_ocean"));
   m_splash_text.setString("DVG Party");
   m_splash_text.setCharacterSize(240);

   m_splash_text.setOrigin(m_splash_text.getLocalBounds().width / 2,
                           m_splash_text.getLocalBounds().height / 2);
   m_splash_text.setFillColor(sf::Color::Black);


   m_splash_text.setPosition(window_bounds.x / 2, window_bounds.y / 2 - 400);

}

void GameStateStart::draw(const float dt)
{
   m_game->window()->draw(m_background);
   m_game->window()->draw(m_splash_text);
}

void GameStateStart::update(const float dt)
{

}

void GameStateStart::handleInput(sf::Event event)
{
   switch(event.type)
   {
   case sf::Event::KeyReleased:
      switch(event.key.code)
      {
      case sf::Keyboard::G:
         break;
      case sf::Keyboard::Escape:
         m_game->window()->close();
         break;
      default:
         break;
      }
      break;

   case sf::Event::KeyPressed:
      break;

   case sf::Event::MouseMoved:
      break;

   case sf::Event::MouseButtonPressed:
      break;

   default:
      break;
   }
}

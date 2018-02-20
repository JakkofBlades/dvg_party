//******************************************************************************
// Header Guards
//******************************************************************************
#ifndef _GAME_HPP_
#define _GAME_HPP_


//******************************************************************************
// Includes
//******************************************************************************
#include <stack>

#include <SFML/Graphics.hpp>

#include "texture_map.hpp"
#include "font_map.hpp"


//******************************************************************************
// Forward Declarations
//******************************************************************************
class GameState;


//******************************************************************************
// Class Definition
//******************************************************************************
class Game
{
public:
   Game();
   ~Game();

   void RunGameLoop();

   void PushState(GameState* state);
   void PopState();
   void ChangeState(GameState* state);

   GameState* PeekState();

   sf::RenderWindow* window() { return &m_window; }

   TextureMap* texture_map() { return &m_texture_map; }
   FontMap* font_map() { return &m_font_map; }

   sf::Clock* game_clock() { return &m_game_clock; }

   const sf::FloatRect& local_bounds() { return m_local_bounds; }

private:
   std::stack<GameState*> m_states;

   //@NOTE dahlbergs: Resource handlers live at Game global scope. They should
   // be accessible from anywhere in the game, either directly or from some
   // messaging system.
   TextureMap m_texture_map;
   FontMap m_font_map;

   // @NOTE dahlbergs: Utilities
   dahl::iris::Logger m_log;

   sf::RenderWindow m_window;
   sf::FloatRect m_local_bounds;

   sf::Clock m_game_clock;

   // @TODO dahlbergs: If we want to have a dynamic sizing window, these should
   // not be const. We can use these as defaults however.
   // @TODO dahlbergs: We should make this a reference to the windows bounds.
   static const int WINDOW_WIDTH = 1600;
   static const int WINDOW_HEIGHT = 900;
};

#endif /* _GAME_HPP_ */

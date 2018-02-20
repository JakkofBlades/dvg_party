#ifndef _GAME_STATE_START_HPP_
#define _GAME_STATE_START_HPP_

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

#include "logger.hpp"

#include "texture_map.hpp"

class GameStateStart : public GameState
{
public:
   GameStateStart(Game* game);

   virtual void draw(const float dt);
   virtual void update(const float dt);
   virtual void handleInput(sf::Event event);

private:
   dahl::iris::Logger m_log;

   sf::Sprite m_background;
   sf::Text m_splash_text;
};

#endif /* _GAME_STATE_START_HPP_ */

#ifndef _GAME_STATE_HPP_
#define _GAME_STATE_HPP_

#include "game.hpp"

class GameState
{
public:
   virtual void draw(const float dt) = 0;
   virtual void update(const float dt) = 0;
   virtual void handleInput(sf::Event event) = 0;

protected:
   Game* m_game;
};

#endif /* _GAME_STATE_HPP_ */

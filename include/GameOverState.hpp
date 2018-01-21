//
// Created by Younes on 21/01/2018.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace Younux {

    class GameOverState: public State {
    public:
        GameOverState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        GameDataRef _data;

        sf::Sprite _retryButton;
        sf::Sprite _homeButton;

    };

}
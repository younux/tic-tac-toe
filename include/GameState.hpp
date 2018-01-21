//
// Created by Younes on 21/01/2018.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"


namespace Younux {

    class GameState: public State {
    public:
        GameState(GameDataRef data);

        void Init();

        void HandleInput();
        void Update(float dt);
        void Draw(float dt);

    private:
        void InitGridPieces();

        void CheckAndPlace();

        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _pauseButton;
        sf::Sprite _gridSprite;

        sf::Sprite _gridPieces[3][3];
        int gridArray[3][3];

        int _turn;
        int _gameState;




    };

}
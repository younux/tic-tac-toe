//
// Created by Younes on 21/01/2018.
//

#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "iostream"
#include "PauseState.hpp"
#include "GameOverState.hpp"

namespace Younux {

    GameState::GameState(GameDataRef data) : _data(data) {

    }

    void GameState::Init() {
        _gameState = STATE_PLAYING;
        _turn = PLAYER_PIECE;

        this->_data->assets.LoadTexture(PAUSE_BUTTON_NAME, PAUSE_BUTTON_FILEPATH);
        this->_data->assets.LoadTexture(GAME_BACKGROUND_NAME, GAME_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture(GRID_SPRITE_NAME, GRID_SPRITE_FILEPATH);
        this->_data->assets.LoadTexture(X_PIECE_NAME, X_PIECE_FILEPATH);
        this->_data->assets.LoadTexture(O_PIECE_NAME, O_PIECE_FILEPATH);

        _background.setTexture(_data->assets.GetTexture(GAME_BACKGROUND_NAME));
        _pauseButton.setTexture(_data->assets.GetTexture(PAUSE_BUTTON_NAME));
        _gridSprite.setTexture(_data->assets.GetTexture(GRID_SPRITE_NAME));

        _pauseButton.setPosition(_data->window.getSize().x - _pauseButton.getGlobalBounds().width,
                                 _pauseButton.getPosition().x);

        _gridSprite.setPosition(SCREEN_WIDTH / 2 - _gridSprite.getGlobalBounds().width / 2,
                                SCREEN_HEIGHT / 2 - _gridSprite.getGlobalBounds().height / 2);

        InitGridPieces();

        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                gridArray[x][y] = EMPTY_PIECE;

            }
        }

    }

    void GameState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _data->window.close();
            }
            if (_data->input.isSpriteClicked(_pauseButton, sf::Mouse::Left, _data->window)) {
                _data->machine.AddState(StateRef(new PauseState(_data)), false);
            }
            if (_data->input.isSpriteClicked(_gridSprite, sf::Mouse::Left, _data->window)) {
                this->CheckAndPlace();
            }
        }
    }

    void GameState::Update(float dt) {

    }

    void GameState::Draw(float dt) {
        _data->window.clear();

        _data->window.draw(_background);
        _data->window.draw(_pauseButton);
        _data->window.draw(_gridSprite);
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                _data->window.draw(_gridPieces[x][y]);
            }
        }


        _data->window.display();
    }

    void GameState::InitGridPieces() {
        sf::Vector2u tempSpriteSize = _data->assets.GetTexture(X_PIECE_NAME).getSize();

        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                _gridPieces[x][y].setTexture(_data->assets.GetTexture(X_PIECE_NAME));
                _gridPieces[x][y].setPosition(_gridSprite.getPosition().x + tempSpriteSize.x * x - 7,
                                              _gridSprite.getPosition().y + tempSpriteSize.y * y - 7);
                _gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
            }
        }

    }

    void GameState::CheckAndPlace() {
        sf::Vector2i touchPoint = this->_data->input.GetMousePosition(_data->window);
        sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
        sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width)/2,
                                                     (SCREEN_HEIGHT - gridSize.height)/2);
        sf::Vector2f gridLocaTouchPos = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x,
                                touchPoint.y - gapOutsideOfGrid.y);
        sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.height/3, gridSize.height/3);
        int column, row;
        if(gridLocaTouchPos.x < gridSectionSize.x) {
            column = 1;
        } else if(gridLocaTouchPos.x < gridSectionSize.x * 2){
            column = 2;
        } else if(gridLocaTouchPos.x < gridSize.width){
            column = 3;
        }

        if(gridLocaTouchPos.y < gridSectionSize.y) {
            row = 1;
        } else if(gridLocaTouchPos.y < gridSectionSize.y * 2){
            row = 2;
        } else if(gridLocaTouchPos.y < gridSize.height){
            row = 3;
        }

        if(gridArray[column-1][row-1]==EMPTY_PIECE){
            gridArray[column-1][row-1] = _turn;
            if(_turn == PLAYER_PIECE){
                _gridPieces[column-1][row-1].setTexture(_data->assets.GetTexture(X_PIECE_NAME));
                _turn = AI_PIECE;
            } else if(_turn == AI_PIECE){
                _gridPieces[column-1][row-1].setTexture(_data->assets.GetTexture(O_PIECE_NAME));
                _turn = PLAYER_PIECE;
            }
            _gridPieces[column-1][row-1].setColor(sf::Color(255,255,255,255));

        }


    }

}



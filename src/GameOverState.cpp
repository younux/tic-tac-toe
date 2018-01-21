//
// Created by Younes on 21/01/2018.
//

#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "iostream"
#include "GameState.hpp"
#include "MainMenuState.hpp"

namespace Younux{

    GameOverState::GameOverState(GameDataRef data) : _data(data) {

    }

    void GameOverState::Init() {
        _data->assets.LoadTexture(RETRY_BUTTON_NAME, RETRY_BUTTON_FILEPATH);
        _data->assets.LoadTexture(HOME_BUTTON_NAME, HOME_BUTTON_FILEPATH);

        _retryButton.setTexture(_data->assets.GetTexture(RETRY_BUTTON_NAME));
        _homeButton.setTexture(_data->assets.GetTexture(HOME_BUTTON_NAME));

        _retryButton.setPosition(_data->window.getSize().x / 2- _retryButton.getGlobalBounds().width / 2,
                                  _data->window.getSize().y / 3- - _retryButton.getGlobalBounds().height / 2);

        _homeButton.setPosition(_data->window.getSize().x / 2- _homeButton.getGlobalBounds().width / 2,
                                _data->window.getSize().y / 3 * 2 - _homeButton.getGlobalBounds().height / 2);

    }

    void GameOverState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                _data->window.close();
            }
            if(_data->input.isSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)){
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
            if(_data->input.isSpriteClicked(_homeButton, sf::Mouse::Left, _data->window)){
                _data->machine.RemoveState();
                _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
            }
        }
    }

    void GameOverState::Update(float dt) {

    }

    void GameOverState::Draw(float dt) {
        _data->window.clear();

        _data->window.draw(_retryButton);
        _data->window.draw(_homeButton);

        _data->window.display();

    }


}
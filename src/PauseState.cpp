//
// Created by Younes on 21/01/2018.
//

#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include "iostream"
#include "GameState.hpp"
#include "MainMenuState.hpp"

namespace Younux{

    PauseState::PauseState(GameDataRef data) : _data(data) {

    }

    void PauseState::Init() {
        _data->assets.LoadTexture(PAUSE_BACKGROUND_NAME, PAUSE_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture(RESUME_BUTTON_NAME, RESUME_BUTTON_FILEPATH);
        _data->assets.LoadTexture(HOME_BUTTON_NAME, HOME_BUTTON_FILEPATH);

        _background.setTexture(_data->assets.GetTexture(PAUSE_BACKGROUND_NAME));
        _resumeButton.setTexture(_data->assets.GetTexture(RESUME_BUTTON_NAME));
        _homeButton.setTexture(_data->assets.GetTexture(HOME_BUTTON_NAME));

        _resumeButton.setPosition(_data->window.getSize().x / 2- _resumeButton.getGlobalBounds().width / 2,
                                  _data->window.getSize().y / 3- - _resumeButton.getGlobalBounds().height / 2);

        _homeButton.setPosition(_data->window.getSize().x / 2- _homeButton.getGlobalBounds().width / 2,
                                _data->window.getSize().y / 3 * 2 - _homeButton.getGlobalBounds().height / 2);

    }

    void PauseState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                _data->window.close();
            }
            if(_data->input.isSpriteClicked(_resumeButton, sf::Mouse::Left, _data->window)){
                _data->machine.RemoveState();
            }
            if(_data->input.isSpriteClicked(_homeButton, sf::Mouse::Left, _data->window)){
                _data->machine.RemoveState();
                _data->machine.AddState(StateRef(new MainMenuState(_data)), true);
            }
        }
    }

    void PauseState::Update(float dt) {

    }

    void PauseState::Draw(float dt) {
        _data->window.clear();

        _data->window.draw(_background);
        _data->window.draw(_resumeButton);
        _data->window.draw(_homeButton);

        _data->window.display();

    }


}
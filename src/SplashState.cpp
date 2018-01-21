//
// Created by Younes on 21/01/2018.
//

#include "SplashState.hpp"
#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace Younux {

    SplashState::SplashState(GameDataRef data) : _data(data) {

    }

    void SplashState::Init() {
        this->_data->assets.LoadTexture(SPLASH_SCENE_BACKGRAOUND_NAME,
                                        SPLASH_SCENE_BACKGRAOUND_FILEPATH);
        _background.setTexture(this->_data->assets.GetTexture(SPLASH_SCENE_BACKGRAOUND_NAME));

    }

    void SplashState::HandleInput() {
        sf::Event event;

        while(this->_data->window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                this->_data->window.close();

            }
        }
    }

    void SplashState::Update(float dt) {
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME){
            // switch to main menu
            _data->machine.AddState(StateRef(new MainMenuState(_data)), true);

        }


    }



    void SplashState::Draw(float dt) {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw(this->_background);

        this->_data->window.display();

    }
}
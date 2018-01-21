//
// Created by Younes on 21/01/2018.
//

#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"
#include "iostream"
#include "GameState.hpp"

namespace Younux{

    MainMenuState::MainMenuState(GameDataRef data) : _data(data) {

    }

    void MainMenuState::Init() {
        _data->assets.LoadTexture(MAIN_MENU_BACKGROUND_NAME, MAIN_MENU_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture(MAIN_MENU_TITLE_NAME, MAIN_MENU_TITLE_FILEPATH);
        _data->assets.LoadTexture(MAIN_MENU_PLAY_BUTTON_NAME, MAIN_MENU_PLAY_BUTTON_FILEPATH);
        _data->assets.LoadTexture(MAIN_MENU_PLAY_BUTTON_OUTER_NAME, MAIN_MENU_PLAY_BUTTON_OUTER_FILEPATH);

        _background.setTexture(_data->assets.GetTexture(MAIN_MENU_BACKGROUND_NAME));
        _title.setTexture(_data->assets.GetTexture(MAIN_MENU_TITLE_NAME));
        _playButton.setTexture(_data->assets.GetTexture(MAIN_MENU_PLAY_BUTTON_NAME));
        _playButtonOuter.setTexture(_data->assets.GetTexture(MAIN_MENU_PLAY_BUTTON_OUTER_NAME));

        _playButton.setPosition(SCREEN_WIDTH / 2 - _playButton.getGlobalBounds().width / 2,
                                SCREEN_HEIGHT / 2 - _playButton.getGlobalBounds().height / 2);

        _playButtonOuter.setPosition(SCREEN_WIDTH / 2 - _playButtonOuter.getGlobalBounds().width / 2,
                                SCREEN_HEIGHT / 2 - _playButtonOuter.getGlobalBounds().height / 2);

        _title.setPosition(SCREEN_WIDTH / 2 - _title.getGlobalBounds().width / 2,
                            _title.getGlobalBounds().height * 0.1);

    }

    void MainMenuState::HandleInput() {
        sf::Event event;

        while (_data->window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                _data->window.close();
            }
            if(_data->input.isSpriteClicked(_playButton, sf::Mouse::Left, _data->window)){
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt) {

    }

    void MainMenuState::Draw(float dt) {
        _data->window.clear();

        _data->window.draw(_background);
        _data->window.draw(_title);
        _data->window.draw(_playButton);
        _data->window.draw(_playButtonOuter);

        _data->window.display();

    }


}
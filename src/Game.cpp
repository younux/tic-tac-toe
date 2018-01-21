//
// Created by Younes on 21/01/2018.
//

#include "Game.hpp"
#include "SplashState.hpp"


namespace Younux {

    Game::Game(int width, int height, std::string title) {
        _data->window.create(sf::VideoMode(width, height), title,
                             sf::Style::Close | sf::Style::Titlebar);

        _data->machine.AddState(StateRef(new SplashState(_data)));
        this->Run();

    }

    void Game::Run() {
        float newTime, frameTime, interpolationn;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->_data->window.isOpen()){
            this->_data->machine.ProcessStateChanges();
            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            if(frameTime > 0.25f){
                frameTime = 0.25f;
            }
            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt){
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }
            interpolationn = accumulator / dt;
            this->_data->machine.GetActiveState()->Draw(interpolationn);


        }


    }


}
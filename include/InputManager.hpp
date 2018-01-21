//
// Created by Younes on 21/01/2018.
//

#pragma oncne

#include <SFML/Graphics.hpp>

namespace Younux {

    class InputManager{
    public:
        InputManager() {}
        ~InputManager() {}

        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button,
                        sf::RenderWindow& window);

        sf::Vector2i GetMousePosition(sf::RenderWindow& window);

    };

}
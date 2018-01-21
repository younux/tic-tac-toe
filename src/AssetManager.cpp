//
// Created by Younes on 21/01/2018.
//

#include "AssetManager.hpp"
#include <iostream>

namespace Younux {

    void AssetManager::LoadTexture(std::string name, std::string fileName) {
        sf::Texture tex;

        if(tex.loadFromFile(fileName)){
            this->_textures[name] = tex;
        } else{
            std::cout << " Failed to load texture " + name <<std::endl;
        }
    }

    sf::Texture& AssetManager::GetTexture(std::string name) {
        return this->_textures.at(name);
    }

    void AssetManager::LoadFont(std::string name, std::string fileName) {
        sf::Font font;

        if(font.loadFromFile(fileName)){
            this->_fonts[name] = font;
        } else{
            std::cout << " Failed to load font " + name <<std::endl;
        }
    }

    sf::Font& AssetManager::GetFont(std::string name) {
        return this->_fonts.at(name);
    }


}
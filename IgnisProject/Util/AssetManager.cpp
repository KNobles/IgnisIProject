#include "AssetManager.h"

void AssetManager::loadTexture(std::string name, std::string fileName)
{
    sf::Texture tex;

    if(tex.loadFromFile(fileName))
    {
        this->textures[name] = tex;
    }
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
    sf::Font font;

    if(font.loadFromFile(fileName))
    {
        this->fonts[name] = font;
    }
}

sf::Texture &AssetManager::getTexture(std::string name)
{
    return this->textures.at(name);
}

sf::Font &AssetManager::getFont(std::string name)
{
    return this->fonts.at(name);
}

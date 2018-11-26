#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>

class AssetManager
{
    public:
        AssetManager(){}
        ~AssetManager(){}

        void loadTexture(std::string name, std::string fileName);
        void loadFont(std::string name, std::string fileName);
        sf::Texture &getTexture(std::string name);
        sf::Font &getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> textures;
        std::map<std::string, sf::Font> fonts;
};

#endif // ASSETMANAGER_H

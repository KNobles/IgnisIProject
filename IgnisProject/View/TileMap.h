#ifndef TILEMAP_H
#define TILEMAP_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "CharacterSprite.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
    public:
        TileMap();
        virtual ~TileMap();

        bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
        bool loadLevel1();
        int fileLines(std::ifstream& infile, std::string fileName)const;
        bool loadFromFile(std::string fileName, std::string imageName);

    protected:

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;
        std::vector<CharacterSprite*> characters;
};

#endif // TILEMAP_H

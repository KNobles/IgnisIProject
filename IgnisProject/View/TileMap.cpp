#include "TileMap.h"

TileMap::TileMap()
{
    //ctor
}

TileMap::~TileMap()
{
    //dtor
}

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
{
    // load the tileset texture
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // resize the vertex array to fit the level size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // populate the vertex array, with one quad per tile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width];
//            std::cout << "TILE NUMBER :" << tiles->at(i + j * width) << std::endl;
            // find its position in the tileset texture
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

int TileMap::fileLines(std::ifstream& infile, std::string fileName)const
{
    int count = 0;
    std::string line;
    infile.open("Assets/Sprites/Tiles/" + fileName);

    while (getline(infile, line))
    {
        count++;
    }
    infile.close();
    return count;
}

bool TileMap::loadFromFile(std::string fileName, std::string imageName)
{
    std::ifstream infile;
    int index;
    infile.open("Assets/Sprites/Tiles/" + fileName);
    std::vector<int> arr;
    while(infile >> index)
    {
        arr.push_back(index);
    }
    infile.close();

    int tileHeight = fileLines(infile, fileName);
    int tileWidth = arr.size()/tileHeight;
    int lvl[arr.size()];

    std::copy(arr.begin(), arr.end(), lvl);

    if (!this->load("Assets/Sprites/Tiles/" + imageName, sf::Vector2u(16, 16), lvl, tileWidth, tileHeight))
        return 0;
}

bool TileMap::loadLevel1()
{
    return loadFromFile("map1.txt", "Castle Blue.png");
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
}

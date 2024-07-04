#ifndef LEVEL_H
#define LEVEL_H

#include "ITile.h"
#include "IEntity.h" 
#include "Position.h"
#include <vector>

class Level
{   
    int _width, _height;

    /* 
        Object slicing occurs when an object of a derived class is assigned to an object of a base class, resulting in the loss of 
        derived class-specific data and methods.
        To prevent object slicing, use pointers or references to base class objects, especially in collections, e.g. Vectors. 

        std::vector<ITile> _tiles; -> would be an issue because derived class of ITiles eg. wall can not be stored in the vector
                                      because results in oject slicing: eg. _tiles.push_back(wall) _tiles[0].colorWall() is a derived
                                      method of wall but not a method of ITiles, then loss of derived class-specifi methods.
    */

    std::vector<ITile*> _tiles;
    std::vector<IEntity*> _entities;

public:
    Level(int width, int height);
    int GetWidth();
    int GetHeight();

    void SetTile(ITile& tile, Position pos);
    void SetTiles(ITile& tile, Position from, Position to);
    void SetEntity(IEntity& entity, Position pos);
    void MoveEntity(IEntity& entity, Position pos);

    void RenderAll(); 

private:
    int GetIndexForXY(int x, int y);
    void SetCharacter(char ch, int x, int y);

};

#endif
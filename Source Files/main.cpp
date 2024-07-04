#include <iostream>
#include <string>
#include <iostream>
#include "Level.h"
#include <conio.h>

using namespace std;


class BasicTile : public ITile
{
private: 
    char _character;
    bool _canEnter;

public:
    BasicTile(char ch, bool canEnter) : _character(ch), _canEnter(canEnter)
    {}

    virtual char GetCharacter(){return _character;}
    virtual bool CanEnter(IEntity& entity){return _canEnter;}
    virtual void Enter(IEntity& entity) {}
};


class BasicEntity : public IEntity
{
    char _character;
    Position _position;

public:
    BasicEntity(char ch) : _character(ch), _position(0,0)
    {}    

    virtual char GetCharacter() {return _character;}
    virtual Position& GetPosition() {return _position;}
    virtual void SetPosition(Position& position) {_position = position;}
    virtual void Collide(IEntity& entity) {}

};


int main()
{    
    Level level(20,20);    
    BasicTile empty(' ',true);
    BasicTile wall('*', false);

    level.SetTiles(empty, Position(0,0), Position(19,19));
    level.SetTiles(wall, Position(0,0), Position(0,19));
    level.SetTiles(wall, Position(0,0), Position(19,0));
    level.SetTiles(wall, Position(19,0), Position(19,19));
    level.SetTiles(wall, Position(0,19), Position(19,19));

    level.SetTiles(wall, Position(4,4), Position(6,6));
    level.SetTiles(wall, Position(7,12), Position(10,16));

    BasicEntity player('o');
    level.SetEntity(player,Position(1,1));

    char input;
    level.RenderAll();

    while ((input = _getch()) != 27)
    {
        auto pos = player.GetPosition();

        if (input == 'w')
            level.MoveEntity(player, Position(pos.GetX(), pos.GetY()-1));
        else if (input == 'a')
            level.MoveEntity(player, Position(pos.GetX()-1, pos.GetY()));
        else if (input == 's')
            level.MoveEntity(player, Position(pos.GetX(), pos.GetY()+1));
        else if (input == 'd')
            level.MoveEntity(player, Position(pos.GetX()+1, pos.GetY()));
    }

    cin.get();
    return 0;
}
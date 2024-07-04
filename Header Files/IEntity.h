#ifndef IENTITY_H
#define IENTITY_H

#include "Position.h"

class IEntity
{
public:
    virtual char GetCharacter() =0;
    virtual Position& GetPosition() = 0; 
    virtual void SetPosition(Position& position) = 0;
    virtual void Collide(IEntity& entity) = 0;
};

#endif
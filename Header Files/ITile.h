#ifndef ITILE_H
#define ITILE_H

#include "IEntity.h"

class ITile
{
public:
    virtual char GetCharacter() = 0;
    virtual bool CanEnter(IEntity& entity)= 0;
    virtual void Enter(IEntity& entity) = 0;

};

#endif
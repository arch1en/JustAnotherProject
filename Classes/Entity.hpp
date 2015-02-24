#pragma once

#include "EntityComposite.hpp"

static unsigned int NUM_ID;

class Entity
{
public:
	Entity() : ID{ NUM_ID++ }, composite{new EntityComposite()} {}
	std::shared_ptr<EntityComposite> getComposite() 
	{
		return composite;
	}
private:
	std::shared_ptr<EntityComposite> composite;
	const unsigned int ID;
};
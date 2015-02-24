#pragma once

#include <vector>
#include <algorithm>

class EntityComposite
{
public:
	EntityComposite(){}
	bool addComponent(EntityComposite* e)
	{
		componentStack.push_back(e);
		return true;
	}

	bool removeComponent(EntityComposite* e)
	{
		std::vector<EntityComposite*>::iterator found = std::find(componentStack.begin(), componentStack.end(), e);
		if (found != componentStack.end())
		{
			componentStack.erase(std::remove_if(componentStack.begin(), componentStack.end(), [&e](EntityComposite* f)->bool{
				return e == f;
			}), componentStack.end());
			return true;
		}
		return false;
	}

	std::vector<EntityComposite*> & getComponentStack()
	{
		return componentStack;
	}
private:
	std::vector<EntityComposite*> componentStack;
};
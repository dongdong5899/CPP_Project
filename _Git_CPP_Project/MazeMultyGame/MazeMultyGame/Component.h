#pragma once
#include "Object.h"
#include "GameObject.h"
class Component : public Object
{
public:
	GameObject getGameObject();
	Transform getTransform();
	//gameObjedt get reference
};


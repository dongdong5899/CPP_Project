#pragma once
#include "Object.h"
#include "Transform.h"
class GameObject : public Object
{
public:
	Transform transform;
	void SetActive(bool value);
	void AddComponent(Component c);
private:
	bool active;
};


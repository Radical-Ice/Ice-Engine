#pragma once
#include "SFML/Graphics.hpp"
class BaseComponent
{
public:

	BaseComponent();
	virtual void Update();
	~BaseComponent();
};


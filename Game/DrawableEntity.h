#pragma once
#include "Entity.h"
#include "Header_loader.h"

class DrawableEntity :
	public virtual Entity
{
private:

public:
	DrawableEntity(int id, double x, double y);
	virtual ~DrawableEntity();

	virtual void draw();
};


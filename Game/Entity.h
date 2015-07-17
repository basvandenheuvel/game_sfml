#pragma once
#include "Header_loader.h"

class Entity
{
private:
	//Entity ID
	int id;

	//Entity Position
	double x;
	double y;
	double z;

	//Entity Size
	double width;
	double height;

	//Entity chunk
	int chunkY;
	int chunkX;

public:
	Entity(int id, double x, double y);
	virtual ~Entity();

	//Setters
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	void setWidth(double width);
	void setHeight(double height);
	void setChunks();

	//Getters
	int getId();
	int getChunkY();
	int getChunkX();
	double getX();
	double getY();
	double getZ();
	double getWidth();
	double getHeight();
	double getCenterX();
	double getCenterY();
};


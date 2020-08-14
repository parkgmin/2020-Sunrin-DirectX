#pragma once
#include<d3dx9.h>
#include<list>

class Object
{
protected:
	Object* parent;

	D3DXMATRIX mat;
	D3DXVECTOR2 pos;

	D3DXVECTOR2 scalingCenter;
	D3DXVECTOR2 scale;

	D3DXVECTOR2 rotationCenter;
	float rotation;

	RECT rect;

	std::list<Object*> childList;

public:
	Object();
	~Object();

	virtual void Render();
	virtual void Update(float dTime);

	void AddChild(Object* child);
	void RemoveChild(Object* childe);

	bool IsCollisionRect(D3DXVECTOR2 p1, D3DXVECTOR2 p2, RECT r1, RECT r2);
	bool IsCollisionRect(Object * obj);

	bool IsPointInRect(D3DXVECTOR2 p);

	D3DXMATRIX getMat();
	D3DXVECTOR2 getPos();

	int getPosX();
	int getPosY();
	RECT getRect();

	void setParent(Object* parent);
	void setPos(int x, int y);
	void setPos(D3DXVECTOR2 pos);


};


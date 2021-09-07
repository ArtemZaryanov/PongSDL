#pragma once
#include "Entity.h"
class Collision
{
public:
	bool checkCollision(const Entity& e1, const Entity& e2);
private:
	Collision(const Collision&) = delete;
	//�������� ������������ ������������(�� ����������)
	Collision& operator=(const Collision&) = delete;
};


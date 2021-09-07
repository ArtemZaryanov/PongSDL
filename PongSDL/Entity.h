#pragma once
#include "SDL.h"
#include "SDL_image.h"
using Point_t = SDL_Point;
using Texture = SDL_Texture;
using RectBound = SDL_Rect;
class Entity
{
public:
	Entity(const int type,const RectBound& rectBound);
	//��������� �������� � ��������������� ��������������
	//����������� �����������
	//�������� ������������ ������������
	//������ pos � rectBound
	void move(const Point_t& dr, const Point_t& direct);

	//���-�� ��� ��������� �������� ���������� � �������(����� ������) - ��� ��������
	const RectBound& getRectBound()const;
	//1 - wall, paddle, 1 - ball
	int getType() const;
	~Entity();
protected:
	const int type;
	//bool isStatic;
	Point_t direct;
	Point_t pos;// �������� ��������������, �� ����� �������������� ������� �� ������������?
	Point_t pos_LU;// ���� ������� ���� ��� SDL// �����������s
	//Texture texture;
	RectBound rectBound;
	//����������� �����������(�� ����������)
	Entity(const Entity&)=delete;
	//�������� ������������ ������������(�� ����������)
	Entity& operator=(const Entity&)=delete;

};


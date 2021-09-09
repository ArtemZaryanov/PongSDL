#pragma once
#include "SDL.h"
#include "SDL_image.h"
using Point_t = SDL_FPoint;
using FPoint_t = SDL_FPoint;
using Texture = SDL_Texture;
using RectBound = SDL_FRect;
class Entity
{
public:
	Entity(const int type,const RectBound& rectBound);
	//��������� �������� � ��������������� ��������������
	//����������� �����������
	//�������� ������������ ������������
	//������ pos � rectBound
	void move(const Point_t& dr, const FPoint_t& direct);
	void move(Point_t&& dr, FPoint_t&& dir);
	//���-�� ��� ��������� �������� ���������� � �������(����� ������) - ��� ��������
	const RectBound& getRectBound()const;
	//1 - wall, paddle, 1 - ball
	int getType() const;
	~Entity();
protected:
	const int type;
	//bool isStatic;
	FPoint_t direct;
	Point_t pos;// �������� ��������������, �� ����� �������������� ������� �� ������������?
	Point_t pos_LU;// ���� ������� ���� ��� SDL// �����������s
	//Texture texture;
	RectBound rectBound;
	//����������� �����������(�� ����������)
	Entity(const Entity&)=delete;
	void Update();
	//�������� ������������ ������������(�� ����������)
	Entity& operator=(const Entity&)=delete;

};


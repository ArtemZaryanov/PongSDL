#pragma once
#include "SDL.h"
#include "SDL_image.h"
using Point_t = SDL_Point*;
using Texture = SDL_Texture*;
using RectBound = SDL_Rect*;
class Entity
{
public:
	Entity();
	//��������� �������� � ��������������� ��������������
	Entity(const char * fileText);
	//����������� �����������
	//�������� ������������ ������������
	//������ pos � rectBound
	void move(Point_t dr, Point_t direct);

	//���-�� ��� ��������� �������� ���������� � �������(����� ������) - ��� ��������
	const RectBound& getRectBound()const;
	const Texture& getTexture() const;
	~Entity();
protected:
	Point_t direct;
	Point_t pos;// �������� ��������������, �� ����� �������������� ������� �� ������������?
	Point_t pos_LU;// ���� ������� ���� ��� SDL// �����������s
	Texture texture;
	RectBound rectBound;
	//����������� �����������(�� ����������)
	Entity(const Entity&)=delete;
	//�������� ������������ ������������(�� ����������)
	Entity& operator=(const Entity&)=delete;

};


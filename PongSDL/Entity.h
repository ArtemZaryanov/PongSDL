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
	//Генерация текстуры и ограничивающего прямоугольника
	//Конструктор перемещения
	//Оператор присваивания перемещением
	//Менять pos и rectBound
	void move(const Point_t& dr, const Point_t& direct);

	//Что-то что позволяет получать информацию о объекте(длина ширина) - для коллизий
	const RectBound& getRectBound()const;
	//1 - wall, paddle, 1 - ball
	int getType() const;
	~Entity();
protected:
	const int type;
	//bool isStatic;
	Point_t direct;
	Point_t pos;// середина прямоугольника, но тогда дополнительные расходы на преобзование?
	Point_t pos_LU;// Левы верхний угол для SDL// Оптимизацияs
	//Texture texture;
	RectBound rectBound;
	//Конструктор копирование(не реализовал)
	Entity(const Entity&)=delete;
	//Оператор присваивания копированием(не раализовал)
	Entity& operator=(const Entity&)=delete;

};


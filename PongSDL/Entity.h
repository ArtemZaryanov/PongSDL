#pragma once
#include "SDL.h"
using Point_t = SDL_Point;
using Texture = SDL_Texture*;
using RectBound = SDL_Rect;
class Entity
{
public:
	//Генерация текстуры и ограничивающего прямоугольника
	Entity(const char * fileText);
	//Конструктор перемещения
	//Оператор присваивания перемещением
	//Менять pos и rectBound
	void move(Point_t dr, Point_t direct);
	//Что-то что позволяет получать информацию о объекте(длина ширина) - для коллизий
	const RectBound& getRectBound();
	~Entity();
private:
	Point_t direct;
	Point_t pos;// середина прямоугольника, но тогда дополнительные расходы на преобзование?
	Point_t pos_LU;// Левы верхний угол для SDL// Оптимизацияs
	Texture texture;
	RectBound rectBound;
	//Конструктор копирование(не реализовал)
	Entity(const Entity&)=delete;
	//Оператор присваивания копированием(не раализовал)
	Entity& operator=(const Entity&)=delete;

};


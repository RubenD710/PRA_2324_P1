#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include <ostream>
#include "Shape.h"
#include "Point2D.h"
#include "Rectangle.h"

class Square : public Rectangle {
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
		void set_vertices(Point2D* vertices) override;
		double area() const override;
		double perimeter() const override;
		void translate(double incX, double incY) override;
		void print() override;

	private:
		static bool check(Point2D* vertices);

};

#endif

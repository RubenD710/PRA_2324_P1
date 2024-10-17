#include "Circle.h"
#include <cmath>

Circle::Circle() : Shape() {
	center= Point2D(0,0);
	radius=1;
}

Circle::Circle(std::string color, Point2D center, double radius): Shape(color) {
	this->center=center;
	this->radius=radius;
}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center=p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius= r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "[Circle: color = " << c.color << "; center = " << c.center << "; radius = " << c.radius << "]" << std::endl;
	return out;
}

double Circle::area() const{
	return 3.141592*pow(radius,2);
}

double Circle::perimeter() const{
	return 2*3.141592*radius;
}

void Circle::translate(double incX, double incY){
	center=Point2D(center.x+incX,center.y+incY);
}

void Circle::print(){
	std::cout << this << std::endl;
}

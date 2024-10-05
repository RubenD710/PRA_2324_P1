#include "Shape.h"

Shape::Shape(){
	color="rojo";
}

Shape::Shape(std::string color){
	this->color=color;
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	color=c;
}

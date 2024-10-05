#include "Shape.h"

Shape::Shape(){
	color="red";
}

Shape::Shape(std::string color){
	if (color=="red"||color=="green"|| color=="blue"){
		this->color=color;
	}else{
		throw std::invalid_argument("El color introducido no es correcto");
	}
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if (c=="red"||c=="green"|| c=="blue"){
		color=c;
	}else{
		throw std::invalid_argument("El color introducido no es correcto");
	}
}

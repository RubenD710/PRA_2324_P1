#include "Square.h"
#include <cmath>

bool Square::check(Point2D* vertices){
	return (Point2D::distance(vertices[0], vertices[1])==Point2D::distance(vertices[1],vertices[2]))&&(Point2D::distance(vertices[2], vertices[3])==Point2D::distance(vertices[3],vertices[0]));
}

Square::Square() : Rectangle(){
	vs = new Point2D[N_VERTICES];
	vs[0]=Point2D (-1,1);
	vs[1]=Point2D (1,1);
	vs[2]=Point2D (1,-1);
	vs[3]=Point2D (-1,-1);
}

Square::Square(std::string color, Point2D* vertices){
	this->color=color;
	if (!check(vertices)){
		throw std::invalid_argument("Los vertices introducidos no forman un rectangulo");
	}else{
		vs=vertices;
	}
}

void Square::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("Los vertices introducidos no forman un rectangulo");
	}else{
		vs=vertices;
	}
}

std::ostream& operator<<(std::ostream &out, const Square &square){
	out << "[Square: color = " << square.color << "; v0 = " << square.vs[0] << "; v1 = " << square.vs[1] << "]" << "; v2 = " << square.vs[2] << "; v3 = " << square.vs[3] << std::endl; //cambiar por el metodo print() sin que de error
	return out;
}

double Square::area() const{
	return (Point2D::distance(vs[0], vs[1]))*(Point2D::distance(vs[1], vs[2]));
}

double Square::perimeter() const{
	return Point2D::distance(vs[0], vs[1])*4;
}

void Square::translate(double incX, double incY){
	vs[0]=Point2D(vs[0].x+incX,vs[0].y+incY);
	vs[1]=Point2D(vs[1].x+incX,vs[1].y+incY);
	vs[2]=Point2D(vs[2].x+incX,vs[2].y+incY);
	vs[3]=Point2D(vs[3].x+incX,vs[3].y+incY);
}

void Square::print(){
	std::cout << "[Square: color = " << color << "; v0 = " << vs[0] << "; v1 = " << vs[1] << "; v2 = " << vs[2] << "; v3 = " << vs[3] << "]" << std::endl;
}


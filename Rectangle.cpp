#include "Rectangle.h"
#include <cmath>

bool Rectangle::check(Point2D* vertices){
	return (Point2D::distance(vertices[0], vertices[1])==Point2D::distance(vertices[2],vertices[3]))&&(Point2D::distance(vertices[1], vertices[2])==Point2D::distance(vertices[3],vertices[0]));
}

Rectangle::Rectangle() : Shape(){
	vs = new Point2D[N_VERTICES];
	vs[0]=Point2D (-1,0.5);
	vs[1]=Point2D (1,0.5);
	vs[2]=Point2D (1,-0.5);
	vs[3]=Point2D (-1,-0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices){
	this->color=color;
	if (!check(vertices)){
		throw std::invalid_argument("Los vertices introducidos no forman un rectangulo");
	}else{
		vs = new Point2D[N_VERTICES];
		for (int i = 0; i < N_VERTICES; ++i) {
    			vs[i] = vertices[i];
		}
	}
}

Rectangle::Rectangle(const Rectangle &r){
	vs = new Point2D[N_VERTICES];
    	for (int i = 0; i < N_VERTICES; ++i) {
        	vs[i] = r.vs[i];
    	}
}

Rectangle::~Rectangle(){
	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
	if (ind<N_VERTICES){
		return vs[ind];
	}else{
		throw std::out_of_range("El indice introducido no es valido");
	}
	
}

Point2D Rectangle::operator[] (int ind) const{
	if (ind<N_VERTICES){
		return vs[ind];
	}else{
		throw std::out_of_range("El indice introducido no es valido");
	}
}

void Rectangle::set_vertices(Point2D* vertices){
	if (!check(vertices)) {
        	throw std::invalid_argument("Los vertices introducidos no forman un rectangulo");
    	} else {
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = vertices[i];
        }
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs;

        color = r.color;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "[Rectangle: color = " << r.color << "; v0 = " << r.vs[0] << "; v1 = " << r.vs[1] << "]" << "; v2 = " << r.vs[2] << "; v3 = " << r.vs[3] << std::endl; 
	return out;
}

double Rectangle::area() const{
	return (Point2D::distance(vs[0], vs[1]))*(Point2D::distance(vs[0], vs[3]));
}

double Rectangle::perimeter() const{
	return ((Point2D::distance(vs[0], vs[1]))+(Point2D::distance(vs[1], vs[2])))*2;
}

void Rectangle::translate(double incX, double incY){
	vs[0]=Point2D(vs[0].x+incX,vs[0].y+incY);
	vs[1]=Point2D(vs[1].x+incX,vs[1].y+incY);
	vs[2]=Point2D(vs[2].x+incX,vs[2].y+incY);
	vs[3]=Point2D(vs[3].x+incX,vs[3].y+incY);
}

void Rectangle::print(){
	std::cout << this << std::endl;
}


#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing(){
	shapes = new ListArray<Shape*>();
}
Drawing::~Drawing(){
	delete shapes;
}

void Drawing::add_front(Shape* shape){
	shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape){
	shapes->append(shape);
}

void Drawing::print_all() {
    std::cout << "Drawing contents: " << std::endl;
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();  // Llamar a la función virtual print()
    }
}

double Drawing::get_area_all_circles() {
    double AreaTotal = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle) {
            AreaTotal += circle->area();
        }
    }
    return AreaTotal;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square) {
            square->translate(incX, incY);
        }
    }
}


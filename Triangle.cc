#include "Triangle.hh"

Triangle::Triangle(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Color color, sf::Color border)
{
    triangle.setPointCount(3) ;
    triangle.setPoint(0, A);
    triangle.setPoint(1, B);
    triangle.setPoint(2, C);
    triangle.setOutlineThickness(1);
    triangle.setOutlineColor(border);
    triangle.setFillColor(color); // Default: red color
}

sf::ConvexShape Triangle::get()
{
    return triangle ; 
}
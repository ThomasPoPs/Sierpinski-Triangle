#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef DEF_TRIANGLE
#define DEF_TRIANGLE
class Triangle
{
    public:
        Triangle(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, 
        sf::Color color = sf::Color(255,0,0), sf::Color border = sf::Color::Black) ; 
        sf::ConvexShape get() ; 
    private:
        sf::ConvexShape triangle ; 
};
#endif

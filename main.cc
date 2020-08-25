#include "Triangle.hh"

using Point = sf::Vector2f ; 
void Sierpinski_Fractal(Point A, Point B, Point C, int n, sf::RenderWindow &window) ; 

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Sierpinski's Triangle !");
    window.setFramerateLimit(60);
     
    int  N = 9;  // Number of iterations
    Point A (250,0) ;    // Coordinates of the first triangle
    Point B (500,500) ;
    Point C (0,500) ;
    Sierpinski_Fractal(A,B,C,N,window); // Draw the fractal
    window.display(); // Fractal's display 

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}

void Sierpinski_Fractal(Point A, Point B, Point C, int n, sf::RenderWindow &window)
{
    // Lambda function which returns the middle of two point
    auto Middle = [](Point A, Point B) { return Point((A.x+B.x)/2, (A.y+B.y)/2) ; };

    if(n > 0){
        // Draw triangle
        window.draw(Triangle(A,B,C).get()) ;
        // Draw three sub-triangles in the triangle
        Sierpinski_Fractal(A,Middle(A,B),Middle(A,C),n-1,window) ;
        Sierpinski_Fractal(Middle(A,C),Middle(B,C),C,n-1,window) ;
        Sierpinski_Fractal(Middle(A,B),B,Middle(B,C),n-1,window) ;
    }
    return ; 
}
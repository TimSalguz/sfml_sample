#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
int main()
{
    int windowWidth = 1366;
    int windowHeight = 768;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML works!");
    float speedCircle = 0.1;
    float acceleration = 0.1;

    int radius = windowWidth * 0.05;
    sf::CircleShape circleShape(radius);
    circleShape.setPosition(0, 0);
    circleShape.setOrigin(0, 0);
    circleShape.setFillColor(sf::Color::Green);
    int shapeCircle_x = 0.5 * windowWidth-radius;
    int shapeCircle_y = 0;

    float rectangleWidth = windowWidth/10;
    float rectangleHeight = windowHeight/10;
    sf::RectangleShape rectangleShape(sf::Vector2f(rectangleWidth, rectangleHeight));
    int shapeRectangle_x = windowWidth/2+2*rectangleWidth;
    int shapeRectangle_y = windowHeight*0.25;
    rectangleShape.setFillColor(sf::Color::Magenta);
    rectangleShape.setPosition(0, 0);
    rectangleShape.setOrigin(0, 0);


    int radiusTriangle = windowWidth * 0.1;
    sf::CircleShape triangle(radiusTriangle, 3);
    int triangle_x = windowWidth*0.5 - radiusTriangle*3;
    int triangle_y = -windowHeight*0.5;
    triangle.setPosition(0, 0);
    triangle.setFillColor(sf::Color::Yellow);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        speedCircle += acceleration;
        if(speedCircle<0) {
            speedCircle *= 0.999;
            speedCircle += acceleration*1.1;
        }

        if(shapeCircle_y < windowHeight - radius * 2){
            shapeCircle_y = shapeCircle_y+1*speedCircle;
        }
        if(shapeCircle_y > windowHeight - radius * 2)
            shapeCircle_y = windowHeight - radius * 2;

        if(shapeCircle_y == windowHeight - radius * 2){
            std::cout << speedCircle << std::endl;
            shapeCircle_y = shapeCircle_y - 0.001;
            speedCircle = -0.99 * speedCircle;
            if(abs(speedCircle)<3)
                speedCircle *= 0.3;
            if(abs(speedCircle)<0.4)
                speedCircle = 0;
        }

        if(shapeRectangle_y < windowHeight-rectangleHeight)
            shapeRectangle_y++;

        if(triangle_y < windowHeight-radiusTriangle*1.5)
            triangle_y++;

        circleShape.setPosition(shapeCircle_x, shapeCircle_y);
        rectangleShape.setPosition(shapeRectangle_x, shapeRectangle_y);
        triangle.setPosition(triangle_x, triangle_y);
        window.clear();
        window.draw(circleShape);
        window.draw(rectangleShape);
        window.draw(triangle);
        window.display();
        std::this_thread::sleep_for(3ms);
    }

    return 0;
}
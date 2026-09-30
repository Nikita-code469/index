#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

int main() {
    const unsigned int width = 800;
    const unsigned int height = 800;


    sf::RenderWindow window(sf::VideoMode({width, height}), "Sierpinski Triangle - Chaos Game");
    window.setFramerateLimit(60);


    std::vector<sf::Vector2f> vertices = {
        {400.f, 50.f},   // Верхняя
        {50.f, 750.f},   // Левая нижняя
        {750.f, 750.f}   // Правая нижняя
    };


    sf::Vector2f currentPoint(400.f, 400.f);

    sf::VertexArray points(sf::PrimitiveType::Points, 0);


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);


    while (window.isOpen()) {
  
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        for (int i = 0; i < 200; ++i) {
            int targetVertex = dis(gen);
            

            currentPoint.x = (currentPoint.x + vertices[targetVertex].x) / 2.0f;
            currentPoint.y = (currentPoint.y + vertices[targetVertex].y) / 2.0f;

  
            points.append(sf::Vertex{currentPoint, sf::Color::Cyan});
        }


        window.clear();
        window.draw(points);
        window.display();
    }

    return 0;
}
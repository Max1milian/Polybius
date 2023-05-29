#include <SFML/Graphics.hpp>
int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Testwindow");
  // Creating our shape.
  sf::RectangleShape rectangle(sf::Vector2f(window.getSize().x / 2 , window.getSize().x / 2));
  rectangle.setFillColor(sf::Color::Red);
  rectangle.setPosition(320, 240);
  rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // Close window button clicked.
        window.close();
      }
    }
    window.clear(sf::Color::Black);
    window.draw(rectangle); // Drawing our shape.
    window.display();
  }
}

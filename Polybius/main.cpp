#include <pthread.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <iostream>
 
int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Polybius", sf::State::Windowed);
 
    // Load a sprite to display
    const sf::Texture texture("./assets/sprites/ship.png");
    sf::Sprite sprite(texture);
    sprite.setScale({4,4});
 
    // Create a graphical text to display
     const sf::Font font("./assets/fonts/Polybius1981.ttf");
     sf::Text text(font, "Hello SFML", 50);
    text.setPosition({window.getSize().x / 2.f, 0});
 
    // Load a music to play
    // sf::Music music("nice_music.ogg");
 
    // Play the music
    // music.play();
 
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
            }
        }
 
        // Clear screen
        window.clear(sf::Color::Cyan);
 
        // Draw the sprite
        window.draw(sprite);
 
        // Draw the string
        window.draw(text);
 
        // Update the window
        window.display();
    }
}

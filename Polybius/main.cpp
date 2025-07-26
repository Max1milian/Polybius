#include <pthread.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>

int main()
{
    //init section

    // Create the main window
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "Polybius",sf::Style::Default, sf::State::Windowed);
 
    // Load a sprite to display
    const sf::Texture texture("./assets/sprites/ship.png");
    sf::Sprite sprite(texture);
    sprite.setScale({4,4});
    sprite.setOrigin({texture.getSize().x / 2.f, texture.getSize().y / 2.f});
    sprite.setPosition({(window.getSize().x / 2.f) + 100, window.getSize().y / 2.f});

     //kinda keep that snippet for subliminal message. Problably outsource that into its own procedure
     // Create a graphical text to display
     //const sf::Font font("./assets/fonts/Polybius1981.ttf");
     //sf::Text text(font, "Hello SFML", 50);
     //text.setPosition({window.getSize().x / 2.f, 0});
 
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
                //todo need to implement a rotation matrix that rotates the ship arround window.getWindowSize().x / 2 and windowy.getWindowSize().y / 2.f
                //cuz right now it's just constantly rotating for arround 180 degrees every frame
                /*
                 the rotation matrix is a 2x2 matrix that is defined by 
                 [cos(θ) -sin(θ)] [x]
                 [sin(θ) cos(θ)]  [y]
                 */
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    window.close();
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Right) {
                    sprite.move({2,0});
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Left) {
                sprite.move({-2,0});
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Down) {
                    sprite.move({0, 2});

                    // PROBLEM: it's currently rotating the sprite 180 degree every frame. I just need it once. need to figure it out how
                    // TODO: need to implement a if clause that checks if the sprite has already rotated once.
                    sprite.rotate(sf::degrees(180));                 
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
                    sprite.move({0, -2});
                    //same goes here. need to place that if clause here as well.
                    sprite.rotate(sf::degrees(180));
                }
                std::cout << "x position of the ship: " <<  sprite.getPosition().x << " y position of the ship: " << sprite.getPosition().y << "\n";
            }
        }
 
        // Clear screen
        window.clear(sf::Color::Black);
 
        // Draw the sprite
        window.draw(sprite);
 
        // Draw the string
        //window.draw(text);
 
        // Update the window
        window.display();
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

#include <pthread.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>

int main()
{
    //init section
    // Create the main window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Polybius",sf::Style::Default, sf::State::Windowed);

    // Load a sprite to display
    const sf::Vector2f center = {window.getSize().x / 2.f, window.getSize().y / 2.f};
    const sf::Texture texture("./assets/sprites/ship.png");
    sf::Sprite sprite(texture);
    sprite.setScale({4,4}); //setting the scale to 4 times the size because the original size is way to small to be seen on a large screen
    sprite.setOrigin({texture.getSize().x / 2.f, texture.getSize().y / 2.f});
    sprite.setPosition({(window.getSize().x / 2.f) + 100, window.getSize().y / 2.f});

     //gonna keep that snippet for subliminal message. Problably outsource that into its own procedure
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
            // constantly calculating the raduis. This needs to be done because the ship is moving upwards and downwards
            // Formula for calculating the slope: m = (y2 - y1) / (x2 - x1)
            // Ship is x2 and y2.
            // Center is x1 and y1
            sf::Vector2f slope({sprite.getPosition().x - center.x, sprite.getPosition().y - center.y});
            
            
            //due to the definition of Vector2f slope.x will calculate calculates y2 - y1 and slope.y calculates x2 - x1
            //double radius = (slope.y) / (slope.x); 

            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                //todo need to implement a rotation matrix that rotates the ship arround window.getWindowSize().x / 2 and window.getWindowSize().y / 2.f
                //cuz right now it's just constantly rotating for arround 180 degrees every frame
                /*
                 the rotation matrix is a 2x2 matrix that is defined by 
                 [cos(θ) -sin(θ)] [x]   [x * cos(θ)) - y * sin(θ)]
                 [sin(θ) cos(θ)]  [y] = [x * sin(θ) + y * cos(θ)]
                 */
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
                    sprite.move({0, slope.y + 0.75f});

                    // PROBLEM: it's currently rotating the sprite 180 degree every frame. I just need it once. need to figure it out how
                    // TODO: need to implement a if clause that checks if the sprite has already rotated once.
                    // Another idea is to get the number of every corner of the sprite and them allign them in the wanted position
                    //sprite.rotate(sf::degrees(180));                 
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::Up) {
                    sprite.move({0, -(slope.y + 0.75f)});
                    //same goes here. need to place that if clause here as well.
                    //sprite.rotate(sf::degrees(180));
                }
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
    //music.stop();
    std::cout << std::endl;
    return EXIT_SUCCESS;
}

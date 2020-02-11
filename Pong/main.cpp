#include <SFML/Graphics.hpp>        // 
#include <iostream>                 // DEBUG 
#include <SFML/System.hpp>          // vector2<Type> overloaded operators
#include "lib/Player.h"
#include "lib/Ball.h"
#include "lib/utility.h"
#include "lib/ScoreTable.h"


int main()
{ 
    // generating random velocity vector for ball
    srand(time(NULL));

    // Main window definition 
    sf::RenderWindow window(sf::VideoMode(1024, 768), "MAIN WINDOW", sf::Style::Default);
    window.setFramerateLimit(60);

    /*  
        Weird but: 
        player (id == 1) is on lefthand side
        player2 (id == 0) is on righthand side
    */
    Player player2({window.getSize().x - 24, window.getSize().y / 2}, 0), player({0, window.getSize().y / 2}, 1);


    Ball ball({window.getSize().x / 2, window.getSize().y / 2});
    ball.setVelocity(sf::Vector2<float>({5, -2}));

    Wall upperWall({0, 0}, {window.getSize().x, 1}, U);
    Wall bottomWall({0, window.getSize().y - 1}, {window.getSize().x, 1}, B);
    Wall leftWall({0, 0}, {1, window.getSize().y}, L);
    Wall rightWall({window.getSize().x - 1, 0}, {1, window.getSize().y}, R);

    ScoreTable score(sf::Vector2f(window.getSize().x / 2, 0), 0, 0);

    /* Main loop */
    /// =============================================================================
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {  
                /*  
                if (ball.isMoving())
                    ball.setVelocity({0, 0});
                else 
                    ball.setVelocity({rand() % 10, rand() % 3});
                */
               ball.setVelocity(randVelocity(10, 1));
            }
            
            /* Steerage */
            /// =============================================================================
            // player 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                player.setVelocity(UP);

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                player.setVelocity(DOWN);

            else
                player.setVelocity(NONE);

            // player2
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                player2.setVelocity(UP);

            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                player2.setVelocity(DOWN);
            
            else
                player2.setVelocity(NONE);
            /// =============================================================================

            
        }
        /* Collisions */
        /// =============================================================================
        testCollision(ball, player);
        testCollision(ball, player2);
        testCollision(ball, upperWall);
        testCollision(ball, bottomWall);
        if (testCollision(ball, leftWall)) 
        {
            score.add(1, 0);
            ball.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});
            ball.setVelocity(randVelocity(9, 1));
        }
        if (testCollision(ball, rightWall)) 
        {
            score.add(0, 1);
            ball.setPosition({window.getSize().x * 0.5f, window.getSize().y * 0.5f});
            ball.setVelocity(randVelocity(9, 1));
        }
        /// =============================================================================

        /* Moving objects */
        /// =============================================================================
        ball.move();
        player.move();
        player2.move();
        /// =============================================================================
        
        window.clear(sf::Color::Black);

        /* Drawing */
        /// =============================================================================
        player.drawTo(window);
        player2.drawTo(window);
        ball.drawTo(window);
        score.drawTo(window);
        /// =============================================================================


        window.display();
    }
    /// =============================================================================

    return 0;
}

#ifndef __UTILITY_H_INCLUDED__
#define __UTILITY_H_INCLUDED__

#include <time.h>
#include "Wall.h"
#include <SFML/System.hpp>
//#include "Ball.h"
//#include "Player.h"


/// =============================================================================
/*  
    \brief testing collision between Ball object and Wall object

    \param &ball         - Ball object ref
    \param &wall         - Wall object ref

    \return
        true - in case they collide
        false - otherwise
*/
bool testCollision(Ball & ball, Wall & wall)
{
    /* Zderzenie z gorna sciana */
    if (wall.getType() == U)
    {
        if (ball.getPosition().y <= wall.getPosition().y)
        {
            ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
            return true;
        }
    }
    else if (wall.getType() == B)
    {
        if (ball.getPosition().y + ball.getDimensions().y >= wall.getPosition().y)
        {
            ball.setVelocity(sf::Vector2f(ball.getVelocity().x, -ball.getVelocity().y));
            return true;
        }
    }
    else if (wall.getType() == L)
    {
        if (ball.getPosition().x <= wall.getPosition().x)
        {
            ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
            return true;
        }
    }
    else
    {
        if (ball.getPosition().x + ball.getDimensions().x >= wall.getPosition().x)
        {
            ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y));
            return true;
        }
    }
    
    return false;
}
/// =============================================================================

/// =============================================================================
/*  
    \brief testing collision between Ball object && Player object

    \param &ball     - Ball object ref
    \param &player   - Player object ref

    \return 
        true - in case they collide
        false - otherwise

    \DEBUG_NOTE This function does not handle it properly. There is a bug when ball passes the player below
    player's "middle", intersects with player and false is still returned. 

    \note THAT IF CONDITION IS MONSTROUS :D
*/
bool testCollision(Ball & ball, Player & player)
{
    if (player.getId() == 0)
    {
        if 
        (
            (
            ball.getPosition().x + ball.getDimensions().x >= player.getPosition().x
            ) 
            &&
            ( 
                (
                    (ball.getPosition().y + ball.getDimensions().y >= player.getPosition().y) 
                    && 
                    (ball.getPosition().y + ball.getDimensions().y <= player.getPosition().y + player.getDimensions().y)
                ) 
                || 
                (
                    (ball.getPosition().y >= player.getPosition().y)
                    &&
                    (ball.getPosition().y + ball.getDimensions().y <= player.getPosition().y + player.getDimensions().y) 
                )
            )
        )
        {
            ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y) * 1.05f);
            return true;
        }
    }
    else if (player.getId() == 1)
    {
        if 
        (
            (
            ball.getPosition().x <= player.getPosition().x + player.getDimensions().x
            ) 
            &&
            ( 
                (
                    (ball.getPosition().y + ball.getDimensions().y >= player.getPosition().y) 
                    && 
                    (ball.getPosition().y + ball.getDimensions().y <= player.getPosition().y + player.getDimensions().y)
                ) 
                || 
                (
                    (ball.getPosition().y >= player.getPosition().y)
                    &&
                    (ball.getPosition().y + ball.getDimensions().y <= player.getPosition().y + player.getDimensions().y) 
                )
            )
        )
        {
            ball.setVelocity(sf::Vector2f(-ball.getVelocity().x, ball.getVelocity().y) * 1.05f);
            return true;
        }       
    }
}
/// =============================================================================


/// =============================================================================
/*  
    \brief Converts integer value (> 0 !!!!) to a std::string

    \param integer - number to convert (MUST BE > 0)

    \return integer as a string
*/
std::string intToStr(int integer)
{
    std::string revInteger = "";
    while (integer > 0)
    {
        revInteger += static_cast<char>((integer % 10) + 48);
        integer /= 10;
    }
    std::string returnValue = "";
    for (int i = revInteger.length() - 1; i >= 0; --i)
    {
        returnValue += revInteger[i];
    }
    return returnValue;
}
/// =============================================================================

/// =============================================================================
/*  
    \brief generates random velocity vector with coordinates in range (-range - modifier, range + modifier)

    \param range - as above
    \param modifier - as above

    \return sf::Vector2f - velocity vector
*/
sf::Vector2f randVelocity(int range, int modifier = 0)
{
    int signX = rand() % 2, signY = rand() % 2;
    return sf::Vector2f( (signX == 0 ? (rand() % range + modifier) : -(rand() % range + modifier)), (signY == 0 ? (rand() % range + modifier) : -(rand() % range + modifier)) );
}
/// =============================================================================

#endif
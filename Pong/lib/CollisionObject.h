#ifndef __COLLISIONOBJECT_H_INCLUDED__
#define __COLLISIONOBJECT_H_INCLUDED__

#include <SFML/Graphics.hpp>
#include <iostream>

/// =============================================================================
class CollisionObject
{
protected:
    /* Position of the CollisionObject relative to the window of the game */
    sf::Vector2f position;
    /* Dimensions of the CollisionObject in pixels */
    sf::Vector2f dimensions;
    /* Rect representing CollisionObject */
    sf::RectangleShape rect;

public:
    /* 
        \brief draws CollisionObject to the game window that is given as parameter

        \param &window - "drawing target"
    */
    virtual void drawTo(sf::RenderWindow & window);
    /*  
        \brief basically it is redundant :D Remove at your own risk!
    */
    virtual void move();
    /*
        \return returns CollisionObject's position vector
    */
    virtual sf::Vector2f getPosition();
    /*  
        \return returns CollisionObject's dimensions vector
    */
    virtual sf::Vector2f getDimensions();
    /*  
        \brief Changes position of Collision object to paramPosition

        \param paramPosition - new position of CollisionObject    
    */
    virtual void setPosition(sf::Vector2f paramPosition);
};
/// =============================================================================

/* Bodies */
/// =============================================================================
sf::Vector2f CollisionObject::getPosition()
{
    return position;
}

void CollisionObject::drawTo(sf::RenderWindow & window)
{
    window.draw(rect);
}

void CollisionObject::move()
{
    return;
}

sf::Vector2f CollisionObject::getDimensions()
{
    return dimensions;
}

void CollisionObject::setPosition(sf::Vector2f paramPosition)
{
    position = paramPosition;
}
/// =============================================================================

#endif
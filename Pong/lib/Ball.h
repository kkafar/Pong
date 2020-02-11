#ifndef __BALL_H_INCLUDED__
#define __BALL_H_INCLUDED__

#include "CollisionObject.h"

class Wall;

/// =============================================================================
class Ball : public CollisionObject
{
private:
    /* Velocity vector (how far, every frame, Ball is moving) */
    sf::Vector2f velocity;
public:
    /*  
        \brief Constructor 
        
        \param paramPosition - starting position of the ball
        
        \default paramPosition = {300, 300}, debug purposes
    */
    Ball(sf::Vector2f paramPosition);
    /*  
        \brief DEBUG destructor
    */
    ~Ball();
    /*  
        \brief Adds velocity vector to position vector
        updates rect position
    */
    void move();
    /*  
        \brief Sets velocity vector to given vector

        \param &vel new velocity vector
    */
    void setVelocity(const sf::Vector2f & vel);
    /* 
        \brief Checks whether ball is moving

        \return
            true - ball is moving
            false - otherwise
    */
    bool isMoving();
    /*  
        \return returns velocity vector
    */
    sf::Vector2f getVelocity();

    friend bool testCollision(const Ball &, const Wall &);
};
/// =============================================================================

/* Bodies */
/// =============================================================================
Ball::Ball(sf::Vector2f paramPosition = {300, 300})
{
    position = paramPosition;
    dimensions = {50, 50};
    rect.setPosition(position);
    rect.setSize(dimensions);
    rect.setFillColor(sf::Color::Blue);
}

Ball::~Ball()
{
    std::cout << "DEBUG: DESTRUKTOR KLASY BALL\n";
}

void Ball::setVelocity(const sf::Vector2f & vel)
{
    velocity = vel;
}

void Ball::move()
{
    position = position + velocity;
    rect.setPosition(position);
}

bool Ball::isMoving()
{
    return (velocity.x != 0 || velocity.y != 0);
}

sf::Vector2f Ball::getVelocity()
{
    return velocity;
}
/// =============================================================================

#endif
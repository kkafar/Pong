#ifndef __PLAYER_H_INCLUDED__
#define __PLAYER_H_INCLUDED__

#include "CollisionObject.h"

/// =============================================================================
enum MovementDirection {UP = 1, DOWN = 2, NONE = 3};
typedef MovementDirection MDIR;
/// =============================================================================

/// =============================================================================
class Player : public CollisionObject
{
private: 
    sf::Vector2f velocity;
    MDIR dir;
    int id;
public:
    /* 
        \brief Constructor
        
        \param paramPosition - starting position of player
        \param ID           - id number of player
    */
    Player(sf::Vector2f paramPosition, int ID);
    /* 
        /brief DEBUG destructor
    */
    ~Player();
    /*  
        \brief Adds velocity vector to position vector
        updates rect position
    */
    void move();
    /*  
        \brief sets velocity vector to appropriate value basing on 'direction' value
            fixed velocity value UP/DOWN is -10/10 pixels per frame 

        \param direction - new direction of player
    */
    void setVelocity(MDIR direction);
    /*  
        \return value of id private member
    */
    int getId();
};
/// =============================================================================

/* Bodies */
/// =============================================================================
Player::Player(sf::Vector2f paramPosition = {1000, 512}, int ID = 0)
{
    position = paramPosition;
    dimensions = {24, 100};
    rect.setFillColor(sf::Color::Yellow);
    rect.setPosition(position);
    rect.setSize(dimensions);
    dir = NONE;
    id = ID;
}

Player::~Player()
{
    std::cout << "DEBUG: DESTRUKTOR KLASY PLAYER\n";
}

int Player::getId()
{
    return id;
}
void Player::move()
{
    position = position + velocity;
    rect.setPosition(position);
}

void Player::setVelocity(MDIR direction)
{
    switch(direction)
    {
        case NONE: 
            velocity = {0, 0};
            break;
        case UP:
            velocity = {0, -10};
            break;
        case DOWN:
            velocity = {0, 10};
            break;
        default:
            std::cout << "DEBUG: BLAD W SETVELOCITY(MDIR DIRECTION)\n";
    }
}
/// =============================================================================
#endif
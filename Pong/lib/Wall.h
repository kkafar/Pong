#ifndef __WALL_H_INCLUDED__
#define __WALL_H_INCLUDED__

#include "CollisionObject.h"

/// =============================================================================
class Ball;
enum WallType {L = 1, R = 2, B = 3, U = 4, N = 0};
/// =============================================================================

/// =============================================================================
class Wall : public CollisionObject
{
private:
    WallType type;
public:
    /*  
        \brief Constructor

        \param paramPosition    - starting wall position
        \param paramDimensions  - wall dimensions (it is represented as rectangle shape) 
        \param t                - type of the wall object (enum WallType)
    */
    Wall(sf::Vector2f paramPosition, sf::Vector2f paramDimensions, WallType t);
    /*  
        \brief DEBUG destructor
    */
    ~Wall();

    friend bool testCollision(const Ball &, const Wall &);

    /*  
        \return returns private member 'type'
    */
    WallType getType();
};
/// =============================================================================


/* Bodies */
/// =============================================================================
Wall::Wall(sf::Vector2f paramPosition, sf::Vector2f paramDimensions, WallType t) : type(t)
{
    position = paramPosition;
    dimensions = paramDimensions;
}

Wall::~Wall()
{
    std::cout << "DEBUG: DESTRUKTOR KLASY WALL\n";
}

WallType Wall::getType()
{
    return type;
}
/// =============================================================================

#endif
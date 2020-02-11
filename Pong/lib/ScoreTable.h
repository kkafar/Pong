#ifndef __SCORETABLE_H_INCLUDED__
#define __SCORETABLE_H_INCLUDED__

#include <SFML/Graphics.hpp>
#include "utility.h"

/// =============================================================================
class ScoreTable 
{
private:
    // sf::Text label;
    sf::Text score;
    sf::Font font;
    int scoreLeft, scoreRight;
    std::string strScoreLeft, strScoreRight;

public:
    /*  
        \brief Constructor
        
        \param paramPosition - position of score table relative to the game window
        \param left         - starting score of left player
        \param right        - starting score of right player
        
        \default
        left = 0
        right = 0
    */
    ScoreTable(sf::Vector2f  paramPosition, int left, int right);
    /*  
        \brief DEBUG destructor
    */
    ~ScoreTable();
    /*  
        \brief  changes score value
                'left' is added to current left-hand side player score
                'right' is added to current right-hand side player score

        \param left     - value added to "left player"  score
        \param right    - value added to "right player" score
    */
    void add(int left, int right);
    /* 
        \brief draws ScoreTable object to the game window that is given as parameter

        \param &window - "drawing target"
    */
    void drawTo(sf::RenderWindow & window);

    friend std::string intToStr(int integer);
};
/// =============================================================================

/* Bodies */
/// =============================================================================
ScoreTable::ScoreTable(sf::Vector2f  paramPosition, int left = 0, int right = 0) : scoreLeft(left), scoreRight(right)
{
    font.loadFromFile("/home/kkafara/workspace/Projects/SFML/Pong/files/fonts/Go-Bold.ttf");
    // label.setFont(font);
    score.setFont(font);
    // label.setCharacterSize(10);
    score.setCharacterSize(10);
    // label.setColor(sf::Color::Blue);
    score.setColor(sf::Color::Red);
    // label.setString("SCORE\n");
    score.setPosition(paramPosition);
    score.setString(intToStr(scoreLeft) + " : " + intToStr(scoreRight));
}

ScoreTable::~ScoreTable()
{
    std::cout << "DEBUG: DESTRUKTOR KLASY SCORETABLE\n";
}

void ScoreTable::add(int left, int right)
{
    if (left > 0)
    {
        scoreLeft += left;
        strScoreLeft = intToStr(scoreLeft);
        std::cout << strScoreLeft << "\n";
    }
    if (right > 0)
    {
        scoreRight += right;
        strScoreRight = intToStr(scoreRight);
        std::cout << strScoreRight << "\n";
    }
    score.setString(intToStr(scoreLeft) + " : " + intToStr(scoreRight));
}

void ScoreTable::drawTo(sf::RenderWindow & window)
{
    window.draw(score);
}
/// =============================================================================
#endif
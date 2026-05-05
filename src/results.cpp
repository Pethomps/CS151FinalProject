#include "../header/results.h"
#include <string>


Results::Results()
{
    if (!mFont.loadFromFile("./assets/Fonts/VintageCharm-Regular.otf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    mResults.setFont(mFont);
    mResults.setCharacterSize(60);
    mResults.setString("Results");

    mScores.setPosition(sf::Vector2f(60, 450));
    mScores.setSize(sf::Vector2f(60, 20));
    mScores.setText("Score");
    mScores.setColorTextNormal(sf::Color::Blue);
    
    mPlayAgain.setPosition(sf::Vector2f(320, 450));
    mPlayAgain.setSize(sf::Vector2f(60, 20));
    mPlayAgain.setText("Play Again");
    mPlayAgain.setColorTextNormal(sf::Color::Blue);

    mLeave.setPosition(sf::Vector2f(580, 450));
    mLeave.setSize(sf::Vector2f(60, 20));
    mLeave.setText("Quit");
    mLeave.setColorTextNormal(sf::Color::Blue);
}
State Results::handleInput(sf::Event &e, sf::RenderWindow &window)
{
    if (mPlayAgain.handleInput(e, window)){
        return game;
    }
    if (mScores.handleInput(e, window)){
        return welcome;
    }
    if (mLeave.handleInput(e, window)){
        return quit;
    }
    return results;
}
void Results::update()
{
    mScores.update();
    mPlayAgain.update();
    mLeave.update();  
}
void Results::render(sf::RenderWindow &window)
{
    window.draw(mResults);
    window.draw(mScores);
    window.draw(mPlayAgain);
    window.draw(mLeave);
}

void Results::setScore(int score)
{
    mResults.setString("Results\n\nScore: " + std::to_string(score));
}

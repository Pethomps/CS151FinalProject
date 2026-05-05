#include "../header/results.h"
#include <string>


Results::Results()
{
    // Font
    if (!mFont.loadFromFile("./assets/Fonts/VintageCharm-Regular.otf"))
    {
        std::cout<<"Error opening file\n";
        exit(2);
    }
    // Background
    mBackground.loadFile("assets/Images/Background2.png");
    mBackground.resizePic({800, 600});
    // Title
    mTitle.setFont(mFont);
    mTitle.setCharacterSize(100);
    mTitle.setString("RESULTS");
    mTitle.setFillColor(sf::Color(249, 235, 205));
    mTitle.setOutlineThickness(8);
    mTitle.setOutlineColor(sf::Color(254, 208, 109));
    sf::FloatRect titleBounds = mTitle.getLocalBounds();
    mTitle.setOrigin(titleBounds.width / 2.f, titleBounds.height / 2.f);
    mTitle.setPosition(400.f, 120.f);
    // Your Score
    mYourScoreText.setFont(mFont);
    mYourScoreText.setCharacterSize(50);
    mYourScoreText.setFillColor(sf::Color(255, 215, 0));
    sf::FloatRect scoreBounds = mYourScoreText.getLocalBounds();
    mYourScoreText.setOrigin(titleBounds.width / 2.f, titleBounds.height / 2.f);
    mYourScoreText.setPosition(400.f, 220.f);
    // High Scores
    mHighScoresText.setFont(mFont);
    mHighScoresText.setCharacterSize(36);
    mHighScoresText.setFillColor(sf::Color(255, 215, 0));
    sf::FloatRect hsBounds = mHighScoresText.getLocalBounds();
    mHighScoresText.setOrigin(hsBounds.width / 2.f, hsBounds.height / 2.f);
    mHighScoresText.setPosition(400.f, 300.f);
    // Button Main Menu
    mMainMenu.setText("Main Menu");
    mMainMenu.setPosition({400, 515});
    mMainMenu.setSize({350, 70});
    mMainMenu.setColorTextNormal(sf::Color(249,235,205));
    mMainMenu.setColorTextHover(sf::Color(254,208,109));
    // Button Play Again
    mPlayAgain.setText("Play Again");
    mPlayAgain.setPosition({400, 440});
    mPlayAgain.setSize({350, 70});
    mPlayAgain.setColorTextNormal(sf::Color(249,235,205));
    mPlayAgain.setColorTextHover(sf::Color(254,208,109));
    mPlayAgain.setColor(sf::Color(254,208,109));
    // Button Exit
    mExit.setText("Exit");
    mExit.setPosition({400, 590});
    mExit.setSize({350, 70});
    mExit.setColorTextNormal(sf::Color(249,235,205));
    mExit.setColorTextHover(sf::Color(254,208,109));
    mExit.setColor(sf::Color(254,208,109));
}

void Results::setScore(int score)
{
    mYourScoreText.setString("Results\n\nScore: " + std::to_string(score));

    mHighScoresText.setString(
        "HIGH SCORES\n\n"
        "1. 28\n"
        "2. 25\n"
        "3. " + std::to_string(score) + "   <--- YOU\n"
        "4. 16\n"
        "5. 12\n"
    );
}

State Results::handleInput(sf::Event &e, sf::RenderWindow &window)
{
    if (mPlayAgain.handleInput(e, window)){
        return game;
    }
    if (mMainMenu.handleInput(e, window)){
        return welcome;
    }
    if (mExit.handleInput(e, window)){
        return quit;
    }
    return results;
}

void Results::update()
{
    mPlayAgain.update();
    mMainMenu.update();
    mExit.update();  
}

void Results::render(sf::RenderWindow &window)
{
    mBackground.draw(window);
    window.draw(mTitle);
    window.draw(mYourScoreText);
    window.draw(mHighScoresText);
    window.draw(mPlayAgain);
    window.draw(mExit);
}
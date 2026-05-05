#include "../header/game.h"
#include "../header/states.h"

Game::Game()
{
    mGameState = welcome;
    // Use current time as seed for random generator
    srand(time(0));

    // Sound and music objects
    mBackgroundMusic.load("./assets/Audio/western-texas-background.ogg");
    mBackgroundMusic.play();
    
}


void Game::handleInput(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        switch (mGameState)
        {
            case welcome:
            {
                mGameState = mWelcomeScreen.handleInput(event, window);
                break;
            }
            case cont:
            {
                break;
            }

            case game:
            {
                State nextState = mGame.handleInput(event, window);
                if (nextState == results) {
                    mResults.setScore(mGame.getScore());
                }
                mGameState = nextState;
                break;
            }
            case results:
                mGameState = mResults.handleInput(event,window);
                break;
            case quit:
            {
                window.close();
                break;
            }
        }
    }
}
void Game::update(double elapsedTime, sf::RenderWindow &window)
{
    switch (mGameState)
    {
    case welcome:
        mWelcomeScreen.update();
        break;
    case game:
        mGame.update(elapsedTime,window);
        if (mGame.isTimeUp()) 
        {
            mResults.setScore(mGame.getScore());
            mGameState = results;
        }
        break;
    case results:
        mResults.update();
        break;
    case quit:
        window.close();
        break;
    case cont:
        break;
    }
}
void Game::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    switch (mGameState)
    {
        case welcome:
            mWelcomeScreen.render(window);
            break;
        case game:
            mGame.render(window);
            break;
        case results:
            mResults.render(window);
            break;
        case quit:
            break;
        case cont:
            break;
    }
    window.display();
}
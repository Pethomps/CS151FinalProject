#include "../header/game.h"

Game::Game()
{
    mGameState = welcome;
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
        case game:
        {
            mGameState = mGame.handleInput(event, window);
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
        break;
    case results:
        mResults.update();
    case quit:
        window.close();
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
    }
    window.display();
}
#include "../header/button.h"
#include "../header/states.h"


class Results
{
    public:
        Results();
        State handleInput(sf::Event& e, sf::RenderWindow& window);
        void update();
        void render(sf::RenderWindow& window);
        void setScore(int score);


    private:
        sf::Text mResults;
        Button mScores;
        Button mPlayAgain;  
        Button mLeave;
        sf::Font mFont;
};

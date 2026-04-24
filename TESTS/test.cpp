#include "catch_amalgamated.hpp"
#include "../header/button.h"
#include "../header/game.h"
// #include "../header/play.h"
#include "../header/results.h"
#include "../header/states.h"
// #include "../header/welcome.h"
#include "../header/weapon.h"
#include "../header/target.h"
#include "../header/background.h"
#include "../header/GameOver.h"


// ----------------------------------------------
// Class Constructors
// ----------------------------------------------
// TEST_CASE("Game class default constructor initializes correctly") {
//     Game g = Game();
//     REQUIRE(true);  // object initialized
    
// }
TEST_CASE("Button class constructor initializes correctly") {

    SECTION("default constructor") {
        //Button("Play!", {300,100}, {1,1}, sf::Color::White)
        Button b = Button();
        REQUIRE(true);  // object initialized
        sf::Vector2f actualSize = b.getDimensions();
        sf::Vector2f expectedSize = {1,1};
        sf::Uint32 actualState = b.getState();
    
        REQUIRE(b.getPosition().x == 300);      // default position (x,y)
        REQUIRE(b.getPosition().y == 100);
        REQUIRE(actualSize == expectedSize);    // default size (width:1, height:1)
        REQUIRE(actualState == normal);         // default state (normal || 0)
    }
    SECTION("explicit constructor") {
        //Button(std::string s, sf::Vector2f position, sf::Vector2f size, sf::Color color)
        Button b = Button("test me", {333,111}, {2,2}, sf::Color::Black);
        REQUIRE(true);
        sf::Vector2f expectedSize = {2,2};
        sf::Vector2f actualSize = b.getDimensions();
        sf::Uint32 actualState = b.getState();
    
        REQUIRE(b.getPosition().x == 333);      // default position (x,y)
        REQUIRE(b.getPosition().y == 111);
        REQUIRE(actualSize == expectedSize);    // default size (width:1, height:1)
        REQUIRE(actualState == normal);         // default state (normal || 0)
    }

}
// TEST_CASE("Play class default constructor initializes correctly") {
//     Play s = Play();
//     REQUIRE(true);  // object initialized
// }
// TEST_CASE("Results class default constructor initializes correctly") {
//     Results r = Results();
//     REQUIRE(true);  // object initialized
// }
// TEST_CASE("Welcome class default constructor initializes correctly") {
//     Welcome w = Welcome();
//     REQUIRE(true);  // object initialized
// }
// TEST_CASE("Weapon class default constructor initializes correctly") {
//     Weapon w = Weapon();
//     REQUIRE(true);  // object initialized
// }
// TEST_CASE("Target class default constructor initializes correctly") {
//     Target t = Target();
//     REQUIRE(true);  // object initialized
//}
TEST_CASE("Background class default constructor initializes correctly") {
    Background b = Background();
    REQUIRE(true);  // object initialized
}
TEST_CASE("GameOver class default constructor initializes correctly")
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    GameOver go(window);
    REQUIRE(true); // constructor runs properly
}
// ----------------------------------------------
// Button
// ----------------------------------------------
TEST_CASE("Button functions work correctly") {
    Button b = Button("test me", {333,111}, {2,2}, sf::Color::Black);
    REQUIRE(true);  // object initialized

    SECTION("changing position") {
        sf::Vector2f oldPosition = b.getPosition();
        sf::Vector2f newPosition = {300,100};
        b.setPosition(newPosition);
        REQUIRE(true);

        sf::Vector2f actualPosition = b.getPosition();
        REQUIRE(newPosition == actualPosition);
        REQUIRE(newPosition != oldPosition);
    }
    SECTION("changing size") {
        sf::Vector2f oldDimensions = b.getDimensions();
        sf::Vector2f newDimensions = {1,1};
        b.setSize(newDimensions);
        REQUIRE(true);

        sf::Vector2f actualDimensions = b.getDimensions();
        REQUIRE(newDimensions == actualDimensions);
        REQUIRE(oldDimensions != actualDimensions);
    }
    SECTION("changing color") {
        b.setColor(sf::Color(128,128,128));
        REQUIRE(true);
    }
    SECTION("changing text") {
        b.setText("changing text");
        REQUIRE(true);
    }
    SECTION("changing normal color") {
        b.setColorTextNormal(sf::Color(0,0,0));
        REQUIRE(true);
    }
    SECTION("changing hover color") {
        b.setColorTextHover(sf::Color(255,255,255));
        REQUIRE(true);
    }
}

// ----------------------------------------------
// Background
// ----------------------------------------------
TEST_CASE("Background functions work correctly") {
    Background b = Background();
    REQUIRE(true);  // object initialized
    sf::RenderWindow window(sf::VideoMode(800, 600), "Background Class Test");

    SECTION("background object loads file successfully") {
        b.loadFile("Background1.png", window);
        REQUIRE(true);
    }
    // We can test for failure-to-load-file if it throws an exception instead of exit(1)
    // SECTION("background object fails successfully") {
    //     REQUIRE_THROWS_AS( b.loadFile("notAFile.png", window), ifstream::badbit );
    // }
}

// ----------------------------------------------
// Game Over
// ----------------------------------------------
TEST_CASE("Test GameOver resize correctly")
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    GameOver go(window);
    
    SECTION("Resize window background to different size"){
        window.setSize(sf::Vector2u(1000, 800));
        go.resize(window);

        REQUIRE(true);
    }
}

TEST_CASE("Test GameOver draw function")
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

    GameOver go(window);
    
    SECTION("Draw works correctly"){
        go.draw(window);
        REQUIRE(true);
    }
}

// ----------------------------------------------
// Target
// ----------------------------------------------
TEST_CASE("Test target initialize alive")
{
    Target t(100.f, 100.f, 10.f);

    REQUIRE(t.isAlive() == true);
}

TEST_CASE("Target moves when updated")
{
    Target t(100.f, 100.f, 10.f);

    sf::Vector2f before = t.getPosition();

    t.update(1.f); // 1 second

    sf::Vector2f after = t.getPosition();

    REQUIRE(after != before);
}

TEST_CASE("Target detects hit")
{
    Target t(100.f, 100.f, 10.f);

    SECTION("Detects hit correclly")
    {
        sf::FloatRect bullet(100.f, 100.f, 5.f, 5.f);
        REQUIRE(t.isHit(bullet) == true);
    }

    SECTION("Does not detect hit")
    {
        sf::FloatRect bullet(400.f, 400.f, 5.f, 5.f);
        REQUIRE(t.isHit(bullet) == false);
    }
}

TEST_CASE("Test change position")
{
    Target t(100.f, 100.f, 10.f);

    sf::Vector2f before = t.getPosition();

    t.newPosition();

    sf::Vector2f after = t.getPosition();

    REQUIRE(after != before);
}

TEST_CASE("Test speed increase")
{
    Target t(100.f, 100.f, 10.f);

    float before = t.getSpeed();

    t.newPosition();

    float after = t.getSpeed();

    REQUIRE(after > before);
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <unistd.h>
#include "Resources.hpp"
#include <istream>

using namespace sf;

bool isDead, isSave;

float rslX = 683, rslY = 384;
float speed = 1.8;
bool startGame(RenderWindow &window)
{
    Player player(heroImage, "Player", 41 * 32, 34 * 32, 0, 0);
    player.health -= minus;
    if(creative)player.health = 2e9;
    Clock clock;
    float time = 0;
    window.setMouseCursorVisible(false);


    clock.restart();



    view.reset(FloatRect(0, 0, rslX, rslY));




    loadEntities(isSave);

    mapTexture.loadFromImage(mapImage);
    mapSprite.setTexture(mapTexture);

    while (window.isOpen())
    {

        window.clear(Color::Black);

        time = clock.getElapsedTime().asSeconds();

        clock.restart();

        time = time / speed ;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Tab))
        {
            return true;
        }
        int flag = 0;
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            sleep(1);
            window.setMouseCursorVisible(true);
            sf::FloatRect visibleArea(0, 0, w, h);
            window.setView(sf::View(visibleArea));
            std::pair<float,int>pers = Menu(window,sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height,true);
            speed = pers.first;
            flag = 1;
        }

        if(flag){
            view.reset(FloatRect(0, 0, rslX, rslY));
            window.setView(view);

            window.setMouseCursorVisible(false);
            clock.restart();

            loadEntities(true);
            continue;
        }
        drawMap(window, player.x, player.y);
        player.update(time);
        clearEntities(time);

        computeEntities(player, window, time);
        window.setView(view);
        window.draw(player.sprite);


        if (!player.life)
        {
            isDead = true;
            window.clear(sf::Color::Black);
            txtDead.setPosition(view.getCenter());
            window.draw(txtDead);
            window.display();
            sleep(4);
            return false;
        }

        if (cntEnemiesAll == cntEnemiesElapsed)
        {
            txtWin.setPosition(view.getCenter().x-128, view.getCenter().y-64);
            window.draw(txtWin);
        }

        showInfo(window, player);

        window.display();

    }
    return false;

}

void GameRunning(RenderWindow &window)
{
    if (startGame(window))
        GameRunning(window);
}

int main(int argc, char **argv) {
    std::ifstream cin("src/save.txt");
    //cin >> isSave;
    isSave = false;
    if(isSave)
        std::cout<<"LOG: loading save"<<std::endl;
    std::cout << "LOG: app is starting" << std::endl;
    loadResources();
    int w = sf::VideoMode::getDesktopMode().width;
    int h = sf::VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode( w, h), "The Game", Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    music[0].play();
    music[0].setVolume(100);
    music[0].setLoop(true);
    font1 = font;
    std::pair<float,int>character = Menu(window, w, h);
    speed = character.first;
    level = character.second;
    if(!survival)
        creative = true;
    GameRunning(window);
    std::cout << "LOG: app is closed" << std::endl;

    return 0;
}
#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>
#include <unistd.h>
sf::Image menuImage, playImage, aboutImage, exitImage,backImage,speedImage,settingsImage,controlImage,authorsImage, continueImage, difficultyImage;
sf::Image img[5], soundImage,microphones[3],heartImage;
sf::Music music[3];
void loadnumbers(sf::Texture& text,sf::Sprite& spr,sf::Image& img1, int flag = 0){
    if(!flag)img1.createMaskFromColor(sf::Color:: Black);
    else img1.createMaskFromColor(sf::Color::White);
    text.loadFromImage(img1);
    spr.setTexture(text);
}
float subspeed = 1.8;
float w,h;
int chosen = 2;
int sound = 4;
int mus = 0;
int health1 = 0;
int minus = -100;
int level1 = 0;
int survival = 1,live = 0;
sf::Text create;
sf::Font font1;
void settingsMenu(sf::RenderWindow &window, sf::Sprite sprMenu,bool pause = false)
{
    create.setString(std::string("Creative"));
    create.setFont(font1);
    create.setScale(3 * w / 1920,3 * h / 1080);
    create.setPosition(0, 900 * h / 1080);
    bool settings = true;
    sf::Texture txtrMusic;
    soundImage.createMaskFromColor(sf::Color::White);
    txtrMusic.loadFromImage(soundImage);
    sf::Sprite sprMusic;
    sprMusic.setTexture(txtrMusic);

    sf::Texture txtrBack;
    backImage.createMaskFromColor(sf::Color::Black);
    txtrBack.loadFromImage(backImage);
    sf::Sprite sprBack;
    sprBack.setTexture(txtrBack);

    sf::Texture txtrSpeed;
    txtrSpeed.loadFromImage(speedImage);
    sf::Sprite sprSpeed;
    sprSpeed.setTexture(txtrSpeed);

    sf::Texture txtrnum[5],txtrsound[5];
    sf::Sprite sprnum[5],sprsound[5];

    for(int i = 0; i < 5; i++) {
        loadnumbers(txtrnum[i], sprnum[i], img[i]);
        loadnumbers(txtrsound[i],sprsound[i],img[i]);
    }
    sf::Texture txtrmus[3];
    sf::Sprite sprmus[3];
    for(int i = 0; i < 3; i++){
        loadnumbers(txtrmus[i],sprmus[i],microphones[i], 1);
    }

    sprMenu.setPosition(0, 0);
    sprMenu.setScale(w / 1920, h / 1080);
    sprBack.setPosition(10 * w / 1920, 10 * h / 1080);
    sprBack.setScale(0.5 * w / 1920, 0.5 * h / 1080);
    sprSpeed.setPosition(800 * w / 1920,20 * h / 1080);
    sprSpeed.setScale(0.4 * w / 1920,0.4 * h / 1080);
    sprMusic.setPosition(900 * w / 1920, 200 * h / 1080);
    sprMusic.setScale(0.15 * w / 1920, 0.15 * h / 1080);

    int size[5] = {13, 18, 15, 17, 17};
    int music1[5] = {0,20,50,80,100};
    for(int i = 0; i < 5; i++) {
        sprnum[i].setScale(1.5 * w / 1920, 1.5 * h / 1080);
        sprnum[i].setPosition( (1200 + 100 * i) * w / 1920, size[i] * h / 1080);
        sprsound[i].setScale(1.5 * w / 1920, 1.5 * h / 1080);
        sprsound[i].setPosition( (1200 + 100 * i) * w / 1920, (size[i] + 200) * h / 1080);
    }
    int coordinates[3] = {350,350,350};
    float sizes[3] = {0.5,0.5,0.5};
    for(int i = 0; i < 3; i++){
        sprmus[i].setScale(sizes[i] * w / 1920, sizes[i] * h / 1080);
        sprmus[i].setPosition((200 * i) * w / 1920, (coordinates[i] - 100) * h / 1080);
    }
    int health[5] = {-100, 0, 50, 80, 99};
    sf::Texture txtrhealth[5];
    sf::Sprite sprhealth[5];
    for(int i = 0; i < 5; i++){
        loadnumbers(txtrhealth[i],sprhealth[i],img[i]);
    }
    for(int i = 0; i < 5; i++) {
        sprhealth[i].setScale(1.5 * w / 1920, 1.5 * h / 1080);
        sprhealth[i].setPosition( (1200 + 100 * i) * w / 1920, (size[i] + 400)* h / 1080);
    }

    sf::Texture txtrlive[5];
    sf::Sprite sprlive[5];
    for(int i = 0; i < 5; i++){
        loadnumbers(txtrlive[i],sprlive[i],img[i]);
    }
    for(int i = 0; i < 5; i++) {
        sprlive[i].setScale(1.5 * w / 1920, 1.5 * h / 1080);
        sprlive[i].setPosition( (1200 + 100 * i) * w / 1920, (size[i] + 570)* h / 1080);
    }
    sf::Texture txtrdifficulty,txtrheart;
    sf::Sprite sprdifficulty,sprheart;
    loadnumbers(txtrdifficulty,sprdifficulty,difficultyImage,1);
    loadnumbers(txtrheart,sprheart,heartImage,1);
    sprdifficulty.setScale(0.2 * w / 1920, 0.2 * h / 1080);
    sprdifficulty.setPosition(900 * w / 1920, 400 * h / 1080);
    sprheart.setPosition(910 * w / 1920, 590 * h / 1080);
    sprheart.setScale(0.13 * w / 1920, 0.13 * h / 1080);

    float curX = 0, curY = 0;

    float speeds[5] = {3, 2.5, 1.8, 1, 0.5};

    while (settings) {
        window.clear(sf::Color::Black);
        sprBack.setColor(sf::Color::Red);
        if(survival)
            create.setFillColor(sf::Color::Red);
        else
            create.setFillColor(sf::Color::Green);
        for(int i = 0; i < 5; i++){
            sprnum[i].setColor(sf::Color::Red);
            sprsound[i].setColor(sf::Color::Red);
            sprhealth[i].setColor(sf::Color::Yellow);
            sprlive[i].setColor(sf::Color::Yellow);
        }
        for(int i = 0; i < 3; i++){
            sprmus[i].setColor(sf::Color::Red);
        }
        sprlive[live].setColor(sf::Color::Magenta);
        sprnum[chosen].setColor(sf::Color::Green);
        sprsound[sound].setColor(sf::Color::Green);
        sprmus[mus].setColor(sf::Color::Green);
        sprhealth[health1].setColor(sf::Color::Magenta);
        curX = (float) sf::Mouse::getPosition(window).x;
        curY = (float) sf::Mouse::getPosition(window).y;
        bool clicked = false;
        if (sprBack.getGlobalBounds().contains(curX, curY))
        {
            sprBack.setColor(sf::Color::Blue);
            clicked = true;
        }
        if(clicked && !sf::Mouse::isButtonPressed(sf::Mouse::Left))clicked = false;
        if(clicked)settings = false;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))clicked = true;
        int nom = -1;
        for(int i = 0; i < 5; i++){
            if(sprnum[i].getGlobalBounds().contains(curX,curY)){
                sprnum[i].setColor(sf::Color::Blue);
                nom = i;
                break;
            }
        }
        if(clicked && nom != -1){
            chosen = nom;
            subspeed = speeds[nom];
        }

        nom = -1;
        for(int i = 0; i < 5; i++){
            if(sprhealth[i].getGlobalBounds().contains(curX,curY)){
                sprhealth[i].setColor(sf::Color::Blue);
                nom = i;
                break;
            }
        }
        if(clicked && nom != -1 && !pause && survival){
            health1 = nom;
            level1 = nom;
        }

        nom = -1;
        for(int i = 0; i < 5; i++){
            if(sprlive[i].getGlobalBounds().contains(curX,curY)){
                sprlive[i].setColor(sf::Color::Blue);
                nom = i;
                break;
            }
        }
        if(clicked && nom != -1 && !pause && survival){
            live = nom;
            minus = health[nom];
        }

        nom = -1;
        for(int i = 0; i < 5; i++){
            if(sprsound[i].getGlobalBounds().contains(curX,curY)){
                sprsound[i].setColor(sf::Color::Blue);
                nom = i;
                break;
            }
        }
        if(clicked && nom != -1){
            sound = nom;
            music[mus].setVolume(music1[sound]);
        }
        nom = -1;
        for(int i = 0; i < 3; i++){
            if(sprmus[i].getGlobalBounds().contains(curX,curY)){
                sprmus[i].setColor(sf::Color::Blue);
                nom = i;
                break;
            }
        }
        if(clicked && nom != -1){
            music[mus].stop();
            mus = nom;
            music[mus].play();
            music[mus].setVolume(music1[sound]);
            music[mus].setLoop(true);
        }
        bool contains = create.getGlobalBounds().contains(curX,curY);
        if(contains) {
            create.setFillColor(sf::Color::Blue);
            if (clicked && !pause) {
                survival ^= 1;
                sleep(1);
            }
        }
        window.draw(sprMenu);
        window.draw(sprBack);
        window.draw(sprSpeed);
        window.draw(sprMusic);
        for(int i = 0; i < 5;i++) {
            window.draw(sprnum[i]);
            window.draw(sprsound[i]);
            window.draw(sprhealth[i]);
            window.draw(sprlive[i]);
        }
        for(int i = 0; i < 3;i++){
            window.draw(sprmus[i]);
        }
        window.draw(sprdifficulty);
        window.draw(create);
        window.draw(sprheart);
        window.display();
    }
}
void aboutMenu(sf::RenderWindow &window, sf::Sprite sprMenu){
    sf::Texture txtrControl,txtrAuthors;
    controlImage.createMaskFromColor(sf::Color::Black);
    authorsImage.createMaskFromColor(sf::Color::Black);
    txtrControl.loadFromImage(controlImage);
    txtrAuthors.loadFromImage(authorsImage);
    sf::Sprite sprControl,sprAuthors;
    sprControl.setTexture(txtrControl);
    sprAuthors.setTexture(txtrAuthors);

    sprMenu.setPosition(0, 0);
    sprMenu.setScale( w / 1920,  h / 1080);
    sf::Texture txtrBack;
    backImage.createMaskFromColor(sf::Color::Black);
    txtrBack.loadFromImage(backImage);
    sf::Sprite sprBack;
    sprBack.setTexture(txtrBack);
    sprBack.setPosition(1700 * w / 1920, 900 * h / 1080);
    sprBack.setScale(0.5 * w / 1920, 0.5 * h / 1080);
    sprAuthors.setPosition(0, 800 * h / 1080);
    sprAuthors.setScale(1 * w / 1920,1 * h / 1080);
    sprControl.setScale(1.4 * w / 1920, 1.4 * h / 1080);
    bool IsMenu = true;
    float curX = 0, curY = 0;
    while(IsMenu){
        window.clear();
        sprBack.setColor(sf::Color::Red);
        sprAuthors.setColor(sf::Color::Red);

        curX = (float) sf::Mouse::getPosition(window).x;
        curY = (float) sf::Mouse::getPosition(window).y;
        bool clicked = false;
        if (sprBack.getGlobalBounds().contains(curX, curY))
        {
            sprBack.setColor(sf::Color::Blue);
            clicked = true;
        }
        if(clicked && !sf::Mouse::isButtonPressed(sf::Mouse::Left))clicked = false;
        if(clicked)IsMenu = false;
        window.draw(sprMenu);
        window.draw(sprControl);
        window.draw(sprBack);
        window.draw(sprAuthors);

        window.display();
    }
}
std::pair<float,int> Menu(sf::RenderWindow &window, int w1, int h1, bool pause = false)
{
    w = w1;
    h = h1;

    sf::Texture txtrMenu, txtrPlay, txtrAbout, txtrExit,txtrSettings;
    playImage.createMaskFromColor(sf::Color::Black);
    continueImage.createMaskFromColor(sf::Color::Black);
    aboutImage.createMaskFromColor(sf::Color::Black);
    exitImage.createMaskFromColor(sf::Color::Black);
    settingsImage.createMaskFromColor(sf::Color::Black);

    txtrMenu.loadFromImage(menuImage);
    if(!pause)
        txtrPlay.loadFromImage(playImage);
    else {
        txtrPlay.loadFromImage(continueImage);
    }
    txtrAbout.loadFromImage(aboutImage);
    txtrExit.loadFromImage(exitImage);
    txtrSettings.loadFromImage(settingsImage);

    sf::Sprite sprMenu, sprPlay, sprAbout, sprExit,sprSettings;
    bool isMenu = true;
    int menuCode = 0;

    sprMenu.setTexture(txtrMenu);
    sprPlay.setTexture(txtrPlay);
    sprAbout.setTexture(txtrAbout);
    sprExit.setTexture(txtrExit);
    sprSettings.setTexture(txtrSettings);

    sprMenu.setPosition(0, 0);
    sprMenu.setScale( w / 1920,  h / 1080);

    if(!pause) {
        sprPlay.setPosition(650 * w / 1920, 30 * h / 1080);
        sprPlay.setScale(4 * w / 1920, 4 * h / 1080);
    }
    else {
        sprPlay.setPosition(765 * w / 1920, 30 * h / 1080);
        sprPlay.setScale(1 * w / 1920, 1 * h / 1080);
    }
    sprAbout.setPosition(765 * w / 1920, 130 * h / 1080);
    sprAbout.setScale(4 * w / 1920, 4 * h / 1080);
    sprExit.setPosition(770 * w / 1920, 230 * h / 1080);
    sprExit.setScale(4 * w / 1920, 4 * h / 1080);
    sprSettings.setPosition(1700 * w / 1920,0);
    sprSettings.setScale(0.1 * w / 1920,0.1 * h / 1080);
    float curX = 0, curY = 0;


    while (isMenu)
    {
        window.clear(sf::Color::Black);
        sprPlay.setColor(sf::Color::Red);
        sprAbout.setColor(sf::Color::Red);
        sprExit.setColor(sf::Color::Red);
        sprSettings.setColor(sf::Color::Red);
        curX = (float) sf::Mouse::getPosition(window).x;
        curY = (float) sf::Mouse::getPosition(window).y;
        if(pause && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            isMenu = false;
            sleep(1);
            break;
        }
        menuCode = 0;
        if (sprPlay.getGlobalBounds().contains(curX, curY))
        {
            sprPlay.setColor(sf::Color::Blue);
            menuCode = 1;
        }
        if (sprAbout.getGlobalBounds().contains(curX, curY))
        {
            sprAbout.setColor(sf::Color::Blue);
            menuCode = 2;
        }
        if (sprExit.getGlobalBounds().contains(curX, curY))
        {
            sprExit.setColor(sf::Color::Blue);
            menuCode = 3;
        }
        if(sprSettings.getGlobalBounds().contains(curX,curY)){
            sprSettings.setColor(sf::Color::Blue);
            menuCode = 4;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuCode == 1) {
                isMenu = false;
                break;
            }
            if (menuCode == 2)
            {
                aboutMenu(window, sprMenu);
            }
            if (menuCode == 3)
            {
                window.close();
                isMenu = false;

            }
            if (menuCode == 4)
            {
                settingsMenu(window,sprMenu,pause);

            }


        }


        window.draw(sprMenu);
        window.draw(sprPlay);
        window.draw(sprAbout);
        window.draw(sprExit);
        window.draw(sprSettings);
        window.display();
    }



    return {subspeed,level1};
}

#endif
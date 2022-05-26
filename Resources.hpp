#ifndef RESOURCES_HPP_INCLUDED
#define RESOURCES_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Menu.hpp"
#include <vector>
#include <sstream>
#include <list>

#include "Classes.hpp"

sf::Font font;

sf::Image mapImage;
sf::Image heroImage;

std::vector<sf::Image> imgEnemies;
sf::Image imgPlatform;

std::list<Entity*> lstEntities;
std::list<Entity*>::iterator itr1, itr2;

int cntEnemiesAll = 0, cntEnemiesElapsed = 0;
sf::Text txtHealth, txtEnemies, txtWin, txtDead;

int level = 0;

void showInfo(sf::RenderWindow &window, Player &player)
{
    txtHealth.setString("Health: "+std::to_string(player.health).erase(5));
    txtEnemies.setString("Enemies defeated: "+std::to_string(cntEnemiesElapsed)+"/"+std::to_string(cntEnemiesAll));

    txtEnemies.setPosition(view.getCenter().x+40, view.getCenter().y-185);
    txtHealth.setPosition(view.getCenter().x+150, view.getCenter().y+150);
        
    window.draw(txtEnemies);
    window.draw(txtHealth);
}

void loadResources()
{
    std::cout << "LOG: loading resources" << std::endl;
    if (!font.loadFromFile("src/uglyFont.otf"))
            std::cout << "ERR: problem while loading font" << std::endl;
        else
        {
            txtEnemies.setFont(font);
            txtEnemies.setFillColor(sf::Color::Black);
            
            txtHealth.setFont(font);
            txtHealth.setFillColor(sf::Color::Red);
            
            txtWin.setFont(font);
            txtWin.setFillColor(sf::Color::Red);
            txtWin.setCharacterSize(30);
            txtWin.setString("You Won!");
            
            txtDead.setFont(font);
            txtDead.setFillColor(sf::Color::Red);
            txtDead.setString("YOU DIED");

            
        }
    settingsImage.loadFromFile("src/sett.png");
    img[0].loadFromFile("src/1.png");
    img[1].loadFromFile("src/2.png");
    img[2].loadFromFile("src/3.png");
    img[3].loadFromFile("src/4.png");
    img[4].loadFromFile("src/5.png");
    backImage.loadFromFile("src/back.png");
    speedImage.loadFromFile("src/speed.png");
    heroImage.loadFromFile("src/copia.png");
    mapImage.loadFromFile("src/tilemap.png");
    menuImage.loadFromFile("src/menu.jpg");
    playImage.loadFromFile("src/startGame.png");
    aboutImage.loadFromFile("src/about.png");
    exitImage.loadFromFile("src/exit.png");
    controlImage.loadFromFile("src/control.png");
    authorsImage.loadFromFile("src/authors.png");
    continueImage.loadFromFile("src/continue.png");
    music[0].openFromFile("src/music1.wav");
    music[1].openFromFile("src/music2.wav");
    music[2].openFromFile("src/music3.wav");
    soundImage.loadFromFile("src/music.jpg");
    microphones[0].loadFromFile("src/micro1.png");
    microphones[1].loadFromFile("src/micro1.png");
    microphones[2].loadFromFile("src/micro1.png");
    difficultyImage.loadFromFile("src/difficulty.jpg");
    heartImage.loadFromFile("src/heart.jpg");

    imgEnemies.resize(2);
    imgEnemies[0].loadFromFile("src/enemy_0.png");
    imgEnemies[1].loadFromFile("src/enemy_1.png");
    imgEnemies[1].createMaskFromColor(sf::Color::White);
    imgPlatform.loadFromFile("src/platform.png");
  
    
    loadMap();
}

void destroyEntities()
{
        std::cout<<std::endl;

    if (lstEntities.begin() != lstEntities.end())
    for ( itr1 = lstEntities.begin(); itr1 != lstEntities.end(); )
    {
        delete (*itr1);
        itr1 = lstEntities.erase(itr1);
    }
    std::cout<<std::endl;
}

void loadEntities(bool pauseOrsave = false)
{
    if(pauseOrsave)return;
    destroyEntities();


    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 20*32, 40*32, 193, 261, 10*32, 21*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 30*32, 40*32, 193, 261, 20*32, 39*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 70*32, 40*32, 193, 261, 50*32, 100*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 80*32, 40*32, 193, 261, 60*32, 100*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 49*32, 23*32, 193, 261, 44*32, 53*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 47*32, 23*32, 193, 261, 44*32, 53*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 46*32, 19*32, 193, 261, 44*32, 53*32));
    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 47*32, 19*32, 193, 261, 44*32, 53*32));

 if(level>=1)
 {
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 35 * 32, 40 * 32, 193, 261, 30 * 32, 38 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 25 * 32, 40 * 32, 193, 261, 25 * 32, 35 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 35 * 32, 40 * 32, 193, 261, 20 * 32, 37 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 49*32, 36*32, 193, 261, 44*32, 53*32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 45*32, 36*32, 193, 261, 44*32, 53*32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 49*32, 31*32, 193, 261, 44*32, 53*32));
 }

 if(level>=2)
 {
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 50 * 32, 31 * 32, 193, 261, 44 * 32, 53 * 32));

     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 71 * 32, 40 * 32, 193, 261, 70 * 32, 100 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 87 * 32, 40 * 32, 193, 261, 80 * 32, 100 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 100 * 32, 40 * 32, 193, 261, 90 * 32, 100 * 32));


     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 105 * 32, 44 * 32, 193, 261, 102 * 32, 108 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 106 * 32, 48 * 32, 193, 261, 104 * 32, 112 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 135 * 32, 40 * 32, 193, 261, 133 * 32, 138 * 32));

     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 42 * 32, 5 * 32, 193, 261, 40 * 32, 47 * 32));
//    lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_0", 36*32, 54*32, 193, 261, 35*32, 37*32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_1", 46 * 32, 52 * 32, 193, 261, 35 * 32, 50 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_1", 50 * 32, 52 * 32, 193, 261, 35 * 32, 60 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_1", 55 * 32, 52 * 32, 193, 261, 35 * 32, 70 * 32));
 }
 if(level>=3)
 {
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_1", 84*32, 40*32, 193, 261, 60*32, 100*32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_1", 75 * 32, 40 * 32, 193, 261, 70 * 32, 100 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[0], "Enemy_1", 89 * 32, 40 * 32, 193, 261, 80 * 32, 100 * 32));
 }
 if(level>=4)
 {
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_1", 48 * 32, 52 * 32, 193, 261, 32 * 32, 72 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_1", 53 * 32, 52 * 32, 193, 261, 33 * 32, 72 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_1", 51 * 32, 52 * 32, 193, 261, 34 * 32, 73 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_0", 52 * 32, 52 * 32, 193, 261, 35 * 32, 70 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_0", 59 * 32, 52 * 32, 193, 261, 35 * 32, 70 * 32));
     lstEntities.push_back(new Enemy(imgEnemies[1], "Enemy_0", 55 * 32, 52 * 32, 193, 261, 35 * 32, 70 * 32));

 }
    cntEnemiesAll = lstEntities.size();
    cntEnemiesElapsed = 0;

    lstEntities.push_back(new Platform(imgPlatform, "Platform_0", 15*32, 39*32, 32*2, 10, 0, -250, 0.5));
    lstEntities.push_back(new Platform(imgPlatform, "Platform_0", 41*32, 44*32+16, 32*2, 10, 0, -150, 5));
    lstEntities.push_back(new Platform(imgPlatform, "Platform_0", 100*32, 42*32+16, 32*2, 10, 0, -30, 2));
    lstEntities.push_back(new Platform(imgPlatform, "Platform_0", 105*32, 39*32+16, 32*2, 10, 100, 0, 7));
    lstEntities.push_back(new Platform(imgPlatform, "Platform_0", 134*32, 47*32+16, 32*2, 10, -10, -50, 6));

}

void clearEntities(float time)
{
    
    for ( itr1 = lstEntities.begin(); itr1 != lstEntities.end(); )
    {
        
        (*itr1)->update(time);
        if ((*itr1)->life == false)
        {
            delete (*itr1);
            itr1 = lstEntities.erase(itr1);
        }
        else
            itr1++;
            
            
    }
}

float lastTime = 0;


void computeEntities(Player &player, sf::RenderWindow &window, float time)
{
    std::string tmp = {0};

    for (itr1 = lstEntities.begin(); itr1 != lstEntities.end(); itr1++)
            {
                tmp = (*itr1)->name;

                window.draw( (*itr1)->sprite );

                if ( (*itr1)->getRect().intersects( player.getRect() ) )
                {
                    std::cout << "LOG: collision with: " << tmp << " at " << player.x/32 <<", "<<player.y/32 <<std::endl;
                    if ( (*itr1)->name == "Platform_0" )
                    {   
                        if ( player.dy > 0 || player.onGround == false )
                            if ( player.y + player.h < (*itr1)->y + (*itr1)->h )
                            {
                                player.y = (*itr1)->y - player.h ;//- 2.0;
                                player.x += (*itr1)->dx * time;
                                player.dy = 0;
                                player.onGround = true;
                            }
                    }
                    
                    if ((*itr1)->name == "Enemy_0" || (*itr1)->name == "Enemy_1")
                    {
                        if ((player.dy > 0) && (player.onGround == false))
                        {
                            (*itr1)->dx = 0;
                            player.dy = -550;
                            (*itr1)->health = 0;
                            cntEnemiesElapsed++;
                        }
                        else
                        {
                            if (std::abs(time - lastTime) > 0.0001f)
                            {
                                lastTime = time;
                                player.health -= 1;
                                player.isInjured = true;
                            }

                            
                        }

                    }
                }
                
                for (itr2 = lstEntities.begin(); itr2 != lstEntities.end(); itr2++)
                {
                    if ((*itr1)->getRect() != (*itr2)->getRect())
                        if ( ((*itr1)->name == "Enemy_0" ||(*itr1)->name == "Enemy_1")  && (((*itr2)->name == "Enemy_0") || (*itr2)->name == "Enemy_1") )
                            if ((*itr1)->getRect().intersects((*itr2)->getRect()))
                            {
                                (*itr1)->dx *= -1;
                                (*itr1)->sprite.scale(-1, 1);
                                (*itr2)->dx *= -1;
                                (*itr2)->sprite.scale(-1, 1);
                            }
                            
                }
            }
}





#endif
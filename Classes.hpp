#ifndef CLASSES_HPP_INCLUDED
#define CLASSES_HPP_INCLUDED


#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>

#include "map.hpp"
#include "View.hpp"

const float GRAVITYDY = -550;
const float SPEEDX = 250;


typedef enum
{ left, right, up, down, jump, stay, right_Top} tState;

using namespace sf;
bool creative = false;
class Entity
{
public:

    float dx, dy, x, y, speed, moveTimer;
    float w, h, health;
    float shift;

    bool life, isMove, onGround;
    Texture texture;
    Sprite sprite;
    String name;
    Entity(Image &image, String Name, float X, float Y, float W, float H)
    {
        x = X;
        y = Y;
        w = W;
        h = H;
        name = Name;
        moveTimer = 0;
        speed = 0;
        health = 100;
        dx = 0;
        dy = 0;
        life = true;
        onGround = false;
        isMove = false;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
        shift = 0;
    }

    FloatRect getRect()
    {
        return FloatRect(x+shift, y, w, h);
    }

    virtual void checkCollisionWithMap(float DX, float DY) = 0;
    virtual void update(float time) = 0;


};

class Player :public Entity
{
public:
    tState state;
    int playerScore,stairs;
    bool isShoot;
    float pTxtrCntrs[4] = {0};
    bool isLastMoveLeft;
    float tmInjured;
    bool isInjured,onstairs;

    Player(Image &image, String Name, float X, float Y, float W, float H) :Entity(image, Name, X, Y, W, H )
    {

        if (name == "Player")
        {
            playerScore = isShoot = 0;
            state = stay;
            sprite.setTextureRect(IntRect(0, 0, w, h));
            sprite.setScale(0.25f, 0.25f);

            isLastMoveLeft = true;
            onGround = false;

            health = 100;
            life = true;
            shift = 16;
            w = (250-2*shift*4)/4;
            h = 250/4;
            tmInjured = 0;
            isInjured = false;
            onstairs=false;
            stairs=0;
            setView(x, y);
        }

    }

    void control()
    {
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            state = left; speed = SPEEDX;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            state = right; speed = SPEEDX;
        }
//|| onstairs
        if ((Keyboard::isKeyPressed(Keyboard::Up)) && (creative || onGround ))
        {
            state = jump; dy = GRAVITYDY; onGround = false; onstairs=false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            state = down;
        }

        if (onGround && (Keyboard::isKeyPressed(Keyboard::Right)) && (Keyboard::isKeyPressed(Keyboard::Up)))
        {
            state = right_Top;
        }


    }

    void checkCollisionWithMap(float DX, float DY)
    {
        bool too_high=false;
        for (int i = (y/32); i < (y+h)/32; i++) {
            if(i<7)
            {
                too_high=true;
            }
            for (int j = ((x + shift) / 32); j < (x + shift + w) / 32; j++) {
                if (Tile_Map[i][j] == 'k') {
                    health -= 0.5;
                }
                if (Tile_Map[i][j] == 'P') {
                    dy = -i * 5 - 800;
                }

                if (isAbsSolid(i, j)) {
                    if (DY > 0) {
                        y = i * 32 - h;
                        onGround = true;
                        if(Tile_Map[i-1][j]!='v')
                        {
                            if (dy > 800) {
                                health -= (dy - 800) / 100;
                            }
                            if (dy > 1500) {
                                health -= (dy - 1500) / 8;
                            }
                        }
                        dy = 0;
                        state = stay;
                    } else if (DY < 0) {
                        y = (i + 1) * 32;
                        dy = 0;
                        state = jump;
                    } else if (DX > 0) {
                        x = (j * 32) - w - shift;
                    } else if (DX < 0)
                    {
                        x = (j + 1) * 32 - shift;
                    }
                } else {
                    onGround = false;
                }
                if(Tile_Map[i][j]=='l')
                {
                   // onGround=true;
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                        dy = 300;
                    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                        dy = -300;
                    } else
                        dy = 0;
                }

            }
        }

        if(too_high)
        {
            dy=150;
        }

    }

    void setCurTexture(float time)
    {

        if (state == left)
        {
            pTxtrCntrs[1] += 2*time;
            if (pTxtrCntrs[1] > 10)
                pTxtrCntrs[1] -= 10;
            sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[1])*250, 0, 250, 250 ) );
            pTxtrCntrs[0] = 0;
            pTxtrCntrs[2] = 0;
            pTxtrCntrs[3] = 0;
            isLastMoveLeft = true;
        }
        else if (state == right)
        {
            pTxtrCntrs[1] += 2*time;
            if (pTxtrCntrs[1] > 10)
                pTxtrCntrs[1] -= 10;
            sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[1])*250, 250, 250, 250 ) );
            pTxtrCntrs[0] = 0;
            pTxtrCntrs[2] = 0;
            pTxtrCntrs[3] = 0;
            isLastMoveLeft = false;
        }
        else if (state == jump)
        {
            pTxtrCntrs[2] += 2*time;
            if (pTxtrCntrs[2] > 10)
                pTxtrCntrs[2] -= 10;
            if (isLastMoveLeft)
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[2])*250, 0, 250, 250 ) );
            else
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[2]), 250, 250, 250 ) );
            pTxtrCntrs[0] = 0;
            pTxtrCntrs[1] = 0;
            pTxtrCntrs[3] = 0;
        }
        else if (state == down)
        {
            pTxtrCntrs[3] += 2*time;
            if (pTxtrCntrs[3] > 10)
                pTxtrCntrs[3] -= 10;
            if (isLastMoveLeft)
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[3])*250, 0, 250, 250 ) );
            else
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[3]), 250, 250, 250 ) );
            pTxtrCntrs[0] = 0;
            pTxtrCntrs[1] = 0;
            pTxtrCntrs[2] = 0;
        }
        else
        {
            pTxtrCntrs[0] += 2*time;
            if (pTxtrCntrs[0] > 10)
                pTxtrCntrs[0] -= 10;
            if (isLastMoveLeft)
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[0])*250, 0, 250, 250 ) );
            else
                sprite.setTextureRect( IntRect( ((int)pTxtrCntrs[0])*250, 250, 250, 250 ) );
            pTxtrCntrs[1] = 0;
            pTxtrCntrs[2] = 0;
            pTxtrCntrs[3] = 0;
        }

        if (isInjured)
        {
            sprite.setColor(sf::Color::Red);
            tmInjured += time;
            if (tmInjured > 0.2)
            {
                tmInjured = 0;
                isInjured = false;
                sprite.setColor(sf::Color::White);

            }
        }


    }

    void update(float time)
    {
        control();
        setCurTexture(time);

        switch (state)
        {
            case right: dx = speed; break;
            case left: dx = -speed; break;
            case up: break;
            case down: dx = 0; break;
            case stay: break;
            case right_Top: dx = speed; break;
            case jump: break;
        }
        x += dx*time;
        checkCollisionWithMap(dx, 0);
        y += dy*time;
        checkCollisionWithMap(0, dy);

        sprite.setPosition(x, y);
        if (health <= 0)
        {
            life = false;
        }
        if (!isMove)
        {
            speed = 0;
        }
        if (life)
        {
            setView(x, y);
        }

        dy = dy + 1500*time;
        if (onGround)
        {
            state = stay;
            dx = 0;
        }


    }
};

class Enemy :public Entity
{
public:
    float b1;
    float b2;
    Enemy(Image &Image, String Name, float X, float Y, float W, float H, float B1, float B2) :Entity(Image, Name, X, Y, W, H)
    {
        if (Name == "Enemy_0" || Name == "Enemy_1")
        {

            sprite.setTextureRect(IntRect(0, 0, w, h));

            sprite.setScale( -0.25f, 0.25f);
            w *= 0.25f;
            h *= 0.25f;


            dx = 250;
            shift = 0;
            b1 = B1;
            b2 = B2;


        }

    }

    void checkCollisionWithMap(float DX, float DY)
    {
        if (name == "Enemy_0" || name == "Enemy_1")
            for (int i = (y/32); i < (y+h)/32; i++)
                for (int j = ((x+shift)/32); j < (x+shift+w)/32; j++)
                {
                    if (isAbsSolid(i, j))
                    {
                        if (DY > 0)
                        {
                            y = i*32 - h;
                            dy = 0;
                        }
                        else if (DY < 0)
                        {
                            y = (i+1)*32;
                            dy = 0;
                        }
                        else if (DX > 0)
                        {
                            x = (j*32) - w - shift;
                            dx *= -1;
                            sprite.scale(-1, 1);
                        }
                        else if (DX < 0)
                        {
                            x = (j+1)*32 - shift;
                            dx *= -1;
                            sprite.scale(-1, 1);
                        }
                    }
                    else
                        onGround = false;
                }
    }

    void update(float time)
    {
        if (name == "Enemy_0" || name == "Enemy_1")
        {
            x += dx*time;
            checkCollisionWithMap(dx, 0);
            y += dy*time;
            checkCollisionWithMap(0, dy);
            dy = dy + 1500*time;
            sprite.setPosition(x+w/2, y+h/2);

            if (x > b2)
            {
                dx *= -1;
                sprite.scale(-1, 1);

            }
            if (x < b1)
            {
                dx *= -1;
                sprite.scale(-1, 1);
            }
            if(name=="Enemy_1" && dx!=0)
            {
                int random=rand()%200;
                if(random==1 && abs(dx) < 500)
                {
                    dx*=2;
                }
                if(random==3)
                {
                    if(dx>0)
                    {
                        dx=100;
                    }
                    else
                    {
                        dx=-100;
                    }
                }

            }
            if (health <= 0)
                life = false;
        }


    }

};

class Platform: public Entity
{
public:
    float moveTimer;
    float period;
    Platform(Image Image, String Name, float X, float Y, float W, float H, float DX, float DY, float Period) :Entity(Image, Name, X, Y, W, H)
    {
        sprite.setOrigin(w/2, h/2);

        sprite.setTextureRect(IntRect(0, 0, 32, 32));
        sprite.setScale(w/32, h/32);

        dx = DX;
        dy = DY;
        period = Period;
        moveTimer = 0;
    }
    void update(float time)
    {
        x += dx*time;
        y += dy*time;
        moveTimer += time;
        if (moveTimer > period)
        {
            dx *= -1;
            dy *= -1;
            moveTimer = 0;
        }
        sprite.setPosition(x+w, y+h/2);
        //sprite.setPosition(x, y);
    }

    void checkCollisionWithMap ( float DX, float DY )
    {

    }

};

#endif // CLASSES_HPP_INCLUDED
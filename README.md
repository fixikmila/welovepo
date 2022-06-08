# Platform game

## IDE:

To open the application, you need to download the project.zip file from github, unzip it to any folder.


Open clion (perhaps another C++ ide is also suitable, but not tested), open the unpacked project "project" using the CMakeLists.txt file.


Then run the main.cpp file and the game will be launched.

## command line:

### install

git clone https://github.com/fixikmila/welovepo.git # install

cd ./welovepo

sudo chmod +x ./install.sh

sudo ./install.sh

### run

/opt/welovepo/project


# changelog: 

## 05.05.2022 v.1.0
map (in the future we are going to make it bigger)

gravity (with free fall acceleration)

several types of objects (platforms, monsters), that move independently of the hero

collision mechanics depending on the position of objects (for example, if the hero falls on top of the monster, then the monster is dead, otherwise the hero is injured)
and with field cells (you can’t walk through the walls)

the menu from which the game is launched

hero control (jumping and walking)

## 26.05.2022 v.2.2

the game adjusts to the selected screen resolution

game menu was realized and has:

settings
[before the game, you can choose the difficulty level (the number of monsters), the speed of the game (the movement of all objects), the music (there are several options) and its volume, the game mode (normal survival and creative (a new mode in which the hero cannot die and can fly) ) and number of lives if survival is chosen]
and game control(in "about")

the hero has an animation depending on the current movement (for example, when the hero falls down, his cloak flutters in the wind, etc.)

during the game (at any time) you can call the menu that will pause the game

in the pause menu it will be possible to change most of the characteristics (but not those that contradict the logic, for example, the difficulty of the game cannot be changed in the process)

inside the game, the map was greatly enlarged (a dungeon appeared, a cave and both glades increased)

there are many new types of blocks (cannons that bounce the player up, cacti that hit player during contact
pillows that protect against fall damage (at this stage, we also added fall damage that does increase not linearly depending on height), stairs that you can move on, etc.)

the game has a new type of monsters (red which randomly changes its speed)

platforms can now move along 2 coordinates at the same time

## 09.06.2022 v.3.0

implemented saving settings

# Authors:           Contribution:

Milana Kananovich    50%

Artemy Oueiski       50%

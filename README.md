# welovepo
Platform game

To open the application, you need to download the project.zip file, unzip it to any folder.
Open clion (perhaps another C++ compiler application is also suitable, but not tested), open the unpacked project "project" using the CMakeLists.txt file.
Then run the main.cpp file and the game will be launched.

git tag v1.0
changelog:
map (in the future we are going to make it bigger)
gravity (with free fall acceleration)
several types of objects (platforms, monsters) that move independently of the hero
collision mechanics depending on the position of objects (for example, if the hero falls on top of the monster, then the monster is dead, otherwise the hero is injured)
and with field cells (you can’t walk through the walls)
the menu from which the game is launched
hero control (jumping and walking)

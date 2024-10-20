#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Task
{
public:
	//Public funtions
	void initNewTask();

	//MAKE TASKS 10 HIGH AND 700 TALL


	//Constructor
	Task();

	//Destructor
	~Task();

private:
	//Private parameters
	sf::Text taskText; //this will be equal to the taskName while constructing new object
	std::string taskName;
	bool isCompleted;

	//The task shape - tasks will be added like squares in the Snake game
	std::list<sf::RectangleShape> taskBox;
};


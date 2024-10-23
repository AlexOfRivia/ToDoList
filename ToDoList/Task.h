#pragma once
#include <iostream>
#include <list>
#include "Button.h"
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
	void initNewTask(sf::Time dt);
	void renderTasks(sf::RenderTarget& target);

	//Constructor
	Task();

	//Destructor
	~Task();

private:
	//Private functions
	void deleteTask();
	void initVariables();

	//Private parameters
	sf::Text taskText; //this will be equal to the taskName while constructing new object
	std::string taskName;
	bool isCompleted;
	float y = 50;
	sf::Time elapsedTime;

	//The task shape - tasks will be added like squares in the Snake game
	std::list<sf::RectangleShape>::iterator firstTask;
	std::list<sf::RectangleShape> taskBox;
};


#pragma once
#include <iostream>
#include <list>
#include "Button.h"
#include "Textbox.h"
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
	void initNewTask(sf::Time dt, const sf::Vector2f mousePos, sf::RenderWindow& appWindow, sf::Event ev);
	void renderTasks(sf::RenderTarget& target);
	void updateButtons(const sf::Vector2f mousePos, sf::Event ev);
	void updateTextboxes(sf::Event ev);
	void clearTaskList();

	//Constructor
	Task();

	//Destructor
	~Task();

private:
	//Private functions
	void initVariables();
	void deleteTask();

	//Private parameters
	sf::Font taskFont;
	bool isCompleted;
	float y = 50;
	int maxArrAmount = 11; //The maximum amount of Buttons
	int amountOfArrElements; //Current amount of buttons & text in array
	sf::Time elapsedTime;
	
	//The task shape - tasks will be added like squares in the Snake game
	std::list<sf::RectangleShape>::iterator firstTask;
	std::list<sf::RectangleShape> taskBox;

	Button** buttonArray = new Button* [maxArrAmount];
	Textbox** textArray = new Textbox* [maxArrAmount];
	
};


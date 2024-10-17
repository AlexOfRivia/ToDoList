#pragma once
#include <iostream>
#include "Task.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class App
{
public:
	//public functions
	void updateEvents();
	void Update();
	void Render();

	const bool isRunning() const;

	//Constructor & Destructor
	App();
	~App();

private:
	//Private perameters
	sf::RenderWindow* window;
	sf::RectangleShape background;
	sf::Event event;


	//Private functions
	void initNewTask();
	void initWindow();
	void initVariables();

};


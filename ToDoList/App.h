#pragma once
#include <iostream>
#include "Task.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Button.h"


class App
{
public:
	//public functions
	void updateEvents();
	void Update();
	void Render();

	//Checking wether the app is running
	const bool isRunning() const;

	//Constructor & Destructor
	App();
	~App();

private:
	//Private perameters
	sf::RenderWindow* window;
	sf::RectangleShape background;
	Task* task;
	sf::Time deltaTime;
	Button* addButton;
	sf::Event event;
	sf::Vector2f mousePosView;


	//Private functions
	void initWindow();
	void initVariables();

};


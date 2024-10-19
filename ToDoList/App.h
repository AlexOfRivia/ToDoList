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
	/*Button addButton(720.f, 10.f, 35.f, 35.f);*/
	Button* addButton;
	sf::Event event;
	const sf::Mouse mouse;
	sf::Vector2i mousePos;


	//Private functions
	void initWindow();
	void initVariables();

};


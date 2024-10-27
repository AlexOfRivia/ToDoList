#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Textbox
{
public:

	//Constructo & destructor
	Textbox(float width, float height, float posX, float posY, int textSize, sf::Color textBoxColor, sf::Font textFont);
	~Textbox();
private:
	sf::RectangleShape textboxShape;
	std::string userInput;
	sf::Text textboxText;
};


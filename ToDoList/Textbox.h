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
	//Public functions
	void renderTextbox(sf::RenderTarget* target);
	void updateTextbox(const sf::Vector2f mousePos);


	//Constructo & destructor
	Textbox(float width, float height, float posX, float posY, int textSize, sf::Color textBoxColor, sf::Font textFont);
	~Textbox();
private:
	//Private parameters
	sf::RectangleShape textboxShape;
	std::string userInput;
	sf::Text textboxText;
	sf::Font textboxFont;
};


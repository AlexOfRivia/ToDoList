#pragma once
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

/*This Textbox class is mostly universal,
so it can be used in other SFML project*/

/*To register keyboad input, remember to use the typedOn method in the eventPool loop

for example:

Textbox* textbotObj( [your parameters here] )

while(window.isOpen()
{
	while(window->pollEvent(event)
	{
		if(event.type == sf::Event::TextEntered)
		{
			textboxObj.typedOn(event);
		}
	}
}
*/

class Textbox
{
public:
	//Public functions
	void renderTextbox(sf::RenderTarget* target);
	void updateTextbox(const sf::Vector2f mousePos,  sf::Event ev);
	void isTextBoxSelected(bool ToF);
	void typedOn(sf::Event input);


	//Constructor & destructor
	Textbox(float width, float height, float posX, float posY, int textSize, sf::Color textBoxColor, sf::Color textboxHoverColor, sf::Font &textFont, int limit, bool isThereLimit, bool sel);
	~Textbox();
private:
	//Private parameters
	sf::RectangleShape textboxShape;
	std::ostringstream userInput;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Text textboxText;
	sf::Font textboxFont;
	bool isSelected;
	bool hasLimit;
	int charLimit;

	//Private functions
	void inputLogic(int charTyped);
	void deleteLastChar();
};


#include "Textbox.h"



//Rendering the textbox
void Textbox::renderTextbox(sf::RenderTarget* target)
{
	target->draw(this->textboxShape);
}

//Updating the textbox
void Textbox::updateTextbox(const sf::Vector2f mousePos)
{
	//Updatin the mouse hover
}

//Constructor
Textbox::Textbox(float width, float height, float posX, float posY, int textSize, sf::Color textBoxColor, sf::Font textFont)
{
	//Setting the desired textbox parameters
	this->textboxShape.setPosition(sf::Vector2f(posX, posY));
	this->textboxShape.setFillColor(textBoxColor);
	this->textboxShape.setSize(sf::Vector2f(width, height));
	this->textboxText.setCharacterSize(textSize);
	this->textboxFont = textFont;
}

//Destructor
Textbox::~Textbox()
{

}

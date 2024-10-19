#include "Button.h"

//Rendering the button onto the screen
void Button::renderButton(sf::RenderTarget* target)
{
	target->draw(this->buttonShape);
}

//Updating the button
void Button::updateButton(const sf::Vector2f mousePos)
{
	if (this->buttonShape.getGlobalBounds().contains(mousePos))
	{

	}
}

//Constructor
Button::Button(float x, float y, float width, float height, sf::Color color)
{
	//Setting the desired button parameters
	this->buttonShape.setPosition(sf::Vector2f(x,y));
	this->buttonShape.setFillColor(sf::Color::White);
	this->buttonShape.setSize(sf::Vector2f(width,height));

	this->clickColor = color;
}

//Destructor
Button::~Button()
{

}

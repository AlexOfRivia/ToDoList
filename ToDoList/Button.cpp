#include "Button.h"

//Rendering the button onto the screen
void Button::renderButton(sf::RenderTarget* target)
{
	target->draw(this->buttonShape);
}

//Updating the button
void Button::updateButton(const sf::Vector2f mousePos)
{
	//Button being idle
	this->buttonState = BTN_IDLE;

	//Hovering over the button
	if (this->buttonShape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		//Pressing the button
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_PRESSED;
			std::cout << "Button pressed\n";
		}
	}

	switch (this->buttonState)
	{

	case BTN_IDLE:
	{
		this->buttonShape.setFillColor(idleColor);
		break;
	}
	case BTN_HOVER:
	{
		this->buttonShape.setFillColor(sf::Color(hoverColor));
		break;
	}
	case BTN_PRESSED:
	{
		this->buttonShape.setFillColor(clickColor);
		break;
	}

	default:
	{

		this->buttonShape.setFillColor(sf::Color::Red);

		break;
	}
	}
}

const bool Button::isPressed() const
{
	if(this->buttonState == BTN_PRESSED)
	{
		return true;
	}
	return false;
}

//Constructor
Button::Button(float x, float y, float width, float height, sf::Color pressColor,sf::Color hovColor,sf::Color idColor)
{
	this->buttonState = BTN_IDLE;

	//Setting the desired button parameters
	this->buttonShape.setPosition(sf::Vector2f(x,y));
	this->buttonShape.setFillColor(sf::Color::White);
	this->buttonShape.setSize(sf::Vector2f(width,height));

	this->clickColor = pressColor;
	this->hoverColor = hovColor;
	this->idleColor = idColor;
}

//Destructor
Button::~Button()
{

}

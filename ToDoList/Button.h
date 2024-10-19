#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

/*This Button class is mostly universal,
so it can be used in other SFML project*/

//Button state enum
enum button_states {BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button
{
public:
	//Public functions
	void renderButton(sf::RenderTarget* target);
	void updateButton(const sf::Vector2f mousePos);

	//Accessors
	const bool isPressed() const;



	//Constructo & destructor
	Button(float x, float y, float width, float height, sf::Color pressColor, sf::Color hovColor, sf::Color idColor);
	~Button();
private:
	//Private functions

	//Private parameters
	sf::RectangleShape buttonShape;
	sf::Color clickColor;
	sf::Color idleColor;
	sf::Color hoverColor;
	short unsigned buttonState;
	bool pressed;
	bool hover;
};


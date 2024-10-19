#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
class Button
{
public:
	//Public functions
	void renderButton(sf::RenderTarget* target);
	void updateButton(const sf::Vector2f mousePos);

	//Constructo & destructor
	Button(float x, float y, float width, float height, sf::Color color);
	~Button();
private:
	//Private functions

	//Private parameters
	sf::RectangleShape buttonShape;
	sf::Color clickColor;


};


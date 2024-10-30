#include "Textbox.h"

//Rendering the textbox
void Textbox::renderTextbox(sf::RenderTarget* target)
{
	target->draw(this->textboxShape);
	target->draw(this->textboxText);
}

//Updating the textbox
void Textbox::updateTextbox(const sf::Vector2f mousePos, sf::Event ev)
{
	//Updating the mouse hover etc
	
	if (this->textboxShape.getGlobalBounds().contains(mousePos))
	{
		this->textboxShape.setFillColor(this->hoverColor);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->isTextBoxSelected(true);
		}
	}
	else {
		this->textboxShape.setFillColor(this->idleColor);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		if (this->userInput.str().length()==0)
		{
			this->textboxText.setString("");
		}
		this->isTextBoxSelected(false);
	}

}

void Textbox::isTextBoxSelected(bool ToF)
{
	this->isSelected = ToF;
	if (!ToF)
	{
		std::string t = this->userInput.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		this->textboxText.setString(newT);
	}
}

void Textbox::typedOn(sf::Event input)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (hasLimit)
			{
				if (this->userInput.str().length() <= this->charLimit)
				{
					this->inputLogic(charTyped);
				}
				else if (this->userInput.str().length() > this->charLimit && charTyped == DELETE_KEY)
				{
					this->deleteLastChar();
				}
			}
			else {
				this->inputLogic(charTyped);
			}
		}
	}
}

//Logic behind textboxes
void Textbox::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		this->userInput << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (this->userInput.str().length() > 0)
		{
			this->deleteLastChar();
		}
	}

	this->textboxText.setString(this->userInput.str() + "_");
}

//deleting the last character
void Textbox::deleteLastChar()
{
	std::string t = this->userInput.str();
	std::string newT = "";
	for (int i = 0; i<t.length()-1; i++)
	{
		newT += t[i];
	}
	this->userInput.str(""); 
	this->userInput << newT;

	this->textboxText.setString(this->userInput.str());
}

//Constructor
Textbox::Textbox(float width, float height, float posX, float posY, int textSize, sf::Color textBoxColor,sf::Color textboxHoverColor, sf::Font &textFont, int limit, bool isThereLimit, bool sel)
{
	//Setting the desired textbox parameters
	this->textboxShape.setPosition(sf::Vector2f(posX, posY));
	this->textboxShape.setFillColor(textBoxColor);
	this->textboxShape.setSize(sf::Vector2f(width, height));

	this->textboxText.setPosition(sf::Vector2f(posX, posY));
	this->textboxText.setCharacterSize(textSize);
	this->textboxText.setFont(textFont);

	this->idleColor = textBoxColor;
	this->hoverColor = textboxHoverColor;
	this->charLimit = limit;
	this->hasLimit = isThereLimit;
	this->isSelected = sel;
	if (sel)
	{
		this->textboxText.setString("_");
	}
	else {
		this->textboxText.setString("");

	}

}

//Destructor
Textbox::~Textbox()
{

}


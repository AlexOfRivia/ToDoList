#include "Task.h"

//Initializing a new task
void Task::initNewTask(sf::Time dt,const sf::Vector2f mousePos, sf::RenderWindow& appWindow)
{
	elapsedTime += dt;
	if (elapsedTime.asSeconds() > 0.25 && taskBox.size() < 12)
	{
		sf::RectangleShape newPiece;
		newPiece.setSize(sf::Vector2f(700, 50));
		newPiece.setFillColor(sf::Color::Black);
		newPiece.setPosition(50, y);

		//Adding a new task to the list
		this->firstTask = this->taskBox.insert(this->firstTask++, newPiece);

		//Adding a new button to the array
		this->buttonArray[amountOfArrElements] = new Button(725, (y + 10), 20.f, 20.f, sf::Color(133, 29, 7), sf::Color(161, 34, 8), sf::Color(181, 38, 9));
		this->textArray[amountOfArrElements].setPosition(50, (y + 5));
		this->textArray[amountOfArrElements].setFont(this->taskFont);
		this->textArray[amountOfArrElements].setCharacterSize(20);
		/*while (appWindow.isOpen())
		{
			while (appWindow.pollEvent(this->event))
			{
				if (this->event.type == sf::Event::TextEntered)
				{
					if (std::isprint(event.text.unicode))
					{
						this->userInput += static_cast<char>(event.text.unicode);
					}
				}
				if (event.type == sf::Event::KeyPressed)
				{
						if (event.key.code == sf::Keyboard::BackSpace) {
							if (!userInput.empty())
								userInput.pop_back();
						}
				}
				if (event.key.code == sf::Keyboard::Return) {
					this->textArray[amountOfArrElements].setString(this->userInput);
					std::cout << "Text added\n";
					userInput += '\n';
				}

			}
		}*/
		
		
		amountOfArrElements++; //Incrementing the button & text amount
		y += 65;
		elapsedTime = sf::Time::Zero;
		std::cout << "Task added\n";
	}
}



//Rendering tasks on the screen
void Task::renderTasks(sf::RenderTarget& target)
{
	for (auto& piece : this->taskBox)
	{
		target.draw(piece);
	}

	//Rendering all buttons in the array
	for (int i = 0; i < amountOfArrElements; i++)
	{
		this->buttonArray[i]->renderButton(&target); //Rendering the buttons
		target.draw(this->textArray[i]); //Rendering the text
	}
}

void Task::updateButtons(const sf::Vector2f mousePos)
{
	//Updating all buttons in the array
	for (int i=0;i<amountOfArrElements;i++)
	{
		this->buttonArray[i]->updateButton(mousePos);
	}
}

//Deleting a task via a button
void Task::deleteTask()
{

}

//If current text doesn't work - use a button as a textBox, add a string to it, and a public setString method

//Initalizing variables
void Task::initVariables()
{
	taskFont.loadFromFile("ARIAL.ttf");
	elapsedTime = sf::Time::Zero;
}
//Constructor
Task::Task() : taskBox(std::list<sf::RectangleShape>(1))
{
	this->firstTask = --this->taskBox.end();	
	this->amountOfArrElements = 0;
	this->initVariables();
	
	//Colors for the delete button 

	//Delete task idle color: (181, 38, 9)
	//delete task hover color: (161, 34, 9)
	//delete task click color: (133, 29, 9)
}

//Destructor
Task::~Task()
{
	//Deleting the button array
	delete[] this->buttonArray;
	delete[] this->textArray;
}


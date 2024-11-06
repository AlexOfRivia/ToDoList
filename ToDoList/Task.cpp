#include "Task.h"

//Initializing a new task
void Task::initNewTask(sf::Time dt,const sf::Vector2f mousePos, sf::RenderWindow& appWindow, sf::Event ev)
{
	elapsedTime += dt;
	if (elapsedTime.asSeconds() > 0.25 && amountOfArrElements < 11 && y<=700)
	{
		//Adding a new task box to the array
		this->taskArray[amountOfArrElements] = new sf::RectangleShape;
		this->taskArray[amountOfArrElements]->setSize(sf::Vector2f(700, 50));
		this->taskArray[amountOfArrElements]->setFillColor(sf::Color::Black);
		this->taskArray[amountOfArrElements]->setPosition(50, y);
		
		
		//Adding a new button to the array
		this->buttonArray[amountOfArrElements] = new Button(725, (y + 10), 20.f, 20.f, sf::Color(133, 29, 7), sf::Color(161, 34, 8), sf::Color(181, 38, 9));
		
		//Adding a new textbox to the array
		this->textArray[amountOfArrElements] = new Textbox(600, 40 ,60, (y+5),20, sf::Color(40,40,40), sf::Color(30,30,30), this->taskFont, 120, true, false);
		

		amountOfArrElements++; //Incrementing the button & text amount
		y += 65; //changing the next box position
		elapsedTime = sf::Time::Zero;
		std::cout << "Task added\n"; //For debuging
	}
}
		

//Rendering tasks on the screen
void Task::renderTasks(sf::RenderTarget& target)
{

	//Rendering all array elements
	for (int i = 0; i < amountOfArrElements; i++)
	{
		target.draw(*taskArray[i]); //Rednering the task boxes
		this->buttonArray[i]->renderButton(&target); //Rendering the buttons
		this->textArray[i]->renderTextbox(&target); //Rendering the te6xtboxes
	}
}

void Task::updateButtons(const sf::Vector2f mousePos, sf::Event ev)
{
	//Updating all buttons in the array
	for (int i=0;i<amountOfArrElements;i++)
	{
		this->buttonArray[i]->updateButton(mousePos);
		if (this->buttonArray[i]->isPressed() == true)
		{
			this->deleteTask(i);
		}
	}
	for (int i = 0; i < amountOfArrElements; i++)
	{
		
		this->textArray[i]->updateTextbox(mousePos, ev);

	}
}

void Task::updateTextboxes(sf::Event ev)
{
	for (int i = 0; i < amountOfArrElements; i++)
	{
		
		this->textArray[i]->typedOn(ev);
		
	}

}

//Deleting all tasks
void Task::clearTaskList()
{
	this->amountOfArrElements = 0;
	y = 50;
}

//Initalizing variables
void Task::initVariables()
{
	taskFont.loadFromFile("arial.ttf");
	elapsedTime = sf::Time::Zero;
}

//Deleting a task
void Task::deleteTask(int arrIndex)
{
	for (int j = (arrIndex); j <= this->amountOfArrElements; j++)
	{
		this->taskArray[j] = this->taskArray[j+1];
		this->buttonArray[j] = this->buttonArray[j+1];
		this->textArray[j] = this->textArray[j+1];
	}
	this->amountOfArrElements--;
	if (this->amountOfArrElements == 0)
	{
		this->y = 50;
	}
}

//Constructor
Task::Task() 
{	
	this->amountOfArrElements = 0;
	this->initVariables();
	
}

//Destructor
Task::~Task()
{
	////Deleting all dynamic array
	//delete[] this->buttonArray;
	//delete[] this->textArray;
}


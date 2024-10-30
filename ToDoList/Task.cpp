#include "Task.h"

//Initializing a new task
void Task::initNewTask(sf::Time dt,const sf::Vector2f mousePos, sf::RenderWindow& appWindow, sf::Event ev)
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
		this->textArray[amountOfArrElements] = new Textbox(600, 40 ,60, (y+5),15, sf::Color(40,40,40), sf::Color(30,30,30), this->taskFont, 120, true, false);
		

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
		this->textArray[i]->renderTextbox(&target); //Rendering the textboxes
	}
}

void Task::updateButtons(const sf::Vector2f mousePos, sf::Event ev)
{
	//Updating all buttons in the array
	for (int i=0;i<amountOfArrElements;i++)
	{
		this->buttonArray[i]->updateButton(mousePos);
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

//Deleting a task via a button
void Task::deleteTask()
{

}

//Initalizing variables
void Task::initVariables()
{
	taskFont.loadFromFile("arial.ttf");
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


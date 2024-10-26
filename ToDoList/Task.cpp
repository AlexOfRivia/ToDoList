#include "Task.h"

//Initializing a new task
void Task::initNewTask(sf::Time dt,const sf::Vector2f mousePos, sf::RenderTarget& target)
{
	//Max task number is 13
	elapsedTime += dt;
	if (elapsedTime.asSeconds() > 0.25 && taskBox.size()<12)
	{
		sf::RectangleShape newPiece;
		newPiece.setSize(sf::Vector2f(700, 50));
		newPiece.setFillColor(sf::Color::White);
		newPiece.setPosition(50,y);

		this->firstTask = this->taskBox.insert(this->firstTask++, newPiece);
		this->buttonArray[amountOfButtons] = new Button(725, (y+10), 20.f,20.f, sf::Color(133, 29, 7), sf::Color(161, 34, 8), sf::Color(181, 38, 9));
		
		amountOfButtons++;
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
	for (int i = 0; i < amountOfButtons; i++)
	{
		this->buttonArray[i]->renderButton(&target);
	}
}

void Task::updateButtons(const sf::Vector2f mousePos)
{
	for (int i=0;i<amountOfButtons;i++)
	{
		this->buttonArray[i]->updateButton(mousePos);
	}
}

//Deleting a task via a button
void Task::deleteTask()
{

}

//Initalizing variables
void Task::initVariables()
{
	elapsedTime = sf::Time::Zero;
}
//Constructor
Task::Task() : taskBox(std::list<sf::RectangleShape>(1))
{
	this->firstTask = --this->taskBox.end();
	//firstButton = --buttonList.end();
	
	this->amountOfButtons = 0;
	this->initVariables();
	
	//Colors for the delete button 

	//Delete task idle color: (181, 38, 9)
	//delete task hover color: (161, 34, 9)
	//delete task click color: (133, 29, 9)
}

//Destructor
Task::~Task()
{
	delete[] this->buttonArray;
}


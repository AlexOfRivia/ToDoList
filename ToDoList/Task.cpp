#include "Task.h"


/*TODO
- ADD A DELETE BUTTON TO A TASK
*/


//Initializing a new task
void Task::initNewTask(sf::Time dt)
{
	//Max task number is 13
	elapsedTime += dt;
	if (elapsedTime.asSeconds() > 0.25 && taskBox.size()<12)
	{
		sf::RectangleShape newPiece;
		newPiece.setSize(sf::Vector2f(700, 50));
		newPiece.setFillColor(sf::Color::White);
		newPiece.setPosition(50,y);
		firstTask = taskBox.insert(firstTask++, newPiece);
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
	firstTask = --taskBox.end();
	this->initVariables();

	//Colors for the delete button 

	//Delete task idle color: (181, 38, 9)
	//delete task hover color: (161, 34, 9)
	//delete task click color: (133, 29, 9)
}

//Destructor
Task::~Task()
{

}


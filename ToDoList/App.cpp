#include "App.h"


//Updating app events
void App::updateEvents()
{
	sf::Clock clock;
	deltaTime = sf::seconds(1.f / 60.f);

	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			this->window->close();
		}
	}

	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window)); //This MUST be in the update method, as it updates the mouse position!
	this->addButton->updateButton(this->mousePosView);
	
	this->deleteButton->updateButton(this->mousePosView);

	this->task->updateButtons(this->mousePosView);

	if (this->addButton->isPressed() == true)
	{
		this->task->initNewTask(this->deltaTime, this->mousePosView, *this->window, this->event);
	}
	this->task->updateButtons(this->mousePosView);

	//Delete all tasks
	if (this->deleteButton->isPressed()== true)
	{

	}

}

//Updating things in the App
void App::Update()
{
	this->updateEvents();
	this->task->updateButtons(this->mousePosView);
}

//Rendering everything to the screen
void App::Render()
{
	this->window->clear(sf::Color(22,22,22,100));//clears old frame

	//Rendering everything on the screen
	this->window->draw(this->background);
	this->addButton->renderButton(this->window);
	this->deleteButton->renderButton(this->window);
	this->task->renderTasks(*this->window);
	this->window->display();//displays new frame
}

//Checking if the app is running
const bool App::isRunning() const
{
	return this->window->isOpen();
}

//Initializing window
void App::initWindow()
{
	//Background with all Tasks
	this->background.setSize(sf::Vector2f(700, 700));
	this->background.setFillColor(sf::Color(37,37,37,100));
	this->background.setPosition(50,50);

	//Task
	this->task = new Task();

	//Main Window
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "ToDo List",sf::Style::Titlebar | sf::Style::Close );
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//Initializing variables
void App::initVariables()
{
	this->window = nullptr;
	//(X, Y, Width, Height, Idle Color, Hover Color, Pressed Color)
	this->addButton = new Button(720.f, 10.f, 35.f, 35.f, sf::Color(42, 44, 42), sf::Color(82, 84, 82), sf::Color(102, 104, 102));
	this->deleteButton = new Button(640, 10, 70.f, 35.f, sf::Color(133, 29, 9), sf::Color(161, 34, 9), sf::Color(181, 38, 9));
}

//Constructor
App::App()
{
	this->initVariables(); //this function must be first, because of window being set to nullptr
	this->initWindow();
}

//Destructor
App::~App()
{
	delete this->addButton;
	delete this->deleteButton;
	delete this->window;
	delete this->task;
}
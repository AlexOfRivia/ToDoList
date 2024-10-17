#include "App.h"


//Updating app events
void App::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

//Updating things in the App
void App::Update()
{
	this->updateEvents();
}

//Rendering everything to the screen
void App::Render()
{
	this->window->clear(sf::Color(25, 25, 25, 0));//clears old frame

	//Rendering everything on the screen
	this->window->draw(this->background);

	this->window->display();//displays new frame
}

const bool App::isRunning() const
{
	return this->window->isOpen();
}

//Initializing a new task
void App::initNewTask()
{

}

//Initializing window
void App::initWindow()
{
	this->background.setSize(sf::Vector2f(70, 70));
	this->background.setFillColor(sf::Color::White);
	this->background.setPosition(100,100);
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "ToDo List",sf::Style::Titlebar | sf::Style::Close );
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//Initializing variables
void App::initVariables()
{
	this->window = nullptr;
	
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
	delete this->window;
}
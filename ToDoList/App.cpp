#include "App.h"


//Updating app events
void App::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}

	if (mousePos.x > addButton.getPosition().x && mousePos.x < (addButton.getPosition().x + addButton.getSize().x)) 
	{
		if (mousePos.y > addButton.getPosition().y && mousePos.y < (addButton.getPosition().y + addButton.getSize().y)) 
		{
				std::cout << "Button clicked\n";
		}
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
	this->window->clear(sf::Color(22,22,22,100));//clears old frame

	//Rendering everything on the screen
	this->window->draw(this->background);
	this->window->draw(this->addButton);
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

	//Button for adding new tasks
	this->addButton.setSize(sf::Vector2f(35,35));
	this->addButton.setPosition(720, 10);
	this->addButton.setFillColor(sf::Color::Green);

	//Main Window
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "ToDo List",sf::Style::Titlebar | sf::Style::Close );
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

//Initializing variables
void App::initVariables()
{
	this->window = nullptr;
	this->mousePos = sf::Mouse::getPosition();
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
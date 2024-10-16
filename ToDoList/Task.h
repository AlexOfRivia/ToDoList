#pragma once
#include <iostream>

class Task
{
public:



	//Constructor
	Task();

	//Destructor
	~Task();

private:
	sf::Text taskText; //this will be equal to the taskName while constructing new object
	std::string taskName;
	bool isCompleted;
};


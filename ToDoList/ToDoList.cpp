#include <iostream>
#include "App.h"

#include <iostream>

int main()
{
	App app;
	while (app.isRunning())
	{
		app.Update();

		app.Render();
	}
}


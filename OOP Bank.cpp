#include <iostream>
#include "clsLoginScreen.h"
#include "clsTransferHistoryScreen.h"
#include "clsCurrency.h"



int main()
{
	
	//clsMainScreen::ShowMainMenu();
	
	while (clsLoginScreen::ShowLoginScreen())
	{
		clsLoginScreen::ShowLoginScreen();


		 //There's Nothing To Fear.
	}

	return 0;
}
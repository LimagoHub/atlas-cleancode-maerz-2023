// SimpleNimSpielProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include "ComputerPlayer.h"
#include "GameClient.h"
#include "HumanPlayer.h"
#include "TakeGameImpl.h"
#include "ConsolenWriter.h"



int main()
{

	ConsolenWriter writer;
    TakeGameImpl impl{writer};
	HumanPlayer human{"Mensch"};
	ComputerPlayer computer{ "Computer" };
	impl.addPlayer(&human);
	impl.addPlayer(&computer);
	GameClient client{ impl };
	client.go();
}


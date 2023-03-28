// SimpleNimSpielProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "GameClient.h"
#include "TakeGameImpl.h"
int main()
{
    TakeGameImpl impl;
	GameClient client{ impl };
	client.go();
}


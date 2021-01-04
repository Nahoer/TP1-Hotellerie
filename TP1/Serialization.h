#pragma once
#include "App.h";
class Serialization 
{
public:
	Serialization(string filesPath="");
	App read();
	void write(App app);
private:
	App readHotels(App app);
	App readClients(App app);
	App readReservations(App app);
	string _path;

};
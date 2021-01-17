#pragma once
#include "App.h";
class Serialization 
{
public:
	Serialization(string filesPath="");
	void read(App &app);
	
private:
	void readHotels(App &app);
	void readClients(App &app);
	void readReservations(App& app);
	string _path;

};
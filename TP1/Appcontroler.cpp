#include "Appcontroler.h";

Appcontroler::Appcontroler() : _app(App()), _serial(Serialization())
{
	this->actualize();
}

App Appcontroler::getApp() const {

	return this->_app;
}

void Appcontroler::actualize() 
{
	this->_serial.read(this->_app);
}

void Appcontroler::addHotel(Hotel h)
{
	this->_serial.addHotel(h);
	this->actualize();
}
void Appcontroler::addClient(Client c)
{

	this->actualize();
}
void Appcontroler::addChambre(Chambre c)
{

	this->actualize();
}
void Appcontroler::addReservation(Reservation r)
{

	this->actualize();
}

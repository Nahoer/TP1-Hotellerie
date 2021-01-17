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

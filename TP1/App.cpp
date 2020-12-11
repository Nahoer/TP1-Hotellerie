#include "App.h";

App::App() : _clients(vector<Client>()), _hotels(vector<Hotel>()), _reservations(vector<Reservation>())
{
	
}
void App::addClient(string nom, string prenom) 
{
	int id = 0;
	if (this->_clients.size() != 0) 
	{
		id = this->_clients.at(this->_clients.size() - 1).getID() + 1;
	}
	this->_clients.push_back(Client(id, nom, prenom));
}
void App::addHotel(string nom, string ville)
{
	int id = 0;
	if (this->_hotels.size() != 0)
	{
		id = this->_hotels.at(this->_hotels.size() - 1).getID() + 1;
	}
	this->_hotels.push_back(Hotel(id, nom, ville));
}
void App::addReservation(Date dateDebut, Date dateFin, Hotel hotel, Chambre chambre, Client client)
{
	int id = 0;
	if (this->_reservations.size() != 0)
	{
		id = this->_reservations.at(this->_reservations.size() - 1).getID() + 1;
	}
	this->_reservations.push_back(Reservation(id, dateDebut, dateFin, hotel, chambre, client));
}

vector<Client> App::getClients() const
{
	return this->_clients;
}

vector<Hotel> App::getHotels() const
{
	return this->_hotels;
}

vector<Reservation> App::getReservations() const
{
	return this->_reservations;
}
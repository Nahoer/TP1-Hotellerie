#include "App.h";

App::App() : _clients(vector<Client>()), _hotels(vector<Hotel>()), _reservations(vector<Reservation>())
{
	
}
void App::addClient(Client client)
{
	this->_clients.push_back(client);
}
void App::addClient(string nom, string prenom) 
{
	int id = 0;
	if (this->_clients.size() != 0) 
	{
		id = this->_clients.at(this->_clients.size() - 1).getID() + 1;
	}
	this->addClient(Client(id, nom, prenom));
}

void App::addHotel(Hotel hotel)
{
	this->_hotels.push_back(hotel);
}

void App::addHotel(string nom, string ville)
{
	int id = 0;
	if (this->_hotels.size() != 0)
	{
		id = this->_hotels.at(this->_hotels.size() - 1).getID() + 1;
	}
	this->addHotel(Hotel(id, nom, ville));
}

void App::addReservation(Reservation reservation)
{
	this->_reservations.push_back(reservation);
}

void App::addReservation(Date dateDebut, Date dateFin, Hotel hotel, Chambre chambre, Client client)
{
	int id = 0;
	if (this->_reservations.size() != 0)
	{
		id = this->_reservations.at(this->_reservations.size() - 1).getID() + 1;
	}
	this->addReservation(Reservation(id, dateDebut, dateFin, hotel, chambre, client));
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

void App::addChambre(Hotel hotel, int id, RoomType type, int prix)
{
	hotel.addChambre(Chambre(id, type, prix));
}

void App::addChambre(Hotel hotel, RoomType type, int prix)
{
	int id = 0;
	if (this->_reservations.size() != 0)
	{
		id = hotel.getChambre(hotel.getChambres().size()).getID() + 1;
	}
	this->addChambre(hotel, id, type, prix);
}


Client App::getClientByID(int id) const 
{
	int i = 0;
	Client c = Client();
	bool found = false;
	while (i < this->getClients().size() && found == false)
	{
		if (this->getClients().at(i).getID() == id)
		{
			c = this->getClients().at(i);
			found = true;
		}

		i++;
	}

	return c;
}

Hotel App::getHotelByID(int id) const
{
	int i = 0;
	Hotel h = Hotel();
	bool found = false;
	while (i < this->getHotels().size() && found == false)
	{
		if (this->getHotels().at(i).getID() == id)
		{
			h = this->getHotels().at(i);
			found = true;
		}

		i++;
	}

	return h;
}

Reservation App::getReservationByID(int id) const
{
	int i = 0;
	Reservation r = Reservation();
	bool found = false;
	while (i < this->getReservations().size() && found == false)
	{
		if (this->getReservations().at(i).getID() == id)
		{
			r = this->getReservations().at(i);
			found = true;
		}

		i++;
	}

	return r;
}

Chambre App::getChambreByID(int idHotel, int idChambre) const
{
	return this->getHotels()[idHotel].getChambreByID(idChambre);
}
#pragma once

#include <iostream>;
#include <string>;
#include <vector>;
#include "Hotel.h";
#include "Client.h";
#include "Reservation.h";
using namespace std;
using namespace hotellerie;


class App {

	public:
		App();
		void addClient(string nom, string prenom);
		void addHotel(string nom, string ville);
		void addReservation(Date dateDebut, Date dateFin, Hotel hotel, Chambre chambre, Client client);
		vector<Client> getClients() const;
		vector<Hotel> getHotels() const;
		vector<Reservation> getReservations() const;
	private:
		vector<Client> _clients;
		vector<Hotel> _hotels;
		vector<Reservation> _reservations;

};

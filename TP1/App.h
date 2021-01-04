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
		void addChambre(Hotel hotel, RoomType type, int prix);
		void addClient(Client client);
		void addHotel(Hotel hotel);
		void addReservation(Reservation reservation);
		void addChambre(Hotel hotel, int id, RoomType type, int prix);
		
		Chambre getChambreByID(int idHotel, int idChambre) const;

		Client getClientByID(int id) const;
		vector<Client> getClients() const;

		Hotel getHotelByID(int id) const;
		vector<Hotel> getHotels()const ;

		Reservation getReservationByID(int id) const;
		vector<Reservation> getReservations() const;
		vector<Reservation> getReservatuinsByClient(Client c) 
		{
			vector<Reservation> reservations = vector<Reservation>();
			for (int i = 0; i < c.getReservations().size(); i++)
			{
				reservations.push_back(this->getReservationByID(c.getReservation(i)));
			}
		}
	private:
		vector<Client> _clients;
		vector<Hotel> _hotels;
		vector<Reservation> _reservations;

};

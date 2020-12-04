#pragma once
#include "Date.h";
#include "Client.h";
#include "Chambre.h";
#include "Hotel.h";

namespace hotelerie {
	class Reservation {

	public:

		Reservation();

		Reservation(int id, Date dateDebut, Date dateFin, Hotel hotel, Chambre chambre, Client client);

		int getID() const;

		Date getDateDebut() const;
		void setDateDebut(Date d);

		Date getDateFin() const;
		void setDateFin(Date d);

		Hotel getHotel() const;

		void setChambre(Chambre c);
		Chambre getChambre() const;

		void setClient(Client c);
		Client getClient() const;

		int getMontant() const;

		string toString() const;


	private:
		int _id;
		Date _dateDebut;
		Date _dateFin;
		Hotel _hotel;
		Chambre _chambre;
		Client _client;
		int _montant;

	};


}

#include "Reservation.h";


namespace hotelerie {
	Reservation::Reservation() : _id(0), _dateDebut(Date()), _dateFin(Date()), _hotel(Hotel()), _chambre(Chambre()), _client(Client())
	{

	}

	Reservation::Reservation(int id, Date dateDebut, Date dateFin, Hotel hotel, Chambre chambre, Client client) : _id(id), _dateDebut(dateDebut), _dateFin(dateFin), _hotel(hotel), _chambre(chambre), _client(client)
	{

	}

	int Reservation::getID() const
	{
		return this->_id;
	}

	Date Reservation::getDateDebut() const
	{
		return this->_dateDebut;
	}
	void Reservation::setDateDebut(Date d)
	{
		this->_dateDebut = d;
	}

	Date Reservation::getDateFin() const
	{
		return this->_dateFin;
	}
	void Reservation::setDateFin(Date d)
	{
		if (d>this->getDateDebut()) {
			this->_dateFin = d;
		}

	}

	Hotel Reservation::getHotel() const
	{
		return this->_hotel;
	}

	void Reservation::setChambre(Chambre c)
	{
		this->_chambre = c;
	}

	Chambre Reservation::getChambre() const
	{
		return this->_chambre;
	}


	void Reservation::setClient(Client c)
	{
		this->_client = c;
	}

	Client Reservation::getClient() const
	{
		return this->_client;
	}


	int Reservation::getMontant() const
	{
		int remise = 1;
		int nbrJour = this->getDateDebut().ecartJour(this->getDateFin());
		return this->getChambre().getPrix()*nbrJour*remise;
	}

	string Reservation::toString() const
	{
		string str = "";
		str += "Reservation " + to_string(this->getID());
		str += "\nAu nom de " + this->getClient().getNom() + " " + this->getClient().getPrenom();
		str += "\nHotel: " + this->getHotel().getNom();
		str += "\nChambre: " + to_string(this->getChambre().getID());
		str += "\nType de chambre: " + this->getChambre().getTypeAsString();
		str += "\nDu " + this->getDateDebut().toStringShortFormat() + " au " + this->getDateFin().toStringShortFormat();
		str += "\nPrix/nuit: " + to_string(this->getChambre().getPrix()) + " euros";
		str += "\nPrix total: " + to_string(this->getMontant()) + " euros";


		return str;
	}
}

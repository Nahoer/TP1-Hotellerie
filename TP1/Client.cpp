
#include "Client.h";

namespace hotellerie {
	Client::Client() : _id(0), _nom(""), _prenom(""), _IDReservations(vector<int>())
	{

	}
	Client::Client(int id, string nom, string prenom) : _id(id), _nom(nom), _prenom(prenom), _IDReservations(vector<int>())
	{

	}

	int Client::getID() const
	{
		return this->_id;
	}

	void Client::setNom(string nom)
	{
		this->_nom = nom;
	}

	string Client::getNom() const
	{
		return this->_nom;
	}

	void Client::setPrenom(string prenom)
	{
		this->_prenom = prenom;
	}

	string Client::getPrenom() const
	{
		return this->_prenom;
	}

	int Client::getReservation(int index) const
	{
		return this->_IDReservations[index];
	}

	vector<int> Client::getReservations() const
	{
		return this->_IDReservations;
	}

	void Client::addReservation(int idR)
	{
		this->_IDReservations.push_back(idR);
	}
	void Client::removeReservation(int index)
	{
		this->_IDReservations.erase(this->getReservations().begin() + index);
	}

	void Client::replaceReservation(int index, int idR) 
	{
		this->_IDReservations[index] = idR;
	}

	ostream& operator<<(ostream& os, const Client& c)
	{
		os << to_string(c.getID()) + " " + c.getNom() + " " + c.getPrenom();

		return os;
	}
}
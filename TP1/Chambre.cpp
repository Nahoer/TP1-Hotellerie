
#include "Chambre.h";


namespace hotelerie {
	Chambre::Chambre() : _prix(0), _id(0), _type(Single)
	{

	}


	Chambre::Chambre(int id, RoomType type, int prix) : _id(id), _type(type), _prix(prix)
	{

	}

	int Chambre::getID() const
	{
		return this->_id;
	}

	RoomType Chambre::getType() const
	{
		return this->_type;
	}
	void Chambre::setType(RoomType type)
	{
		this->_type = type;
	}

	int Chambre::getPrix() const
	{
		return this->_prix;
	}
	void Chambre::setPrix(int prix)
	{
		this->_prix = prix;
	}

	string Chambre::getTypeAsString() const
	{
		string type;
		switch (this->_type) {
		case 0:
			type = "single";
			break;
		case 1:
			type = "double";
			break;
		case 2:
			type = "suite";
			break;
		}
		return type;
	}

	string Chambre::toString() const
	{
		
		return "Chambre " + to_string(this->getID()) + "\nPrix: " + to_string(this->getPrix()) + "\nType: " + this->getTypeAsString();
	}
}
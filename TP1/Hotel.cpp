

#include "Hotel.h";
#include <iostream>
using namespace std;
namespace hotelerie {
	Hotel::Hotel() : _id(0), _nom(""), _ville("")
	{
		this->_listeChambres = vector<Chambre>();
	}
	Hotel::Hotel(int id, string nom, string ville) : _id(id), _nom(nom), _ville(ville)
	{
		this->_listeChambres = vector<Chambre>();
	}

	int Hotel::getID() const
	{
		return this->_id;
	}

	void Hotel::setNom(string nom)
	{
		this->_nom = nom;
	}

	string Hotel::getNom() const
	{
		return this->_nom;
	}

	void Hotel::setVille(string ville)
	{
		this->_ville = ville;
	}

	string Hotel::getVille() const
	{
		return this->_ville;
	}

	int Hotel::getIndexOf(Chambre c)  const
	{
		int i = 0;
		int index = -1;
		bool found = false;
		while (i < this->_listeChambres.size() && found == false)
		{
			if (this->getChambres().at(i).getID() == c.getID())
			{
				index = i;
				found = true;
			}

			i++;
		}

		return index;


	}

	void Hotel::addChambre(Chambre c)
	{
		this->_listeChambres.push_back(c);
	}
	void Hotel::removeChambre(Chambre c)
	{
		int index = this->getIndexOf(c);
		this->_listeChambres.erase(this->getChambres().begin() + index);
	}
	void Hotel::removeChambre(int index)
	{
		this->_listeChambres.erase(this->getChambres().begin() + index);
	}
	vector<Chambre> Hotel::getChambres() const
	{
		return this->_listeChambres;
	}
	vector<Chambre> Hotel::getChambresDispo() const
	{
		return this->_listeChambres;
	}
	Chambre Hotel::getChambre(int index) const
	{
		return this->getChambres().at(index);
	}


	void Hotel::modifyChambre(int index, Chambre c)
	{
		this->getChambres()[index] = c;
	}

	string Hotel::toString() const
	{
		string str = "Hotel " + this->getNom() + " a " + this->getVille();
		for (Chambre c : this->getChambres())
		{
			str += "\n" + c.toString();
		}

		return str;
	}

}

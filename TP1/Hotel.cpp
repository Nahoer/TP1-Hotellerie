

#include "Hotel.h";
#include <iostream>
using namespace std;
namespace hotellerie {
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

	Chambre Hotel::getChambreByID(int id) const
	{
		int i = 0;
		Chambre c = Chambre();
		bool found = false;
		while (i < this->_listeChambres.size() && found == false)
		{
			if (this->getChambres().at(i).getID() == id)
			{
				c = this->getChambres().at(i);
				found = true;
			}

			i++;
		}

		return c;
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

	ostream& operator<<(ostream& os, const Hotel& h)
	{
		os << "Hotel " + h.getNom() + " a " + h.getVille();
		for (Chambre c : h.getChambres())
		{
			os << "\n" << c;
		}

		return os;
	}

}

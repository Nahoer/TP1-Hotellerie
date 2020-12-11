#pragma once

#include <string>;
#include <vector>;
#include "Chambre.h";
using namespace std;



namespace hotelerie {

	class Hotel {

	public:
		Hotel();
		Hotel(int id, string nom, string ville);

		int getID() const;
		void setNom(string nom);
		string getNom() const;
		void setVille(string ville);
		string getVille() const;
		int getIndexOf(Chambre c) const;
		void addChambre(Chambre c);
		void removeChambre(Chambre c);
		void removeChambre(int index);
		vector<Chambre> getChambres() const;
		vector<Chambre> getChambresDispo() const;
		Chambre getChambre(int index) const;
		void modifyChambre(int index, Chambre c);

			


	private:
		int _id;
		string _nom;
		string _ville;
		vector<Chambre> _listeChambres;


	};

	string operator << (Hotel& h);
}
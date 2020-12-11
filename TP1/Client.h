#pragma once
#include <iostream>;
#include <string>;
#include <vector>;


using namespace std;

namespace hotelerie {
	class Client {
	public:

		Client();
		Client(int id, string nom, string prenom);

		int getID() const;

		string getNom() const;
		void setNom(string nom);


		string getPrenom() const;
		void setPrenom(string prenom);

		vector<int> getReservations() const;
		int getReservation(int index) const;
		void addReservation(int idR);
		void removeReservation(int index);
		void replaceReservation(int index, int idR);



	private:
		int _id;
		string _nom;
		string _prenom;
		vector<int> _IDReservations;

	};

	ostream& operator<<(ostream& os, const Client& c);
}
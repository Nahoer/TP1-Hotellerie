#pragma once
#include <iostream>;
#include <string>

using namespace std;

namespace hotellerie {
	enum RoomType { Single, Double, Suite };

	class Chambre {

	public:
		Chambre();
		Chambre(int id, RoomType type, int prix);

		int getID() const;

		RoomType getType() const;
		void setType(RoomType type);

		int getPrix() const;
		void setPrix(int prix);

		string getTypeAsString() const;

	private:
		int _id;
		RoomType _type;
		int _prix;


	};

	ostream& operator<<(ostream& os, const Chambre& c);
}
	


#include "Serialization.h";
#include <fstream>
using namespace std;

bool endsWith(const std::string& s, const std::string& suffix)
{
	return s.size() >= suffix.size() &&
		s.substr(s.size() - suffix.size()) == suffix;
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter, const bool& removeEmptyEntries = false)
{
	std::vector<std::string> tokens;

	for (size_t start = 0, end; start < s.length(); start = end + delimiter.length())
	{
		size_t position = s.find(delimiter, start);
		end = position != string::npos ? position : s.length();

		std::string token = s.substr(start, end - start);
		if (!removeEmptyEntries || !token.empty())
		{
			tokens.push_back(token);
		}
	}

	if (!removeEmptyEntries &&
		(s.empty() || endsWith(s, delimiter)))
	{
		tokens.push_back("");
	}

	return tokens;
}

Serialization::Serialization(string filesPath) : _path(filesPath)
{
}
void Serialization::read(App &app)
{
	this->readClients(app);
	this->readHotels(app);
	this->readReservations(app);

}

void Serialization::readHotels(App &app)
{
	string line;
	vector<Chambre> chambres = vector<Chambre>();
	ifstream file(_path + "chambres.txt");
	while (getline(file, line))
	{
		vector<string> words = split(line, " ");

		chambres.push_back(Chambre(stoi(words[0]), static_cast<RoomType>(stoi(words[1])), stoi(words[2])));
	}
	

	file = ifstream(_path + "hotels.txt");
	while (getline(file, line))
	{
		vector<string> words = split(line, " ");
		Hotel h = Hotel(stoi(words[0]), words[1], words[2]);
		
		if (words.size() > 3) 
		{
			for (int i = 3; i < words.size(); i++) 
			{
				for (int j = 0; j < chambres.size(); j++)
				{
					if (chambres[j].getID() == stoi(words[i])) 
					{
						h.addChambre(chambres[j]);
					}
				}
			}
		}

		app.addHotel(h);
		
	}
}
void Serialization::readClients(App &app)
{
	string line;
	ifstream file(_path+"clients.txt");
	while (getline(file, line)) 
	{
		vector<string> words = split(line, " ");
		Client c = Client(stoi(words[0]), words[1], words[2]);
		if (words.size() > 3)
		{
			for (int i = 3; i < words.size(); i++)
			{
				c.addReservation(stoi(words[i]));
			}
		}

		app.addClient(c);

		
	}
}
void Serialization::readReservations(App &app)
{
	string line;
	ifstream file(_path + "reservations.txt");

	while (getline(file, line))
	{
		vector<string> words = split(line, " ");
		Hotel h = app.getHotelByID(stoi(words[7]));
		Chambre ch = app.getChambreByID(h.getID(), stoi(words[8]));
		Client client = app.getClientByID(stoi(words[9]));
		Reservation r = Reservation(stoi(words[0]), Date(stoi(words[1]), stoi(words[2]), stoi(words[3])), Date(stoi(words[4]), stoi(words[5]), stoi(words[6])), h, ch, client);
		app.addReservation(r);
	}

}

void Serialization::addHotel(Hotel hotel)
{
	ofstream stream = ofstream(_path + "hotels.txt");
		
	stream << to_string(hotel.getID()) + " " + hotel.getNom() + " " + hotel.getVille() + "\n";


}





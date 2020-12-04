#pragma once
#include <string>

using namespace std;

class Date {
public:
	Date();
	Date(int jour, int mois, int annee);

	int getJour() const;
	void setJour(int jour);

	int getMois() const;
	void setMois(int mois);

	int getAnnee() const;
	void setAnnnee(int annee);

	void setDate(int jour, int mois, int annee);

	int GetNbrJourParMois() const;

	bool isBisextile() const;

	int ecartJour(Date d) const;

	bool isOlderThan(Date d) const;

	string toStringShortFormat();

	string toStringFullFormat();

	void jourSuivant();
	void moisSuivant();
	void anneeSuivante();


private :
	int _jour;
	int _mois;
	int _annee;
};
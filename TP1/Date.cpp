#include "Date.h";
#include <iostream>

using namespace std;


Date::Date()
{
	this->setDate(0, 0, 0);
}
Date::Date(int jour, int mois, int annee)
{
	this->setDate(jour, mois, annee);
}
int Date::getJour() const
{
	return this->_jour;
}
void Date::setJour(int jour)
{
	this->_jour = jour;
	if (this->getJour() >= this->GetNbrJourParMois()+1) 
	{
		this->_jour = 1;
	}
}

int Date::getMois() const
{
	return this->_mois;
}

void Date::setMois(int mois)
{
	this->_mois = mois;
	if (this->getMois() >= 13)
	{
		this->_mois = 1;
	}
}

int Date::GetNbrJourParMois() const
{
	int nbr;
	if (this->getMois() == 2) 
	{
		if (this->isBisextile())
		{
			nbr = 28;
		}
		else 
		{
			nbr = 29;
		}
		
	}
	else if (this->getMois()== 4 || this->getMois() == 6 || this->getMois() == 9 || this->getMois() == 11)
	{
		nbr = 30;
	}
	else
	{
		nbr = 31;
	}

	return nbr;
}

bool Date::isBisextile() const
{
	bool isBisextile = false;
	if (this->getAnnee() % 4 == 0)
	{
		isBisextile = true;
	}

	return isBisextile;
}

int Date::getAnnee() const
{
	return this->_annee;
}
void Date::setAnnnee(int annee)
{
	this->_annee = annee;
}

void Date::setDate(int jour, int mois, int annee)
{
	this->setJour(jour);
	this->setMois(mois);
	this->setAnnnee(annee);
}

int Date::ecartJour(Date d) const
{
	int ecart = 0;
	if (this->isOlderThan(d)) 
	{
		Date d2 = Date(this->getJour(), this->getMois(), this->getAnnee());
		ecart = d.ecartJour(d2);
	}
	else 
	{
		Date d3 = Date(this->getJour(), this->getMois(), this->getAnnee());
		while (d.isOlderThan(d3))
		{
			d3.jourSuivant();
			ecart++;
		}
	}

	return ecart;
}

bool Date::isOlderThan(Date d) const
{
	bool isOlder = false;
	if (this->getAnnee() > d.getAnnee())
	{
		isOlder = true;
	}
	else 
	{
		if (this->getAnnee() == d.getAnnee())
		{
			if (this->getMois() > d.getMois()) 
			{

				isOlder = true;
			}
			else
			{
				if (this->getMois() == d.getMois())
				{
					if (this->getJour() > d.getJour()) {
						isOlder = true;
					}
				}
			}
		}
	}

	return isOlder;

}

string Date::toStringShortFormat()
{
	string date = "";	
	date += to_string(this->getJour()) + "/";
	date += to_string(this->getMois()) + "/";
	date += to_string(this->getAnnee());
	return date;
}

string Date::toStringFullFormat()
{
	return "";
}

void Date::jourSuivant()
{
	
	if (this->getJour() >= this->GetNbrJourParMois()) 
	{
		this->setJour(this->getJour() + 1);
		this->moisSuivant();
	}
	else
	{
		this->setJour(this->getJour() + 1);
	}

	
}

void Date::moisSuivant()
{
	
	if (this->getMois() >= 12) 
	{
		this->setMois(this->getMois() + 1);
		this->anneeSuivante();
	}
	else
	{
		this->setMois(this->getMois() + 1);
	}

	
}

void Date::anneeSuivante()
{
	this->setAnnnee(this->getAnnee() + 1);
}
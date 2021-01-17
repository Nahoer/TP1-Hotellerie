// TP1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "Date.h"
#include "Appcontroler.h"
#include <iostream>
#include <fstream>
#include "hotel.h"
#include "Client.h"
#include "Reservation.h"


using namespace hotellerie;
using namespace std;

int main()
{
	/*
	//Test de la classe Client
	cout << "Test de la classe Client" << endl;
	Client c1 = Client(1, "Prunot", "Clement");
	Client c2 = Client(1, "Math", "Hugo");
	cout << c1 << endl;
	cout << c2 << endl;
	c1.setNom("Dupont");
	c1.setPrenom("Bernard");
	cout << c1 << endl;
	cout << c2 << endl;
	cout << endl;
	cout << endl;
	

	//Test de la classe Chambre
	cout << "Test de la classe Chambre" << endl;
	Chambre ch1 = Chambre(1, Single, 90);
	Chambre ch2 = Chambre(2, Suite, 200);
	cout << ch1 << endl;
	cout << ch2 << endl;
	ch1.setPrix(1000);
	ch1.setType(Double);
	cout << ch1 << endl;
	cout << ch2 << endl;
	cout << endl;
	cout << endl;

	//Test de la classe Hotel
	cout << "Test de la classe Hotel" << endl;
	Hotel h1 = Hotel(1, "La Cloche", "Dijon");
	Hotel h2 = Hotel(1, "Palym", "Paris");
	h1.addChambre(ch1);
	h1.addChambre(ch2);
	h2.addChambre(ch2);
	cout << h1 << endl;
	cout << h2 << endl;
	h1.setNom("Ibis");
	h2.setVille("Bordeaux");
	cout << h1 << endl;
	cout << h2 << endl;
	cout << endl;
	cout << endl;

	//Test de la classe Reservation
	cout << "Test de la classe Reservation" << endl;
	Reservation r1 = Reservation(1, Date(19, 11, 2020), Date(25, 11, 2020), h1, ch1, c1);
	cout << r1.toString() << endl;
	cout << endl;
	r1.setDateDebut(Date(26, 11, 2020));
	r1.setDateFin(Date(30, 11, 2020));
	r1.setChambre(ch2);
	cout << r1.toString() << endl;
	cout << endl;
	cout << endl;
	*/


	Appcontroler controler = Appcontroler();

	/*
	for (int i = 0; i < controler.getApp().getClients().size(); i++)
	{
		cout << controler.getApp().getClients()[i] << endl;
	}
	*/

	
	for (int i = 0; i < controler.getApp().getHotels().size(); i++)
	{
		cout << controler.getApp().getHotels()[i] << endl;
	}
	/*
	for (int i = 0; i < controler.getApp().getReservations().size(); i++)
	{
		cout << controler.getApp().getReservations()[i].toString() << endl;
	}
	*/
	




	

}



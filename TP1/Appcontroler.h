#pragma once

#include "Serialization.h"

class Appcontroler {
public:
	Appcontroler();
	App getApp() const;
	void actualize();
	void addHotel(Hotel h);
	void addClient(Client c);
	void addChambre(Chambre c);
	void addReservation(Reservation r);
private:
	App _app;
	Serialization _serial;
};
#pragma once

#include "Serialization.h"

class Appcontroler {
public:
	Appcontroler();
	App getApp() const;
	void actualize();
private:
	App _app;
	Serialization _serial;
};
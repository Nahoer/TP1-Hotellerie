#pragma once
#include <string>

using namespace std;

class Date {
public:
	Date(int year, int month, int day);
	Date() = default;
	~Date();
	int year() const;
	int month() const;
	int day() const;
	bool checkDate(int year, int month, int day);
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void nextDay();
	std::string toString() const;

	int ecartJour(Date d) const;


	string toStringShortFormat();

	string toStringFullFormat();



private :
	int _year;
	int _month;
	int _day;
};

bool operator == (const Date& d1, const Date& d2); // comparison operators
bool operator != (const Date& d1, const Date& d2);
bool operator < (const Date& d1, const Date& d2);
bool operator > (const Date& d1, const Date& d2);
bool operator <= (const Date& d1, const Date& d2);
bool operator >= (const Date& d1, const Date& d2);
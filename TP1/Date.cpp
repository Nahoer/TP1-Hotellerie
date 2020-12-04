#include "Date.h"
#include <iostream>
#include <cassert>


bool Date::checkDate(int day, int month, int year) {
	if (year < 0) {
		return false;
	}
	if ((month < 1) || (month > 12)) {
		return false;
	}
	if ((day < 1) || (day > 31)) {
		return false;
	}
	if ((month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12) && (day > 31)) {
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& (day > 30)) {
		return false;
	}
	if ((month == 2) && (day > 29)) {
		return false;
	}
	if ((month == 2) && (day == 29)) {
		if ((year % 4) || ((year % 100 == 0) && (year % 400))) {
			return false;
		}
	}
	return true;
}



Date::Date(int day, int month, int year) {
	bool status = checkDate(day, month, year);
	assert(status == true && "Date is not valid");
	_year = year;
	_month = month;
	_day = day;
	//std::cout << "Constructor: " << _year << "/" << _month << "/" << _day << '\n';
}

Date::~Date() {
	//std::cout << "  Destructor: " << _year << "/" << _month << "/" << _day << '\n';
}

int Date::year() const {
	return _year;
}
int Date::month() const {
	return _month;
}

int Date::day() const {
	return _day;
}

std::string Date::toString() const {
	std::string month[12] = { "Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };
	std::string to_display;
	to_display = std::to_string(_year) + "/" + month[_month - 1] + "/" + std::to_string(_day);
	return to_display;
}

void Date::setYear(int year) {
	assert(year >= 0 && "Year must be positive");
	_year = year;
}

void Date::setMonth(int month) {
	assert((month >= 1) && (month <= 12) && "Month must be between 1 and 121");
	_month = month;
}

void Date::setDay(int day) {
	bool status = checkDate(_year, _month, day);
	assert(status == true && "Day is not valid");
	_day = day;
}

void Date::nextDay() {
	bool status = checkDate(_day + 1, _month, _year);
	if (!status) {
		status = checkDate(1, _month + 1, _year);
		if (!status) {
			_year++;
			_month = 1;
			_day = 1;
		}
		else {
			_month++;
			_day = 1;
		}
	}
	else {
		_day += 1;
	}
}

int Date::ecartJour(Date d) const
{
	int ecart = 0;
	if (*this>d) 
	{
		ecart = d.ecartJour(*this);
	}
	else 
	{
		Date d2 = Date(*this);
		while (d!=d2)
		{
			d2.nextDay();
			ecart++;
		}
	}
	return ecart;
}



string Date::toStringShortFormat()
{
	string date = "";	
	date += to_string(this->day()) + "/";
	date += to_string(this->month()) + "/";
	date += to_string(this->year());
	return date;
}

string Date::toStringFullFormat()
{
	return "";
}

bool operator == (const Date& d1, const Date& d2) { // check for equality
	if ((d1.day() == d2.day()) && (d1.month() == d2.month()) && (d1.year() == d2.year())) {
		return true;
	}
	return false;
}

bool operator !=(const Date& d1, const Date& d2) {
	return !(d1 == d2);
}

bool operator < (const Date& d1, const Date& d2) {
	if (d1.year() < d2.year()) {
		return true;
	}
	else if (d1.year() > d2.year()) {
		return false;
	}
	else { // same year
		if (d1.month() < d2.month()) {
			return true;
		}
		else if (d1.month() > d2.month()) {
			return false;
		}
		else { // same month
			if (d1.day() < d2.day()) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}


bool operator > (const Date& d1, const Date& d2) {
	if (d1 == d2) {
		return false;
	}
	if (d1 < d2) {
		return false;
	}
	return true;
}

bool operator <=(const Date& d1, const Date& d2) {
	if (d1 == d2) {
		return true;
	}
	return (d1 < d2);
}

bool operator >=(const Date& d1, const Date& d2) {
	if (d1 == d2) {
		return true;
	}
	return (d1 > d2);
}

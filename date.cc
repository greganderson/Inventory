#include <string>
#include <sstream>
#include "date.h"


date::date(int _month, int _day, int _year) {
	this->month = _month;
	this->day = _day;
	this->year = _year;
}

std::string date::getDate() {
	std::ostringstream convert;
	convert << month;
	std::string sMonth = convert.str();
	convert.str("");

	convert << day;
	std::string sDay = convert.str();
	convert.str("");

	convert << year;
	std::string sYear = convert.str();


	return sMonth + "/" + sDay + "/" + sYear;
}

bool date::isEarlier(const date & d) const {
	if (this->year < d->year)
		return true;
	if (year == d->year) {
		if (month < d->month)
			return true;
		if (month == d->month) {
			if (day < d->day)
				return true;
			return false;
		}
		return false;
	}
	return false;
}

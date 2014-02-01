#include <string>
#include <sstream>
#include "date.h"

using namespace std;

/*
 * Creates a new date.
 */
date::date(int _month, int _day, int _year) {
	this->month = _month;
	this->day = _day;
	this->year = _year;
}

/*
 * Creates a new date out of the string.  Assumes it is formatted correctly.
 */
date::date(string d) {
	// TODO: Implement
}

/*
 * Returns the date as mm/dd/yyyy
 */
string date::getDate() {
	// Convert ints to strings
	ostringstream convert;
	convert << month;
	string sMonth = convert.str();
	convert.str("");

	convert << day;
	string sDay = convert.str();
	convert.str("");

	convert << year;
	string sYear = convert.str();


	return sMonth + "/" + sDay + "/" + sYear;
}

/*
 * Returns true if this date is earlier than d.
 */
bool date::isEarlier(const date & d) const {
	if (this->year < d.year)
		return true;
	if (year == d.year) {
		if (month < d.month)
			return true;
		if (month == d.month) {
			if (day < d.day)
				return true;
			return false;
		}
		return false;
	}
	return false;
}

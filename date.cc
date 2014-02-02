/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <iostream>
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
date::date(string s) {
	string m = s.substr(0,2);
	string d = s.substr(3,2);
	string y = s.substr(6,4);

	this->month = (m[0] - '0') * 10 + (m[1] - '0') * 1;
	this->day = (d[0] - '0') * 10 + (d[1] - '0') * 1;
	this->year = (y[0] - '0') * 1000 + (y[1] - '0') * 100 + (y[2] - '0') * 10 + (y[3] - '0') * 1;
}

/*
 * Returns the date as mm/dd/yyyy
 */
string date::getDate() {
	// Convert ints to strings
	ostringstream convert;
	convert << month;
	string sMonth = convert.str();
	if (sMonth.length() == 1)
		sMonth.insert(0, "0");
	convert.str("");

	convert << day;
	string sDay = convert.str();
	if (sDay.length() == 1)
		sDay.insert(0, "0");
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

/*
 * Advances the date by one day.
 */
void date::advanceDate() {
	switch (month) {
		case 1:
			advanceDay(31);
			break;
		case 2:
			// Check for leap year
			if (year == 2004 || year == 2008 || year == 2012)
				advanceDay(29);
			else
				advanceDay(28);
			break;
		case 3:
			advanceDay(31);
			break;
		case 4:
			advanceDay(30);
			break;
		case 5:
			advanceDay(31);
			break;
		case 6:
			advanceDay(30);
			break;
		case 7:
			advanceDay(31);
			break;
		case 8:
			advanceDay(31);
			break;
		case 9:
			advanceDay(30);
			break;
		case 10:
			advanceDay(31);
			break;
		case 11:
			advanceDay(30);
			break;
		case 12:
			advanceDay(31);
			break;
	}
}

/*
 * Advances the day, where the number of days in the month are passed in.
 * If day is greater than the number of days in the month, then it resets
 * to 1 and the month is incremented.
 */
void date::advanceDay(int days) {
	day++;
	if (day > days) {
		day = 1;
		advanceMonth();
	}
}

/*
 * Advances the month, moving from December to January if needed.
 */
void date::advanceMonth() {
	month++;
	if (month == 13) {
		month = 1;
		year++;
	}
}

void date::changeDate(string s) {
	string m = s.substr(0,2);
	string d = s.substr(3,2);
	string y = s.substr(6,4);

	this->month = (m[0] - '0') * 10 + (m[1] - '0') * 1;
	this->day = (d[0] - '0') * 10 + (d[1] - '0') * 1;
	this->year = (y[0] - '0') * 1000 + (y[1] - '0') * 100 + (y[2] - '0') * 10 + (y[3] - '0') * 1;
}

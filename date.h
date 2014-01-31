#include <string>

#ifndef DATE_H
#define DATE_H

class date {
	public:
		date(int month, int day, int year);
		std::string getDate();
		bool isEarlier(const date &) const;
	private:
		int month;
		int day;
		int year;
};
#endif

#include <string>

#ifndef DATE_H
#define DATE_H

class date {
	public:
		date(int month, int day, int year);
		date(std::string);
		std::string getDate();
		bool isEarlier(const date &) const;
		void advanceDate();
		void advanceDay(int);
		void advanceMonth();
	private:
		int month;
		int day;
		int year;
};
#endif

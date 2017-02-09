#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <iomanip>
#include <regex>
#include <sstream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

using namespace std;

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	if(day > daysPerMonth[month-1]) { //Next month
		day = 1;
		if(month == 12) //Next year
			year++;
		month = month % 12 + 1; //1->2, ..., 10 -> 11, 12->1
	}
}

ostream& operator<<(ostream& out, const Date& d) {
	out << setw(4) << setfill('0') << d.getYear() << '-';
	out << setw(2) << setfill('0') << d.getMonth() << '-';
	out << setw(2) << setfill('0') << d.getDay();
	return out;
}

//Correct format is yyyy-mm-dd
istream& operator>>(istream& in, Date& d) {
	//Read line
	string line;
	in >> line;

	//Check for wrong format
	regex date_format("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	if(!regex_match(line, date_format)) {
		in.setstate(ios_base::failbit);
	} else { //Read year, month, day
		line = regex_replace(line, regex("-"), " ");
		istringstream iss(line);
		int year, month, day;
		iss >> year >> month >> day;
		if(month < 1 || month > 12 || day > Date::daysPerMonth[month-1])
			in.setstate(ios_base::failbit);
		d.year = year;
		d.month = month;
		d.day = day;
	}
	return in;
}

#include <ctime>  // time and localtime
#include <sstream>
#include <iostream>
#include <regex>
#include "date.h"

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
	++day;
	if (day > daysPerMonth[month-1]) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
}

ostream& operator<<(ostream& out, const Date& d) {
	out << d.getYear() << "-";
	if (d.getMonth() < 10) {
		out << "0";
	}
	out << d.getMonth() << "-";
	if (d.getDay() < 10) {
		out << "0";
	}
	out << d.getDay();
	return out;
}

istream& operator>>(istream& in, Date& d) {
	string line;
	in >> line;

	regex date_format("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	if(!regex_match(line, date_format)) {
		in.setstate(ios_base::failbit);
	}
	else {
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

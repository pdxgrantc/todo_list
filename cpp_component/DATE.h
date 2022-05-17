#pragma once
#include <ctime>

class DATE
{
protected:
	int day, month, year;
public:
	DATE();
	DATE(int day, int month, int year);
	int get_day();
	int get_month();
	int get_year();
	void set_current_date();
};


#include <iostream>
#include <string>
#include "UTILITIES.h"

using namespace std;

bool is_number(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]) == false) {
            return false;
        }
    }
    return true;
}

DATE get_due_date_user() {
	int day, month, year;
	string cache;
	while (true) {
		cout << "Please enter a day between 1 - 31: ";
		getline(cin, cache);
		if ((is_number(cache)) && (stoi(cache) > 0) && (stoi(cache) < 32)) {
			day = stoi(cache);
			break;
		}
		else {
			cout << "Invalid input. ";
		}
	}
	while (true) {
		cout << "Please enter a month between 1 - 12: ";
		getline(cin, cache);
		if ((is_number(cache)) && (stoi(cache) > 0) && (stoi(cache) < 13)) {
			month = stoi(cache);
			break;
		}
		else {
			cout << "Invalid input. ";
		}
	}
	while (true) {
		cout << "Please enter a year greater than 1970: ";
		getline(cin, cache);
		if ((is_number(cache)) && (stoi(cache) > 1970)) {
			year = stoi(cache);
			break;
		}
		else {
			cout << "Invalid input. ";
		}
	}
	DATE due_date = DATE(day, month, year);
	return due_date;
}
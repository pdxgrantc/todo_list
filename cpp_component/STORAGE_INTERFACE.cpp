#include <iostream>
#include <string>
#include <vector>
#include "STORAGE_INTERFACE.h"
#include "DATE.h"
#include "UTILITIES.h"

using namespace std;

void print_month(int);
DATE get_due_date_user();

void STORAGE_INTERFACE::test(int test_val) {
	DATE creation_date = DATE();
	TODO_ITEM new_item = TODO_ITEM();
	if (test_val == 0) {
		new_item.create_item("Grant0", creation_date, creation_date, "Information0");
	}
	else if (test_val == 1) {
		new_item.create_item("Grant1", creation_date, creation_date, "Information1");
	}
	else if (test_val == 2) {
		new_item.create_item("Grant2", creation_date, creation_date, "Information2");
	}
	else if (test_val == 3) {
		new_item.create_item("Grant3", creation_date, creation_date, "Information3");
	}

	todo_items.push_back(new_item);
}

size_t STORAGE_INTERFACE::get_num_items() {
	size_t value = todo_items.size();
	return value;
}

void STORAGE_INTERFACE::change_title(int index, string title) {
	todo_items[index].set_title(title);
}

void STORAGE_INTERFACE::change_due_date(int index, DATE new_due_date)
{
	todo_items[index].set_due_date(new_due_date);
}

void STORAGE_INTERFACE::change_description(int index, string description) {
	todo_items[index].set_description(description);
}

void STORAGE_INTERFACE::remove(int index) {
	todo_items.erase(todo_items.begin() + index);
}

void STORAGE_INTERFACE::mark_complete(int index) {
	todo_items[index].mark_complete();
}

void STORAGE_INTERFACE::create_new_todo_item() {
	TODO_ITEM new_item = TODO_ITEM();
	DATE creation_date = DATE();
	DATE due_date = get_due_date_user();
	string name, information;
	cout << "Please enter a name for your todo item: ";
	getline(cin, name);
	cout << "Please enter a description for your todo item: ";
	getline(cin, information);
	new_item.create_item(name, creation_date, due_date, information);
	todo_items.push_back(new_item);
}

void STORAGE_INTERFACE::print_list() {
	cout << "Here are your todo tasks:" << endl << endl;
	int counter = 0;
	for (TODO_ITEM& item : todo_items) {
		counter++;
		cout << "Task " << counter << ":" << endl;
		int int_cache;
		string str_cache, str_cachet;
		DATE date_cache;
		bool bool_cache;
		str_cache = item.get_title();
		cout << "Title: " << "\t\t";
		cout << str_cache << endl;
		date_cache = item.get_creation_date();
		cout << "Created on: " << '\t';
		int_cache = date_cache.get_month();
		print_month(int_cache);
		str_cache = to_string(date_cache.get_day());
		cout << " " << str_cache << ", ";
		str_cache = to_string(date_cache.get_year());
		cout << str_cache << endl;
		date_cache = item.get_due_date();
		cout << "Due date: " << '\t';
		print_month(int_cache);
		str_cache = to_string(date_cache.get_day());
		cout << " " << str_cache << ", ";
		str_cache = to_string(date_cache.get_year());
		cout << str_cache << endl;
		str_cachet = item.get_information();
		cout << "Description: " << '\t';
		cout << str_cachet << endl;
		bool_cache = item.get_complete();
		cout << "Status: " << '\t';
		switch (bool_cache)
		{
		case true:
			cout << "Complete" << endl;
			break;
		case false:
			cout << "Incomplete" << endl;
			break;
		}
		cout << endl;
	}
}

void STORAGE_INTERFACE::print_list_item(int index) {
	TODO_ITEM item = todo_items[index];
	cout << "Task " << (index + 1) << ":" << endl;
	int int_cache;
	string str_cache, str_cachet;
	DATE date_cache;
	bool bool_cache;
	str_cache = item.get_title();
	cout << "Title: " << "\t\t";
	cout << str_cache << endl;
	date_cache = item.get_creation_date();
	cout << "Created on: " << '\t';
	int_cache = date_cache.get_month();
	print_month(int_cache);
	str_cache = to_string(date_cache.get_day());
	cout << " " << str_cache << ", ";
	str_cache = to_string(date_cache.get_year());
	cout << str_cache << endl;
	date_cache = item.get_due_date();
	cout << "Due date: " << '\t';
	print_month(int_cache);
	str_cache = to_string(date_cache.get_day());
	cout << " " << str_cache << ", ";
	str_cache = to_string(date_cache.get_year());
	cout << str_cache << endl;
	str_cachet = item.get_information();
	cout << "Description: " << '\t';
	cout << str_cachet << endl;
	bool_cache = item.get_complete();
	cout << "Status: " << '\t';
	switch (bool_cache)
	{
	case true:
		cout << "Complete" << endl;
		break;
	case false:
		cout << "Incomplete" << endl;
		break;
	}
	cout << endl;
}

void print_month(int month) {
	switch (month)
	{
	case 1:
		cout << "Jauary";
		break;
	case 2:
		cout << "February";
		break;
	case 3:
		cout << "March";
		break;
	case 4:
		cout << "April";
		break;
	case 5:
		cout << "May";
		break;
	case 6:
		cout << "June";
		break;
	case 7:
		cout << "July";
		break;
	case 8:
		cout << "August";
		break;
	case 9:
		cout << "September";
		break;
	case 10:
		cout << "October";
		break;
	case 11:
		cout << "November";
		break;
	case 12:
		cout << "December";
		break;
	default:
		break;
	}
}

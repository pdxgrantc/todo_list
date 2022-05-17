#include "TODO_ITEM.h"
#include "DATE.h"
#include <string>
#include <iostream>

TODO_ITEM::TODO_ITEM() {
	complete = false;
}

void TODO_ITEM::create_item(std::string new_title, DATE new_creation_date, DATE new_due_date, std::string new_information) {
	title = new_title;
	creation_date = new_creation_date;
	due_date = new_due_date;
	information = new_information;
	title = new_title;
	complete = false;
}

void TODO_ITEM::mark_complete() {
	complete = true;
}

std::string TODO_ITEM::get_title() {
	return title;
}

DATE TODO_ITEM::get_creation_date() {
	return creation_date;
}

DATE TODO_ITEM::get_due_date() {
	return due_date;
}

std::string TODO_ITEM::get_information() {
	return information;
}

bool TODO_ITEM::get_complete() {
	return complete;
}

void TODO_ITEM::set_title(std::string new_title) {
	title = new_title;
}

void TODO_ITEM::set_due_date(DATE new_date) {
	due_date = new_date;
}

void TODO_ITEM::set_description(std::string new_description) {
	information = new_description;
}

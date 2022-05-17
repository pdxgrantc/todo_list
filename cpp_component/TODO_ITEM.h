#pragma once

#include "DATE.h"
#include <string>

class TODO_ITEM
{
protected:
	std::string title;
	DATE creation_date;
	DATE due_date;
	std::string information;
	bool complete;
public:
	TODO_ITEM();
	void create_item(std::string name, DATE creation_date, DATE due_date, std::string information);
	void mark_complete();
	std::string get_title();
	DATE get_creation_date();
	DATE get_due_date();
	std::string get_information();
	bool get_complete();
	void set_title(std::string);
	void set_due_date(DATE);
	void set_description(std::string);
};


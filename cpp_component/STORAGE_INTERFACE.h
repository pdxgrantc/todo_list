#pragma once

#include <vector>
#include <string>
#include "TODO_ITEM.h"
#include "DATE.h"

class STORAGE_INTERFACE
{
protected:
	std::vector<TODO_ITEM> todo_items;
	
public:
	void test(int);
	size_t get_num_items();
	void change_title(int, std::string);
	void change_due_date(int, DATE);
	void change_description(int, std::string);
	void remove(int);
	void mark_complete(int);
	void create_new_todo_item();
	void print_list();
	void print_list_item(int);
};


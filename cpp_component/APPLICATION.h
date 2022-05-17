#pragma once

#include <iostream>
#include <string>
#include "STORAGE_INTERFACE.h"

class APPLICATION
{
protected:
	STORAGE_INTERFACE* db;
public:
	APPLICATION();
	void edit_item_stage_two(int);
	void main_driver(int top_choice);
	void print_list();
	void create_new_todo();
	void edit_item();
	void mark_complete();
	void delete_item();
	void save_and_quit();
	void test_additions();
};


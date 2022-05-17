#include <iostream>
#include <string>
#include "STORAGE_INTERFACE.h"
#include "APPLICATION.h"
#include "UTILITIES.h"

STORAGE_INTERFACE* create_db();
void delete_ptrs(STORAGE_INTERFACE* db);
int take_top_choice_input();

APPLICATION::APPLICATION() {
	db = create_db();
    
    test_additions();
    
    while (true) {
        int top_choice = take_top_choice_input();
        main_driver(top_choice);
        if (top_choice == 6) {
            break;
        }
    }
    
    delete_ptrs(db);
}

void APPLICATION::test_additions() {
    db->test(0);
    db->test(1);
    db->test(2);
    db->test(3);
    db->print_list();
}

void APPLICATION::main_driver(int top_choice) {
    switch (top_choice)
    {
    case 1:
        print_list();
        break;
    case 2:
        create_new_todo();
        std::cout << std::endl;
        break;
    case 3:
        edit_item();
        break;
    case 4:
        mark_complete();
        break;
    case 5:
        delete_item();
        break;
    case 6:
        save_and_quit();
        break;
    default:
        break;
    }
}

void APPLICATION::print_list() {
    db->print_list();
}

void APPLICATION::create_new_todo() {
    std::string title, information;
    db->create_new_todo_item();
}

void APPLICATION::edit_item() {
    print_list();
    std::string cache;
    int index;
    while (true) {
        std::cout << "Which item number do you want to edit: ";
        getline(std::cin, cache);
        if (is_number(cache) && (stoi(cache) < (db->get_num_items() + 1)) && (stoi(cache) > 0)) {
            index = stoi(cache);
            break;
        }
        else {
            std::cout << "You didn't enter an index value in the list." << std::endl;
        }
    }
    index--;
    edit_item_stage_two(index);
    db->print_list_item(index);
}

void APPLICATION::edit_item_stage_two(int index) {
    std::cout << "Please choose an option below for whihc element you would like to edit:" << std::endl;
    std::cout << "1. Title" << std::endl;
    std::cout << "2. Due date" << std::endl;
    std::cout << "3. Description" << std::endl;
    std::cout << "Enter a number here: ";
    std::string str;
    int input;
    getline(std::cin, str);
    while (true) {
        if ((is_number(str)) && (stoi(str) > 0) && (stoi(str) < 4)) {
            input = stoi(str);
            break;
        }
        else {
            std::cout << "Please enter a integer relating to a list item." << std::endl;
        }
    }
    std::cout << std::endl;
    std::string cache;
    DATE new_due_date;
    switch (input)
    {
    case 1:
        std::cout << "Please enter a new title: ";
        getline(std::cin, cache);
        db->change_title(index, cache);
        break;
    case 2:
        new_due_date = get_due_date_user();
        db->change_due_date(index, new_due_date);
        break;
    case 3:
        std::cout << "Please enter a new description: ";
        getline(std::cin, cache);
        db->change_description(index, cache);
        break;
    default:
        break;
    }
    std::cout << std::endl;
}

void APPLICATION::mark_complete() {
    print_list();
    std::string cache;
    int index;
    while (true) {
        std::cout << "Which item number do you want to mark complete: ";
        getline(std::cin, cache);
        if (is_number(cache) && (stoi(cache) < (db->get_num_items() + 1)) && (stoi(cache) > 0)) {
            index = stoi(cache);
            break;
        }
        else {
            std::cout << "You didn't enter an index value in the list." << std::endl;
        }
    }
    index--;
    db->mark_complete(index);
}

void APPLICATION::delete_item() {
    print_list();
    std::string cache;
    int index;
    while (true) {
        std::cout << "Which item number do you want to delete: ";
        getline(std::cin, cache);
        if (is_number(cache) && (stoi(cache) < (db->get_num_items() + 1)) && (stoi(cache) > 0)) {
            index = stoi(cache);
            break;
        }
        else {
            std::cout << "You didn't enter an index value in the list." << std::endl;
        }
    }
    index--;
    db->remove(index);
}

void APPLICATION::save_and_quit() {
    // Needs to write to a file
}

int take_top_choice_input() {
    std::cout << "Please choose an option below:" << std::endl;
    std::cout << "1. Print TODO Items" << std::endl;
    std::cout << "2. Create new todo item" << std::endl;
    std::cout << "3. Edit item" << std::endl;
    std::cout << "4. Mark item complete" << std::endl;
    std::cout << "5. Delete an Item" << std::endl;
    std::cout << "6. Save and Quit" << std::endl;
    std::cout << "Enter a number here: ";
    std::string str;
    int input = 6;
    getline(std::cin, str);
    while (true) {
        if ((is_number(str)) && (stoi(str) > 0) && (stoi(str) < 7)) {
            input = stoi(str);
            break;
        }
        else {
            std::cout << "Please enter a integer relating to a list item." << std::endl;
        }
    }
    std::cout << std::endl;
    return input;
}

STORAGE_INTERFACE* create_db()
{
    STORAGE_INTERFACE *db = new STORAGE_INTERFACE;
    return db;
}

void delete_ptrs(STORAGE_INTERFACE* db) {
    delete db;
}
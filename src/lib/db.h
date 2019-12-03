#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include "contract.h"
#include "category.h"

struct DB {
    std::vector<Category> _categories;
    std::string _notifier_email = "";
};

auto  db_addCategory(DB db, Category item) -> void {
    // Check if category is already present.
    for (auto i : db._categories) {
        if (i == item) {
            throw std::runtime_error("Category already exists.");
        }
    }

    // Add the category.
    db._categories.push_back(item);
}

auto db_removeCategory(DB db, Category &item) -> void {
    // Search for the item to remove.
    for (int i = 0; i < db._categories.size(); i++) {
        if (db._categories[i] == item) {
            db._categories.erase(db._categories._contracts.begin()+i);
            break;
        }
    }
    throw std::runtime_error("Category to remove does not exist.");
}

#endif
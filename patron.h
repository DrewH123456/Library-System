/** The Patron class represents a library patron. Each patron has a unique
 * identifier, a name, and a list of books they have checked out. The Patron
 * can check out a book, return a book, and view their checkout history.
 **/
#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
using namespace std;

class Item;
class Action;

class Patron
{
private:
    int idNumber;
    string lastName;
    string firstName;
    unordered_map<Item *, int> checkedOutBooks;
    vector<Item *> history;

public:
    // Default constructor
    Patron(){};

    // Destructor
    ~Patron(){};

    // sets item's data using info from line in infile
    void setData(ifstream &inputFile);

    void setDataCommand(ifstream &inputFile);

    // Returns the unique identifier for the patron
    int getId() const;

    // Returns the last name of the patron
    string getLastName() const;

    // Returns the first name of the patron
    string getFirstName() const;

    // Adds a book to the list of books checked out by the patron
    void checkOutItem(Item *item);

    // Removes a book from the list of books checked out by the patron
    void returnBook(Item *item);

    // Displays the checkout history for the patron
    void viewHistory() const;

    // Displays patron's id and name
    void print() const;

    // Adds action and associated item to user's history
    void updateHistory(Action *addAction, Item *addItem);
};

#endif
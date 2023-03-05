/*
 * The ChildrenBook class represents a children book item in the library system.
 * It inherits from the Book class and includes additional data members specific
 * to children books, such as author and title
 */

#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H

// #include "item.h"
#include "book.h"
#include <string>
#include <iostream>
#include <fstream>

class ChildrenBook : public Book
{
protected:
    string authorName;
    string title;
    int year;

public:
    // Constructor
    ChildrenBook();

    // Destructor
    virtual ~ChildrenBook();

    // Counts available copies
    virtual int countAvailable() const;

    // Checks checked out count for given book
    virtual int countCheckedOut() const;

    // Checks out this book for a given user in a given library
    virtual void checkOut();

    // Returns this book for a given user in a given library
    virtual void returnItem();

    // Allows item factory to create a children book object
    virtual Item *create() const;

    // sets item's data using info from line in infile
    virtual void setData(ifstream &inputFile);

    // prints book's description
    virtual void print(ostream &out) const;

    // Overloaded output operator
    // virtual ostream &operator<<(ostream &output, const Item &item) const;

    // Overloaded comparison operators
    virtual bool operator<(const Item &other) const;
    virtual bool operator>(const Item &other) const;
    virtual bool operator>=(const Item &other) const;
    virtual bool operator<=(const Item &other) const;
    virtual bool operator==(const Item &other) const;
    virtual bool operator!=(const Item &other) const;
};

#endif
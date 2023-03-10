/** The Patron class represents a library patron. Each patron has a unique
 * identifier, a name, and a list of books they have checked out. The Patron
 * can check out a book, return a book, and view their checkout history.
 **/

#include "patron.h"
#include "item.h"

void Patron::setData(ifstream &inputFile)
{
    string dummy; // used in final getLine to move inputFile to next line

    inputFile >> idNumber;
    inputFile >> lastName;
    inputFile >> firstName;
    getline(inputFile, dummy, '\n');
}

void Patron::setDataCommand(ifstream &inputFile)
{
    inputFile >> idNumber;
}

int Patron::getId() const
{
    return idNumber;
}

string Patron::getLastName() const
{
    return lastName;
}

string Patron::getFirstName() const
{
    return firstName;
}

void Patron::print() const
{
    cout << idNumber << ": " << lastName << ", " << firstName << endl;
}

void Patron::displayItems() const
{
    for (int i = 0; i < history.size(); i++)
    {
        checkedOutItems[i]->individualPrint();
    }
}

// item added to patron's checkedOutItems collection
void Patron::checkOutItem(Item *addItem)
{
    checkedOutItems.push_back(addItem);
}

void Patron::updateHistory(Action *addAction)
{
    history.push_back(addAction);
}
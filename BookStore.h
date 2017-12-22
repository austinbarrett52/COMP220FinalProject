
#pragma once

#ifndef BookStore_h
#define BookStore_h

#include "Book.h"
#include "LinkedList.h"


class BookStore {

private:

    Book* book;

    //user input choice
    int choice;

    int numBooks;


public:
    std::string name;


    //Makes up the bulk of program
    //All user interaction is done here
    //Reloads inventory, presents welcome message, prompts user, takes inputs, and makes appropriate action
    //while loop runs as long as user does not input 10 to end program
    BookStore();

    //Called upon at the start of the program and whenever the user enters 1
    //Does not do anything except print the 10 options that the user has within the virtual bookstore
    void printCommands ();


    //adds a line to the end of the text file
    //takes parameters of text file and the line to add to that text file
    //no return value
    void appendLineToFile(std::string filepath, std::string line);


    //Called upon at the start of the program before user has ability to do anything
    //Takes LinkedList pointer as parameter with no return
    //Reads in information of text files bookStore.txt for inventory and waitingLists.txt for individuals waiting
    //waiting for a book
    //Will catch any invalid integer values for haveValue and wantValue
    void restartInventory(LinkedList* myBookstore);


        //Deletes the object instances, as all are pointers
    ~BookStore();
};

#endif
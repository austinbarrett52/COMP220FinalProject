//
// Created by Brendan King on 12/7/17.
//

#ifndef FINALPROJECT_LIST_H
#define FINALPROJECT_LIST_H

#include <stdexcept>
#include <string>

class List {

public:

    virtual ~List(){};

    /**
     * Displays all information for a specified title
     * @param Title of book of information you want
     */
    virtual std::string getBook(std::string bookTitle)=0;

    /**
     * List all information for the entire inventory in alphabetical order by title
     */
    virtual std::string getAllBooks()=0;

    /**
     * Add a book to the inventory in  alphabetical order
     * If book already exists, display info for that title
     * @param new Book title, have value and want value
     * @post new book in inventory
     */
    virtual void addBook(std::string bookTitle, int haveValue, int wantValue, WaitList* waitList)=0;

    /**
     * Modifies the want value for specified title
     * @param book title and new want value
     * @post want value is changed
     */
    virtual void updateBook(std::string bookTitle, int newWantValue)=0;

    /**
     * descreases the count for a specified title by 1
     * If title does not exist, it should be added
     * If title is have value is 0, prompt for user info and add to wait list
     * @param book title
     * @post have value is 1 less
     */
    virtual std::string sellBook(std::string bookTitle)=0;

};


#endif //FINALPROJECT_LIST_H

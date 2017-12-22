//
// Created by Brendan King on 11/30/17.
//

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>
#include "WaitList.h"

class Book {

private:

    Book* next;
    std::string title;
    int haveValue;
    int wantValue;
    WaitList* waitList;

public:

    /**
     *
     * @param title string title of the book
     * @param haveValue integer value of how many books are in stock
     * @param wantValue integer value of how many people want that book
     * @param waitListIn pointer to a queue of people that want the book
     */
    Book(std::string title, int haveValue, int wantValue, WaitList* waitListIn);

    /** Copy Constructor
     *
     * @param bookToCopy
     */
    Book(const Book& bookToCopy);

    /** Simple accessing method
     *
     * @return title of book
     */
    std::string getTitle();

    /** Simple setting method
     *
     * @param newTitle the new title of the book
     */
    void setTitle(std::string newTitle);

    /** Simple accessing method
     *
     * @return the amount of copies of the book that are in the inventory
     */
    int getHaveValue();

    /** Simple setting method
     *
     * @param newHaveValue the number of people that want the book
     */
    void setHaveValue(int newHaveValue);

    /** Simple accessing method
     *
     * @return the number of people that want the book
     */
    int getWantValue();

    /** Simple setting method
     *
     * @param newWantValue the new amount of people that want the book
     */
    void setWantValue(int newWantValue);

    /** Simple accessing method
     *
     * @return the pointer to the book that is next in the linkedList
     */
    Book* getNext();

    /** Simple setting method
     *
     * @param newNext the pointer to the book that is next in the linkedList
     */
    void setNext(Book* newNext);

    /** Simple accessing method
     *
     * @return the pointer to the queue of people that want the book
     */
    WaitList* getWaitlist();

};

#endif //FINALPROJECT_BOOK_H



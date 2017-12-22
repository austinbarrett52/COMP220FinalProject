#ifndef FINALPROJECT_LINKEDLIST_H
#define FINALPROJECT_LINKEDLIST_H

#include "Book.h"
#include "List.h"
#include <string>


class LinkedList : public List {

private:

    Book* front = nullptr;
    Book* end = nullptr;

public:

    //creates empty list
    LinkedList();

    //destructor
    ~LinkedList();

    //copy constructor
    LinkedList(const LinkedList& LinkedListToCopy);

    //assignment operator
    LinkedList& operator=(const LinkedList LinkedListToCopy);

/**
     * Displays all information for a specified title
     * @param Title of book of information you want
     */
    std::string getBook(std::string bookTitle);

    /**
     * List all information for the entire inventory in alphabetical order by title
     */
    std::string getAllBooks();

    /**
     * Add a book to the inventory in  alphabetical order
     * If book already exists, display info for that title
     * @param new Book title, have value and want value
     * @post new book in inventory
     */
    void addBook(std::string bookTitle, int haveValue, int wantValue, WaitList* waitList);

    /**
     * Modifies the want value for specified title
     * @param book title and new want value
     * @post want value is changed
     */
    void updateBook(std::string bookTitle, int newWantValue);

    /**
     * decreases the count for a specified title by 1
     * If title does not exist, it should be added
     * If title is have value is 0, prompt for user info and add to wait list
     * @param book title
     * @post have value is 1 less
     */
    std::string sellBook(std::string bookTitle);

    /**
     * Adds a new person to the waitlist of a book that has 0 books in have value
     * @param book title, name, phone number, email and contact preference
     */
    void addToWaitList(std::string bookTitle, std::string name, int phoneNumber, std::string email, std::string contact);

    /**
     * checks to see if a book already exists in the inventory
     * @param book title
     */
    bool doesExist(std::string bookTitle);

    /**
     * returns have value
     * @param book title
     */
    int getHave(std::string bookTitle);

    /**
     * returns want value
     * @param book title
     */
    int getWant(std::string bookTitle);

    /**
     * sets a new have value
     * @param book title and new have value
     * @post have value is changed
     */
    void setHave(std::string bookTitle, int newHave);

    /**
     * Modifies the want value for specified title
     * @param book title and new want value
     * @post want value is changed
     */
    void setWant(std::string bookTitle, int newWant);

    /**
     * finds out which books have have values lower than their want values and adds those books to a text file
     * with the amount of books it needs to be equal to want value
     * @post all have values equal their want value
     */
    std::string orderMore();

    /**
     * finds the books whose have value is bigger than their want value and returns those books
     * @post all have values equal to their want value
     */
    std::string returnBooks();

    /**
     * updates have value and puts books on hold for people in the wait list for each book
     * @param book title and new have value
     */
    std::string updateHaveValue(std::string title, int haveValue);

    /**
     * counts the amount of books that have a have value less than their want value
     * @post returns the amount
     */
    int totalHaveLessThanWant();

};


#endif //FinalProject_LINKEDLIST_H
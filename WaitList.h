
#ifndef FINALPROJECT_WAITLIST_H
#define FINALPROJECT_WAITLIST_H

#include <string>
#include "Person.h"

class WaitList {

private:

    Person* front;
    Person* end;

public:


    /**
     * Creates an empty queue
     */
    WaitList();

    /**
     * Creates an empty queue
     */
    WaitList(const WaitList& queueToCopy);

    /**
     * Destructor
     */
    ~WaitList();

    /**
     * adds a Person to the end of the queue
     * @param name, phone number, email, contact preference
     * @post new book in inventory
     */
    void enqueue(std::string name, int phoneNumber, std::string email, std::string contact);

    /**
     * takes an Person off the front of the queue and returns it's info
     * throws out_of_range exception if the queue is empty
     * @param name, phone number, email, contact preference
     * @post new book in inventory
     */
    std::string dequeue();

    /**
     * returns true if the queue has no items, false otherwise
     * @param name, phone number, email, contact preference
     * @post new book in inventory
     */
    bool isEmpty();

    /**
     * returns pointer to front Person in Queue
     */
    Person* getPerson();
};


#endif //FINALPROJECT_WAITLIST_H

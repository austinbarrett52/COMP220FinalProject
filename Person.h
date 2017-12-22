
//
// Created by Brendan King on 12/6/17.
//

#ifndef FINALPROJECT_PERSON_H
#define FINALPROJECT_PERSON_H

#include <string>

class Person {

private:

    std::string name;
    int phoneNumber;
    std::string email;
    std::string contact;
    Person* next;

public:

    /** A Person object represents a node within the waitingList Queues
    *
    * @param nameIn Name of person
    * @param phoneNumberIn person's phone number
    * @param emailIn person's email address
    * @param contactIn what type of contact is preferred
    */
    Person(std::string name, int phoneNumber, std::string email, std::string contact);

    /**Copy constructor
     *
     * @param personToCopy
     */
    Person(const Person& personToCopy);

    /** Simple accessing method
     *
     * @return name of person
     */
    std::string getName();

    /** Simple accessing method
     *
     * @return phone number of person
     */
    int getPhoneNumber();

    /** Simple accessing method
     *
     * @return email address of person
     */
    std::string getEmail();

    /** Simple accessing method
     *
     * @return the string name of the person's preference
     */
    std::string getContact();

    /** Simple accessing method
     *
     * @param newContact the name of the person
     */
    void setContact(std::string newContact);

    /** Simple setting method
     *
     * @return the pointer to the next person within the queue
     */
    Person* getNext();

    /** Simple setting method
     *
     * @param newNext the pointer to the person in which you are setting the next person
     */
    void setNext(Person* newNext);



};


#endif //FINALPROJECT_PERSON_H


#include "LinkedList.h"
#include "WaitList.h"
#include "Person.h"
#include <iostream>
#include <string>


LinkedList::LinkedList() {
    front = nullptr;
    end = nullptr;
}

LinkedList::~LinkedList() {

    while (front != nullptr){
        Book* toDelete = end;
        front = front->getNext();
        delete toDelete;
    }
}

LinkedList::LinkedList(const LinkedList& LinkedListToCopy){
    front = LinkedListToCopy.front;
    end = LinkedListToCopy.end;

}

//assignment operator
LinkedList& LinkedList::operator=(const LinkedList LinkedListToCopy){
    if (this != &LinkedListToCopy) {
        front = LinkedListToCopy.front;
        end = LinkedListToCopy.end;
    }
    return *this;

}

bool LinkedList::doesExist(std::string bookTitle) {

    if (front == nullptr) {
        return false;
    }

    Book* temp = front;

    while (bookTitle != temp->getTitle()){

        if (temp == nullptr) {
            return false;
        }
        temp = temp->getNext();
    }
    return true;
}

std::string LinkedList::getBook(std::string bookTitle) {

    if (front == nullptr){
        return "Book Not Found";
    }

    Book* temp = front;

    std::string s;

    while (bookTitle != temp->getTitle()){

        if (temp == nullptr){

            return "Book Not Found";
        }
        temp = temp->getNext();
    }

    s = "Book: " + temp->getTitle() + "\n" + "Have Value: " + std::to_string(temp->getHaveValue()) + "\n" + "Want Value: " + std::to_string(temp->getWantValue()) + "\n";
    return s;
}

std::string LinkedList::getAllBooks() {

    std::string s;

    Book* temp = front;

    while (temp != nullptr){

        s += getBook(temp->getTitle());
        s += "\n";
        temp = temp->getNext();
    }
    return s;
}

void LinkedList::addBook(std::string bookTitle, int haveValue, int wantValue, WaitList* waitList) {

    Book* temp = front;

    if (temp == nullptr) {

        Book* newBook = new Book(bookTitle, haveValue, wantValue, waitList);

        front = newBook;
        end = newBook;
    }
    else {

        Book* newBook = new Book(bookTitle, haveValue, wantValue, waitList);
        end->setNext(newBook);
        end = newBook;

    }
}

void LinkedList::updateBook(std::string bookTitle, int newWantValue){

    Book* temp = front;

    while (bookTitle != temp->getTitle())
    {
        if (temp == nullptr){
            return;
        }
        temp = temp->getNext();
    }
    temp->setWantValue(newWantValue);
}

std::string LinkedList::sellBook(std::string bookTitle){

    Book* temp = front;

    while (temp != nullptr){

        if (bookTitle == temp->getTitle()){

            if (temp->getHaveValue() == 0){

                return "Sold Out";
            }
            else {
                temp->setHaveValue((temp->getHaveValue()) - 1);
                return "Successfully Purchased Book";
            }
        }
        temp = temp->getNext();
    }
}

void LinkedList::addToWaitList(std::string bookTitle, std::string name, int phoneNumber, std::string email,
                               std::string contact) {

    Book* temp = front;
    WaitList* temp1;

    if (front == nullptr){

        temp1 = temp->getWaitlist();
        temp1->enqueue(name, phoneNumber, email, contact);
    }

    while (temp != nullptr){

        if (bookTitle == temp->getTitle()){

            temp1 = temp->getWaitlist();

            temp1->enqueue(name, phoneNumber, email, contact);
        }
        temp = temp->getNext();
    }
}


int LinkedList::getHave(std::string bookTitle) {

    Book* temp = front;

    while(temp != nullptr){

        if (bookTitle == temp->getTitle()){

            return temp->getHaveValue();
        }
        temp = temp->getNext();
    }
    return -1;
}

int LinkedList::getWant(std::string bookTitle) {

    Book* temp = front;

    while(temp != nullptr){

        if (bookTitle == temp->getTitle()){

            return temp->getWantValue();
        }
        temp = temp->getNext();
    }
    return -1;
}

void LinkedList::setHave(std::string bookTitle, int newHave) {

    Book* temp = front;

    while (temp != nullptr){

        if (bookTitle == temp->getTitle()){

            temp->setHaveValue(newHave);
        }
        temp = temp->getNext();
    }
}

void LinkedList::setWant(std::string bookTitle, int newWant) {

    Book* temp = front;

    while (temp != nullptr){

        if (bookTitle == temp->getTitle()){

            temp->setHaveValue(newWant);
        }
        temp = temp->getNext();
    }
}

std::string LinkedList::orderMore() {

    Book* temp = front;
    std::string listOfHaveValues;

    while (temp != nullptr){

        if (temp->getHaveValue() < temp->getWantValue()) {

            listOfHaveValues = listOfHaveValues + temp->getTitle() + "|" + std::to_string(temp->getWantValue() - temp->getHaveValue()) + "|";
        } else{
            listOfHaveValues = listOfHaveValues + temp->getTitle() + "|" + std::to_string(0) + "|";
        }
        temp = temp->getNext();
    }
    return listOfHaveValues;
}

std::string LinkedList::returnBooks() {

    Book* temp = front;
    std::string listOfReturnBooks;

    while (temp != nullptr){

        if (temp->getHaveValue() > temp->getWantValue()){

            listOfReturnBooks = listOfReturnBooks + temp->getTitle() + "|" + std::to_string((temp->getHaveValue() - temp->getWantValue()));
            temp->setHaveValue(temp->getWantValue());
        }
        temp= temp->getNext();
    }
    return listOfReturnBooks;
}

std::string LinkedList::updateHaveValue(std::string title, int haveValue) {

    Book* temp = front;

    std::string booksOnHold;

    while (temp != nullptr) {

        if (title == temp->getTitle()) {

            //gets waitlist for title
            WaitList* wait = temp->getWaitlist();

            //checks to see if waitlist is empty
            if(!wait->isEmpty()) {

                //while the new have value doesnt = 0
                while (haveValue != 0) {

                    //gets the person at the front of queue
                    Person *p1 = wait->getPerson();

                    //while temp person isn't nullptr
                    while (p1 != nullptr) {

                        //creates string to return
                        return booksOnHold = booksOnHold + temp->getTitle() + " has been put on hold for " + p1->getName() +
                                             ". We have contacted them by " + p1->getContact() + "ing them.";

                        //dequeues that person
                        wait->dequeue();
                        //decreases have value by 1
                        haveValue--;
                        //moves pointer to next person in queue
                        p1 = p1->getNext();
                    }
                }
            }
            //if less people in queue than there was newHaveValue, adds the remaining new have value to current have value for that book
            temp->setHaveValue(temp->getHaveValue() + haveValue);
        }
        //moves on to next book
        temp = temp->getNext();
    }
    //return booksOnHold;
}

int LinkedList::totalHaveLessThanWant() {

    Book* temp = front;
    int counter = 0;

    while (temp != nullptr){

        if (temp->getHaveValue() < temp->getWantValue()){
            counter++;
        }
        temp = temp->getNext();
    }
    return counter;
}

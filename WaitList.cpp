
#include "WaitList.h"
#include <string>


WaitList::WaitList() {
    front = nullptr;
    end = nullptr;
}

WaitList::WaitList(const WaitList &queueToCopy) {

    if (queueToCopy.front == nullptr){

        front = nullptr;
        end = nullptr;
    }
    else {
        Person* newQueue = queueToCopy.front;
        front = new Person(newQueue->getName(), newQueue->getPhoneNumber(), newQueue->getEmail(), newQueue->getContact());
        Person* a = front;
        newQueue = newQueue->getNext();

        while (newQueue != nullptr){

            Person* newPerson = new Person(newQueue->getName(), newQueue->getPhoneNumber(), newQueue->getEmail(), newQueue->getContact());
            a->setNext(newPerson);
            a = newPerson;
            newQueue = newQueue->getNext();
        }
        end = a;
    }
}

WaitList::~WaitList() {

    while (front != nullptr){

        Person* deletePerson = end;
        front = front->getNext();
        delete deletePerson;
    }
}

void WaitList::enqueue(std::string name, int phoneNumber, std::string email, std::string contact) {

    Person* newPerson = new Person(name, phoneNumber, email, contact);

    if (front == nullptr){
        front = newPerson;
        end = newPerson;
    }
    else {
        end->setNext(newPerson);
        end = newPerson;
    }
}

std::string WaitList::dequeue() {

    if (isEmpty()){
        throw std::out_of_range("Queue is empty");
    }else {

        std::string person = front->getName() + "|" + std::to_string(front->getPhoneNumber()) + "|" + front->getEmail() + "|" + front->getContact();

        if (front == end) {
            delete front;
            front = nullptr;
            end = nullptr;
        } else {
            Person* deletePerson = front;
            front = front->getNext();
            delete deletePerson;
        }
        return person;
    }

}

bool WaitList::isEmpty() {
    return front == nullptr;
}

Person* WaitList::getPerson(){
    return front;
}

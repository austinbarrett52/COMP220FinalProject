//
// Created by Austin Barrett on 12/6/17.
//

#include "Person.h"

//
// Created by Brendan King on 12/6/17.
//


Person::Person(std::string nameIn, int phoneNumberIn, std::string emailIn, std::string contactIn) {

    name = nameIn;
    phoneNumber = phoneNumberIn;
    email = emailIn;
    contact = contactIn;
    next = nullptr;
}

Person::Person(const Person &personToCopy) {

    name = personToCopy.name;
    phoneNumber = personToCopy.phoneNumber;
    email = personToCopy.email;
    contact = personToCopy.contact;
    next = nullptr;
}

std::string Person::getName() {
    return name;
}


int Person::getPhoneNumber() {
    return phoneNumber;
}


std::string Person::getEmail() {
    return email;
}


std::string Person::getContact() {
    return contact;
}

void Person::setContact(std::string newContact) {
    contact = newContact;
}


Person* Person::getNext() {
    return next;
}


void Person::setNext(Person* newNext) {
    next = newNext;
}
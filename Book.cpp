//
// Created by Brendan King on 11/30/17.
//

#include <iostream>
#include "Book.h"

Book::Book(std::string titleIn, int haveValueIn, int wantValueIn, WaitList* waitListIn) {

    this->title = titleIn;
    haveValue = haveValueIn;
    wantValue = wantValueIn;
    waitList = waitListIn;
    next = nullptr;
}

Book::Book(const Book& bookToCopy) {

    title = bookToCopy.title;
    haveValue = bookToCopy.haveValue;
    wantValue = bookToCopy.wantValue;
    waitList = bookToCopy.waitList;
    next = nullptr;
}

std::string Book::getTitle() {
    return title;
}

void Book::setTitle(std::string newTitle) {
    title = newTitle;
}

int Book::getHaveValue() {
    return haveValue;
}

void Book::setHaveValue(int newHaveValue) {
    haveValue = newHaveValue;
}

int Book::getWantValue() {
    return wantValue;
}

void Book::setWantValue(int newWantValue) {
    wantValue = newWantValue;
}

Book* Book::getNext() {
    return next;
}

void Book::setNext(Book* newNext) {
    next = newNext;
}

WaitList* Book::getWaitlist() {

    return waitList;
}

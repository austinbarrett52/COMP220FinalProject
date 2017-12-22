
#include <iostream>
#include <string>
#include <fstream>

#include "Book.h"
#include "LinkedList.h"
#include "Person.h"
#include "WaitList.h"

using namespace std;


void testAddBook(LinkedList* testBookstore){
    std::cout << "Testing AddBook" << std::endl;

    //not used, only to fill parameter
    WaitList* book1Queue = new WaitList;
    WaitList* book2Queue = new WaitList;

    //if there is any error, print fail. Else, print pass.
    try{
        testBookstore->addBook("book1", 45, 5, book1Queue);
        testBookstore->addBook("book2", 7, 8, book2Queue);
    }
    catch(logic_error){
        cout<< "Fail."<<endl;
    }

    cout << "If there is no Fail in the line above this line, then it passes." << endl;



}

void testGetBook (LinkedList* testBookstore){
    std::cout << "Testing GetBook" << std::endl;

    std::string getBook1= testBookstore->getBook("book1");
    if (getBook1 == "Book Not Found"){
        std::cout << "Fail" << std::endl;

    }else{
        std::cout << "pass" << std::endl;
    }
}

void testDequeueWaitlist (LinkedList* testBookstore, WaitList* thisBookWaitlist){
    cout<< "Testing DequeueWaitList" << endl;

    std::string getPerson = thisBookWaitlist->dequeue();

    if (getPerson == "Bob Smith|1234567890|bobsmith@gmail.com|email"){
        cout << "pass" << endl;
    }else{
        cout << "Fail" << endl;
    }
}

void testAddWaitlist(LinkedList* testBookstore, WaitList* thisBookWaitlist){
    std::cout << "Testing AddWaitList" << std::endl;

    //if there is any error, print fail. Else, print pass.
    try{
        std::string bookToAddTo = testBookstore->getBook("book1");
        thisBookWaitlist->enqueue("Bob Smith", 1234567890, "bobsmith@gmail.com", "email");
    }
    catch(logic_error){
        cout<< "Fail."<<endl;
    }

    cout << "If there is no Fail in the line above this line, then it passes." << endl;
}

void testRestartInventory(LinkedList* testBookstore){
    std::cout << "Testing RestartInventory" << std::endl;

    ifstream bookFile("bookInventory.txt");

    //delimeter for bookInventory.txt
    char delimeter = '|';

    //attributes for bookInventory
    std::string title = "";
    std::string strWantValue = "";
    std::string strHaveValue = "";
    int wantValue = -1;
    int haveValue = -1;
    WaitList* thisBookWaitlist = new WaitList;


    //bookInventory.txt information
    if (bookFile) {
        while (bookFile) {
            getline(bookFile, title, delimeter);
            getline(bookFile, strHaveValue, delimeter);
            getline(bookFile, strWantValue, delimeter);

            try {
                wantValue = stoi(strWantValue);
                haveValue = stoi(strHaveValue);
            } catch (logic_error) {
                wantValue = -1;
                haveValue = -1;
                cout << "WantValue and/or HaveValue were loaded incorrectly, values will be stored as -1." << endl;
            }
            //finally, add the book to the linkedList with the waitList pointer attached to it
            testBookstore->addBook(title, haveValue, wantValue, thisBookWaitlist);
        }
        cout << "pass" << endl;
    }

    else{
        cout<< "Fail" << endl;
    }
}

int main(){

    LinkedList* testBookstore = new LinkedList();
    WaitList* thisBookWaitlist = new WaitList;


    std::cout<< std::endl;
    testAddBook(testBookstore);
    std::cout<< std::endl;
    testGetBook(testBookstore);
    std::cout<< std::endl;
    testAddWaitlist(testBookstore, thisBookWaitlist);
    std::cout<< std::endl;
    testDequeueWaitlist(testBookstore, thisBookWaitlist);
    std::cout<< std::endl;
    testRestartInventory(testBookstore);


    return 0;
}


#include <iostream>
#include <string>
#include <fstream>

#include "BookStore.h"
#include "LinkedList.h"
#include "Book.h"
#include "Person.h"



using namespace std;

BookStore::BookStore() {

    //initialize bookstore
    LinkedList* myBookstore = new LinkedList();

    //read in all previous books and waiting lists
    restartInventory(myBookstore);

    cout << "Hello! Welcome to our virtual library!" << endl;
    cout << "First things first! Here is a list of commands that you can input: " << endl;

    printCommands();

    cout << "Enter an integer value for which action you would like to do." << endl;
    bool goodInput = false;

    //This checks for the correct input, as well as quits the program if the user enters 10
    while (choice!= 10) {
        //if user enters a key that is not an integer
        try{
            std::string strChoice = "";
            getline(cin, strChoice);
            choice = stoi(strChoice);
        }
        catch(logic_error){
            goodInput = false;
        }

        //if user enters an input that is an integer but not a valid option
        if (choice < 1 || choice > 10) {
            cout << "Please enter a valid number." << endl;
            goodInput = false;
        }

        else{ //good input
            cout << "Selection recorded!" << endl;
            goodInput = true;
        }


        if (choice == 1) {
            cout << "Printing a summary of all available commands..." << endl;
            printCommands();
        }
        else if (choice == 2) {
            cout << "Enter the title of the book you would like" << endl;
            std::string bookChoice = "";
            getline(cin, bookChoice);
            cout << "Displaying all information for the specified title..." << endl;

            bool bookExists = false;
            //call a method to iterate through and find the title
            std::string thisBook = myBookstore->getBook(bookChoice);
            if (thisBook != "Book Not Found"){
                bookExists = true;
                cout << thisBook << endl;

            }else{
                cout << "Book Not Found" << endl;
            }
        }

        else if (choice == 3) {
            cout << "Listing the information for the entire inventory..." << endl;
            cout << myBookstore->getAllBooks() << endl;
        }

        else if (choice == 4) {
            //initialize values
            std::string title = "";
            int wantValue = -1;
            int haveValue = -1;
            WaitList* thisBookWaitlist = new WaitList;

            //title
            cout << "Let's add a book to the inventory!" << endl;
            cout << "Please enter the title of the book: " << endl;
            getline(cin, title);


            //check to see if the book is already in the inventory
            std::string doesExist = myBookstore->getBook(title);
            //std::string toCompare = "Book Not Found";

            if (doesExist != "Book Not Found"){
                cout << "This book already exists in our inventory" << endl;
                //print out the information of the book
                std::string thisBook = myBookstore->getBook(title);
                cout << thisBook << endl;
            }else { //book does not exist
                //get want value
                cout << "Please enter the initial want value (between 0 and 100)" << endl;
                std::string strWantValue = "";

                while (wantValue < 0 || wantValue > 100) {
                    //if user enters a key that is not an integer
                    try{
                        getline(cin, strWantValue);
                        wantValue = stoi(strWantValue);
                    }
                    catch(logic_error){
                        cout << "You entered a string of letters." << endl;
                    }

                    if (wantValue < 0 || wantValue > 100 ){
                        cout << "Please enter a valid number between 0 and 100." << endl;
                    }
                }

                //get have value
                cout << "Please enter the initial have value (between 0 and 100)" << endl;
                //if user enters a key that is not an integer
                std::string strHaveValue = "";

                while (haveValue < 0 || haveValue > 100) {
                    //if user enters a key that is not an integer
                    try{
                        getline(cin, strHaveValue);
                        haveValue = stoi(strHaveValue);
                    }
                    catch(logic_error){
                        cout << "You entered a string of letters." << endl;
                    }
                    if (haveValue < 0 || haveValue > 100){
                        cout << "Please enter a valid number between 0 and 100." << endl;
                    }
                }

                //add the book to the linkedList
                myBookstore->addBook(title, haveValue, wantValue, thisBookWaitlist);

                //add the book to the textfile
                std::string lineToAdd = title + "|" + std::to_string(haveValue) + "|" + std::to_string(wantValue) + "|";
                appendLineToFile("bookInventory.txt", lineToAdd);

                cout << "Book successfully added!" << endl;
            }
        }

        else if (choice == 5) {
            std::string title = "";
            int newWantValue = -1;
            cout << "Modifying the want value for the specified title..." << endl;
            cout << "Enter the desired book title:" << endl;
            getline(cin, title);

            //check to make sure book exists
            std::string thisBook = myBookstore->getBook(title);

            if(thisBook != "Book Not Found") {
                cout << "Current information for this book:"<< endl;
                cout << myBookstore->getBook(title);

                //new want value
                cout << "What do you wish the new want value to be?" << endl;
                try{
                    std::string strWantValue = "";
                    getline(cin, strWantValue);
                    newWantValue = stoi(strWantValue);
                }
                catch(logic_error){}

                if (newWantValue < 0 || newWantValue > 100 || !newWantValue) {
                    cout << "Invalid input, want value will be stored as -1." << endl;
                }

                //modify the book value
                myBookstore->updateBook(title, newWantValue);
                cout << "Successfully Recorded" << endl;
            }
            else { //book does not exist
                cout << "This book does not exist in our inventory" << endl;
                cout << "No books will be updated." << endl;
                cout << endl;
            }
        }

        else if (choice == 6) {
            std::string title = "";
            cout << "Please enter the title of the book you would like to purchase" << endl;
            getline(cin, title);

            //check to make sure book exists
            std::string bookExists = myBookstore->getBook(title);

            if(bookExists != "Book Not Found" && myBookstore->getHave(title) > 0){
                cout << "Thank you for your purchase!" << endl;
                myBookstore->setHave(title, myBookstore->getHave(title)-1);
                cout << "The new information for the book is: " << endl;
                cout << myBookstore->getBook(title) << endl;
            }else if(bookExists != "Book Not Found" && myBookstore->getHave(title) == 0){
                cout << "The book you are looking for is currently sold out" << endl;
                cout << "Please enter the following information so we can add you to the wait list" << endl;
                std::string name = "";
                cout << "Enter your name" << endl;
                getline(cin, name);

                int phoneNumber = 0;
                std::string strPhoneNumber = "";
                cout << "Enter your Phone Number" << endl;
                getline(cin, strPhoneNumber);
                phoneNumber = stoi(strPhoneNumber);

                std::string email = "";
                cout << "Enter your Email:" << endl;
                getline(cin, email);

                std::string contact = "";
                cout << "Enter your Contact Preference (Call, Text or Email):" << endl;
                getline(cin, contact);

                //add to the queue
                myBookstore->addToWaitList(title, name, phoneNumber, email, contact);

                //add to the waitingLists.txt
                std::string lineToAdd = name + "|" + strPhoneNumber + "|" + email + "|" + contact + "|";
                appendLineToFile("waitingLists.txt", lineToAdd);

                cout << name + " you have been successfully added to the Wait List. We will contact you when we get our shipment in" << endl;

            } else { //book does not exist
                cout << "This book does not exist in our inventory" << endl;
                int wantValue = -1;
                int haveValue = -1;
                WaitList* thisBookWaitlist = new WaitList;

                //title
                cout << "Let's add that book to the inventory!" << endl;

                //check to see if the book is already in the inventory
                std::string doesExist = myBookstore->getBook(title);
                if (doesExist != "Book Not Found"){
                    cout << "This book already exists in our inventory" << endl;
                    //print out the information of the book
                    std::string thisBook = myBookstore->getBook(title);
                    cout << thisBook << endl;
                }else { //book does not exist
                    //get want value
                    cout << "Please enter the initial want value (less than 100)" << endl;

                    //if user enters a key that is not an integer
                    std::string strWantValue = "";
                    try{

                        getline(cin, strWantValue);
                        wantValue = stoi(strWantValue);
                    }
                    catch(logic_error){}

                    if (wantValue < 0 || wantValue > 100 || !wantValue) {
                        cout << "Invalid input, want value will be stored as -1." << endl;
                    }
                    //get have value
                    cout << "Please enter the initial have value (less than 100)" << endl;
                    //if user enters a key that is not an integer

                    std::string strHaveValue = "";
                    try{
                        getline(cin, strHaveValue);
                        haveValue = stoi(strHaveValue);
                    }
                    catch(logic_error){}

                    if (haveValue < 0 || haveValue > 100 || !haveValue) {
                        cout << "Invalid input, have value will be stored as -1." << endl;
                    }

                    //add the book to the textfile
                    std::string lineToAdd = title + "|" + strHaveValue + "|" + strWantValue + "|";
                    appendLineToFile("bookInventory.txt", lineToAdd);

                    //add the book
                    myBookstore->addBook(title, haveValue, wantValue, thisBookWaitlist);
                    cout << "Book successfully added!" << endl;
                }
            }
        }

        else if (choice == 7) {

            cout << "Creating bulk purchase order for more books" << endl;

            int numBookOrders = myBookstore->totalHaveLessThanWant();

            if (numBookOrders == 0){
                cout << "We do not need to perform an order, all books are sufficiently stocked." << endl;
            }else{

                std::string listOfHaveValues = myBookstore->orderMore();
                appendLineToFile("orderInfo.txt", listOfHaveValues);

                cout << "All books have successfully been restocked" << endl;
            }
        }

        else if (choice == 8) {

            cout << "Delivering Books..." << endl;

            ifstream orderInfo("orderInfo.txt");

            char delimeter = '|';

            std::string title = "";

            std::string strHaveValue = "";
            int haveValue = -1;

            if (orderInfo){

                while (orderInfo){

                    getline(orderInfo, title, delimeter);
                    getline(orderInfo, strHaveValue, delimeter);

                    try {
                        haveValue = stoi(strHaveValue);
                    }catch (logic_error) {
                        haveValue = -1;
                        cout << "All books are sufficiently stocked" << endl;
                    }

                    std::string waitList = myBookstore->updateHaveValue(title, haveValue);
                    cout << waitList << endl;
                }
            }
        }
        else if (choice == 9) {
            cout << "Returning all books with greater have values than want values..." << endl;

            std::string listOfReturnBooks = myBookstore->returnBooks();
            appendLineToFile("returnBooks.txt", listOfReturnBooks);

            cout << "Successfully Returned!" << endl;
        }
    }
}


void BookStore::appendLineToFile(std::string filepath, std::string line) {
    std::ofstream file;
    //can't enable exception now because of gcc bug that raises ios_base::failure with useless message
    //file.exceptions(file.exceptions() | std::ios::failbit);
    file.open(filepath, std::ios::out | std::ios::app);
    if (file.fail()){
        throw std::ios_base::failure(std::strerror(errno));
    }

    //make sure write fails with exception if something is wrong
    file.exceptions(file.exceptions() | std::ios::failbit | std::ifstream::badbit);

    file << line << std::endl;
}

void BookStore::restartInventory(LinkedList* myBookstore){

    ifstream bookFile("bookInventory.txt");
    ifstream waitListFile("waitingLists.txt");

    //delimeter for both bookInventory.txt AND waitingLists.txt
    char delimeter = '|';

    //attributes for bookInventory
    std::string title = "";
    std::string strWantValue = "";
    std::string strHaveValue = "";
    int wantValue = -1;
    int haveValue = -1;

    //attributes of waitList
    //Book* listToAdd;
    WaitList* thisBookWaitlist = new WaitList;
    std::string thisBookTitle = "";
    std::string name = "";
    std::string strPhone = "";
    int phoneNumber = -1;
    std::string email = "";
    std::string contact = "";


//    //waitingLists.txt information
//    if (waitListFile) {
//        while (waitListFile) {
//            getline(bookFile, thisBookTitle, delimeter);
//            getline(bookFile, name, delimeter);
//            getline(bookFile, strPhone, delimeter);
//            getline(bookFile, email, delimeter);
//            getline(bookFile, contact, delimeter);
//
//            try {
//                phoneNumber = stoi(strPhone);
//            } catch (logic_error) {
//                phoneNumber = -1;
//                cout << "Phone number was loaded incorrectly, values will be stored as -1." << endl;
//            }
//
//            //find the right book before enqueueing waiting list
//            //listToAdd = myBookstore->getBook(thisBookTitle);
//            //add the waitList
//            thisBookWaitlist->enqueue(name, phoneNumber, email, contact);
//        }
//    }

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
            myBookstore->addBook(title, haveValue, wantValue, thisBookWaitlist);
        }
    }


    else{
        cout<< "Unable to load inventory from memory." << endl;
    }
}

void BookStore::printCommands(){
    cout << "1) Help with commands" << endl;
    cout << "2) Inquire about a book" << endl;
    cout << "3) List out all the books" << endl;
    cout << "4) Add a book" << endl;
    cout << "5) Modify information about a book" << endl;
    cout << "6) Sell a book" << endl;
    cout << "7) Order" << endl;
    cout << "8) Delivery" << endl;
    cout << "9) Return" << endl;
    cout << "10) Quit program" << endl;
}

BookStore::~BookStore() {
    //Calls all destructors for each object
    //delete myBookstore;
}


int main() {
    //Seed random for all methods to use
    srand(time(NULL));

    BookStore* myBookStore = new BookStore();

    return 0;
}

Within this virtual bookstore you will immediately be prompted with a welcome message and list of commands.
As long as you are not being prompted for something such as a book title (IE at the main input line), you can always
press 1 for more options.

Below are the steps we want the evaluator to go through when evaluating our final product:

Enter 1: This will print out all the commands.

Enter 2: Inquire about a book. Enter the title "Harry Potter". This book exists in the inventory,therefore all of the
information will be printed out. Next, enter "asdf"; this title does not exist in inventory and you will be told so.
Remember that input is case sensitive.

Enter 3: Prints out all of the books currently in the linked list. If there are no books in the inventory then you will
 see a message "printing out all of the books..." and then there will not be anything after that. Assuming you did not
 modify the bookInventory.txt file, you will see 4 books that we preset into the text file. A bug in our code that we
 were not able to fix was that the have value and want value of the last line is read in twice and added into a book
 twice (but not the title for some reason...).

Enter 4: Adds a book to the inventory. Enter "Harry Potter" in the command line for the book title. This book already
exists in our inventory and you will be told so and presented with the book information. Now, enter 4 again and input
anything you would like for the title. Then enter a number between 0 and 100 for the have and want values. If you try
to enter anything for the have value or want value that is not a number between 0 and 100 you will be prompted to do
so until you properly input.

Enter 3 (again): You will now see the book you just added in our inventory of books.

Enter 5: Modify the want value for a particular book. Enter any sort of title that does not exist and you will be told so
and nothing will happen. Now enter "Harry Potter" and you will be prompted with the current information and asked what
you want the new information to be.
A bug in this step is that when you modify the value of a book, it will be modified in the linkedList but it will
not be modified in the text file. Therefore, when you reload the file the value will be the same as it originally was
when the book was added to the text file.

Enter 6: You will be asked which book you want to purchase. Enter "Harry Potter" and you will be presented with the
new information for that book. Since the previous have value was 1 there was no issue with pruchasing this book. Now
enter 6 again and input "Harry Potter" again. Since there are currently no books in stock, you will be prompted to
input your name, phone number, email, and contact preference. You will then be added to the waitlist.

Enter 7: This command will create a new text file with all books that need to be restocked (IE if the haveValue is less
than the wantValue). As you enter 7, the text file called "orderInfo.txt" is updated. Now go to that text file and you
will see the name of each book and how many books need to be ordered.

Enter 8: This command will read in the orderInfo.txt file and gets the title and have value for each book who's have value is less
than their want value. A bug in our program is that it finds the first book and the first person waiting on the waitlist and prints
out their information but crashes after. To see a working example create a book with command 4. Enter any title you want with
have value at 0 and want value 3. Then enter 6 to sell the book you just created and enter the title of the book you just made.
Add yourself to the waitlist and then press 7 to update the orderInfo.txt. Once this is complete press 8 to see you or the first
person on the waitlist's information print.

Enter 9: This command will tell you every book in the inventory that has less wantValues than haveValues.

Enter 10: To exit the program, press 10. Upon closing the program and opening it again, all books and information
regarding have value and want value will be retained. However, we did not successfully accomplish the requirement of
reading in waiting list information that is designated to its own book.


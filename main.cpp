#include <iostream>
#include <string>
#include <map>
using namespace std;

// First we have to define what we need to store account information in the program
struct Account {
    string password;
    double balance;
};

   //In this program we are going to work with accounts that stores Account objects with a string in this case we need map and a userid as a key.
map<string, Account> accounts;

int main() {
// Now we are going to work our program with menu loop
  char choice;

    	cout << "Hi! Welcome to the ATM Machine! Please select an option from the menu below: \n";
    	 while (true) {
        cout << "l-> Login\n";
        cout << "c-> Create New Account\n";
        cout << "q-> Quit\n";
        cout << "Enter your choice: ";


        cin >> choice;

        switch (choice) {
             //Here we are going to start working with the cases by there let us start with the first case which is login
        	 case 'l': {
        	     //login
                string userId, password;
                cout << "Enter user ID: ";
                cin >> userId;
                cout << "Enter password: ";
                cin >> password;

                // Here we are going to use if function to check if account exists and password matches then the user his login is successfully and  is going to be able to keep on with the next steps.
                if (accounts.find(userId) != accounts.end() && accounts[userId].password == password) {
                        cout <<"Access Granted!\n";
                    // By there the login successful to the user,next we need to keep on with the loop.
                    while (true) {

                        cout << "d-> Deposit money\n";
                        cout << "w-> Withdraw money\n";
                        cout << "r-> Request balance\n";
                        cout << "q-> Quit\n";
                        cout << "Enter your choice: ";

                        char mainChoice;
                        cin >> mainChoice;

                        switch (mainChoice) {//Now we are going to work with the case of deposit money
                            case 'd': {
                                // Deposit money
                                double amount;
                                cout << "Enter amount to deposit:$ ";
                                cin >> amount;
                                accounts[userId].balance += amount;
                                //once the user deposits money in his account the computer is going to display the information to him/her
                                cout << "Your balance is:$"<<accounts[userId].balance<<"\n";
                                break;
                            }
                            // let us work with case of withdraw money

                            case 'w': {
                                // Withdraw money
                                double amount;
                                cout << "Enter amount to withdraw:$ ";
                                cin >> amount;
                                //we use if function here to show that when the user withdraw the amount greater than her balance
                                if (amount > accounts[userId].balance) {
                                    cout << "Your balance is too low!\n";
                                }
                                else {
                                    accounts[userId].balance -= amount;
                                    cout << "Your balance is: $ "<<accounts[userId].balance<<"\n";
                                }
                                break;
                            }
							case 'r': {
                                // We keep going with the case of request balance
                                cout << "Your balance is: $ " << accounts[userId].balance<<"\n";

                                break;
                         }
                                   case 'q': {
                                // Let us end up with the case of quit
                                cout << "Your process is completed successfully!\n";
                                return 0;
                            }
                            default:
                                cout << "Your choice is not found. Please try again. \n";
                        }
                    }
                } else {
                    cout << "*** LOGIN FAILED! *** \n";
                    cout <<"\n";
                    cout <<"Please select an option from the menu below: \n";
            }
                break;
        	 }

            case'c': {
                     // Then here we keep on with the first switch case of create new account
                     string userId, password;
                     cout << "Enter user ID: ";
                     cin >> userId;
                     cout << "Enter password: ";
                     cin >> password;
                      accounts[userId] = {password, 0.0};
                     cout << "Thank You! Your account has been created!\n";
                }
                break;

            case 'q':{
                // For the first switch case of quit
                cout << "Your process is completed successfully!\n";
                return 0;
            default:
                cout << "Your choice is not found. Please try again.\n";
                        }
                        break;
        }
    }


    return 0;
  }


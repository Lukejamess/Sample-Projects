// include necessary packages and use namespace std for ease of coding
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// declare constants for prices and buy limits, these are constant because they will never change.
// 4 ints that function as our switch cases
// 6 doubles for menu option prices and sale prices
// 1 int that sets the buy limit which will trigger sale prices to be activated
const int SANDWICH = 1;
const double sandCost = 3.50;
const double saladCost = 4.50;
const int PLATTER = 2;
const double saleSand = 2.75;
const double saleSalad = 3.75;
const int SALAD = 3;
const double platterCost = 5.50;
const double salePlatter = 4.75;
const int QUIT = 4;
const int buyLimit = 3;

// declare main 
int main()
{

	// variable assignments -
	// 1 int for processing user input in switch statement for order (choice)
	// 3 ints and 3 doubles for item prices and sale prices
	// 1 int to control termination of program (programEnd)
	// 1 int for processing user input to decide if program should be ran again (moreOrder)
	int choice = 0;
	int numberSand = 0;
	int numberSalad = 0;
	int numberPlatter = 0;
	double totalSandCost = 0;
	double totalSaladCost = 0;
	double totalPlatterCost = 0;
	int programEnd = 0;
	int moreOrder = 0;

	//set decimal precision to 2 for the entirity of the program.
	cout << fixed << setprecision(2);

	//create while loop which will repeat until programEnd is changed from 0
	while (programEnd == 0) {

		//create menu interface which will prompt the user to enter 1, 2, 3, or 4 in 
		// correspondence with their intended menu choice
		cout << "Welcome to the Quad Sandwhich shop" << endl;
		cout << "Place your order? " << endl << endl;
		cout << " 1. Sandwich" << endl;
		cout << " 2. Platter" << endl;
		cout << " 3. Salad" << endl;
		cout << " 4. Quit" << endl << endl;
		cout << "Please enter your choice: ";

		//assign user input to variable choice
		cin >> choice;

		//create nested while loop that prompts the user to enter a positive number
		while (choice <= 0) {
			cout << "Please enter one of the numbers presented: ";
			cin >> choice;
		}

		//create switch statement that will switch based on what the user entered previously
		switch (choice) {

		//if user chose 1 for sandwich, this case will ask them how many they would like,
		// calculate the total cost, and print the per-item cost as well as the total cost.
		case SANDWICH:
			cout << "\nHow many sandwiches would you like? ";
			cin >> numberSand;
			if (numberSand >= buyLimit) {
				totalSandCost = numberSand * saleSand;
			}
			else {
				totalSandCost = numberSand * sandCost;
			}
			cout << "\nEach sandwich is $" << (totalSandCost / numberSand);
			cout << "\nThe total cost is $" << totalSandCost << endl << endl;
			break;

		//if user chose 2 for Platter, this case will ask them how many they would like,
		// calculate the total cost, and print the per-item cost as well as the total cost.
		case PLATTER:
			cout << "\nHow many platters would you like to buy? ";
			cin >> numberPlatter;
			if (numberPlatter >= buyLimit) {
				totalPlatterCost = numberPlatter * salePlatter;
			}
			else {
				totalPlatterCost = numberPlatter * platterCost;
			}
			cout << "\nEach platter is $" << (totalPlatterCost / numberPlatter);
			cout << "\nThe total cost is $" << totalPlatterCost << endl << endl;
			break;

		//if user chose 3 for salad, this case will ask them how many they would like,
		// calculate the total cost, and print the per-item cost as well as the total cost.
		case SALAD:
			cout << "\nHow many salads would you like to buy? ";
			cin >> numberSalad;
			if (numberSalad >= buyLimit) {
				totalSaladCost = numberSalad * saleSalad;
			}
			else {
				totalSaladCost = numberSalad * saladCost;
			}
			cout << "\nEach salad is $" << (totalSaladCost / numberSalad);
			cout << "\nThe total cost is $" << totalSaladCost << endl << endl;
			break;

		//if user chose 4 for quit, this case will thank the user and promptly end the program.
		case QUIT:
			cout << "Thank you for coming to the Quad Sandwich Shop" << endl;
			programEnd = 1;
			break;

		//if user chose a number that was not an option, this message will alert the user that their input is bad 
		default:
			cout << "Order was not completed.  You must chose a proper selection from our menu." << endl;
		}

		//create if statement to test if the program has fulfilled its purpose yet (in this case if user selection was 4)
		//if program has not finished it's purpose, (AKA if user is not done ordering) the program will ask the user if
		//they would like to order again.  
		if (programEnd == 0) {
			cout << "Would you like to place another order?" << endl << endl;
			cout << " 1. No" << endl;
			cout << " 2. Yes" << endl << endl;
			cout << "Please enter your choice: ";
			cin >> moreOrder;
			while (moreOrder <= 0 || moreOrder > 2) {
				cout << "Please enter one of the numbers presented: ";
				cin >> moreOrder;
			}

			//create switch statement that ends the program if the user is done ordering, or loops the program again 
			// if the user would like to order again.
			switch (moreOrder) {
			case 1:
				programEnd = 1;
				cout << "Thank you for coming to the Quad Sandwich Shop";
			default:
				cout << endl << endl;
				break;
			}
		}

	}

}
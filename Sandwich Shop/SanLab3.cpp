// include necessary packages and use namespace std for ease of coding
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int SANDWICH = 1; // constant for selection of sandwich (1)
const double sandCost = 3.50; // constant double to hold cost of a non-sale sandwich
const double saladCost = 4.50; //constant double to hold cost of a non-sale salad
const int PLATTER = 2; // constant for selection of platter (2)
const double saleSand = 2.75; // constant double to hold cost of a sale sandwich
const double saleSalad = 3.75; // constant double to hold cost of a sale salad
const int SALAD = 3; // constant for selection of salad (3)
const double platterCost = 5.50; // contant double to hold cost of a non-sale platter
const double salePlatter = 4.75; // constant double to hold cost of a sale platter
const int QUIT = 4; // constant for selection to quit (4)
const int buyLimit = 3; // the buylimit that must be hit before sale price is triggered

// declare main 
int main()
{

	// variable assignments -
	int choice = 0; // menu switch statement operates base on this input
	int numberSand = 0; // number of sandwiches desired
	int numberSalad = 0; // number of salads desired
	int numberPlatter = 0; // number of platters desired
	int choicesOnMenu = 4; // number of possible choices listed on the menu
	double totalSandCost = 0; // total cost of sandwiches purchased
	double totalSaladCost = 0; // total cost of salads purchased
	double totalPlatterCost = 0; // total cost of platters purchased
	int programEnd = 0; // sentinel to end the program
	int caseLoop = 0; // sentinel to end loops inside of the switch statement
	double totalCostAllOrders = 0; // total cost of all the orders that were taken 

	//set decimal precision to 2 for the entirity of the program.
	cout << fixed << setprecision(2);

	//create do.. while loop which will repeat until programEnd is changed from 0

	do {

		//create menu interface which will prompt the user to enter 1, 2, 3, or 4 in 
		// correspondence with their intended menu choice
		cout << "Place your order? " << endl << endl;
		cout << " 1. Sandwich" << endl;
		cout << " 2. Platter" << endl;
		cout << " 3. Salad" << endl;
		cout << " 4. Quit" << endl << endl;
		cout << "Please enter your choice: ";

		//assign user input to variable choice
		cin >> choice;

		//create switch statement that will switch based on what the user entered previously
		switch (choice) {

		//if user chose 1 for sandwich, this case will ask them how many they would like,
		// calculate the total cost, and print the per-item cost as well as the total cost.
		// if the number of items they entered is negative, it will prompt them to enter again
			case SANDWICH:
			
				do {
					cout << "\nHow many sandwiches would you like? ";
					cin >> numberSand;
						if (numberSand >= buyLimit) {
							totalSandCost = numberSand * saleSand;
							cout << "\nEach sandwich is $" << (totalSandCost / numberSand) << endl;
							cout << "\nThe total cost is $" << totalSandCost << endl << endl;
							totalCostAllOrders += totalSandCost;
							caseLoop = 1;
						}
						else if ((numberSand < buyLimit) && (numberSand > 0)) {
							(totalSandCost = numberSand * sandCost);
							cout << "\nEach sandwich is $" << (totalSandCost / numberSand) << endl;
							cout << "\nThe total cost is $" << totalSandCost << endl << endl;
							totalCostAllOrders += totalSandCost;
							caseLoop = 1;
						}
						else if (numberSand < 0) {
							cout << "You entered a negative number, you must enter a positive number!" << endl;
						}

				} while (caseLoop == 0);
			
				caseLoop = 0;
				break;

			//if user chose 2 for Platter, this case will ask them how many they would like,
			// calculate the total cost, and print the per-item cost as well as the total cost.
			// if the number of items they entered is negative, it will prompt them to enter again

			case PLATTER:
				do {
					cout << "\nHow many platters would you like? ";
					cin >> numberPlatter;
					if (numberPlatter >= buyLimit) {
						totalPlatterCost = numberPlatter * salePlatter;
						cout << "\nEach platter is $" << (totalPlatterCost / numberPlatter) << endl;
						cout << "\nThe total cost is $" << totalPlatterCost << endl << endl;
						totalCostAllOrders += totalPlatterCost;
						caseLoop = 1;
					}
					else if ((numberPlatter < buyLimit) && (numberPlatter > 0)) {
						(totalPlatterCost = numberPlatter * platterCost);
						cout << "\nEach platters $" << (totalPlatterCost / numberPlatter) << endl;
						cout << "\nThe total cost is $" << totalPlatterCost << endl << endl;
						totalCostAllOrders += totalPlatterCost;
						caseLoop = 1;
					}
					else if (numberPlatter < 0) {
						cout << "You entered a negative number, you must enter a positive number!" << endl;
					}

				} while (caseLoop == 0);
				caseLoop = 0;
				break;

			//if user chose 3 for Salad, this case will ask them how many they would like,
			// calculate the total cost, and print the per-item cost as well as the total cost.
			// if the number of items they entered is negative, it will prompt them to enter again

			case SALAD:
				do {
					cout << "\nHow many salads would you like? ";
					cin >> numberSalad;
					if (numberSalad >= buyLimit) {
						totalSaladCost = numberSalad * saleSalad;
						cout << "\nEach salad is $" << (totalSaladCost / numberSalad) << endl;
						cout << "\nThe total cost is $" << totalSaladCost << endl << endl;
						totalCostAllOrders += totalSaladCost;
						caseLoop = 1;
					}
					else if ((numberSalad< buyLimit) && (numberSalad > 0)) {
						(totalSaladCost = numberSalad * saladCost);
						cout << "\nEach salad is $" << (totalSaladCost / numberSalad) << endl;
						cout << "\nThe total cost is $" << totalSaladCost << endl << endl;
						totalCostAllOrders += totalSaladCost;
						caseLoop = 1;
					}
					else if (numberSalad < 0) {
						cout << "You entered a negative number, you must enter a positive number!" << endl;
					}

				} while (caseLoop == 0);
				caseLoop = 0;
				break;

			//if user chose 4 for quit, this case will thank the user, display the total cost of all the orders combined, 
			// and end the program
			case QUIT:
				cout << "\nThe total cost of all of your orders is: $" << totalCostAllOrders << endl << endl;
				cout << "Thank you, have a nice day!" << endl << endl;
				programEnd = 1;
				system("pause");
				break;

			//if user chose a number that was not an option, this message will alert the user that their input is bad 
			default:
				cout << "\nOrder was not completed.  You must choose a proper selection from our menu." << endl << endl;
				if (choice <= 0) {
					cout << "You entered a negative number, you must enter a positive number!" << endl << endl;
				}
				break;
		}
	} while (programEnd == 0);


}

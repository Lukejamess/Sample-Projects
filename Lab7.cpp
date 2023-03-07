/**
Luke McClure
CMSY
This program displays information about an initialized empty array of structures which contain a double, string, and structure.
It then accepts user input to fill the array with values.
It then displays the information again with the newly user-updated values.
*/

//includes
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//constant declarations
const int MAXFAMILYS = 4;
const int MAXCELLPHONES = 3;
const int DECIMALPRECISION = 2;
const int INDENT = 8;
const int PERCENTAGE = 100;
const int MINDATAINPLAN = 0;
const int MAXDATAINPLAN = 1000;

//structure declarations
struct CellPhone {
	string modelName = "";
	double amtDataUsed = 0.0;
};

struct Family {
	string nameOfFamily = "";
	double gbAvailable = 0;
	CellPhone familyCellphones[MAXCELLPHONES];
};

//prototype declarations
void showStats(Family family[], bool);
void getFamilyInfo(Family family[]);
double doubleValidityCheck(double numToCheck, double max, double min);

//main
int main() {

	//set precision to 2 decimal places
	cout << setprecision(DECIMALPRECISION) << fixed;

	//set bool for extra credit which i wont be able to get around to
	bool showstatbool = false;

	//initialize familyArray with given initilization values
	Family familyArray[MAXFAMILYS] = {  
									   "NONE", 0, { { "NONE", 0} , { "NONE", 0} , { "NONE", 0} } ,
									   "NONE", 0, { { "NONE", 0} , { "NONE", 0} , { "NONE", 0} } ,
									   "NONE", 0, { { "NONE", 0} , { "NONE", 0} , { "NONE", 0} } ,
									   "NONE", 0, { { "NONE", 0} , { "NONE", 0} , { "NONE", 0} } 
								     };

	//call showStats and pass familyArray and showstatbool
	showStats(familyArray, showstatbool);

	//call getFamily info and pass it familyArray
	getFamilyInfo(familyArray);

	//call showStats and pass it newly accumulated familyArray and showstatbool
	showStats(familyArray, showstatbool);

	//system pause to observe data
	system("pause");

}

//define showStats function
void showStats(Family family[], bool) {

	//if gbAvailable is 0, User Input phase must have not begun, thus we display Data after initialization
	if (family[1].gbAvailable == 0) {
		cout << "Data After Initialization: " << endl;
		cout << endl;
	}
	//else gbAvailable has been set, and therefor we display Data After User Input
	else {
		cout << "Data After User Input: " << endl;
		cout << endl;
	}

	//create for loop to iterate through families
	for (int i = 0; i < MAXFAMILYS; i++) {

		cout << "The family: " << family[i].nameOfFamily << " has " << family[i].gbAvailable << " GB of data." << endl;

		//create for loop to iterate through cellphones
		for (int j = 0; j < MAXCELLPHONES; j++) {

			cout << setw(INDENT) << left << "" << "Phone model: " << family[i].familyCellphones[j].modelName << ", has used "
				<< family[i].familyCellphones[j].amtDataUsed << " GB of data." << endl;

			//if gbAvailable is less or equal to 0, display no data used and display 0%
			if (family[i].gbAvailable <= 0) {
				string noPercentage = "No Data Used";
				cout << "The percentage of data used: " << noPercentage;
				cout << endl;

			}
			//else gbAvailable is greater than 0, so we will figure out what the percentage of data usage is and display it
			else {
				double percentage = (family[i].familyCellphones[j].amtDataUsed / family[i].gbAvailable) * PERCENTAGE;
				cout << "The percentage of data used: " << percentage << "%";
				cout << endl;

			}

		}

		cout << endl;
	}
}


//define getFamilyInfo function
void getFamilyInfo(Family family[]) {

	//declare local variables
	string familyName;
	double amtDataInPlan;

	//display "User Input: "
	cout << "User Input:" << endl;
	cout << endl;

	//create for loop to iterate through families
	for (int i = 0; i < MAXFAMILYS; i++) {

		//accepts input for nameOfFamily for each family
		cout << "Enter the family's name: ";
		getline(cin, family[i].nameOfFamily);
		
		//accepts input for gbAvaiable for each family, using a validity check function 
		cout << "Enter the size of the data plan (in GB): ";
		cin >> family[i].gbAvailable;
		family[i].gbAvailable = doubleValidityCheck(family[i].gbAvailable, MAXDATAINPLAN, MINDATAINPLAN);
		cin.get();

		//create for loop to iterate through cellphones
		for (int j = 0; j < MAXCELLPHONES; j++) {

			//accepts input for model of the phone
			cout << "Enter model or the phone: " << j + 1 << ": ";
			getline(cin, family[i].familyCellphones[j].modelName);

			//if the user enters none, or NONE then we will exit this loop as no new phones are being entered
			if (family[i].familyCellphones[j].modelName == "NONE" || family[i].familyCellphones[j].modelName == "none") {
				break;
			}

			//else if the user entered a phone model, accepts input for amtDataUsed, using a validity check function 
			else {
				cout << "Enter amount of data used: " << j + 1 << ": ";
				cin >> family[i].familyCellphones[j].amtDataUsed;
				family[i].familyCellphones[j].amtDataUsed = doubleValidityCheck(family[i].familyCellphones[j].amtDataUsed, family[i].gbAvailable, 0);
				cin.get();
			}
		}

		cout << endl;

	}
}

//simple validity check function for doubles
double doubleValidityCheck(double numToCheck, double max, double min) {

	while (numToCheck > max || numToCheck < min) {
		cout << "ERROR:  You must enter in a valid number.  Please try again" << endl;
		cin >> numToCheck;
	}
	return numToCheck;
}
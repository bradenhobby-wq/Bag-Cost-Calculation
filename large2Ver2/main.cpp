/*---------------------------------------
* Braden Hobby
* 09/18/2025
* Large Program 2
* Description: Bag Charges
*---------------------------------------
*/


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//asks for bag weight and distance traveled to come up with the cost
int main() {
	cout << "Large Program Week 4-6 - Bag Charges" << endl; //meets ZyLab requirements
	
	int milesFlown; //user input variable for how many miles the user has flown
	int numberOfMileSegments; //calculates how many mile segments were flown
	const int NUM_OF_MILES_PER_SEGMENT = 500; //sets the distance, in miles, of each mile segment
	double weightOfBag; //user input variable of weight of their bag, in pounds
	double totalCost; //total fee for the bag, in dollars
	const double FIRST_WEIGHT = 10.0; //first cut off in bracketed cost system
	const double SECOND_WEIGHT = 20.0; //second cut off
	const double THIRD_WEIGHT = 30.0; //third cut off
	const double FOURTH_WEIGHT = 50.0; //final cut off
	const double FIRST_COST = 2.0; //cost of first weight cost bracket
	const double SECOND_COST = 3.5; //cost of second bracket
	const double THIRD_COST = 4.8; //cost of third bracket
	const double FOURTH_COST = 5.9; //cost of final bracket
	const int MAX_MILES = 4000; //sets limit for miles on a flight
	const int MIN_MILES = 40; //sets minimum for miles on a flight

	//gets user input for miles flown and the weight of their bag
	cout << "How many miles long is your flight? ";
	cin >> milesFlown;

	
	
	if (cin.fail()) {
		cout << endl << "Error: invalid input" << endl;
	}
	else {
		cout << "How many pounds does your bag weigh? ";
		cin >> weightOfBag;   //the following if statements check for wrong weight or distance inputs
		if (cin.fail()) {
			cout << endl << "Error: invalid input" << endl;
		}
		else {
			if (weightOfBag > FOURTH_WEIGHT) {
				cout << endl << "Your bag is overweight" << endl;
			}
			else if (weightOfBag < 0) {
				cout << endl << "You know what positive numbers. Enter them" << endl;
			}
			else {
				if (milesFlown > MAX_MILES || milesFlown < MIN_MILES) {
					cout << "There are no flights less than 40 miles long and none greater than 4,000 miles" << endl;
				}
				else {

					//calculates # of mile segments
					if (milesFlown % NUM_OF_MILES_PER_SEGMENT == 0) {
						numberOfMileSegments = milesFlown / NUM_OF_MILES_PER_SEGMENT;
					}
					else {
						numberOfMileSegments = milesFlown / NUM_OF_MILES_PER_SEGMENT + 1;
					}

					//calculates total cost or warns the user if their bag is over the limit
					if (weightOfBag <= FIRST_WEIGHT) {
						totalCost = FIRST_COST * numberOfMileSegments;
					}
					else if (weightOfBag <= SECOND_WEIGHT) {
						totalCost = SECOND_COST * numberOfMileSegments;
					}
					else if (weightOfBag <= THIRD_WEIGHT) {
						totalCost = THIRD_COST * numberOfMileSegments;
					}
					else if (weightOfBag <= FOURTH_WEIGHT) {
						totalCost = FOURTH_COST * numberOfMileSegments;
					}


					//displays the total cost of the bag
					cout << "Your total cost is $" << fixed << setprecision(2) << totalCost << endl;
				}
			}
		}
	}

	

	return 0;
}
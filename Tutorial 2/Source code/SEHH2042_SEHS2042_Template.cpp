// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
//since I need to output specific decimal point, iomanip is included
#include <iomanip>
//#include <cmath> to use std::pow()
#include <cmath>
#include <algorithm>
//since std::vector and std::sort are used in Q4, include <vector> and <algorithm> files
#include <vector>
using namespace std;

void showInfo()
{
	// Fill in your personal particulars below
	"Name      : HIDDEN\n";
	"Student ID: HIDDEN\n";
	"Class     : A01A\n";
}

void Q1()
{
	// =====================================
	// Insert your codes for Question 1 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int n = 0, digit1 = 0, digit2 = 0;
	cout << "Enter a two-digit integer: (00 - 99): ";
	//input n
	cin >> n;
	digit1 = n / 10; //get the first digit
	digit2 = n % 10; //get the second digit
	//compartion checking and output the required answer
	if (digit1 == digit2) {
		cout << digit1 << " = " << digit2 << endl;
	}  
	else if (digit1 > digit2) {
		cout << digit1 << " > " << digit2 << endl;
	} 
	else {
		cout << digit1 << " < " << digit2 << endl;
	}
}

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int x, y;
	//input x, y
	cout << "Input x: ";
	cin >> x;
	cout << "Input y: ";
	cin >> y;
	//check if y is the factor of x
	if (y % x == 0) {
		cout << x << " is a factor of " << y << endl;
	}  
	else {
		cout << x << " is not a factor of " << y << endl;
	} 
}

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variable
	int year;
	//input year
	cout << "Input a year: ";
	cin >> year;
	cout << "Is " << year << " a leap year? ";
	//check whether it is a leap year, a leap year if and only if it is divisible by 4 but not divisible by 100, or it is divisible by 400
	((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? cout << "Yes.\n" : cout << "No.\n";
}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	//since the test case includes decimal, double is used
	double sinA, cosA, tanA;
	vector <double> sides(3); //use a vector to store the three sides since the question does not specify which side is the hypotenuse
	//input the length of three sides
	cout << "Input side x: ";
	cin >> sides[0];
	cout << "Input side y: ";
	cin >> sides[1];
	cout << "Input side z: ";
	cin >> sides[2];
	//sort the three sides in ascending order, so that I can ensure the two smaller sides are the two legs, and the largest side is the hypotenuse
	sort(sides.begin(), sides.end()); 
	//check if the three sides can form a right-angle triangle
	//Again i can directly use sides[n] * sides[n] but I want to use std::pow() instead. Therefore, I include <cmath> header file
	bool isValid = pow(sides[0], 2) + pow(sides[1], 2) == pow(sides[2], 2);
	//obviously I can use bool isValid = pow(sides[0], 2) + pow(sides[1], 2) == pow(sides[2], 2) ? true : false;
	//However, the boolean expression itself already initialize true if it match the condition, so I just assign it directly to isValid
	if (isValid) {
		cout << "The three sides can form a right-angle triangle.\n";
		//calculate sinA, cosA, tanA
		//I assume side1 and side2 are the two legs, side3 is the hypotenuse
		sinA = sides[0] / sides[2];
		cosA = sides[1] / sides[2];
		tanA = sides[0] / sides[1];
		//output with three columns with same width so I use std::setw()
		//output the result with 3 decimal points
		cout << fixed << setprecision(3);
		//Note: setw() only works for the next output item, so I need to use it for each output item
		//Note: fixed must be used because without fixed, the output will correct to 3 scientific figure
		cout << setw(10) << "sinA = " << setw(10) << "cosA = "<< setw(10) << "tanA = \n";
		cout << setw(10) << sinA << setw(10) << cosA << setw(10) << tanA << endl;
	}
	else {
		//output an error message since it cannot form a right-angle triangle
		cout << "Error: Not right-angled triangle.\n";
	}
}

void Q5()
{
	// =====================================
	// Insert your codes for Question 5 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	double intrest_rate = 0, value;
	int type = 0;
	//input the principal value and customer type
	cout << "What is the principal value? ";
	cin >> value;
	cout << "Please enter the customer type: ";
	cin >> type;
	cout << "Interest eate after one year: ";
	//switch case to find the interest rate required to the customer type
	switch (type) {
	case 0:
		intrest_rate = 0.005; //0.5%
		break;
	case 1:
		intrest_rate = 0.008; //0.8%
		break;
	case 2:
		intrest_rate = 0.01; //1%
		break;
	case 3:
		intrest_rate = 0.012; //1.2%
		break;
	case 4:
		intrest_rate = 0.02; //2%
		break;
	default:
		intrest_rate = -1; //invalid type, no interest
		break;
	}
	if (intrest_rate == -1) {
		//output an error message since the customer type is invalid
		cout << "Error in customer type.\n";
	}
	else {
		//calcuate the interest rate after one yaer based on the customer type
		value = value * intrest_rate;
		//check if the value is an integer, if so then remove the decimal point
		//I use floor() and round() in <cmath> to check if the value is an integer
		//If the value is an integer, then floor(value) == round(value)
		if (floor(value) == round(value)) {
			value = round(value);
		}
		//output the interest rate after one year
		cout << "$" << value << endl;
	}
	
}

void Q6()
{
	// =====================================
	// Insert your codes for Question 5 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int day, month, year;
	cout << "Input day month year: ";
	cin >> day >> month >> year;
	//check if the input month is valid
	//check if the input day is valid
	//check if it is a leap year, since February has 29 days in leap year but 28 days in non-leap year
	bool isleapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int daysInMonth;
	switch (month) {
	//first case is the month with 31 days
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		daysInMonth = 31;
		break;
	//second case is the month with 30 days
	case 4: case 6: case 9: case 11:
		daysInMonth = 30;
		break;
	//since February has 29 days in leap year but 28 days in non-leap year, so we need to check whether it is a leap year
	case 2:
		daysInMonth = isleapyear ? 29 : 28;
		break;
	//default case, which are not valid month since we have filter out allvalid cases
	default:
		daysInMonth = 0; 
		break;
	}
	//check if the input day is valid and output the final answer
	//also need to check if the year is positive
	if (day < 1 || day > daysInMonth && year > 0) {
		cout << day << "-" << month << "-" << year << " is incorrect.\n";
	}
	else {
		cout << day << "-" << month << "-" << year << " is correct.\n";
	}
}

// IMPORTANT: DO NOT MODIFY main()
int main()
{
	char prog_choice;

	do {
		cout << "\n\n";
		cout << "Program Selection Menu" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Enter question number ('q' to quit): ";
		cin >> prog_choice;
		cout << "\n\n";

		switch (prog_choice) {
		case '0': showInfo(); break;
		case '1': Q1(); break;
		case '2': Q2(); break;
		case '3': Q3(); break;
		case '4': Q4(); break;
		case '5': Q5(); break;
		case '6': Q6(); break;
		case 'q': break;
		default:
			cout << "No such question " << prog_choice << endl;
			break;
		}
	} while (prog_choice != 'q');
 I need 3.86神力
	cout << "Program terminates. Good bye!" << endl;
	return 0;
}
// END

// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
//#include <cmath> to use std::pow()
#include <cmath>
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
	//output This is Tutorial 1
	cout << "This is Tutorial 1\n";
}

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	double m = 0, cm = 0;
	cout << "Input meter: ";
	//input meter
	cin >> m;
	//convert meter to centimeter
	cm = m * 100;
	//output
	cout << m << "m = " << cm << "cm\n";
}

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	const double pi = 3.14159265;
	//since i don't know whether all inputs are int type so I use double instead
	double r = 0, h = 0, volume = 0;
	//input
	cout << "Enter the radius (in cm): ";
	cin >> r;
	cout << "Enter the height (in cm): ";
	cin >> h;
	//obviously i can directly use r * r but I want to use std::pow() instead. Therefore, I include <cmath> header file
	//times 1.0 to ensure the result is double type(prevent int type division mistake)
	//calculate the volume, just sub formula
	volume = pi * pow(r, 2) * h * 1.0 / 3;
	//output the volume
	cout << "The volume of the cone is " << volume << " cm^3\n";
}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int x = 0;
	double ans = 0;
	cout << "Enter the value of x: ";
	cin >> x;
	//calculate the answer, just sub firmula
	//times 1.0 to ensure the result is double type(prevent int type division mistake)
	//use std::pow() because i am lazy to type once more if I just directly n* n
	ans = pow((3 + 4 * x * 1.0) / 10 - (10 * pow((x - 2), 2) * 1.0 / (x - 3)), 2);
	//output the answer
	cout << "The answer is " << ans << endl;
}

void Q5()
{
	// =====================================
	// Insert your codes for Question 5 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int n = 0, digit1 = 0, digit2 = 0;
	cout << "Enter a two-digit integer: (00 - 99): ";
	cin >> n;
	digit1 = n / 10; //get the first digit
	digit2 = n % 10; //get the second digit
	//output the answer
	cout << "The two digits are " << digit1 << " and " << digit2 << endl;
	//if added a validtion, just use a while loop, as shown as the followed
	//since we don't know how many times the user will input wrong number, so we use while loop
	//while (true) {
		//cout << "Enter a two-digit integer: (00 - 99)";
		//cin >> n;
		//check whether the input is valid, if ture then break the loop
		//if (n >= 0 && n <= 99) {
		//	break;
		//}
	//}
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
		case 'q': break;
		default:
			cout << "No such question " << prog_choice << endl;
			break;
		}
	} while (prog_choice != 'q');

	cout << "Program terminates. Good bye!" << endl;
	return 0;
}
// END

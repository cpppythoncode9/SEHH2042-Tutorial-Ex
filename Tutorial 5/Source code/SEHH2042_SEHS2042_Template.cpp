// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
#include <cmath>
#include <iomanip>
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
	const double PI = 3.14159265;
	cout << "Degree\t\tSin\t\tCos\n";
	for (int i = 0; i<= 360; i += 10) {
		//convert degree to radian
		double r = i * PI / 180.0;
		//print the result with 4 decimal places
		cout << i << "\t\t" << sin(r) << "\t\t" << cos(r) << endl;
	}
}

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	const double PI = 3.14159265;
	cout << "Degree\t\tSin\t\tCos\n";
	for (int i = 0; i<= 360; i += 10) {
		//convert degree to radian
		double r = i * PI / 180.0;
		cout << setw(3) << right << i << "\t\t" << fixed << setprecision(4);
		(i <= 180) ?  cout << "+" : cout << "-";
		cout << sin(r)<< "\t\t";
		//the following confitional operator can have same result
		//(i <= 90 || (i >= 270 && i <= 360)) ? cout << "+" : cout << "-";
		(i > 90 && i < 270) ? cout << "-" : cout << "+";
		cout << cos(r) << endl;
		//Note: unsetf() is used to reset the format flags of cout
		//otherwise, all output will be fixed with 4 decimal places after calling Q2()
		cout.unsetf(ios::fixed);
	}
}
you need wow sauce 
double integerPower(double n, int exp) {
	//filter out the base cases
	//since n^0 = 1, where n belongs to R\{0}
	//Meanwhile, this is also the terminating condition for recursion
	//if (exp == 0) {
		//return 1;
	//}
	//for positive exponents
	//if (exp > 1) {
		//return n * integerPower(n, exp - 1);
	//}
	//for negative exponents
	//no need to add else since all other conditions are filtered out
	//and return value is required in non-void function
	//return (1 / n) * integerPower(n, exp + 1);\
	//The above code is my initial idea
	//However, the segmentation fault occurs when exp = 0
	//Thus, I use for loop to implement the function
	//make exp positive before calculation is exp is negative
	int temp = exp; //store the original value of exp
	double result = 1.0; //initialize result
	if (exp < 0) {
		exp = -exp; 
	}
	for (int i = 1; i <= exp; i++) {
		//multiply n by itself |exp| times
		result *= n;
	}
	//since the negative exponent is just 1 / (n^|exp|), so I can just use a for loop
	//then return the result based on the sign of temp (original exp)
	return (temp >= 0) ? result : (1 / result);
}
void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	double n;
	int exp;
	//input base value
	cout << "Enter the base value: ";
	cin >> n;
	//input exponent value
	cout << "Enter the exponent value: ";
	cin >> exp;
	//call the integerPower function to calculate n^exp by using recursion
	cout << n << " to the power of " << exp << " is " << integerPower(n, exp) << endl;
}
//user-defined function nChar()
void nChar(int n, char c) 
{
	for (int i = 0; i < n; i++)
		cout << c;
}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//print pattern (a)
	for (int i = 1; i <= 5; i++) {
		//note: i must be start from 1 since in nChar(), the loop is iterated from 0 to n-1
		//print i stars
		nChar(i, '*');
		cout << endl;
	}
	//print pattern (b)
	for (int i = 1; i <= 5; i++) {
		//note: i must be start from 1, the reason as same as (a)
		//print (5-i) spaces first
		nChar(5 - i, ' ');
		//then print i stars
		nChar(i, '*');
		cout << endl;
	}
	//print pattern (c)
	int p = 1; //number of stars in each row
	for (int i = 1; i <= 5; i++) {
		//note: i must be start from 1, the reason as same as (a)
		int l = (9 - p) / 2; //number of leading spaces
		//print leading spaces
		nChar(l, ' ');
		//print stars
		nChar(p, '*');
		nChar(l, ' '); //print trailing spaces (same as leading spaces)
		cout << endl;
		p += 2; //increase number of stars by 2 for next row
	}
	//print pattern (d)
	p = 1; //reset number of stars in each row
	for (int i = 1; i <= 9; i++) {
		//note: i must be start from 1, the reason as same as (a)
		int l = (9 - p) / 2; //number of leading spaces
		//print leading spaces
		nChar(l, ' ');
		//print stars
		nChar(p, '*');
		nChar(l, ' '); //print trailing spaces (same as leading spaces)
		cout << endl;
		(i >= 5) ? p -= 2 : p += 2; 
		//if i >= 5, decrease number of stars by 2 for next row
		//else, increase number of stars by 2 for next row
	}
	//print pattern (e)
	//pattern (e) is just print pattern (c) by 3 times
	for (int i = 1; i <= 3; i++) {
		//note: j must be start from 1, the reason as same as (a)
		int p = 1; //number of stars in each row
		for (int j = 1; j <= 5; j++) {
			int l = (9 - p) / 2; //number of leading spaces
			//note: the reson why divide by 2 is that the total number of spaces is (9 - p),
			//and the leading spaces and trailing spaces are the same
			//print leading spaces
			nChar(l, ' ');
			//print stars
			nChar(p, '*');
			nChar(l, ' '); //print trailing spaces (same as leading spaces)
			cout << endl;
			p += 2; //increase number of stars by 2 for next row
		}
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

// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes
相信自己，一個夜晚，一個奇蹟
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
	double side1, side2, hypotenuse;
	//input side1 and side2
	cout << "Please enter the length of first side: ";
	cin >> side1;
	cout << "Please enter the length of second side: ";
	cin >> side2;
	//calculate hypotenuse using Pythagorean theorem(hypotenuse^2 = side1^2 + side2^2)
	hypotenuse = sqrt(pow(side1, 2) + pow(side2, 2));
	//print the hypotenuse
	cout << "Hypotenuse of a " << side1 << " by " << side2 << " right triangle is " << hypotenuse << endl;
	
}
//note: pass-by-reference is used for sum and average
//so that the calculated sum and average can be returned to the caller
int sumAvg(int lower, int upper, int &sum, float &average) {
	//initialize sum and count
	sum = 0;
	int count = 0;
	//calculate sum and count of numbers from lower to upper
	for (int i = lower; i <= upper; i++) {
		sum += i;
		count++;
	}
	//remember to cast sum to float to avoid integer division(prevent floating point argument loss)
	average = static_cast<float>(sum) / count;
	//since no variable stored the returned value from sumAvg() in the original function prototype(void Q2()) 
	//return 0 to indicate successful execution
	return 0;
}
void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//code form T6_Q2.cpp
	int lower, upper, sum;
	float average;

	cout << "Enter the lower bound: ";
	cin >> lower;
	cout << "Enter the upper bound: ";
	cin >> upper;

	sumAvg(lower, upper, sum, average);

	cout << "From " << lower << " to " << upper << ":\n";
	cout << "Sum     = " << sum << endl;
	cout << "Average = " << average << endl;

}

double calcPI(int terms) {
	//using recursion to calculate PI
	if (terms == 1) {
		return 4.0; //base case
	}
	//recursive case
	//check the parity of terms to determine the sign of the term
	//if terms is odd, add the term into PI else subtract the term into PI
	double term = (terms % 2 == 1) ? 4.0 / (2 * terms - 1) : -4.0 / (2 * terms - 1);
	//call calcPI() recursively to get the sum of remaining terms
	//until the base case is reached(terms == 1)
	//then add the return value from previous term to the current term
	//this process continues until all terms are added up (subtract down)
	return term + calcPI(terms - 1);
}
void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int terms;
	cout << "How many terms for PI: ";
	//input number of terms
	cin >> terms;
	//call the calcPI() function to calculate PI
	double pi = calcPI(terms);
	//output PI with 15 decimal places
	cout << "PI with " << terms << " terms is " << fixed << setprecision(15) << pi << endl;
	//remember to unset the format flag of cout
	cout.unsetf(ios::fixed);
}

void printBinary(int num) {
	//base case: if num is 0, return
	if (num == 0) {
		return;
	}
	//print the binary representation of num/2 first (recursive call)
	printBinary(num / 2);
	//then print the least significant bit of num
	cout << (num % 2);
	//Note: if the range of num is larger than long long,
	//i will use dynamic programming to store the binary digits in an array/vector
	//then print the array/vector in reverse order
	//this can avoid stack overflow due to deep recursion
	//but for this question, the range of int is sufficient(and the question requirment is using recursion)
	//so just recursion can meet the requirement
	//if using dynamic programming, the code will be like this:
	//no need to declared size of vector dp since std::push_back() is used
	//note: include <vector> header file is needed
	//initialize vector dp to store binary digits
	//vector<int> dp;
	//while (num > 0) {
	//	  //store the binary digits in reverse order
	//    //insert the least significant bit at the back of the vector
	//    dp.push_back(num % 2);
	//    //update num by dividing it by 2
	//    num /= 2;
	//}
	//print the binary digits in reverse order
	//for (int i = dp.size() - 1; i >= 0; i--) {
	//    cout << dp[i];
	//}
}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//code form T6_Q4.cpp
	int num;

	cout << "Input a positive decimal integer: ";
	cin >> num;

	cout << "The binary version is ";
	printBinary(num);
	cout << endl;
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

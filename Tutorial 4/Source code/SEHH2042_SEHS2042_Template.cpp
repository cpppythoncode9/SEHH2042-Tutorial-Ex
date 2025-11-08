// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes
群主們的女裝債係有生之年系列
// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
//since std::vector is used in Q2, include <vector> header file
#include <vector>
#include <iomanip>
//since std::setw() function is used in Q3, include <algorithm> header file
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
	int n;
	while (n > 0) {
		cout << "Enter a positive integer: ";
		cin >> n;
		//check if n is positive
		//not possible to find a factor in negative number
		//or zero
		if (n <= 0) {
			cout << "Only positive integer is accepted. Program ends.\n";
		}
		else {
			//There are different ways to find factors, and have different iteraotrs to store all factors
			//For example, std::priority_queue, std::vector, std::list, std::set, std::multiset, etc.
			//or we can use std::vector<std::part<int, int>> to store all factors n
			//Now find alll the factors of n first
			//since i don't want to use extra sapce to store ll factors, I will print out the factors directly
			//although the run time cannot be optimized
			//print out all factors of n
			cout << "Factors of " << n << " : ";
			for (int i = 1; i <= n; i++) {
				//i is a factor of n if and only if n % i == 0 (remainder is 0)
				(n % i == 0) ? cout << i << " " : cout << "";
			}
			cout << endl;
		}
	}
}

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	//since the question mention to find all prime numbers between 1 and 200
	//so n is fixed to 200
	//that's why i use const int type
	const int n = 200;
	//use Sieve of Eratosthenes to the ith number check it's a prime number or not
	//I know this method because I have solve the similar question in HKOI when I was F5
	//use a boolean array(vector) to store whether the number is prime or not
	vector <bool> is_prime(n + 1, 1);
	//initialize is_prime[0] and is_prime[1] to false since 0 and 1 are not prime numbers
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		//if is_prime[i] is true, then mark all multiples of i as false
		//start from i*i because all smaller multiples of i have already been marked as false
		//the loop continues until i*i > n
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				//filter out all multiples of i
				//mark is_prime[j] as false
				is_prime[j] = 0;
			}
		}
	}
	//output all prime numbers between 1 and 200
	//variable check is used to check whether to print a new line or not
	int check = 0;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			cout << setw(3) << i << " ";
			check++;
		}
		//print a new line after every 10 prime numbers
		if (check % 10 == 0 && check != 0) {
			//reset check to 0 for preventing unecessary new line
			check = 0;
			cout << endl;
		}
	}
}

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	const int n = 100000;
	double var = 1.0;
	//I prevent unecpected error occur so I use long double instead of double
	long double pi = 0.0;
	cout << setw(10) << "Terms" << setw(20) << "Value of Pi" << endl;
	cout << setw(10) << "-----" << setw(20) << "-----------" << endl;
	//use for loop to calculate pi in n terms
	for (int i = 10; i <= n; i *= 10) {
		pi = 0.0; //reset pi to 0 for each iteration
		for (int j = 1; j <= i; j++) {
			//use the formula to calculate pi
			//check if j is odd or even
			//if j is odd, add the term
			//else, subtract the term
			var = 4.0 / (2 * j - 1);
			(j % 2 == 0) ? pi -= var : pi += var;
		}
		//output the result pi with fixed point notation and 15 decimal places
		cout << setw(10) << i << setw(20) << fixed << setprecision(15) << pi << endl;
	}

}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int size;
	cout << "Pattern size: ";
	cin >> size;
	//print the pattern
	//now print part(a) first
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//print * at the border of the square
			(i == 1 || i == size || j == 1 || j == size) ? cout << "*" : cout << " ";
		}
		cout << endl;
	}
	//now print part(b)
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//print * at the diagonals of the square
			(i == 1 || i == size || i == j) ? cout << "*" : cout << " ";
		}
		cout << endl;
	}
	//now print part(c)
	//Note: part(c) is the reverse diagonals of part(b)
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//print * at the reverse diagonals of the square
			(i == 1 || i == size || i + j == size + 1) ? cout << "*" : cout << " ";
			
		}
		cout << endl;
	}
	//Now print part(d)
	//part (d) is a combination of part (b) and (c)
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//print * at the border and both diagonals of the square
			(i == 1 || i == size || i == j || i + j == size + 1) ? cout << "*" : cout << " ";
		}
		cout << endl;
	}
	//Now print part(e)
	//Part (e) is a combination of part (a) and (d) 
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size; j++) {
			//print * at the border and both diagonals of the square
			(i == 1 || i == size || j == 1 || j == size || i == j || i + j == size + 1) ? cout << "*" : cout << " ";
		}
		cout << endl;
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

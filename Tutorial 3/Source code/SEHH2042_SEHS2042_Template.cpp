// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
//since std::vector is used in Q5, include <vector> header file
#include <vector>
//since std::swap() function is used in Q3, include <algorithm> header file
#include <algorithm>
//since std::floor() and std::ceil() functions are used in Q4, include <cmath> header file
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
	//initialize variables
	//use srand() and rand() functions to generate a random number
	//include <cstdlib> and <ctime> header files
	//if the guess number is random
	//srand(time(0));
	//int guess = rand() % 100 + 1;
	//Note: must be % 100 + 1, otherwise the number will be between 0 and 99
	//but since the guess number is fixed, no need to use srand() and rand()
	int input, guess = 31;
	//since I don't know how many times the user will input, a while loop is used
	//since the loop must be executed at least once, a do-while loop is used instead of a while loop
	cout << "I have a number between 1 and 100.\n";
	cout << "Can you guess my number?\n";
	do {
		//ask user for input
		cout << "Guess: ";
		cin >> input;
		if (input < guess) {
			cout << "Too low. Try again.\n";
		}
		else if (input > guess) {
			cout << "Too high. Try again.\n";
		}
	}
	while (input != guess);
	cout << "Excellent! Correct guess.\n";
}

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	//initialially I want to use recursion to solve this problem
	//but I need to input the number of lines first
	//so I use iteration instead
	int n;
	//use long long to avoid overflow
	//if the range is too large, I will use string to do this
	//but since the range is not that large, long long is enough
	//since 0! = 1, I initialize factorial to 1
	long long factorial = 1;
	//input n
	cout << "n: ";
	cin >> n;
	//since n! = n * (n-1)!, I use a for loop to calculate the factorial
	//start from 2 because 1! = 1 and 0! = 1
	//if start from 1, it will be redundant
	//Note: if n = 0 or n = 1, the for loop will not be executed (fatorial = 1) so no need to use if statement to handle these two cases
	//Note: the maximum value of n is 20, because 21! is larger than the maximum value of long long
	//If n > 20, use string is recommended
	//But I don't think the question will test for n > 20 :)
	for (int i = 2; i <= n; i++) {
		factorial *= i;
	}
	//output the result
	//since the question mention n must be a non-negative integer so no need to handle negative n
	cout << n << "! = " << factorial << endl;
}

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int a, b, sum = 0;
	//input a and b
	cout << "Please input value A: ";
	cin >> a;
	cout << "Please input value B: ";
	cin >> b;
	//if a > b, swap a and b since I want the for loop always start from the smaller number which is a
	//otherwise, the for loop will not work
	//use the built-in swap() function to swap a and b
	if (a > b) {
		swap(a, b);
	}
	//use a for loop to add all odd numbers between a and b
	for (int i = a; i <= b; i++) {
		//if i is odd, add i to sum
		if (i % 2 != 0) {
			sum += i;
		}
	}
	//output the result
	cout << "Sum of odd integers from " << a << " to " << b << " is " << sum << endl;
}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	double base;
	int exponent;
	//input base and exponent
	cout << "Enter the base value: ";
	cin >> base;
	cout << "Enter the exponent value: ";
	cin >> exponent;
	//use for loop to calculate the power//initially I want to use pow() function to calculate the power
	//but since the question mention to use for loop, I use for loop instead
	//if exponent = 0, the result is 1
	double result = 1.0;
	if (exponent > 0) {
		for (int i = 1; i <= exponent; i++) {
			result *= base;
		}
	}
	//if exponent < 0, the result is 1 / (base ^ -exponent)
	//In the other words, multiply base -exponent times and then take the reciprocal
	//That's why I use result /= base
	else if (exponent < 0) {
		for (int i = 1; i <= -exponent; i++) {
			result /= base;
		}
	}
	//if exponent = 0, result = 1 (already initialized)
	//check if result is an integer
	if (floor(result) == ceil(result)) {
		//if result is an integer, use static_cast to convert double to int
		result = static_cast<int>(result);
	}
	//output the result
	cout << base << " to the power " << exponent << " is " << result << endl;
}

void Q5()
{
	// =====================================
	// Insert your codes for Question 5 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int n;
	//input n
	cout << "Input a positive integer: ";
	cin >> n;
	//Note: if you handle negaive n, the stl_bvector.h will catch and throw an error message since I use n to initialize a vector with size n+1
	//So I just assume n is a positive integer as the question mentioned
	//use Sieve of Eratosthenes to check it's a prime number or not
	//I know this method because I have solve the similar question in HKOI when I was F5
	//use a boolean array to store whether the number is prime or not
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
	//check if n is prime or not
	//Note: All negstive numbers, 0 and 1 are not prime numbers
	(is_prime[n]) ? cout << n << " is a prime number.\n" : cout << n << " is not a prime number.\n";
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

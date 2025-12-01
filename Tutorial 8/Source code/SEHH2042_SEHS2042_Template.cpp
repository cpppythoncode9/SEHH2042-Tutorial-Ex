// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
#include <cstdlib>
#include <iomanip>
//since multiset is used in Q4 so #include <set>
#include <set>  
#include <cmath> //for using max() function
using namespace std;

void showInfo()
{
	// Fill in your personal particulars below
	"Name      : HIDDEN\n";
	"Student ID: HIDDEN\n";
	"Class     : A01A\n";
}

// Function prototypes
void printData(int list[], int size, int num);
void printBar(int list[], int size);
int largest(int list[], int size);
double average(int list[], int size);
void maxAppear(int list[], int size, int &max, int &freq);

void printData(int list[], int size, int num) {
	for (int i = 0; i < size; i++) {
		//output the integers stored in the array for n times
		cout << setw(5) << right << list[i] << " ";
		//output 5 in a row
		if ((i + 1) % num == 0) {
			//if num integers have been outputted, then output a new line
			cout << "\n";
		}
	}
	cout << "\n";
}
void Q1()
{
	// =====================================
	// Insert your codes for Question 1 here
	// No need main() and return 0
	// =====================================
	//initialize variables and create an iterator with size 20
	//the code is followed by the question requirement
	int n, data[20];
	cout << "How many integers to enter? ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "? ";
		//input data into the array for n times
		cin >> data[i];
	}
	//call the function printData() to print the data
	cout << "The input integers are:\n";
	printData(data, n, 5);
}

void printBar(int list[], int size) {
	cout << "The bar chart is:\n";
	for (int i = 0; i < size; i++) {
		//output the integers stored in the array for n times
		//print '*' according to the value of each integer
		for (int j = 0; j < list[i]; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}
void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	//hence from Q1
	int n, data[20];
	cout << "How many integers to enter? ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "? ";
		//input data into the array for n times
		cin >> data[i];
	}
	//call the function printBar() to print the bar chart
	printBar(data, n);
}

int largest(int list[], int size) {
	//innitialize max value as the first integer in the array
	int max = list[0];
	//assume the first integer is the largest
	for (int i = 1; i < size; i++) {
		//compare with the rest integers
		if (list[i] > max) {
			//if any integer is larger than max, update max
			max = list[i];
		}
	}
	//return the largest integer in the array
	return max;
}

double average(int list[], int size) {
	//initialize sum variable
	int sum = 0;
	//note: if don't want to use for loop to sum up all elements, you can use std::accumulate from <numeric> header
	//For example, sum = std::accumulate(list, list + size, 0);
	//remember to include <numeric> header first if using std::accumulate
	for (int i = 0; i < size; i++) {
		//add up all integers in the array
		sum += list[i];
	}
	//return the average value
	//use static_cast to convert int to double for accurate division
	return static_cast<double>(sum) / size;
}
void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int seed, data[20];
	cout << "Enter seed value: ";
	cin >> seed;
	//set the seed for random number generation
	srand(seed);
	//generate 20 random integers between 1 and 100
	for (int i = 0; i < 20; i++) {
		data[i] = rand() % 100 + 1;
	}
	//output the largest integer
	cout << "The random integers are:\n";
	//call the function printData() to print the data
	printData(data, 20, 5);
	//call the function largest() to find the largest integer
	cout << "The largest integer is: " << largest(data, 20) << endl;
	//call the function average() to find the average value
	cout << "The average value is: " << average(data, 20) << endl;
}

void maxAppear(int list[], int size, int &max, int &freq) {
	//find the max freq of the integers
	//if more than one integer has the same freq, return the first one found
	//use multiset to count the frequency of each integer
	//note: you can directly write "multiset<int> ms(list, list + size);" to initialize the multiset
	//instead of inserting elements one by one using for loop
	//note: sice sd::multiset allows duplicate elements while std::set only allows unique elements
	//so multiset is more suitable for this question(you can use std::unordered_map as well)
	multiset <int> ms(list, list + size);
	for (int i : ms) {
		//use if-condition to upfated the maximun frequency
		//note: i use static_cast<int> to convert size_t to int to avoid warning(due to my compiler settings)
		if (static_cast<int>(ms.count(i)) > freq) {
			//update freq if a larger frequency is found
			freq = static_cast<int>(ms.count(i));
		}
	}
	//find the integer with the maximum frequency
	//since i don't know how many time it iterated, so use while-loop
	//initialize pos to 0
	int pos = 0;
	while (true) {
		//if the frequency of the integer at position pos equals to freq
		if (ms.count(list[pos]) == freq) {
			//set max as that integer
			max = list[pos];
			break; //exit the loop
		}
		//else, move to the next position
		pos++; 
	}
}
void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//initialize variables
	int seed, data[100];
	cout << "Enter seed value: ";
	cin >> seed;
	//set the seed for random number generation
	srand(seed);
	//generate 100 random integers between 1 and 100
	for (int i = 0; i < 100; i++) {
		data[i] = rand() % 100 + 1;
	}
	cout << "The random integers are:\n";
	//call the function printData() to print the data
	printData(data, 100, 10);
	//initialize max as the minimum integer value
	//initialize max as the first element in the array 
	int max = data[0]; 
	//initialize freq as 1 since at least one occurrence of the integer
	int freq = 1;
	//call the function maxAppear() to find the integer that appears the most and its frequency
	maxAppear(data, 100, max, freq);
	//output the result
	cout << max << " appears the most with " << freq << " times.\n";
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

// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
using namespace std;
pointer is very easy and basic right
void showInfo()
{
	// Fill in your personal particulars below
	"Name      : HIDDEN\n";
	"Student ID: HIDDEN\n";
	"Class     : A01A\n";
}

void swapInteger(int *, int *); //function prototype for Q2
void printArray(const int [], int); //function prototype for Q3
void multiplyArray(int * const, int, int); //function prototype for Q3
void Q1()
{
	// =====================================
	// Insert your codes for Question 1 here
	// No need main() and return 0
	// =====================================
	//initialize integer x and an array y
	int x = 1;
	int y[5] = {10, 20, 30, 40, 50};
	//initialize two poiners xPtr and yPtr
	int *xPtr = &x;
	int *yPtr = y; //array name is pointer to first element
	//note: &x is address of x, but &y is address of whole array y
	//*xPtr dereferences the pointer to get value of x
	//*yPtr dereferences the pointer to get first element of array y
	//note: it is totally different for *(yPtr + 2) and *yPtr + 2
	//for first one, it gets the 3rd element of array y(move the pointer 2 steps forward first, then dereference it)
	//for second one, it gets the value of first element of array y, then add 2 to it
	//juts basice pointer concept for me:)
	//output followed from the tutorial class:)
	cout << "Address of x = " << &x << endl;
	cout << "Address of y = " << y << endl << endl;
	//still output the address of x and y since xPtr and yPtr store the memory address of x and y
	cout << "xPtr = " << xPtr << endl;
	cout << "yPtr = " << yPtr << endl << endl; 
	//output the value of x and y
	cout << "*xPtr = " << *xPtr << endl;
	cout << "*yPtr = " << *yPtr << endl << endl; 
	//add the value of yPtr by 2
	cout << "*yPtr + 2 = " << *yPtr + 2 << endl;
	//move the position of list y[] by 2, now the pointer point to y[2]
	cout << "*(yPtr + 2) = " << *(yPtr + 2) << endl << endl;
	//updated xPtr be yPtr + 2
	xPtr = yPtr + 2;
	//add the value of xPtr by 1
	(*xPtr)++;
	//add the value of yPtr by 1
	(*yPtr)++;
	//since the value of x does not changed, so x still = 1
	cout << "x = " << x << endl;
	cout << "*xPtr = " << *xPtr << endl;
	cout << "*yPtr = " << *yPtr << endl;
	cout << "*(yPtr + 2) = " << *(yPtr + 2) << endl;
}

void swapInteger(int *x, int *y)
{
	// =====================================
	// Insert your codes for swapping here
	// =====================================
	int temp;
	temp = *x; //store value pointed by a into temp
	*x = *y;   //store value pointed by b into location pointed by a
	*y = temp; //store value in temp into location pointed by b
}

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//code copied from T10_Q2.cpp
	int x = 2, y = 5;
	
	cout << "Before swapping:" << endl;
	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;

	// call swapInteger here...
	swapInteger(&x, &y);
	cout << "After swapping:" << endl;
	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;
}

void printArray(const int arr[], int size)
{
	//use for loop to print array elements
	const int *ptr = arr; //initialize pointer to point to first element of array
	//since the arr[] is constant, so the pointer should also be constant pointer
	for (int i = 0; i < size; i++) {
		cout << *(ptr + i) << " "; //dereference the pointer to get array element
	}
	cout << endl;
}

void multiplyArray(int * const arr, int size, int factor)
{
	//use for loop to multiply each element by factor
	for (int i = 0; i < size; i++) {
		*(arr + i) = *(arr + i) * factor; //dereference the pointer to get array element and multiply by factor
	}
}

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//code copied from T10_Q3.cpp
	const int arraySize = 10;

	int c[arraySize] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	
	cout << "Before multiplyArray, array is: ";
	printArray(c, arraySize);

	// Function call on multiplyArray
	// Insert your codes here

	cout << "After multiplyArray, array is: ";
	multiplyArray(c, arraySize, 3); //multiply each element by 3
	printArray(c, arraySize);
}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//code copied from T10_Q4.cpp
	char *buffer = new char [100];	// reserve 100 characters
	char *word[10] = {};			// initialize all pointers to 0 (NULL)

	// Your code should be inserted here
	//input a line of text
	cout << "Enter a sentence with at most 10 words and 100 characters: ";
	cin.ignore(); //ignore the newline character left in the input buffer
	cin.getline(buffer, 100, '\n'); //read a line of text into buffer
	//spilt the line into words and store the address of each word into word array
	char *ptr = buffer; //initialize pointer to point to the first character of buffer
	int index = 0; //initialize index for word array
	while (*ptr != '\0' && index < 10) { //loop until end of buffer or word array is full
		//skip leading spaces
		while (*ptr == ' ') {
			ptr++;
		}
		if (*ptr == '\0') {
			break; //end of buffer
		}
		word[index] = ptr; //store the address of the first character of the word
		index++;
		//move pointer to the end of the word
		while (*ptr != ' ' && *ptr != '\0') {
			ptr++;
		}
		if (*ptr == '\0') {
			break; //end of buffer
		}
		*ptr = '\0'; //replace space with null character to terminate the word
		ptr++; //move pointer to the next character
	}
	for (int i = 0; i < 10; i++)
		if (word[i] != 0)			// check if it is a NULL pointer
			cout << i << ": " << word[i] << endl;

	//free the allocated memory, although the question does not ask for it
	//but it is a good practice to avoid memory leak
	delete [] buffer;					
	//another method without using pointer is use stringstream from <sstream> header
	//the code will be like this:
	//assuming the code is placed after the input
	//stringstream ss;
	//note: need to include <sstream> header file
	//note: in c++, << is used to insert data into stream
	//note: in c++, >> is used to extract data from stream
	//ss << buffer;
	//initialize temporary string to store each word
	//string temp;
	//int index = 0;
	//iterate to extract each word from stringstream
	//while (ss >> temp && index < 10) {
	//	allocate memory for each word and copy the word from temp to word array
	//	word[index] = new char [temp.length() + 1];
	//  copy the content of temp to word[index]
	//	strcpy(word[index], temp.c_str());
	//  increment index
	//	index++;
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


// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes

// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
#include <cstring>
//include <cstring> for Q3
#define _CRT_SECURE_NO_WARNINGS
//add this to avoid error for using standard C functions like strcpy(), strcat(), etc. in microsoft visual studio
//i hate microsoft visual studio :( 
//all my work(tutorial ex. 1-10) are done in Visual Studio Code(the blue logo one) in week 1:)
//Visual Studio Code my goat:)
using namespace std;

void showInfo()
{
	// Fill in your personal particulars below
	"Name      : HIDDEN\n";
	"Student ID: HIDDEN\n";
	"Class     : A01A\n";
}

void swapString(char [], char []);	// function prototype from T9_Q2.cpp
// Global constants for Question 4
const int NMSG = 3;		// (Global) maximum no. of messages
const int MAXLEN = 80;	// (Global) maximum length of each message
void printReverse(char [][MAXLEN]);	// function prototype from T9_Q4.cpp

void Q1()
{
	// =====================================
	// Insert your codes for Question 1 here
	// No need main() and return 0
	// =====================================
	//initialize an char array text with size 100
	char text[100];
	//input text
	cout << "Enter a string: ";
	cin >> text;
	for (int i = 0; text[i] != '\0'; i++) {
		//check if the character is lowercase letter
		//also you can write asASCI code directly
		//if (text[i] >= 97 && text[i] <= 122) {
		//where 97 is the ASCII code for 'a' and 122 is the ASCII code for 'z'
		//}
		if (text[i] >= 'a' && text[i] <= 'z') {
			//convert to uppercase letter
			text[i] = text[i] - ('a' - 'A');
		}
		//another method:
		//if (islower(text[i])) {
		//	text[i] = toupper(text[i]);
		//}
		//note: you need to include <cctype> header file for toupper() ans islower() function first
	}
	//output the converted text
	cout << "Converted string is: " << text << endl;
}

void swapString(char w1[], char w2[]) {
	int pos = 0;
	//swap w1 and w2 character by character
	//if the size of w2 is larger than w1, the remaining characters of w2 will not be changed
	//also if the size of w1 is larger than w2, the remaining characters of w1 will not be changed
	while (w1[pos] != '\0' && w2[pos] != '\0') {
		//apply temp character to swap
		char temp = w1[pos];
		//copied the pos th character from w1 to w2 and vice versa
		//then move to next position
		w1[pos] = w2[pos];
		w2[pos] = temp;
		//another method using std::swap from <algorithm> header
		//swap(w1[pos], w2[pos]);
		pos++;
	}
}
void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//code from T9_Q2.cpp
	char w1[20], w2[20];

	cout << "Enter the two words (separated by space): ";
	cin >> w1;
	cin >> w2;

	cout << "Before swapping, words are:\n";
	cout << w1 << endl << w2 << endl;

	// Function call on swapString
	// Insert your code here
	swapString(w1, w2);
	cout << "After swapping, words are:\n";
	cout << w1 << endl << w2 << endl;
}

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//code from T9_Q3.cpp
	char buffer[80];
	char msgs[10][15] = {
		"a", "ab", "abc", "abcd", "abcde", "abcdef", 
		"abcdefg", "abcdefgh", "abcdefghi", "abcdefghij"
	};
	
	// Put strings in msgs into buffer
	// Your codes should be inserted here.
	//initialize buffer as empty string
	//also you can use buffer[0] = 0; or strcpy(buffer, "");
	buffer[0] = '\0';
	for (int i = 0; i < 10; i++) {
		//concatenate msgs[i] to buffer
		//remember to add '\n' after each msgs[i]
		//note: use strcat_s() instead of strcat() in microsoft visual studio(prevent error)
		strcat_s(buffer, msgs[i]);
		strcat_s(buffer, "\n");
	}
	// Print the buffer content
	cout << "buffer is:" << endl;
	cout << buffer;

	// Show the length of buffer, using strlen()
	//note: size variable is calculated in the above for loop
	// Your codes should be inserted here.
	cout << "Length of buffer is: " << strlen(buffer) << endl;
}
void printReverse(char messages[][MAXLEN]) {
	//print the messages in reverse order since the order is follewed the property of stack(LIFO), which means last in first out
	//note: followed the sample result from question, so skip line before output(use '\n' or std::endl)
	cout << "\nThe messages are printed in a last-in-first-out sequence.\n";
	cout << "Characters in each message are printed in a reverse order.\n";
	//now iterate from the last message to the first message
	for (int i = NMSG - 1; i >= 0; i--) {
		cout << "Message " << i << ": "; 
		//get the size of each message using strlen() before output 
		int size = strlen(messages[i]);
		//print each message in reverse order
		//so just output from the last character to the first character
		for (int j = size - 1; j >= 0; j--) {
			cout << messages[i][j];
		}
		cout << endl;
	}
}
void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//code from T9_Q4.cpp
	char message[NMSG][MAXLEN];

	// Your code should be inserted here
	
	cin.ignore(255, '\n');
	//cin.ignore() is used to clear the input buffer before using cin.getline()
	//otherwise, the '\n' character from previous input will be read by cin.getline()
	//This will cause the first message to be empty
	//for example, if the previous input is an integer followed by pressing Enter key
	//the '\n' character from pressing Enter key will remain in the input buffer
	//I have faced this error before when solving questions in HKOI during secondary school life:(
	for (int i = 0; i < NMSG; i++) {
		//Note: 255 is an arbitrary large number to clear the input buffer
		//in general, 255 is most commonly used
		cout << "Enter message " << i << ": ";
		cin.getline(message[i], MAXLEN, '\n');
	}
	//call printReverse function to print messages in reverse order
	printReverse(message);
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

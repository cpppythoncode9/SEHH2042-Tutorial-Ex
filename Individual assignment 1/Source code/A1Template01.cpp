// SEHH2042/SEHS2042 Assignment 1
// Program template file: A1Template.cpp
// Do not modify the given codes (keep the comments)
史上最強bh VS 當代最強yoink大帝
// Insert more header files when necessary
#include <iostream>
// For std::fixed and std::setprecision
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
	// Insert your codes for Question 1 here
	cout << "Q1 Program Output - Odd Version\n"; 
	int Y = 3; 
 
	for (int k = 1; k <= 3; k++) { 
		cout << Y << ":"; 
		do { 
			cout << "A-"; 
			Y += 3; 
		} while (Y < 10); 
		cout << endl; 
	} 

}

void Q2()
{
	// Insert your codes for Question 2 here
	//initialize variables
	double distance, total, basic_charge = 34.0;
	int time, surcharge, mode;
	//input total distance
	cin >> distance;
	//input total waiting time
	cin >> time;
	//input dynamic pricing mode
	cin >> mode;
	//input surcharge
	cin >> surcharge;
	//since the first 2 km is included in the basic charge
	//so just directly minus 2 from distance first
	distance -= 2;
	//calculate basic charge
	//It seems that there are some error during the iteration of while loop
	//So I use the condition "distance >= 0.2" instead of "distance > 0"
	while (distance >= 0.2) {
		basic_charge += (basic_charge >= 130) ? 1.9 : 2.4;
		distance -= 0.2;
	}
	//The same for time
	//So I use the condition "time >= 2" instead of "time > 0"
	while (time >= 2) {
		basic_charge += (basic_charge >= 130) ? 1.9 : 2.4;
		time -= 2;
	}
	//calculate total charge according to different mode
	switch (mode) {
		case 1:
			//10% discount
			total = basic_charge * 0.9 + surcharge;
			break;
		case 2:
			//normal charge
			total = basic_charge + surcharge;
			break;
		case 3:
			//peak hour charge (10% increase)
			total = basic_charge * 1.1 + surcharge;
			break;
		default:
			//although the question does not mention this case
			//but it is a good practice to have a default case even through nothing to do in default case
			//why don't push case 3 as default because it is more clear and safer
			//since it can prevent some unexpected error
			break;
	}	
	//output total charge with 2 decimal places
	cout << fixed << setprecision(2) << total << endl;
}

void Q3()
{
	// Insert your codes for Question 3 here
	int row;
	cin >> row;
	//check if the input is valid
	//row should be positive odd number
	//if not, output "E"(impossible to form the pattern)
	if (row <= 0 || row % 2 == 0) {
		cout << "E\n";
	}
	else {
		//calculate the number of columns
		//it is always odd number
		//since col, mid, col_mid are always constant during the whole process
		//so declare them as const
		//left and right will change during the process
		//so declare them as normal int
		//mid is the middle row
		//col_mid is the middle column
		//col is the total number of columns(refer to the question diagram)
		//left and right are the positions of "^"
		const int col = row * 2 - 1;
		const int mid = row / 2 + 1;
		const int col_mid = col / 2 + 1;
		int left = col / 2 + 1;
		int right = col / 2 + 1;
		//display the pattern
		//use nested for loop to display the pattern row by row
		for (int i = 1; i <= row; i++) {
			//for each row, display column by column
			//use conditional operator to determine what to display although it is a bit complicated and low readability
			//but it can reduce the number of lines of codes
			//and it can provided my original idea clearly
			//the conditions are listed according to the priority
			for (int j = 1; j <= col; j++) {
				//first check if it is the border
				//if yes, display "*"
				//then check whether it is the middle row and left equals right and at the middle column(this is mainly to handle the case when row = 3)
				//if yes, display "|"
				//Note: this condition must be put before the next two conditions otherwise it will be affected by the next two conditions
				//then check whether it is above the middle row and at the position of left or right or it is the middle row and left not equals right and at the position of left or right
				//if yes, display "^"
				//then check whether it is below the middle row and at the middle column or it is the middle row and left not equals right and at the middle column
				//if yes, display "|"
				//if none of the above, display " "
				//To clarify the logic, here is the if-else version of the same logic
				//if (i == 1 || i == row || j == 1 || j == col) {
				//    cout << "*";
				//}
				//else if (i == mid && left == right && j == col_mid) {
				//    cout << "|";
				//}
				//else if ((i < mid && (j == left || j == right)) || (i == mid && left != right && (j == left || j == right))) {
				//    cout << "^";
				//}
				//else if ((i > mid && j == col_mid) || (i == mid && left != right && j == col_mid)) {
				//    cout << "|";
				//}
				//else {
				//    cout << " ";
				//}
				(i == 1 || i == row ||  j == 1 || j == col) ? cout << "*" : (i == mid && left == right && j == col_mid) ? cout << "|" : ((i < mid && (j == left || j == right)) || (i == mid && left != right && (j == left || j == right))) ? cout << "^" : ((i > mid && j == col_mid) || (i == mid && left != right && j == col_mid)) ? cout << "|" : cout << " ";
			}
			//after each row, update left and right if necessary
			//left and right will not change during the first two rows
			//left will decrease by 1 and right will increase by 1 after each row starting from the third row until the middle row
			//(shift to left and right respectively, that's why left-- and right++)
			//so the condition is i > 1 and i < mid
			//after the middle row, left and right will not change anymore
			if (i > 1 && i < mid) {
				left--;
				right++;
			}
			cout << "\n";
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

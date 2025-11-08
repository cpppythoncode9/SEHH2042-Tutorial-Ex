// SEHH2042 SEHS2042 In-class Exercises (Tutorial Work)
// Program template file
// Do not modify the given codes
拒絕rolling, chill guy才是真理
// =======================================
// Insert more header files when necessary
// =======================================
#include <iostream>
//since Q3 is using c-string, we need to include cstring
#include <cstring>
#include <iomanip>
using namespace std;

void showInfo()
{
	// Fill in your personal particulars below
	"Name      : HIDDEN\n";
	"Student ID: HIDDEN\n";
	"Class     : A01A\n";
}

class Date {
	public:

		void setDate(int d, int m, int y)
		{
			day = d;
			month = m;
			year = y;
		}
		// Initialize the constructor with parameters to solve the problem
		Date (int d, int m, int y) {
			setDate(d, m, y);
		}

		// Default constructor
		Date() {
			//just set all data members to 0
			setDate(0, 0, 0);
		}

		void print()
		{
			cout << day << "-" << month << "-" << year;
		}
	// Declare private data members
	private:
		// Data members to store day, month, year
		int day;
		int month;
		int year;
};

void Q1()
{
	// =====================================
	// Insert your codes for Question 1 here
	// No need main() and return 0
	// =====================================
	//code copied from T7_Q1.cpp
	// Create an object called xmas
	Date xmas;
	xmas.setDate(25, 12, 2013);
	cout << "xmas is: ";
	// Use xmas object to call print()
	//Note: now cannot successfully output the inputted date
	//That is because we have not implemented the member functions yet
	//In other words, the data members (day, month, year) have not been assigned any values yet
	//No data stored in the object xmas (no data stored in the constructors)
	//to solve this proplem, just initializ the constructor Data() using setDate() function
	xmas.print();
	cout << endl;
}

class Car
{
public:
	Car() {
		// Your code for part (a) should be inserted here
		//initialize speed to 0
		//my habit is using the pointer this-> to access data member
		//unless the code like T7_Q1.cpp 
		//I use this-> to stored value to data member in the constructor
		this->speed = 0;
	}

	void showSpeed() {
		//display the current speed
		//since i use this-> to access data member the constructor
		//so the output function should also use this->
		cout << "The car is moving at " << this->speed << " km/h." << endl;
	}

	void accelerate(int a) {
		cout << "Accelerating ... " << endl;
		// Your code for part (b) should be inserted here
		//increase speed by a (acceleration)
		//now we can see the advantage of using this-> is to avoid confusion
		//and enhance the readability of my code
		this->speed += a;
		//ensure speed will not exceed 150 km/h
		if (this->speed > 150) {
			this->speed = 150;
		}
	}

	// Your code for part (c) should be inserted here

	void decelerate(int b) {
		cout << "Decelerating ...\n";
		//decrease speed by b (deceleration)
		this->speed -= b;
		//ensure speed will not be negative
		if (this->speed < 0) {
			this->speed = 0;
		}
	}

	// Your code for part (d) should be inserted here

	void stop() {
		cout << "Stopping ...\n";
		//set speed to 0
		this->speed = 0;
	}

private:
	int speed;   // speed of the car, in km/h
};

void Q2()
{
	// =====================================
	// Insert your codes for Question 2 here
	// No need main() and return 0
	// =====================================
	//code copied from T7_Q2.cpp
	Car myCar;

	myCar.showSpeed();
	myCar.accelerate(70);
	myCar.showSpeed();
	myCar.decelerate(20);
	myCar.showSpeed();
	myCar.accelerate(120);
	myCar.showSpeed();
	myCar.decelerate(100);
	myCar.showSpeed();
	myCar.stop();
	myCar.showSpeed();
}

class Phone {
	//initialize data members
	//brand_name, os_version, price
	//this also my habbit, writing private first then public
	//use char* instead of string to stored brand_name and os_version
	//one of the advantage is to save memory space
	private:
		char* brand_name;
		char* os_version;
		double price;
	public:
		Phone(const char* b, const char* os) {
			//again my habit is using this-> to access data members
			//so all the following codes will use this-> (including the final output showConfig())
			//allocate memory and copy the input c-string to data members
			//new char[] is used to allocate memory for c-string in C++ (dynamic allocation)
			//in other words, create an array of char with size strlen(b) + 1
			//strlen() is used to get the length of a c-string in C++
			//note: +1 is for null terminator
			this->brand_name = new char[strlen(b) + 1];
			//copy the content of input c-string b to data member brand_name
			//use strcpy() for copying c-string in C++
			strcpy(this->brand_name, b);
			//same initilaization for os_version as brand_name
			this->os_version = new char[strlen(os) + 1];
			strcpy(this->os_version, os);
			//initialize price to 0
			this->price = 0;
		}
		//defaukt constructor (not necessary in this case, but good practice)
		Phone() {
			//initialize brand_name and os_version to empty c-string
			this->brand_name = new char[1];
			//set the first character to null terminator to represent empty c-string
			this->brand_name[0] = '\0'; //null terminator
			this->os_version = new char[1];
			//same as brand_name
			this->os_version[0] = '\0'; //null terminator
			//initialize price to 0
			this->price = 0;
		}
		//default destructor to free the dynamically allocated memory(brand_name and os_version)
		//although the question did not ask for destructor, but it is a good practice to implement it
		//this can prevent memory leak
		//note: only this class (Phone) need destructor because it has dynamic memory allocation
		~Phone() {
			//use delete[] to free the memory allocated for c-string in C++
			delete[] this->brand_name;
			delete[] this->os_version;
		}
		void setPrice(int p) {
			//set the price data member
			this->price = p;
		}
		void showConfig() {
			//display the phone configuration
			cout << "Brand:\t" << this->brand_name << endl;
			cout << "OS:\t" << this->os_version << endl;
			cout << "Price:\t$" << fixed << setprecision(2) << this->price << endl;
			//remember unset the format flag after using fixed
			cout.unsetf(ios::fixed);
		}
};

void Q3()
{
	// =====================================
	// Insert your codes for Question 3 here
	// No need main() and return 0
	// =====================================
	//code copied from T7_Q3.cpp
	Phone iPhone("Apple", "iOS version 6");
	Phone noteTwo("Samsung", "Android 4.1");

	iPhone.setPrice(5588);
	noteTwo.setPrice(4630);

	cout << "Specification of iPhone:" << endl;
	iPhone.showConfig();
	cout << "\nSpecification of Note 2:" << endl;
	noteTwo.showConfig();
}

class Account {
	private:
		double balance;
	public:
		Account(double input) {
			//initialize balance with input value
			this->balance = input;
		}
		//default constructor (not necessary in this case, but good practice)
		Account() {
			//initialize balance to 0
			this->balance = 0;
		}
		double getBalance() {
			//return the current balance
			return this->balance;
		}
		void credit(double amount) {
			//add amount to balance
			this->balance += amount;
		}
		void debit(double amount) {
			//check if balance is sufficient
			//deduct amount from balance
			//else do nothing (use 0 to represent do nothing)
			(balance > amount) ? this->balance -= amount : 0;
		}
};

void transfer(Account &a1, Account &a2) 
{
	// (b) code for function body should be inserted here
	//note: pass by reference must be implement in here because we need to modify the balance of a1 and a2
	//in other words, we need to update the balance of a1 and a2 after the transfer
	double amount;
	//input amount to transfer
	cout << "How much to transfer: ";
	cin >> amount;
	//check if a1 has sufficient balance
	if (a1.getBalance() >= amount) {
		//call debit() and credit() member functions subtract amount from a1 and add to a2
		a1.debit(amount);
		a2.credit(amount);
		cout << "Transfer completed.\n";
	}
	else {
		//denied case, insufficient balance to transfer
		cout << "Insufficient balance.\n";
	}

}

void Q4()
{
	// =====================================
	// Insert your codes for Question 4 here
	// No need main() and return 0
	// =====================================
	//code copied from T7_Q4.cpp
	Account peter(1000), mary(1500);
	int option;

	cout << fixed << setprecision(2);   // 2 decimal places

	do {
		cout << "\n";
		cout << "Peter's balance: " << peter.getBalance() << endl;
		cout << "Mary's balance:  " << mary.getBalance() << endl;
		cout << "------\n";
		cout << "(1) Transfer money from Peter to Mary\n";
		cout << "(2) Transfer money from Mary to Peter\n";
		cout << "(3) Quit\n";
		cout << "Option: ";
		cin >> option;

		switch (option) {
		case 1: transfer(peter, mary); break;
		case 2: transfer(mary, peter); break;
		case 3: cout << "Bye Bye.\n"; break;
		default: cout << "Incorrect option.\n";
		}
	} while (option != 3);
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

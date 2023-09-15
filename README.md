# HowLong
C++ program which records the days you have spend on a Tasks.
Hey, Welcome to this file. What this program actually does is that it will count te number of days you've been working on a specific task so you dont have to remember the number of task you are doing and for how long.

 
Features :-
1. This will record how long you've been doing that task.
2. You can add as much task as you want. 
3. You'll be able to see the status if it is completed or on hold.

Below I'll paste the code everytime if there's a change or something. This file and project will get uploaded on github too. github.com/Kanak883.
Format for the changes applied.
1. DATE and TIME 
2. Changes which have to made/ After changes (You have to tell everytime you commit) 
3. what are the problems you getting/ improve it 
4. SOURCE CODE
5. Line of Oblique for eg. ////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
				 	15-09-23 1:03 PM
Before changes - It's working fine with no errors.
Problem - when choosing 1. "Add Task" it's printing the same syntax for 5 times in a row
When choosing to 2. see status it aint printing anything and not exiting the program
When choosing 3. Its exiting the program.

#include <iostream>
#include <sstream>
#include <fstream>
#define print(x) std::cout<< x << std::endl;



bool correct = false;
char data_name;
int choice;
void choice_2() {
	
	std::ifstream inputfile;
	inputfile.open("data1.txt");

	if (!inputfile) {
		print("Error opening the file for reading!");
	}
	std::string line;
	while (getline(inputfile, line)) {
		print(line);
	}

	inputfile.close();
}

void choice_1() {
	char written_data;
	std::ofstream outputfile;
	outputfile.open("data1.txt");
	print("Write your task: ");
	std::cin >> written_data;
	outputfile << written_data << std::endl;
	if (!outputfile) {
		print("Error opening the file for writing!");
	}


}



int main() {
	print("Hey, This is a system for managing tasks.");
	print("What do you want to do?");
	print("1. Add a new Task");
	print("2. See the status of Task");
	print("3. Exit");

	std::cin >> choice;

	while (!correct) {
		if (choice == 1) {
			choice_1();
		}
		else if (choice == 2) {
			choice_2();
		}
		else if (choice == 3) {
			correct = true;
		}
		else {
			print("Invalid choice. Please select 1, 2, or 3.");

		}
	}

	return 0;
}
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
				15-09-23	01:57 PM
Changes – 
1.	In choice_2 added correct = true so when it prints the data of file “data1.txt” it wont print in infinite loop.
2.	Added while(!correct){} loop in choice_1 to stop the double printing but it aint working yet.
Applying changes – 
1.	In choice_1 function im going to stop the double printing and add the input into the file 
Problems – Double printing and not sending the input into the data1.txt.
Source code - #include <iostream>
#include <sstream>
#include <fstream>
#define print(x) std::cout<< x << std::endl;



bool correct = false;
char data_name;
int choice;
char written_data[100];


void choice_2() {
	
	std::ifstream inputfile;
	inputfile.open("data1.txt");

	if (!inputfile) {
		print("Error opening the file for reading!");
	}
	std::string line;
	while (getline(inputfile, line)) {
		print(line);
		correct = true;
	}

	inputfile.close();
}

void choice_1() {
	std::ofstream outputfile;
	outputfile.open("data1.txt");
	while (!correct) {
		print("Write your task: ");
		std::cin.getline(written_data, sizeof(written_data));
		outputfile << written_data << std::endl;
		print(written_data)
			if (!outputfile) {
				print("Error opening the file for writing!");
				break;
			}
	}

}



int main() {
	print("Hey, This is a system for managing tasks.");
	print("What do you want to do?");
	print("1. Add a new Task");
	print("2. See the status of Task");
	print("3. Exit");

	std::cin >> choice;

	while (!correct) {
		if (choice == 1) {
			choice_1();
		}
		else if (choice == 2) {
			choice_2();
		}
		else if (choice == 3) {
			correct = true;
		}
		else {
			print("Invalid choice. Please select 1, 2, or 3.");

		}
	}

	return 0;
} 



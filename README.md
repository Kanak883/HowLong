Hey, Welcome to this file. What this program actually does is that it will count te number of days you've been working on a specific task so you dont have to remember the number of task you are doing and for how long.

 
Features :-
1. This will record how long you've been doing that task.
2. You can add as much task as you want. 
3. You'll be able to see the status if it is completed or on hold.

Below I'll paste the code everytime if there's a change or something. This file and project will get uploaded on github too. github.com/Kanak883.
Format for the changes applied.
1. DATE and TIME 
2. Changes which have to made/ After changes (You have to tell every time you commit) 
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
////////////////////////////////////////////////////////////////////////////////////////////////////////
16-09-23	12:49 PM
Changes which have to be made :
1.	When choosing 1 to add new task it’s printing write your task and then do you want to add another without inputing the first task.
2.	And if we choose 1 yes to another task after adding task prompt it shows “Write your task ” 2 times and after adding the task name it shows do you want another….. if yes then again write task but when choosing 2 No then again asks to write task and I guess here is the confusion of type variable like if I choose int then it asks again to add new task but when I type char to write task it goes in infinite loop .
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
				16/09/23	10:59 PM
Changes : added std::cin.ignore() to ignore the newline character after write your task prompt
problems- don’t know the status of task if it is completed or not
source code:
	#include <iostream>
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
		int another_choice;
		std::ofstream outputfile("data1.txt", std::ios::app);
		while (!correct) {
			print("Write your task: "); 
			std::cin.ignore();
			std::cin.getline(written_data, sizeof(written_data));
			outputfile << written_data << std::endl;
			if (!correct) {
				print("do you want to add another task? \n1.Yes \n2. No");
				std::cin >> another_choice;
				std::cin.ignore();
				if (another_choice == 1) {
					continue;
				}
				else if (another_choice == 2) {
					correct = true;
				}
			}
			
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
//////////////////////////////////////////////////////////////////////////////////


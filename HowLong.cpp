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
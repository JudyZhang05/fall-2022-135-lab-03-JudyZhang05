/*
 * Author: Judy Zhang
 * Course: CSCI-135
 * Instructor: Professor Zamansky
 * Assignment: Task A. Write a program east-storage.cpp that asks the user to input a string representing 
 * the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main() {
    std::cout << "Enter date: ";
    std::string date;
    std::cin >> date;

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin,junk);
    
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;

    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl) {

        fin.ignore(INT_MAX, '\n');

        if (fin == date) {
            std::cout << "East basin Storage: " << eastSt << " billion gallons" << std::endl;
        }
    }
    fin.close();
    return 0;
}

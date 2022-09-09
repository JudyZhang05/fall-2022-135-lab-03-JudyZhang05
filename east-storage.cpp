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

int east() {
    std::cout << "Enter date: ";
    std::string date;
    std::cin >> date;
    std::string time = date;

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin,junk);
    
    std::string eastSt ="AUGEVolume";
  
    while (fin >> date >> eastSt) {
      if (date == time){
        std::cout << "East basin Storage: " << eastSt << " billion gallons" << std::endl;
        fin.ignore(INT_MAX, '\n');
        }
      }
    fin.close();
    return 0;
}
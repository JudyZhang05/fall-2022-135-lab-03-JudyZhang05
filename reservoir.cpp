/*
 * Author: Judy Zhang
 * Course: CSCI-135
 * Instructor: Professor Zamansky
 * Assignment: Task A. Write a program east-storage.cpp that asks the user to input a string representing 
 * the date (in MM/DD/YYYY format), and prints out the East basin storage on that day.
 */
// add your code
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

double get_east_storage(std::string date) {
    std::cout << "Enter date: ";
    std::cin >> date;
    std::string time = date;

    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin,junk);
    
    std::string eastSt;

    while (fin >> date >> eastSt) {
      if (date == time){
        std::cout << "East basin storage: " << eastSt << " billion gallons" << std::endl;
        fin.ignore(INT_MAX, '\n');
        }
      }
    fin.close();
    return 0;
}

double get_min_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin,junk);

  std::string eastSt;
  std::string date;
  float min = 1000.00;
  
  while (fin >> date >> eastSt){
    float num = std::stof(eastSt);
    fin.ignore(INT_MAX, '\n');
    if (num < min){
        min = num;
        fin.ignore(INT_MAX, '\n');
      }
  }
  std::cout << "minimum storage in East basin: " << min << " billion gallons" << std::endl;
  
  return 0;
} 
double get_max_east(){
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin,junk);

  std::string eastSt;
  std::string date;
  float max = 0.00;
  
  while (fin >> date >> eastSt){
    float num = std::stof(eastSt);
    fin.ignore(INT_MAX, '\n');
    if (num > max){
        max = num;
        fin.ignore(INT_MAX, '\n');
      }
  }
  std::cout << "MAXimum storage in East basin: " << max << " billion gallons" << std::endl;
  
  return 0;
} 

std::string compare_basins(std::string date){
    std::string start;
    std::string end;
    std::cout << "Enter starting date: ";
    std::cin >> start;
    std::cout << "Enter ending date: ";
    std::cin >> end;

    // std::string temp1 = start.substr(3,2);
    // int begin = stoi(temp1);
    // std::string temp2 = end.substr(3,2);
    // int stop = stoi(temp2);
  
    std::cout << std::endl;
  
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
  std::string loop = "n";
  //int count = stop - begin;

  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    float east = stof(eastEl);
    float west = stof(westEl);
    fin.ignore(INT_MAX, '\n');
    if (date == start || loop == "y"){
      loop = "y";
      if (east > west){
        std::cout << date << " East" << std::endl;
        }
      else if (west > east){
        std::cout << date << " West" << std::endl;
        }
      else{
        std::cout << date << " Equal" << std::endl;
        }
      if (date == end){
        loop = "n";
        }
        }
      }
  return(date);
}
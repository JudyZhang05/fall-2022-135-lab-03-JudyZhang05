 /*
 * Author: Judy Zhang
 * Course: CSCI-135
 * Instructor: Professor Zamansky
 * Assignment: Task D
 */
 #include <iostream>
 #include <fstream>
 #include <cstdlib>
 #include <climits>
 #include <vector>
 #include "main.cpp"

void reverse_order(std::string date1, std::string date2){
  std::string early;
  std::string later;
  std::cout << "Enter earlier date: ";
  std::cin >> early;
  std::cout << "Enter later date: ";
  std::cin >> later;

  std::ifstream fin("Current_Reservoir_Levels.tsv");
     if (fin.fail()) {
         std::cerr << "File cannot be opened for reading." << std::endl;
         exit(1);
     }
     std::string junk;
     getline(fin,junk);

  std::string date;
  std::string eastSt;
  std::string eastEl;
  std::string westSt;
  std::string westEl;
  std::vector<std::string> time;
  std::vector<std::string> elevation;
  std::string loop = "n";
  
  std::cout << std::endl;
  
  while (fin >> date >> eastSt >> eastEl >> westSt >> westEl){
    time.push_back(date);
    elevation.push_back(westEl);
    fin.ignore(INT_MAX, '\n' );
    }  
  for (int i = elevation.size() - 1; i >= 0; i--){
    if (time[i] == later || loop == "y"){
      loop = "y";
      std::cout << time[i] << " " << elevation[i] << " ft" << std::endl;
      if (time[i] == early){
        loop = "n";
      }
    }
  }
}
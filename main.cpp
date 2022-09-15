// add your code as appropriate 
#include <iostream>
#include "reservoir.h"
// include "reservoir.cpp" //to run main with g++ uncomment
#include "reverseorder.h"
// #include "reverseorder.cpp" //this too

int main()
{
  get_east_storage("05/20/2018");
  get_min_east();
  get_max_east();
  compare_basins("09/13/2018");
  reverse_order("06/02/2018","05/29/2018");
  return 0;
}

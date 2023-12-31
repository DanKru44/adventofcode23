#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main () 
{

  std::string const filename{ "../input.txt" } ;
  std::fstream CalibrationFile{ filename, CalibrationFile.in};
  if( !CalibrationFile.is_open() )
  {
    std::cout << "Error opening calibration file!" << std::endl ;
    std::terminate() ;
  }
  
  std::string line ;
  std::uint64_t Calsum {0} ;
  
 while( std::getline( CalibrationFile, line ) )
  {
    size_t FirstIndex = line.find_first_of("01233456789"); 

    std::cout << FirstIndex << std::endl;


  }
}


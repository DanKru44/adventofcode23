#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main () 
{
  std::unordered_map<std::string, int> Numbers = {
    {"zero", 0},
    {"0", 0},
    {"one", 1},
    {"1", 1},
    {"two", 2},
    {"2", 2},
    {"three", 3},
    {"3", 3},
    {"four", 4},
    {"4", 4 },
    {"five", 5},
    {"5", 5},
    {"six", 6},
    {"6", 6},
    {"seven", 7},
    {"7", 7},
    {"eight", 8},
    {"8", 8},
    {"nine", 9},
    {"9",9},
  };
    
  
 
  std::string const filename{ "../input.txt" } ;
  std::fstream CalibrationFile{ filename, std::ios::in};
  if( !CalibrationFile.is_open() )
  {
    std::cout << "Error opening calibration file!" << std::endl ;
    std::terminate() ;
  }
  
  std::string line ;
  int i = 1 ;
  std::uint64_t Calsum = 0 ;

  while(std::getline(CalibrationFile, line))
  {
    std::istringstream linestream(line) ;
    std::string partialkey ;
    std::getline(linestream, partialkey, '\n') ;
    std::string firstElement = "" ;
    std::string lastElement = "" ;
    size_t minPos = std::string::npos ;
    size_t maxPos = std::string::npos ;
    int FirstFoundNumber = -1 ;
    int LastFoundNumber = -1 ;
     
    for(const auto& Number : Numbers)
    {
      const std::string& Element = Number.first ;
      const std::size_t Firstpos = partialkey.find(Element) ;
      const std::size_t Lastpos = partialkey.rfind(Element) ;

      if(Firstpos!= std::string::npos && Lastpos != std::string::npos)
      {
        if(firstElement.empty() || Firstpos < minPos)
        {
          firstElement = Element ;
          FirstFoundNumber = Number.second * 10;
          minPos = Firstpos ;
        } 

        if(lastElement.empty() || Lastpos > maxPos)
        {
          lastElement = Element ;
          LastFoundNumber = Number.second ;
          maxPos = Lastpos ;
        }
      }
    }

    std::cout << i << "First found Number: " << FirstFoundNumber <<std::endl ;
    std::cout << i << "Last found Number: " << LastFoundNumber << std::endl ;

    Calsum += FirstFoundNumber + LastFoundNumber ;

    std::cout << i << "Calsum: " << Calsum << std::endl ;
    i++ ;
  }

  std::cout << "Calibration Value: " << Calsum << std::endl ;

  CalibrationFile.close() ;
  return 0 ;
}


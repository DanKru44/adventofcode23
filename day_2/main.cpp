#include <exception>
#include <fstream>
#include <iostream>

int main()
{
  std::string const filename{ "../input.txt" } ;
  std::fstream GameFile{ filename ,std::ios::in } ;
  if( !GameFile.is_open() )
  {
    std::cout << "Error opening Game file!" << std::endl ;
    std::terminate() ;
  }
  

}





  

#include <cstdint>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

int main()
{
  std::string const filename{ "../input.txt" } ;
  std::fstream GameFile{ filename ,std::ios::in } ;
  if( !GameFile.is_open() )
  {
    std::cout << "Error opening Game file!" << std::endl ;
    std::terminate() ;
  }
  
  std::string line ;
  std::uint64_t GameSum = 0 ;

  while( std::getline( GameFile, line, '\n' ) )
  {
    std::istringstream GameIss(line) ;
    std::string Game ;
    GameIss >> Game ;
    int GameNumber = 0 ;
    GameIss >> GameNumber  ;
    GameIss.ignore(std::numeric_limits<std::streamsize>::max() , ':') ;

    std::cout << "Game: " << GameNumber << ":" << std::endl ;


    std::istringstream LineIss( line ) ;
    LineIss >> Game >> GameNumber ;
    LineIss.ignore(std::numeric_limits<std::streamsize>::max() , ':') ;
    std::string Set ;
    
    while( std::getline( LineIss , Set , ';' ) )
    {
      std::size_t start = Set.find_first_not_of( " " ) ;
      std::size_t end = Set.find_last_not_of( " " ) ;
      Set = Set.substr( start , end - start + 1 ) ;

      std::cout << "Set: " << Set << std::endl ;

      std::istringstream NumberIss (Set) ;
      std::string color ;
      int Number ;
      
      while( NumberIss >> Number >> color)
      {
        if( color.back() == ',')
        {
          color.pop_back() ;
        }
        std::cout << color << ": " << Number << std::endl ;
      }

    }
  }
}





  

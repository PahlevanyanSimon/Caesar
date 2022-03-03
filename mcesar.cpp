#include <iostream>
#include "cesar.h"
#include <string>


int main()
{
    std::string str;
    
    std::cout <<" Code/Decode" <<std::endl;
    std::cin >> str;
    if(str == "Code" )
    { 
      Cesar obj;
      obj.code("code.txt");

    }
    else if(str == "Decode")
    { 
      Cesar obj;
      obj.decode("code.txt");

    }
    else
    {
      std::cout << "Incorect type" <<std::endl;
    }
    
    
    
    }
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


class Cesar
{
public:
      Cesar() = default;
      Cesar(const Cesar&) = delete;
      Cesar(Cesar&&) = delete;
      Cesar& operator=(const Cesar&) = delete;
      Cesar& operator=(Cesar&&) = delete;
      ~Cesar() = default;
      void code(std::string st);
      void decode(std::string st);
private:
       void file_is_open();
       std::string str;          
};
void file_is_open()
{   
    std::iftream fin("code.txt");
    std::ofstream fout("decode.txt");
    if(fin.is_open() && fout.is_open())
    {
        std::cout<< "OK" <<std::endl;
    }
    else{
        throw std::exception();
    }

}

void Cesar::code(std::string str)
{
    std::ifstream fayl(str);
    std::ofstream write_fayl("decode.txt");

    std::string line;

 while(std::getline(fayl, line))
   {  

       for(int i = 0; i<line.size(); ++i)
       { if(line[i]>64 && line[i] < 91) 
         {
          if(line[i]>64 && line[i]<68)
          { write_fayl << (char)(line[i]+23);}
          else 
          { write_fayl << (char)(line[i] - 3); }
         }
       }
       write_fayl <<std::endl;
   }
   fayl.close();
   write_fayl.close();

}

void Cesar::decode(std::string str)
{
    std::ifstream fayl(str);
    std::ofstream write_fayl("decode.txt");

    std::string line;

 while(std::getline(fayl, line))
   {
       for(int i = 0; i<line.size(); ++i)
       {  if(line[i]>64 && line[i] < 91) 
          { if(line[i]>87 && line[i] < 91)
            { write_fayl << (char)(line[i]-23); }
           else 
           { write_fayl << (char)(line[i] + 3); }
          }
       }
       write_fayl <<std::endl;
   }
   fayl.close();
   write_fayl.close();

}


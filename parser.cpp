#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
int count = 0 ;
std::vector<std::string> variable;
struct variables_
{
   std::string  vari_typa ;
   std::string  vari_name ;
   void* ptr{}  ;
};

std::vector<variables_*> very ;

/*std::map<std::string, int> amb;
std::map<std::string,double> ketik;
std::map<std::string,bool>  ard;
std::map<std::string,std::string> text;*/
std::string keyWord[6]={"int","double","bool","string","for","while"};
std::string alu[4]={"+","-","/","*"};

bool isVari(const std::string & rhs)
{
   int k=rhs.size();
   for(int i = 0 ; i < rhs.size() ; ++i)
   {
      if(('a'<=rhs[i] && rhs[i]<='z') || ('A'<=rhs[i] && rhs[i]<='Z') )
      {
        --k;
      }
      if(k==0)
      {
         for(int i = 0 ; i<variable.size() ; ++i)
         {
            if(rhs==variable[i])
            {
               std::cout<< "You Are Used This name For Variable"<<std::endl;
               exit(1);
            }
         }
      }
   }
   return !k;
}

bool lineSimbols(const std::vector<std::string>& ohter)
{
   if(ohter[2]=="=")
   {
      if(ohter[4]==";")
      {
         return true ;
      }
      else
      {
         std::cout<<"You are forget < ; > "<<std::endl;
         exit(2);
      }
   }
   else
   {
      std::cout<<"You are forget < = > "<<std::endl;
         exit(3);
   }
}
bool isThisInt(const std::string& other)
{
   for(int i = 0 ; i  < other.size() ; ++i)
   {
      if('0'<=other[i] && other[i]<='9')
      {}
      else
      {
        std::cout<< " This is not integer" << std::endl;
        exit(4);
      }
   }
   return true ;
}
bool isThisdouble(const std::string& other)
{
  
   if(('0'<=other[0] && other[0]<='9') && other[other.size()-1]!='.')
   {
      int h = 0 ;
     for(int i = 0 ; i < other.size() ; ++i)
     {
        if(other[i]=='.')
        {
           ++h;
           if(h==2){
              std::cout << "You can not have 2 or more ' . ' in your double " <<std::endl;
              exit(345);
           }
        }
        if(('0'<=other[i] && other[i]<='9') || other[i]=='.')
        {}
        else
        {
           std::cout<<"You make error This is not double "<<std::endl;
           exit(17);
        }
     }
   }
   return true ;
}
bool isThisString(const std::string& other)
{ 
   std::cout<<"123"<<std::endl;
   if(other[0]=='"' && other[other.size()-1]=='"')
   {
      return true ;
   }
   else
   {
      exit(145);
   }
  
}

   
int stringToInt(const std::string& other)
{ 
   int tmp=0;
   for(int i = 0 ; i <other.size() ; ++i)
   {
      tmp*=10;
     tmp+=other[i]-48;
   }
   return tmp;
}
double stringToDouble(const std::string& other)
{  int i = 0 ;
   int k = 0 ;
   double tmp = 0.0 ;
   if(other[other.size()-1]=='.')
   {
      std::cout<<"You must have number after '.' "<<std::endl;
      exit(99);
   }
   for(i ;other[i]!='.' ; ++i)
   {
      tmp*= 10;
      tmp+=other[i]-48;
   }
    k = other.size() - i; 
   for(i = 0 ; i < k ; ++i)
   {
      tmp+=(other[i]-48)*pow(10,-(i+1));
   }
   return tmp;
}
bool stringToBool(const std::string& other)
{   
   bool tmp=false;
   if(other=="false" || other=="0")
   {
     
      return tmp;
   }
   else 
   {
      return !tmp;
   }
}
int doIHaveThatVari(const std::string& other)
{
   for(int i = 0 ; i < variable.size() ; ++i)
   {
      if(other== variable[i])
      {
        return i ;
      }

   }
   std::cout << "You Do not Have That Variable" << std::endl ;
   exit(333);
}

void printToConsol(const std::vector<std::string>& other)
{
   //std::cout << "You come to printToConsol" <<std::endl;
   int i = 0;
   if(other[other.size()-1]==";")
   {
     i=doIHaveThatVari(other[1]);
     //for(int i = 0 ; i < 4 ; ++i)
     if(very[i]->vari_typa == "int")
     {
        std::cout<<"100" <<std::endl ;
        std::cout << *(int*)very[i]->ptr << std::endl;
     }
     else if (very[i]->vari_typa == "double")
     {
         //std::cout<<"500" <<std::endl ;
         std::cout  << *(double*)very[i]->ptr << std::endl;
     }
     else if (very[i]->vari_typa == "bool")
     {
       std::cout  << *(bool*)very[i]->ptr << std::endl;
     }
     else
     {
         std::cout  << *(std::string*)very[i]->ptr << std::endl;
     }

     
   }
}
void variToMapByDefolt(const std::string& rhs,const std::string& rhs1)
{
   variables_ * p = new variables_ ;
   switch (rhs[0])
   {
   case 'i':
             //amb[rhs1]=0;
             
             p->vari_typa = rhs ;
             p->vari_name = rhs1  ;
             p->ptr= new int ;
             *(int*)p->ptr= 0 ;
             very.push_back(p);
             variable.push_back(rhs1);
             break;
   case 'd':
            // ketik[rhs1]=0.0;
             //std::cout << "adssfrd" << std::endl;
            p->vari_typa = rhs ;
             p->vari_name = rhs1  ;
             p->ptr= new double;
             *(double*)p->ptr= 0.0 ;
              very.push_back(p);
             variable.push_back(rhs1);
             break;
   case 'b':
             //ard[rhs1]=true;
               p->vari_typa = rhs ;
             p->vari_name = rhs1  ;
             p->ptr= new bool ;
             *(bool*)p->ptr= true ;
              very.push_back(p);
             variable.push_back(rhs1);
             break;
   case 's':
             // text[rhs1]="";
             p->vari_typa = rhs ;
             p->vari_name = rhs1  ;
             p->ptr= new std::string ;
             *(std::string*)p->ptr= "" ;
             very.push_back(p);
             variable.push_back(rhs1);
             break;
   default:
      break;
   }
}
void variTreeKnow(const std::vector<std::string>& other)
{ 
  if(isVari(other[1]))
  {
     if(other[2]==";")
     {
        std::cout << other[0] << std::endl ;
         std::cout << other[1] << std::endl ;
     variToMapByDefolt(other[0],other[1]);
     }
  }
  else
  {
     std::cout<<"You make some folse commande"<<std::endl;
     exit(5);
  }

}
void variFiveKnow(const std::vector<std::string>& other)
{
   //std::cout << "you come to variFiveKnow  " <<std::endl;
  // std::cout <<other[0][0]<<std::endl;
      if(lineSimbols(other))
      {
        
         variables_ * p = new variables_ ;
         switch (other[0][0])
         {
         case 'i':
                    if(isThisInt(other[3]))
                    {
                      
                         p->vari_typa = other[0] ;
                         p->vari_name = other[1]  ;
                         p->ptr= new int ;
                        *(int*)p->ptr= stringToInt(other[3]);
                        very.push_back(p);
                        variable.push_back(other[1]);
                    }
                    else
                    {exit(34);}
                    break;
         case 'd':
                       if(isThisdouble(other[3]))
                       {
                          std::cout<< "isThisdouble("<<std::endl;
                           p->vari_typa = other[0] ;
                           p->vari_name = other[1]  ;
                           p->ptr= new double ;
                           *(double*)p->ptr= stringToDouble(other[3]);
                            very.push_back(p);
                           variable.push_back(other[1]);
                       }
                       else
                       {exit(47);}
                       break;
                       
         case 's':
                   if(isThisString(other[3]))     
                     {
                        
                           p->vari_typa = other[0] ;
                           p->vari_name = other[1]  ;
                            p->ptr= new std::string ;
                           *(std::string*)p->ptr= other[3];
                           very.push_back(p);
                           variable.push_back(other[1]);
                     } 
                     else
                     {
                        std::cout<<"12"<<std::endl;
                        exit(675);
                        
                     }
                     break;
         case  'b':
                    
                           p->vari_typa = other[0] ;
                           p->vari_name = other[1]  ;
                           p->ptr= new bool ;
                           *(bool*)p->ptr= stringToBool(other[3]);
                           very.push_back(p);
                           variable.push_back(other[1]);
                           break;
         default:
            break;
         }
      }
   }
   int doIhaveit( std::string other )
   {
       
     for(int f = 0 ; f <variable.size() ; ++f )
     {
        if(other==variable[f])
        {
           return f;
        }
     }
     return -1 ;
        
   }
   int  aluInt(int tmp , int tmp1 , int k)
   { int var = 0 ; 
        std::cout << "int" <<std::endl;
      
      if(k==0)
      {
         var = tmp + tmp1;
      }
      else if(k==1)
      {
         var=tmp - tmp1;
      }
      else if(k==2)
      {
         var=tmp/tmp1;
      }
      else if(k==3)
      {
         var=tmp * tmp1;
      }
      
      return var;
      
   }
   double aluDouble(double tmp , double tmp1 , int k)
   {
      double var = 0 ; 
        std::cout << "double" <<std::endl;
      
      if(k==0)
      {
         var = tmp + tmp1;
      }
      else if(k==1)
      {
         var=tmp - tmp1;
      }
      else if(k==2)
      {
         var=tmp/tmp1;
      }
      else if(k==3)
      {
         var=tmp * tmp1;
      }
      
      return var;
   }
   std::string alustring(std::string tmp , std::string tmp1 , int k)
   {  std::string var="" ;
      if(k==0)
      {
        var=tmp+tmp1;
        return var ;
      }
      std::cout<<"ERROR"<<std::endl;
      exit(545);
      
   }
  void doAlugorc(const std::vector<std::string>& other, int i ,int k)
  {
     int q = 0 ;
     
     if(very[i]->vari_typa=="int")
     {
        std::cout << "int" <<std::endl;
        int tmp1 = 0 ;
        int tmp = 0 ;
        int q = doIhaveit(other[2]);
        
        if(q>-1)
        {
           tmp=*(int*)(very[q]->ptr);
        }
       
        else
        {
           
           isThisInt(other[2]);
           tmp=stringToInt(other[2]);
        }
         q = doIhaveit(other[4]);
        if(q>-1)
        {
          tmp1=*(int*)(very[q]->ptr);
        }
        else
        {
           isThisInt(other[4]);
           tmp1=stringToInt(other[4]);
        }
       int chlp= aluInt(tmp,tmp1,k);
       *(int*)(very[i]->ptr)=chlp;
      
     }
     else if(very[i]->vari_typa=="double")
     {
        double tmp = 0.0 ;
        double tmp1 = 0.0 ;
        int q = doIhaveit(other[2]);
        if(q>-1)
        {
           tmp=*(double*)(very[q]->ptr);
        }
        else
        {
           
           isThisdouble(other[2]);
           tmp=stringToDouble(other[2]);
        }
         q = doIhaveit(other[4]);
        if(q>-1)
        {
          tmp1=*(double*)(very[q]->ptr);
        }
        else
        {
           isThisdouble(other[4]);
           tmp1=stringToDouble(other[4]);
        }
       double chlp= aluDouble(tmp,tmp1,k);
       *(double*)(very[i]->ptr)=chlp;
     }
     else if (very[i]->vari_typa=="string")
     {
        std::string tmp="";
        std::string tmp1="";
        int q = doIhaveit(other[2]);
        if(q>-1)
        {
           tmp=*(std::string*)(very[q]->ptr);
        }
        else
        {
           
           isThisString(other[2]);
           tmp=other[2];
        }
         q = doIhaveit(other[4]);
        if(q>-1)
        {
          tmp1=*(std::string*)(very[q]->ptr);
        }
        else
        {
           isThisString(other[4]);
           tmp1=other[4];
        }
       std::string chlp= alustring(tmp,tmp1,k);
       *(std::string*)(very[i]->ptr)=chlp;
     }
   }
   bool simbolsForFor(const std::vector<std::string>& other)
   {
     
      if(other[1]=="->" && other[3]=="print" && other[5]==";")
      {
         isThisInt(other[2]);
         doIHaveThatVari(other[4]);

      }
      else
      {
         std::cout << "simbolsForFor is false" << std::endl;
         exit(5991);
      }
      
      return true;
   }
   void printForCikl(const std::vector<std::string>& other)
   {
      int cikl=stringToInt(other[2]);
      int k = doIhaveit(other[4]);
      if(very[k]->vari_typa=="int")
     {
      while (cikl)
      {
         std::cout<<*(int*)very[k]->ptr << std::endl;
         --cikl;
      }
     }
     if(very[k]->vari_typa=="double")
     {
      while (cikl)
      {
         std::cout<<*(double*)very[k]->ptr << std::endl;
         --cikl;
      }
     }
     if(very[k]->vari_typa=="bool")
     {
      while (cikl)
      {
         std::cout<<*(bool*)very[k]->ptr << std::endl;
         --cikl;
      }
     }
          if(very[k]->vari_typa=="string")
     {
      while (cikl)
      {
         std::cout<<*(std::string*)very[k]->ptr << std::endl;
         --cikl;
      }
     }
   }



  
    


  void something(std::stringstream& oterh)
{   
     std::vector<std::string> line ;
   while(!oterh.eof())
   {
      std::string tmp; 
      oterh >> tmp;
    
       line.push_back(tmp);
       tmp="";
     
   }
  // for(int i = 0 ; i < line.size() ; ++i)
   //{
      //std::cout<< line[i]<<std::endl;
    //  }
     for(int i = 0 ; i < 4; ++i)
       {
          
           if(line[0]==keyWord[i])
           {
              
               if(line.size()==3)
               {
                  std::cout << "wtf3" << std::endl;
                  variTreeKnow(line);
               }
               else if(line.size()==5)
               {
                   //std::cout << "wtf5" << std::endl;
                  variFiveKnow(line);
               }
               else 
               {
                  std::cout<<"You Make mistake"<<std::endl;
                  exit(23);
               }
           }
            
       }

       if(line[0]=="print")
       {
          //std::cout<<"fdgrsgvdrf"<<std::endl;
          printToConsol(line);
         
       }
       for(int i = 0 ; i < variable.size() ; ++i)
       {
          if(line[0]==variable[i])
          {
            for(int k = 0 ; k < 4 ; ++k )
            {
              if(line[3]==alu[k]){
                 std::cout<<"+"<<std::endl;
               doAlugorc(line,i ,k);
              }
            }
          }
       }
       if(line[0]=="for")
       {

          simbolsForFor(line);
          printForCikl(line);
       }
    
}
         
          
         
      
  




 




int main()
{





std::string path;
std::cin>>path;
std::ifstream fs(path);
if(fs.is_open())
{
    std::cout<<"open" << std::endl;
     while(!fs.eof())
    {
       
      std::string line="";
  
      getline(fs,line);
      std::stringstream some(line);
      //std::cout<<line;
     something(some);
  
   
    } 
 
  
}
/*std::string line;
while(getline(fs, line))
{
  // std::cout << "line: " << line << std::endl;
   std::stringstream some(line);
   something(some);
}*/

else{std::cout<<"chlp" << std::endl;}

fs.close();
/*std::cout <<  variable[0] << std::endl;
std::cout << *(double*)very[0]->ptr<<std::endl;
std::cout << very[0]->vari_typa<<std::endl;
std::cout << very[0]->vari_name<<std::endl;*/
std::cout<<"es inch ankap terminal es havaqel"<<std::endl;
return 0;
}


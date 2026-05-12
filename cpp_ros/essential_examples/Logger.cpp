#include<iostream>
#include<string>
#include<sstream>
//include it in the Resources
int main(){
  std::stringstream ss;
  int bot_speed = 5 ;
  double battery = 12.45;
  
  /*now rather than writing spearate cout statements
   mentioning the bot speed and battery voltage 
   we use string stream*/
  ss<<"Bot Speed : "<<bot_speed<<"m/s || Battery Voltage : "<<battery<<" Volts";
  //string stream is ready , for output we need to convert it into standard string.
  std::string log_entry = ss.str();
  std::cout<<"|[LOG ENTRY]:"<<log_entry<<"||"<<std::endl;

  return 0;

}

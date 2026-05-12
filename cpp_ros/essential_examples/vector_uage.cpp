#include<iostream>
#include<string>
#include<math.h>
#include<sstream>

int main(){
  std::stringstream ss;
  int battery_level = 50 ;
  int battery_threshold = 20;

  std::string action = (battery_level>battery_threshold)? "Sufficient":"Low";
  
  int cpu_temp = 32;
  int cpu_temp_threshold = 50;

  std::string cpu_status= (abs(cpu_temp_threshold-cpu_temp)>15) ? "CPU stable":"CPU Overheat!";
  
  ss<<" ||Battery Status : "<< battery_level<<" ||CPU Status : "<<cpu_status;

  std::string log_entry = ss.str();
  std::cout<<"[[LOG MESSAGE:]]"<<log_entry<<std::endl;
}
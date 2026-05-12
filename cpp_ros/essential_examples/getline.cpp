#include<iostream>
#include<string>

int main(){
  std::string command ; 
  std::cout<<"Enter the robot command : "<<std::endl;
  std::getline(std::cin , command);
  std::cout<<"Command Received: "<< command << std::endl;
}
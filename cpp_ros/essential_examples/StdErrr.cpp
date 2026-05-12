#include<iostream>
#include<string.h>

int main(){
  
  double bot_speed;
  std::cout<<"Enter the speed of your robot: "<<std::endl;
  std::cin>>bot_speed;
  if(!std::cin){
    std::cerr<<"[[ERROR!]]: Bot name was not entered!"<<std::endl;
  }
  std::cout<<"Your bot is moving at :"<<double(bot_speed)<<std::endl;


  return 0;
}
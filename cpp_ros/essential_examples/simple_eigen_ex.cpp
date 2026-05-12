#include<iostream>
#include<eigen3/Eigen/Dense>

int main(){
  Eigen::Vector3d v(1,2,3);
  std::cout<<"Transpose of V is : "<<v.transpose()<<std::endl;
  return 0 ; 
}
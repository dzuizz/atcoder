#include<iostream>
int main() { int _1,_2,_3,_4; for (std::cin>>_1>>_2>>_3;_1--,std::cin>>_4;) std::cout<<(_2<=_4&&_4<=_3?_4:_4<_2?_2:_3)<<" "; }
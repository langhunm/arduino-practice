#include <iostream>
#include <typeinfo>
using namespace std;
//指针 内存单元的地址就叫指针
//指针变量 存放内存地址的变量
//指针变量的指针 指针变量的地址
//指针变量的指针变量 存放“指针变量的地址”的变量
//
//b是a的指针 意思就是b里面存储了a变量的地址 也意思说b是一个指针变量
//
int main(){
	int a[3]={1,2,3};
	int *p[3];  //指针数组 元素为指针变量
	int (*p2)[3]; //定义了一个数组指针变量 这个指针变量指向一个整型数组 这个数组还有三个整型元素
	int *p1;
	int (*p3)[];  //定义了一个数组指针变量 但这个指针变量指向的整型数组的元素的个数没有确定 目前我觉得它无法使用。
	
	p2=&a; //p2是一个数组指针变量，指向一个整型数组 a是一个数组名，代表首元素的地址，可以说它是一个整型指针变量
cout<<typeid(p).name()<<endl;
cout<<typeid(a[0]).name()<<endl;
cout<<typeid(p1).name()<<endl;
cout<<typeid(p2).name()<<endl;
cout<<typeid(a).name()<<endl;
cout<<typeid(p3).name()<<endl;
return 0;
}
//
//A3_Pi  数组 元素为指针
//i
//Pi
//PA3_i 指针变量 指向整型数组
//A3_i 数组 元素为整型
//PA_i
// int *f()   定义了一个返回指针的函数f 返回的指针指向整型
// int (*f1)()  定义了一个指向函数的指针变量f1 这个函数的返回值为int
// 如果一个指针变量p p+1到底加多少，根据他指向变量的类型决定 指向整型 加一个整型长度，如果指向整型数组，加一个整型数组的长度
//

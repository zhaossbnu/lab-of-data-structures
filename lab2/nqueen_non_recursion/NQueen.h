#pragma once
#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
class NQueen
{
public:
	NQueen(int n=4);
	~NQueen();
	void Run();					//运行函数本身没意义 调用Queen函数
protected:
	bool attack(int r,int c);		//判断是否会攻击 
	void print();					//输出皇后布局
private:
	int *a;							//定义存储皇后位置的数组
	int n;
	static int count;				//计数
};

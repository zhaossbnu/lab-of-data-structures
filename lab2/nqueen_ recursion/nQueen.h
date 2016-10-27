#pragma once
#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
class nQueen
{
public:
	nQueen(int n=4);
	~nQueen();
	void Run();					//运行函数本身没意义 调用Queen函数
protected:
	bool attack(int r,int c);		//判断是否会攻击
	void Queen(int i);				//核心算法 
	void print();					//输出皇后布局
private:
	int *a;							//定义存储皇后位置的数组
	int n;
	static int count;				//计数
	int *col;				//col[i]标识第i列是否安放了皇后
	int *zx;				//zx[i]标识第i条主对角线是否安放了皇后
	int* fx;				//fx[i]标识第i条副对角线是否安放了皇后
};

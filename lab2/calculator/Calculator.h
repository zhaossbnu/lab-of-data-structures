#pragma once
#include<iostream>
using namespace std;
#include"LinkedStack.h"

class Calculator				//定义计算器类
{
public:
	Calculator(){}				//无参构造
	~Calculator(){}				//析构函数
	void Run();					//计算器运行函数
protected:
	void Clear();				//清空操作数和操作符栈
	bool Get2Operands(double& left,double& right);		//从操作数栈中提取两个操作数
	void DoOperator(char Operator);						//进行一次运算操作
private:
	LinkedStack<double> num;			//定义操作数栈
	LinkedStack<char> op;				//定义操作符栈
};


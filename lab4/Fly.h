#pragma once
#include<iostream>
#include<string>
using namespace std;
const int Max=10000;			
struct Edge						//边的结构体	
{
    string Plane_Number;		//航班号
    string strart,end;			//起点和终点
    int time_cost,money_cost,interchange_cost;			//时间、费用、转换次数
};

class Fly								//航班的类定义
{
public:
	Fly();								//构造函数
	~Fly();								//析构函数
	void time_min(string st,string ed);				//时间最少的函数
	void money_min(string st,string ed);			//费用最少的函数
	void Interchange_min(string st,string ed);		//换乘次数最少的函数
private:
	Edge fly[8][8];									//航班的邻接矩阵
};


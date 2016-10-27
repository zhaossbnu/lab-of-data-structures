#include<iostream>
#include"NQueen.h"
using namespace std;

int main(void)
{
	int n;
	do
	{
		cout<<"请输入棋盘阶数：";
		cin>>n;
		if(n<4)
			cout<<"没有情况满足！"<<endl;
	}while(n<4);
	NQueen temp(n);
	temp.Run();
	cout<<"N皇后问题结束啦！！！感觉自己喋喋哒！！！"<<endl;
	return 0;
}
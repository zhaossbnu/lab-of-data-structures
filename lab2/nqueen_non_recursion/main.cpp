#include<iostream>
#include"NQueen.h"
using namespace std;

int main(void)
{
	int n;
	do
	{
		cout<<"���������̽�����";
		cin>>n;
		if(n<4)
			cout<<"û��������㣡"<<endl;
	}while(n<4);
	NQueen temp(n);
	temp.Run();
	cout<<"N�ʺ�����������������о��Լ����գ�����"<<endl;
	return 0;
}
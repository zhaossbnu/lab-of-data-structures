#include<iostream>
#include"List.h"
using namespace std;
int a[13]={1,2,2,3,4,5,6,6,7,8,9,9,10};
int main(void)
{	
	List<int> test;
	for(int i=0;i<13;i++)		//����Locate����
	{
		test.Insert(i,a[i]);
	}
	cout<<"Locate���������"<<test;
	
	cout<<"Max�������Խ����"<<test.Max()->data<<endl;		//����Max����

	cout<<"number�������Խ��(������ֵΪ9)��"<<test.number(9)<<endl;			//����number����
	
	
	List<int> hehe;			
	hehe=hehe.create(a,13);				//����create����
	cout<<"create�������Խ����"<<hehe;

	hehe.tidyup();					//����tidyup����
	cout<<"tidyup�������Խ����"<<hehe;

	return 0; 
}
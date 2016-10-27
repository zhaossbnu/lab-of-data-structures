#include<iostream>
#include"List.h"
using namespace std;
int a[13]={1,2,2,3,4,5,6,6,7,8,9,9,10};
int main(void)
{	
	List<int> test;
	for(int i=0;i<13;i++)		//测试Locate函数
	{
		test.Insert(i,a[i]);
	}
	cout<<"Locate函数结果："<<test;
	
	cout<<"Max函数测试结果："<<test.Max()->data<<endl;		//测试Max函数

	cout<<"number函数测试结果(测试数值为9)："<<test.number(9)<<endl;			//测试number函数
	
	
	List<int> hehe;			
	hehe=hehe.create(a,13);				//测试create函数
	cout<<"create函数测试结果："<<hehe;

	hehe.tidyup();					//测试tidyup函数
	cout<<"tidyup函数测试结果："<<hehe;

	return 0; 
}
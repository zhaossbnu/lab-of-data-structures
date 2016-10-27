#include<iostream>
#include<String>
#include"Fly.h"
using namespace std;
string City[8]={"北京","上海","西安","广州","武汉","拉萨","昆明","乌鲁木齐"};

int Position(string place)
{
	for(int i=0;i<8;i++)
		if(City[i]==place)
		{
			return i;
		}
	return -1;
}

int main(void)
{
	char ch;
	do
	{
		cout<<"可供查询的城市有：北京、上海、西安、广州、武汉、拉萨、昆明、乌鲁木齐"<<endl;
		string strart,end;
		while(1)
		{
			cout<<"请输入起点和终点：";
			cin>>strart>>end;
			if(Position(strart)==-1||Position(end)==-1)
			{
				cout<<"输入地点有误！！！"<<endl;
			}
			else
				break;
		}

		Fly fly;
		cout<<"从"<<ends<<strart<<ends<<"到"<<ends<<end<<ends<<"的参考意见如下："<<endl;
		cout<<"最短时间："<<endl;
		fly.time_min(strart,end);
		cout<<"最少费用："<<endl;
		fly.money_min(strart,end);
		cout<<"最少换乘："<<endl;
		fly.Interchange_min(strart,end);
		string temp;
		cout<<"是否继续查询？(Y/N)";
		cin>>temp;
		ch=temp[0];
	}while(toupper(ch)=='Y');
    
    return 0;
}

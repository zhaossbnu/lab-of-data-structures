#include<iostream>
#include<String>
#include"Fly.h"
using namespace std;
string City[8]={"����","�Ϻ�","����","����","�人","����","����","��³ľ��"};

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
		cout<<"�ɹ���ѯ�ĳ����У��������Ϻ������������ݡ��人����������������³ľ��"<<endl;
		string strart,end;
		while(1)
		{
			cout<<"�����������յ㣺";
			cin>>strart>>end;
			if(Position(strart)==-1||Position(end)==-1)
			{
				cout<<"����ص����󣡣���"<<endl;
			}
			else
				break;
		}

		Fly fly;
		cout<<"��"<<ends<<strart<<ends<<"��"<<ends<<end<<ends<<"�Ĳο�������£�"<<endl;
		cout<<"���ʱ�䣺"<<endl;
		fly.time_min(strart,end);
		cout<<"���ٷ��ã�"<<endl;
		fly.money_min(strart,end);
		cout<<"���ٻ��ˣ�"<<endl;
		fly.Interchange_min(strart,end);
		string temp;
		cout<<"�Ƿ������ѯ��(Y/N)";
		cin>>temp;
		ch=temp[0];
	}while(toupper(ch)=='Y');
    
    return 0;
}

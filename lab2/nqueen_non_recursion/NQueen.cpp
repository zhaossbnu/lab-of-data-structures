#include "NQueen.h"

int NQueen::count=0;

NQueen::NQueen(int n)
{
	this->n=n;
	a=new int[n];
	for(int i=0;i<n;i++)			//��ʼ���ʺ�λ��  ������Ϊ-1 ��ʾ�޻ʺ�
		a[i]=-10;
}

NQueen::~NQueen()
{
	delete[] a;				//�ͷſռ�
}

void NQueen::Run()				
{
	int i=0,j=0;
	while(i<n)
	{
		while(j<n)
		{
			if(!attack(i,j))			//�޹���
			{
				a[i]=j;
				j=0;					//Ϊ������һ��ʱ j=0
				break;
			}
			else						//������ǰ�е���һ��
			{
				j++;
			}
		}
		if(a[i]==-10)				//����û�еط����ԷŻʺ�
		{
			if(i==0)				//����ǰ��Ϊ��һ��  ���е�����Ѿ�������
				break;
			else					//������  ����ݵ���һ��
			{
				i--;
				j=a[i]+1;				//������һ�лʺ����һ��
				a[i]=-10;				//����������Ϊ�޻ʺ�
				continue;
			}
		}
		if(i==n-1)				//����ǰ��Ϊ���һ�� ����ʺ� ����������һ��
		{
			count++;
			print();
			system("pause");
			j=a[i]+1;				//������һ�лʺ����һ��
			a[i]=-10;				//����������Ϊ�޻ʺ�
			continue;
		}
		i++;						
	}
}

bool NQueen::attack(int r,int c)		//�ж��Ƿ�ṥ��
{
	for(int i=0;i<n;i++)
		if(a[i]==c||(abs(i-r)==abs(a[i]-c)))			//�ʺ�ṥ��
			return true;
	return false;									//ȷ��û�лʺ�ụ�๥��

}

void NQueen::print()					//����ʺ󲼾�
{
	cout<<"��"<<count<<"�֣�"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==j)					//��⵽�лʺ�
				cout<<"1"<<ends;
			else						//����޻ʺ�
				cout<<"0"<<ends;
		}
		cout<<endl;
	}
}
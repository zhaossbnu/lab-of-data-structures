#include "NQueen.h"

int NQueen::count=0;

NQueen::NQueen(int n)
{
	this->n=n;
	a=new int[n];
	for(int i=0;i<n;i++)			//初始化皇后位置  都设置为-1 表示无皇后
		a[i]=-10;
}

NQueen::~NQueen()
{
	delete[] a;				//释放空间
}

void NQueen::Run()				
{
	int i=0,j=0;
	while(i<n)
	{
		while(j<n)
		{
			if(!attack(i,j))			//无攻击
			{
				a[i]=j;
				j=0;					//为进入下一行时 j=0
				break;
			}
			else						//搜索当前行的下一列
			{
				j++;
			}
		}
		if(a[i]==-10)				//本行没有地方可以放皇后
		{
			if(i==0)				//若当前行为第一行  所有的情况已经列完了
				break;
			else					//若不是  则回溯到上一行
			{
				i--;
				j=a[i]+1;				//搜索上一行皇后的下一列
				a[i]=-10;				//将上列设置为无皇后
				continue;
			}
		}
		if(i==n-1)				//若当前行为最后一行 则输皇后 并且搜索下一列
		{
			count++;
			print();
			system("pause");
			j=a[i]+1;				//搜索上一行皇后的下一列
			a[i]=-10;				//将本列设置为无皇后
			continue;
		}
		i++;						
	}
}

bool NQueen::attack(int r,int c)		//判断是否会攻击
{
	for(int i=0;i<n;i++)
		if(a[i]==c||(abs(i-r)==abs(a[i]-c)))			//皇后会攻击
			return true;
	return false;									//确认没有皇后会互相攻击

}

void NQueen::print()					//输出皇后布局
{
	cout<<"第"<<count<<"种："<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i]==j)					//检测到有皇后
				cout<<"1"<<ends;
			else						//检测无皇后
				cout<<"0"<<ends;
		}
		cout<<endl;
	}
}
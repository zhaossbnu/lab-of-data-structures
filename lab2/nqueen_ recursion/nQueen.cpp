#include "nQueen.h"

int nQueen::count=0;

nQueen::nQueen(int n)
{
	this->n=n;
	col=new int[n];				//col[i]标识第i列是否安放了皇后
	zx=new int[2*n-1];				//zx[i]标识第i条主对角线是否安放了皇后
	fx=new int[2*n-1];				//fx[i]标识第i条副对角线是否安放了皇后
	a=new int[n];
	for(int i=0;i<n;i++)			//初始化皇后位置  都设置为-1 表示无皇后
			a[i]=-1;
}

nQueen::~nQueen()
{
	delete[] a;
}

void nQueen::Run()				//运行函数本身没意义 调用Queen函数
{
	Queen(0);					//调用Queen函数
}

bool nQueen::attack(int r,int c)		//判断是否会攻击
{
	if(col[c]==1||zx[n+r-c-1]==1||fx[r+c]==1)			//皇后会攻击
		return true;
	return false;									//确认没有皇后会互相攻击
}

void nQueen::Queen(int row)							//核心算法 
{
	for(int j=0;j<n;j++)
	{
		if(!attack(row,j))						//皇后不会攻击时
		{
			a[row]=j;							//在第i行第j列放上皇后
			col[j]=1;							//一下三行标注 该皇后所在列和主副对角线不能再有其他皇后
			zx[n+row-j-1]=1;
			fx[row+j]=1;
			if(row==n-1)					//如果当前行时最后一行
			{
				count++;					//计数器加1
				print();					//输出布局
				system("pause");
			}
			else
			{
				Queen(row+1);
			}
			a[row]=-1;
			col[j]=0;
			zx[n+row-j-1]=0;
			fx[row+j]=0;
		}
	}
}
void nQueen::print()					//输出皇后布局
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
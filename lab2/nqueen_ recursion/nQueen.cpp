#include "nQueen.h"

int nQueen::count=0;

nQueen::nQueen(int n)
{
	this->n=n;
	col=new int[n];				//col[i]��ʶ��i���Ƿ񰲷��˻ʺ�
	zx=new int[2*n-1];				//zx[i]��ʶ��i�����Խ����Ƿ񰲷��˻ʺ�
	fx=new int[2*n-1];				//fx[i]��ʶ��i�����Խ����Ƿ񰲷��˻ʺ�
	a=new int[n];
	for(int i=0;i<n;i++)			//��ʼ���ʺ�λ��  ������Ϊ-1 ��ʾ�޻ʺ�
			a[i]=-1;
}

nQueen::~nQueen()
{
	delete[] a;
}

void nQueen::Run()				//���к�������û���� ����Queen����
{
	Queen(0);					//����Queen����
}

bool nQueen::attack(int r,int c)		//�ж��Ƿ�ṥ��
{
	if(col[c]==1||zx[n+r-c-1]==1||fx[r+c]==1)			//�ʺ�ṥ��
		return true;
	return false;									//ȷ��û�лʺ�ụ�๥��
}

void nQueen::Queen(int row)							//�����㷨 
{
	for(int j=0;j<n;j++)
	{
		if(!attack(row,j))						//�ʺ󲻻ṥ��ʱ
		{
			a[row]=j;							//�ڵ�i�е�j�з��ϻʺ�
			col[j]=1;							//һ�����б�ע �ûʺ������к������Խ��߲������������ʺ�
			zx[n+row-j-1]=1;
			fx[row+j]=1;
			if(row==n-1)					//�����ǰ��ʱ���һ��
			{
				count++;					//��������1
				print();					//�������
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
void nQueen::print()					//����ʺ󲼾�
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
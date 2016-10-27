#pragma once
#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
class nQueen
{
public:
	nQueen(int n=4);
	~nQueen();
	void Run();					//���к�������û���� ����Queen����
protected:
	bool attack(int r,int c);		//�ж��Ƿ�ṥ��
	void Queen(int i);				//�����㷨 
	void print();					//����ʺ󲼾�
private:
	int *a;							//����洢�ʺ�λ�õ�����
	int n;
	static int count;				//����
	int *col;				//col[i]��ʶ��i���Ƿ񰲷��˻ʺ�
	int *zx;				//zx[i]��ʶ��i�����Խ����Ƿ񰲷��˻ʺ�
	int* fx;				//fx[i]��ʶ��i�����Խ����Ƿ񰲷��˻ʺ�
};

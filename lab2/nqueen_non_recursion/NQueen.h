#pragma once
#include<iostream>
#include<math.h>
#include<windows.h>
using namespace std;
class NQueen
{
public:
	NQueen(int n=4);
	~NQueen();
	void Run();					//���к�������û���� ����Queen����
protected:
	bool attack(int r,int c);		//�ж��Ƿ�ṥ�� 
	void print();					//����ʺ󲼾�
private:
	int *a;							//����洢�ʺ�λ�õ�����
	int n;
	static int count;				//����
};

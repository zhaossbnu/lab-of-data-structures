#pragma once
#include<iostream>
using namespace std;
#include"LinkedStack.h"

class Calculator				//�����������
{
public:
	Calculator(){}				//�޲ι���
	~Calculator(){}				//��������
	void Run();					//���������к���
protected:
	void Clear();				//��ղ������Ͳ�����ջ
	bool Get2Operands(double& left,double& right);		//�Ӳ�����ջ����ȡ����������
	void DoOperator(char Operator);						//����һ���������
private:
	LinkedStack<double> num;			//���������ջ
	LinkedStack<char> op;				//���������ջ
};


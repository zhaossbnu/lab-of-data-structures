#pragma once
#include<iostream>
#include<string>
using namespace std;
const int Max=10000;			
struct Edge						//�ߵĽṹ��	
{
    string Plane_Number;		//�����
    string strart,end;			//�����յ�
    int time_cost,money_cost,interchange_cost;			//ʱ�䡢���á�ת������
};

class Fly								//������ඨ��
{
public:
	Fly();								//���캯��
	~Fly();								//��������
	void time_min(string st,string ed);				//ʱ�����ٵĺ���
	void money_min(string st,string ed);			//�������ٵĺ���
	void Interchange_min(string st,string ed);		//���˴������ٵĺ���
private:
	Edge fly[8][8];									//������ڽӾ���
};


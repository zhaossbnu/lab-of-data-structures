#pragma once
#include<iostream>
#include<string>
using namespace std; 
const int DefaultSize=10;

struct HuffmanNode				//HuffmanNode ����
{
	char ch;
	int weight;
	HuffmanNode *leftChild,*rightChild,*parent;
	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){}	//�޲ι���
	HuffmanNode(char ch,int weight):leftChild(NULL),rightChild(NULL),parent(NULL)   //�вι���
	{
		this->ch=ch;
		this->weight=weight;
	}
	HuffmanNode(HuffmanNode& temp)				//��������
	{
		this->ch=temp.ch;
		this->weight=temp.weight;
		this->leftChild=temp.leftChild;
		this->rightChild=temp.rightChild;
		this->parent=temp.parent;
	}
	void operator=(HuffmanNode& R)			//�ض���  = ���������ڵ��ĸ�ֵ
	{
		this->ch=R.ch;
		this->weight=R.weight;
		this->leftChild=R.leftChild;
		this->rightChild=R.rightChild;
		this->parent=R.parent;
	}
};

class MinHeap					//��С�Ѷ���
{
public:  
	MinHeap(int sz=DefaultSize);		//���캯��	
	~MinHeap()					//��������
	{
		delete []heap;
	}
	void Insert(HuffmanNode &x);		//���뺯��	
	void RemoveMin(HuffmanNode& tt);		//ȡ�Ѷ�
private:
	HuffmanNode *heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start,int m);			//�»�������Ϊ��С��
	void siftUp(int start);					//�ϻ�������Ϊ��С��
};


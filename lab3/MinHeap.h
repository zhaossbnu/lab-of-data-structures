#pragma once
#include<iostream>
#include<string>
using namespace std; 
const int DefaultSize=10;

struct HuffmanNode				//HuffmanNode 定义
{
	char ch;
	int weight;
	HuffmanNode *leftChild,*rightChild,*parent;
	HuffmanNode():leftChild(NULL),rightChild(NULL),parent(NULL){}	//无参构造
	HuffmanNode(char ch,int weight):leftChild(NULL),rightChild(NULL),parent(NULL)   //有参构造
	{
		this->ch=ch;
		this->weight=weight;
	}
	HuffmanNode(HuffmanNode& temp)				//拷贝构造
	{
		this->ch=temp.ch;
		this->weight=temp.weight;
		this->leftChild=temp.leftChild;
		this->rightChild=temp.rightChild;
		this->parent=temp.parent;
	}
	void operator=(HuffmanNode& R)			//重定义  = 用于两个节点间的赋值
	{
		this->ch=R.ch;
		this->weight=R.weight;
		this->leftChild=R.leftChild;
		this->rightChild=R.rightChild;
		this->parent=R.parent;
	}
};

class MinHeap					//最小堆定义
{
public:  
	MinHeap(int sz=DefaultSize);		//构造函数	
	~MinHeap()					//析构函数
	{
		delete []heap;
	}
	void Insert(HuffmanNode &x);		//插入函数	
	void RemoveMin(HuffmanNode& tt);		//取堆顶
private:
	HuffmanNode *heap;
	int currentSize;
	int maxHeapSize;
	void siftDown(int start,int m);			//下滑调整成为最小堆
	void siftUp(int start);					//上滑调整成为最小堆
};


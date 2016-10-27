#include "MinHeap.h"

MinHeap::MinHeap(int sz)		//构造函数	
{
	maxHeapSize=(DefaultSize<sz)?sz:DefaultSize;
	heap=new HuffmanNode[maxHeapSize];				//分配空间
	currentSize=0;
}

void MinHeap::siftDown(int start,int m)				//下滑调整成为最小堆
{
	int i=start,j=2*i+1;							//j是i的左子女位置
	HuffmanNode temp=heap[i];
	while(j<=m)										//检查是否到最后位置	
	{
		if(j<m&&heap[j].weight>heap[j+1].weight)	//让j指向两子女中的小者
			j++;
		if(temp.weight<=heap[j].weight)				//小则不做调整
			break;
		else										//否者小者上移，i，j下降
		{
			heap[i]=heap[j];
			i=j;
			j=2*j+1;
		}
	}
	heap[i]=temp;									//回放temp中暂存的元素
}

void MinHeap::siftUp(int start)					//上滑调整成为最小堆
{
	int j=start,i=(j-1)/2;						//j是i的左子女位置
	HuffmanNode temp=heap[j];
	while(j>0)									//检查是否到最后位置
	{
		if(heap[i].weight<=temp.weight)			//父节点值小 不调整
			break;
		else                                    //父节点值大 调整
		{
			heap[j]=heap[i];
			j=i;
			i=(i-1)/2;
		}
	}
	heap[j]=temp;						//回放temp中暂存的元素
}

void MinHeap::Insert(HuffmanNode &x)			//插入函数
{
	if(currentSize==maxHeapSize)			//堆满
	{
		cerr<<"The heap has been full!"<<endl;
	}
	heap[currentSize]=x;					//插入
	siftUp(currentSize);					//向上调整
	currentSize++;							//节点个数加1
}

void MinHeap::RemoveMin(HuffmanNode& tt)		//取堆顶
{
	if(currentSize==0)							//堆空
	{
		cerr<<"The heap is empty!"<<endl;
	}
	tt=heap[0];																
	heap[0]=heap[currentSize-1];			//把最后一个节点放到堆顶
	currentSize--;							//节点个数减1
	siftDown(0,currentSize-1);				//向下调整
}
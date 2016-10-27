#include "MinHeap.h"

MinHeap::MinHeap(int sz)		//���캯��	
{
	maxHeapSize=(DefaultSize<sz)?sz:DefaultSize;
	heap=new HuffmanNode[maxHeapSize];				//����ռ�
	currentSize=0;
}

void MinHeap::siftDown(int start,int m)				//�»�������Ϊ��С��
{
	int i=start,j=2*i+1;							//j��i������Ůλ��
	HuffmanNode temp=heap[i];
	while(j<=m)										//����Ƿ����λ��	
	{
		if(j<m&&heap[j].weight>heap[j+1].weight)	//��jָ������Ů�е�С��
			j++;
		if(temp.weight<=heap[j].weight)				//С��������
			break;
		else										//����С�����ƣ�i��j�½�
		{
			heap[i]=heap[j];
			i=j;
			j=2*j+1;
		}
	}
	heap[i]=temp;									//�ط�temp���ݴ��Ԫ��
}

void MinHeap::siftUp(int start)					//�ϻ�������Ϊ��С��
{
	int j=start,i=(j-1)/2;						//j��i������Ůλ��
	HuffmanNode temp=heap[j];
	while(j>0)									//����Ƿ����λ��
	{
		if(heap[i].weight<=temp.weight)			//���ڵ�ֵС ������
			break;
		else                                    //���ڵ�ֵ�� ����
		{
			heap[j]=heap[i];
			j=i;
			i=(i-1)/2;
		}
	}
	heap[j]=temp;						//�ط�temp���ݴ��Ԫ��
}

void MinHeap::Insert(HuffmanNode &x)			//���뺯��
{
	if(currentSize==maxHeapSize)			//����
	{
		cerr<<"The heap has been full!"<<endl;
	}
	heap[currentSize]=x;					//����
	siftUp(currentSize);					//���ϵ���
	currentSize++;							//�ڵ������1
}

void MinHeap::RemoveMin(HuffmanNode& tt)		//ȡ�Ѷ�
{
	if(currentSize==0)							//�ѿ�
	{
		cerr<<"The heap is empty!"<<endl;
	}
	tt=heap[0];																
	heap[0]=heap[currentSize-1];			//�����һ���ڵ�ŵ��Ѷ�
	currentSize--;							//�ڵ������1
	siftDown(0,currentSize-1);				//���µ���
}
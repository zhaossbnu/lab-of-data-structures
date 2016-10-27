#pragma once
#include<iostream>
using namespace std;
template<class T>
struct LinkNode				//����ڵ���Ķ���
{
	T data;					//������
	LinkNode<T> *link;		//ָ����
	LinkNode(LinkNode<T> *ptr=NULL)		//����ʼ��ָ���Ա�Ĺ��캯��
	{
		link=ptr;
	} 
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)			//��ʼ��������ָ���Ա�Ĺ��캯��
	{
		data =item;
		link=ptr;
	}
};

template<class T>
class List
{
public:
	List()					//�޲ι���
	{
		first=new LinkNode<T>;
	}
	List(const T&x)			//�вι���
	{
		first=new LinkNode<T>(x);
	}
	List(List<T>& temp);						//������캯��
	~List(void){}
	bool IsEmpty()const								//�ж������Ƿ�Ϊ��
	{
		return first->link==NULL;
	}
	LinkNode<T>* GetFirstDataNode()const			//�õ���һ�������ݵĽڵ�
	{
		return first->link;
	}
	T GetData(int i);					//�õ��ڵ�����ֵ
	bool Insert(int i,T& x);			//���뺯��
	LinkNode<T>* Locate(int i);		//���ص�i��Ԫ�صĵ�ַ
	LinkNode<T>* Max();				//�������ֵ�ڵ�ĵ�ַ
	int number(const T &x);			//ͳ�Ƶ������о��и���ֵx������Ԫ��
	List<T> create(const T a[],int n);		//����һά���齨������
	bool tidyup();					//ɾ������ڵ�			
	friend ostream& operator<<(ostream& out,LinkNode<T>& temp);		//�����������������ֵ
private:
	LinkNode<T> *first;
};

template<class T>
List<T>::List(List<T>& temp)						//������캯��
{
	T tempdata;										//��ʱ�洢����������ڵ������
	LinkNode<T>* copy=temp.first;					//����������ĸ���ͷ����ַ
	LinkNode<T>* current=first=new LinkNode<T>;
	while(copy->link!=NULL)
	{
		tempdata=copy->link->data;
		current->link=new LinkNode<T>(tempdata);
		current=current->link;
		copy=copy->link;
	}
	current->link=NULL;
}

template<class T>
bool List<T>::Insert(int i,T& x)					//���뺯��
{
	LinkNode<T>* current=Locate(i);					//ȷ������λ��
	if(current==NULL)
		return false;
	LinkNode<T>* NewNode=new LinkNode<T>(x);
	T temp=NewNode->data;
	NewNode->link=current->link;
	current->link=NewNode;
	return true;
}

template<class T>
T List<T>::GetData(int i)					//�õ��ڵ�����ֵ
{
	if(i<0)
		return NULL;
	LinkNode<T>* current=Locate(i);
	if(current==NULL)
		return NULL;
	else
		return current->data;
	
}

template<class T>
LinkNode<T>* List<T>::Locate(int i)		//��λ���� ���ص�i��Ԫ�صĵĵ�ַ
{
	if(i<0)							//iֵ������
		return NULL;
	LinkNode<T> *current=first;
	int k=0;
	while(current!=NULL&&k<i)			//ѭ��Ѱ��i
	{
		current=current->link;
		k++;
	}
	return current;						//���ص�i���ڵ��ַ ���iֵ���ڽڵ��� �򷵻�NULL
}

template<class T>
LinkNode<T>* List<T>::Max()				//�������ֵ�ڵ�ĵ�ַ
{
	T max=first->link->data;			//�������ֵ�ڵ��data
	LinkNode<T> *current=first->link;	
	LinkNode<T> *Max=first->link;			//�������ڵ�
	while(current!=NULL)				//�������� �ҵ����ڵ�
	{
		if(current->data>max)
		{
			max=current->data;
			Max=current;
		}
		current=current->link;
	}
	return Max;
}

template<class T>
int List<T>::number(const T &x)		//ͳ�Ƶ������о��и���ֵx������Ԫ��
{
	int count=0;
	LinkNode<T>* current=first->link;
	while(current!=NULL)			//��������
	{
		if(current->data==x)
			count++;
		current=current->link;
	}
	return count;
}

template<class T>
List<T> List<T>::create(const T a[],int n)
{
	LinkNode<T>* rear=first;	//���������βָ��
	for(int i=0;i<n;i++)		//�������� ������Ԫ�ش浽������
	{ 
		LinkNode<T>* current=new LinkNode<T>(a[i]);
		rear->link=current;
		rear=rear->link;
	}
	return *this;
}

template<class T>
bool List<T>::tidyup()					//ɾ������ڵ�
{
	  LinkNode<T>* current=first->link;		//���嵱ǰ�ڵ�
	  while(current->link!=NULL)
	  {
		  if(current->link->data==current->data)		//�Ƚϵ�ǰ�ڵ�����һ�ڵ��ֵ�Ƿ����
		  {
			  LinkNode<T>* p=current->link;						//ɾ����ǰ�ڵ����һ�ڵ�
			  current->link=current->link->link;
			  delete p;
			  continue;
		  }
		  current=current->link;
	  }
	  return true;
}

template<class T>
ostream& operator<<(ostream& out,List<T>& temp)			//�����������������ֵ
{
	LinkNode<T>* current=temp.GetFirstDataNode();		//�õ���һ�������ݵĽڵ�
	while(current!=NULL)
	{
		out<<current->data<<ends;
		current=current->link;
	}
	out<<endl;
	return out;
}
#pragma once
#include<iostream>
using namespace std;
template<class T>
struct LinkNode				//链表节点类的定义
{
	T data;					//数据域
	LinkNode<T> *link;		//指针域
	LinkNode(LinkNode<T> *ptr=NULL)		//仅初始化指针成员的构造函数
	{
		link=ptr;
	} 
	LinkNode(const T& item,LinkNode<T> *ptr=NULL)			//初始化数据与指针成员的构造函数
	{
		data =item;
		link=ptr;
	}
};

template<class T>
class List
{
public:
	List()					//无参构造
	{
		first=new LinkNode<T>;
	}
	List(const T&x)			//有参构造
	{
		first=new LinkNode<T>(x);
	}
	List(List<T>& temp);						//深拷贝构造函数
	~List(void){}
	bool IsEmpty()const								//判断链表是否为空
	{
		return first->link==NULL;
	}
	LinkNode<T>* GetFirstDataNode()const			//得到第一个有数据的节点
	{
		return first->link;
	}
	T GetData(int i);					//得到节点数据值
	bool Insert(int i,T& x);			//插入函数
	LinkNode<T>* Locate(int i);		//返回第i个元素的地址
	LinkNode<T>* Max();				//返回最大值节点的地址
	int number(const T &x);			//统计单链表中具有给定值x的所有元素
	List<T> create(const T a[],int n);		//根据一维数组建立链表
	bool tidyup();					//删除多余节点			
	friend ostream& operator<<(ostream& out,LinkNode<T>& temp);		//输出链表中所有数据值
private:
	LinkNode<T> *first;
};

template<class T>
List<T>::List(List<T>& temp)						//深拷贝构造函数
{
	T tempdata;										//临时存储被复制链表节点的数据
	LinkNode<T>* copy=temp.first;					//被复制链表的附加头结点地址
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
bool List<T>::Insert(int i,T& x)					//插入函数
{
	LinkNode<T>* current=Locate(i);					//确定插入位置
	if(current==NULL)
		return false;
	LinkNode<T>* NewNode=new LinkNode<T>(x);
	T temp=NewNode->data;
	NewNode->link=current->link;
	current->link=NewNode;
	return true;
}

template<class T>
T List<T>::GetData(int i)					//得到节点数据值
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
LinkNode<T>* List<T>::Locate(int i)		//定位函数 返回第i个元素的的地址
{
	if(i<0)							//i值不合理
		return NULL;
	LinkNode<T> *current=first;
	int k=0;
	while(current!=NULL&&k<i)			//循环寻找i
	{
		current=current->link;
		k++;
	}
	return current;						//返回第i个节点地址 如果i值大于节点数 则返回NULL
}

template<class T>
LinkNode<T>* List<T>::Max()				//返回最大值节点的地址
{
	T max=first->link->data;			//定义最大值节点的data
	LinkNode<T> *current=first->link;	
	LinkNode<T> *Max=first->link;			//定义最大节点
	while(current!=NULL)				//遍历链表 找到最大节点
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
int List<T>::number(const T &x)		//统计单链表中具有给定值x的所有元素
{
	int count=0;
	LinkNode<T>* current=first->link;
	while(current!=NULL)			//遍历链表
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
	LinkNode<T>* rear=first;	//定义链表的尾指针
	for(int i=0;i<n;i++)		//遍历数组 将数组元素存到链表内
	{ 
		LinkNode<T>* current=new LinkNode<T>(a[i]);
		rear->link=current;
		rear=rear->link;
	}
	return *this;
}

template<class T>
bool List<T>::tidyup()					//删除多余节点
{
	  LinkNode<T>* current=first->link;		//定义当前节点
	  while(current->link!=NULL)
	  {
		  if(current->link->data==current->data)		//比较当前节点与下一节点的值是否相等
		  {
			  LinkNode<T>* p=current->link;						//删除当前节点的下一节点
			  current->link=current->link->link;
			  delete p;
			  continue;
		  }
		  current=current->link;
	  }
	  return true;
}

template<class T>
ostream& operator<<(ostream& out,List<T>& temp)			//输出链表中所有数据值
{
	LinkNode<T>* current=temp.GetFirstDataNode();		//得到第一个有数据的节点
	while(current!=NULL)
	{
		out<<current->data<<ends;
		current=current->link;
	}
	out<<endl;
	return out;
}
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
class LinkedStack						//链式栈类定义
{
public:
	LinkedStack():top(NULL){}			//无参构造函数
	~LinkedStack()						//析构函数
	{
		MakeEmpty();					
	}
	void Push(const T& x);				//压栈
	T Pop();							//弹栈
	T GetTop()const;					//得到栈顶数据
	bool IsEmpty()						//判断栈是否为空
	{
		return top==NULL;
	}
	int GetSize()const;					//得到栈中元素个数
	void MakeEmpty();					//清空栈
	friend ostream& operator<<(ostream& out,LinkedStack<T>& t);			//重载运算符<< 输出栈中元素
private:
	LinkNode<T> *top;						//栈顶指针
};

template<class T>
void LinkedStack<T>::Push(const T& x)		//压栈
{
	top=new LinkNode<T>(x,top);				//创建新的节点 使得它指向原来的top
}

template<class T>
T LinkedStack<T>::Pop()						//弹栈
{
	if(IsEmpty())							//判断栈是否为空
		return NULL;
	LinkNode<T>* current=top;				//定义临时指针 令其指向top
	top=top->link;
	T temp=current->data;					//定义临时变量  用来存储栈顶元素值
	delete current;							//释放原top节点
	return temp;
}

template<class T>
T LinkedStack<T>::GetTop()const
{
	return top->data;						//返回栈顶元素值
}

template<class T>
int LinkedStack<T>::GetSize()const 			//得到栈中元素个数
{
	int count=0;							//定义计数变量
	LinkNode<T>* current=top;			
	while(current!=NULL)
	{
		current=current->link;
		count++;
	}
	return count;
}

template<class T>
void LinkedStack<T>::MakeEmpty()	//清空栈
{
	LinkNode<T>* current;
	while(top!=NULL)				//逐个节点释放
	{
		current=top;
		top=top->link;
		delete current;
	}
}

template<class T>
ostream& operator<<(ostream& out,LinkedStack<T>& t)		//重载运算符<< 输出栈中元素
{
	LinkNode<T>* current=top;
	while(current!=NULL)					//逐个输出栈中元素的值
	{
		out<<current->data<<ends;
		current=current->link;
	}
	out<<endl;
	return out;
}
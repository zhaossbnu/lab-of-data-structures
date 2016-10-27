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
class LinkedStack						//��ʽջ�ඨ��
{
public:
	LinkedStack():top(NULL){}			//�޲ι��캯��
	~LinkedStack()						//��������
	{
		MakeEmpty();					
	}
	void Push(const T& x);				//ѹջ
	T Pop();							//��ջ
	T GetTop()const;					//�õ�ջ������
	bool IsEmpty()						//�ж�ջ�Ƿ�Ϊ��
	{
		return top==NULL;
	}
	int GetSize()const;					//�õ�ջ��Ԫ�ظ���
	void MakeEmpty();					//���ջ
	friend ostream& operator<<(ostream& out,LinkedStack<T>& t);			//���������<< ���ջ��Ԫ��
private:
	LinkNode<T> *top;						//ջ��ָ��
};

template<class T>
void LinkedStack<T>::Push(const T& x)		//ѹջ
{
	top=new LinkNode<T>(x,top);				//�����µĽڵ� ʹ����ָ��ԭ����top
}

template<class T>
T LinkedStack<T>::Pop()						//��ջ
{
	if(IsEmpty())							//�ж�ջ�Ƿ�Ϊ��
		return NULL;
	LinkNode<T>* current=top;				//������ʱָ�� ����ָ��top
	top=top->link;
	T temp=current->data;					//������ʱ����  �����洢ջ��Ԫ��ֵ
	delete current;							//�ͷ�ԭtop�ڵ�
	return temp;
}

template<class T>
T LinkedStack<T>::GetTop()const
{
	return top->data;						//����ջ��Ԫ��ֵ
}

template<class T>
int LinkedStack<T>::GetSize()const 			//�õ�ջ��Ԫ�ظ���
{
	int count=0;							//�����������
	LinkNode<T>* current=top;			
	while(current!=NULL)
	{
		current=current->link;
		count++;
	}
	return count;
}

template<class T>
void LinkedStack<T>::MakeEmpty()	//���ջ
{
	LinkNode<T>* current;
	while(top!=NULL)				//����ڵ��ͷ�
	{
		current=top;
		top=top->link;
		delete current;
	}
}

template<class T>
ostream& operator<<(ostream& out,LinkedStack<T>& t)		//���������<< ���ջ��Ԫ��
{
	LinkNode<T>* current=top;
	while(current!=NULL)					//������ջ��Ԫ�ص�ֵ
	{
		out<<current->data<<ends;
		current=current->link;
	}
	out<<endl;
	return out;
}
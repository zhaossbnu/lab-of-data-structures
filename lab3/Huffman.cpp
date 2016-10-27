#include "Huffman.h"


Huffman::Huffman(char ch[],int weight[],int n)				//�вι���
{
	MinHeap hp;									//����С�Ѵ��ɭ��
	HuffmanNode* parent,first,second,temp;
	for(int i=0;i<n;i++)						//ɭ�ָ�������ʼ��
	{
		temp.ch=ch[i];
		temp.weight=weight[i];
		temp.leftChild=NULL;
		temp.rightChild=NULL;
		temp.parent=NULL;
		hp.Insert(temp);					//����
	}
	for(int i=0;i<n-1;i++)
	{
		hp.RemoveMin(first);		//ѡ���Ȩֵ��С����
		hp.RemoveMin(second);		//ѡ���Ȩֵ��С����
		merge(first,second,parent);	//�ϲ�
		hp.Insert(*parent);			//���²�����С��
	}
	root=parent;					//�������ڵ�
}


void Huffman::deleteTree(HuffmanNode *t)		//ɾ����tΪ������
{
	if(t!=NULL)
    {
        deleteTree(t->leftChild);				//ɾ��������
        deleteTree(t->rightChild);				//ɾ��������
        delete t;								//ɾ����
    }
}

Huffman::~Huffman()					//��������
{
	deleteTree(root);
}

void Huffman::code(HuffmanNode *subTree,string str)					//���������ĸ��Huffman����
{
	if(subTree->rightChild==NULL&&subTree->leftChild==NULL)			//�ҵ�Ҷ�ڵ�
	{
		cout<<subTree->ch<<":"<<str<<endl;							//�������
		return;
	}
	code(subTree->leftChild,str+"0");								//������������
	code(subTree->rightChild,str+"1");								//ɾ��������
}

void Huffman::translation(string str)							//���뺯��
{
	int i=0;
	HuffmanNode* subTree=root;									
	while(str[i]!='\0')
	{
		if(str[i]=='0')										//��Ϊ0 ���
			subTree=subTree->leftChild;	
		else												//��Ϊ1 �ҽ�												
			subTree=subTree->rightChild;
		if(subTree->leftChild==NULL&&subTree->rightChild==NULL)		//�ҵ�Ҷ�ڵ� ����ַ�
		{
			cout<<subTree->ch;
			subTree=root;
		}
		i++;
	}
}

void Huffman::outputPreorder()						//���ǰ��������
{
	PreOrder(root);									//ǰ�����
	cout<<endl;
}

void Huffman::outputInorder()						//�������������
{
	InOrder(root);									//�������
	cout<<endl;
}

void Huffman::outputPostorder()						//�������������
{
	PostOrder(root);								//�������
	cout<<endl;
}

void Huffman::PreOrder(HuffmanNode *subTree)		//ǰ�����
{
	if(subTree!=NULL)
	{
		cout<<subTree->weight<<ends;				//���ʸ��ڵ�
		PreOrder(subTree->leftChild);				//ǰ�����������
		PreOrder(subTree->rightChild);				//ǰ�����������
	}
}

void Huffman::InOrder(HuffmanNode *subTree)			//�������
{
	if(subTree!=NULL)
	{
		InOrder(subTree->leftChild);				//�������������
		cout<<subTree->weight<<ends;				//���ʸ��ڵ�
		InOrder(subTree->rightChild);				//�������������
	}
}

void Huffman::PostOrder(HuffmanNode *subTree)		//�������
{
	if(subTree!=NULL)
	{
		PostOrder(subTree->leftChild);				//�������������
		PostOrder(subTree->rightChild);				//�������������
		cout<<subTree->weight<<ends;				//���ʸ��ڵ�
	}
}

void Huffman::merge(HuffmanNode& left,HuffmanNode& right,HuffmanNode*& parent)		//�ϲ�������
{
	parent=new HuffmanNode;
	HuffmanNode *lt=new HuffmanNode;
	HuffmanNode *rt=new HuffmanNode;
	*lt=left;
	*rt=right;
	parent->leftChild=lt;
	parent->rightChild=rt;
	parent->weight=left.weight+right.weight;
	lt->parent=rt->parent=parent;
}
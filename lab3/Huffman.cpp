#include "Huffman.h"


Huffman::Huffman(char ch[],int weight[],int n)				//有参构造
{
	MinHeap hp;									//用最小堆存放森林
	HuffmanNode* parent,first,second,temp;
	for(int i=0;i<n;i++)						//森林各棵树初始化
	{
		temp.ch=ch[i];
		temp.weight=weight[i];
		temp.leftChild=NULL;
		temp.rightChild=NULL;
		temp.parent=NULL;
		hp.Insert(temp);					//插入
	}
	for(int i=0;i<n-1;i++)
	{
		hp.RemoveMin(first);		//选择跟权值最小的树
		hp.RemoveMin(second);		//选择跟权值次小的树
		merge(first,second,parent);	//合并
		hp.Insert(*parent);			//重新插入最小堆
	}
	root=parent;					//建立根节点
}


void Huffman::deleteTree(HuffmanNode *t)		//删除以t为根的树
{
	if(t!=NULL)
    {
        deleteTree(t->leftChild);				//删除左子树
        deleteTree(t->rightChild);				//删除右子树
        delete t;								//删除根
    }
}

Huffman::~Huffman()					//析构函数
{
	deleteTree(root);
}

void Huffman::code(HuffmanNode *subTree,string str)					//输出各个字母的Huffman编码
{
	if(subTree->rightChild==NULL&&subTree->leftChild==NULL)			//找到叶节点
	{
		cout<<subTree->ch<<":"<<str<<endl;							//输出编码
		return;
	}
	code(subTree->leftChild,str+"0");								//向左子树搜索
	code(subTree->rightChild,str+"1");								//删除右子树
}

void Huffman::translation(string str)							//译码函数
{
	int i=0;
	HuffmanNode* subTree=root;									
	while(str[i]!='\0')
	{
		if(str[i]=='0')										//码为0 左进
			subTree=subTree->leftChild;	
		else												//码为1 右进												
			subTree=subTree->rightChild;
		if(subTree->leftChild==NULL&&subTree->rightChild==NULL)		//找到叶节点 输出字符
		{
			cout<<subTree->ch;
			subTree=root;
		}
		i++;
	}
}

void Huffman::outputPreorder()						//输出前序遍历结果
{
	PreOrder(root);									//前序遍历
	cout<<endl;
}

void Huffman::outputInorder()						//输出中序遍历结果
{
	InOrder(root);									//中序遍历
	cout<<endl;
}

void Huffman::outputPostorder()						//输出后序遍历结果
{
	PostOrder(root);								//后序遍历
	cout<<endl;
}

void Huffman::PreOrder(HuffmanNode *subTree)		//前序遍历
{
	if(subTree!=NULL)
	{
		cout<<subTree->weight<<ends;				//访问根节点
		PreOrder(subTree->leftChild);				//前序遍历左子树
		PreOrder(subTree->rightChild);				//前序遍历右子树
	}
}

void Huffman::InOrder(HuffmanNode *subTree)			//中序遍历
{
	if(subTree!=NULL)
	{
		InOrder(subTree->leftChild);				//中序遍历左子树
		cout<<subTree->weight<<ends;				//访问根节点
		InOrder(subTree->rightChild);				//中序遍历右子树
	}
}

void Huffman::PostOrder(HuffmanNode *subTree)		//后序遍历
{
	if(subTree!=NULL)
	{
		PostOrder(subTree->leftChild);				//后序遍历左子树
		PostOrder(subTree->rightChild);				//后序遍历右子树
		cout<<subTree->weight<<ends;				//访问根节点
	}
}

void Huffman::merge(HuffmanNode& left,HuffmanNode& right,HuffmanNode*& parent)		//合并二叉树
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
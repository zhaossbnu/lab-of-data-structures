#pragma once
#include"MinHeap.h"


class Huffman				//Huffman编码数定义
{
public:
	Huffman(char ch[],int weight[],int n);			//有参构造
	~Huffman();										//析构函数
	void code(HuffmanNode *subTree,string str);		//输出各个字母的Huffman编码
	void translation(string str);					//译码函数
	HuffmanNode* GetRoot()							//得到根节点
	{
		return root;
	}
	void outputPreorder();							//输出前序遍历结果
	void outputInorder();							//输出中序遍历结果
	void outputPostorder();							//输出后序遍历结果
protected:
	void deleteTree(HuffmanNode *t);						//删除以t为根的树	
	void merge(HuffmanNode& left,HuffmanNode& right,HuffmanNode*& parent);		//合并二叉树	
	void PreOrder(HuffmanNode *subTree);					//前序遍历
	void InOrder(HuffmanNode *subTree);						//中序遍历
	void PostOrder(HuffmanNode *subTree);					//后序遍历
private:
	HuffmanNode *root;
};

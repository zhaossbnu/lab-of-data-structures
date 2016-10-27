#pragma once
#include"MinHeap.h"


class Huffman				//Huffman����������
{
public:
	Huffman(char ch[],int weight[],int n);			//�вι���
	~Huffman();										//��������
	void code(HuffmanNode *subTree,string str);		//���������ĸ��Huffman����
	void translation(string str);					//���뺯��
	HuffmanNode* GetRoot()							//�õ����ڵ�
	{
		return root;
	}
	void outputPreorder();							//���ǰ��������
	void outputInorder();							//�������������
	void outputPostorder();							//�������������
protected:
	void deleteTree(HuffmanNode *t);						//ɾ����tΪ������	
	void merge(HuffmanNode& left,HuffmanNode& right,HuffmanNode*& parent);		//�ϲ�������	
	void PreOrder(HuffmanNode *subTree);					//ǰ�����
	void InOrder(HuffmanNode *subTree);						//�������
	void PostOrder(HuffmanNode *subTree);					//�������
private:
	HuffmanNode *root;
};

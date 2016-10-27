#include<iostream>
#include"Huffman.h"
using namespace std;

int main(void)
{
	char ch[5]={'a','b','c','d','e'};			//�ַ�����
	int weight[5]={4,7,5,2,9};					//Ȩֵ����
	string test="11000111000101011";			//�����������
	Huffman hehe(ch,weight,5);

	cout<<"Preorder:"<<endl;				//���ǰ��������
	hehe.outputPreorder();
	cout<<"Inorder:"<<endl;					//�������������
	hehe.outputInorder();
	cout<<"Postorder:"<<endl;				//�������������
	hehe.outputPostorder();
	cout<<endl;

	string code="";							//����ַ�����
	hehe.code(hehe.GetRoot(),code);
	cout<<code<<endl;

	cout<<"translation:11000111000101011"<<endl;			//����
	hehe.translation(test);
	cout<<endl;
	
	return 0;
}

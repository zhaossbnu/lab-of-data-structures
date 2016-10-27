#include<iostream>
#include"Huffman.h"
using namespace std;

int main(void)
{
	char ch[5]={'a','b','c','d','e'};			//字符数组
	int weight[5]={4,7,5,2,9};					//权值数组
	string test="11000111000101011";			//译码测试数据
	Huffman hehe(ch,weight,5);

	cout<<"Preorder:"<<endl;				//输出前序遍历结果
	hehe.outputPreorder();
	cout<<"Inorder:"<<endl;					//输出中序遍历结果
	hehe.outputInorder();
	cout<<"Postorder:"<<endl;				//输出后序遍历结果
	hehe.outputPostorder();
	cout<<endl;

	string code="";							//输出字符编码
	hehe.code(hehe.GetRoot(),code);
	cout<<code<<endl;

	cout<<"translation:11000111000101011"<<endl;			//译码
	hehe.translation(test);
	cout<<endl;
	
	return 0;
}

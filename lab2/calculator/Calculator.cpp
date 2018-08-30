#include "Calculator.h"

int isp(char ch)					//栈内符号优先级
{
	int temp=-1;
	switch(ch)
	{
		case '#':
			temp=-1;
			break;
		case '(':
			temp=1;
			break;
		case '*':
		case '/':
		case '%':
			temp=5;
			break;
		case '+':
		case '-':
			temp=3;
			break;
		case ')':
			temp=6;
			break;
	}
	return temp;
}

int icp(char ch)				//栈外符号优先级
{
	int temp=-1;
	switch(ch)
	{
		case '#':
			temp=-1;
			break;
		case '(':
			temp=6;
			break;
		case '*':
		case '/':
		case '%':
			temp=4;
			break;
		case '+':
		case '-':
			temp=2;
			break;
		case ')':
			temp=0;
			break;
	}
	return temp;
}

void Calculator::Run()				//计算器运行函数
{
	Clear();						//清空双栈
	op.Push('#');					//将#压入操作符栈 便于控制运算结束
	cout<<"请输入计算表达式，以#结束：";
	char ch;
	double newOperand;
	while(cin>>ch)
	{
		switch(ch)
		{
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'#':
			if(isp(op.GetTop())<icp(ch))			//如果栈顶元素优先级小于读入字符优先级
				op.Push(ch);
			else if(isp(op.GetTop())>icp(ch))		//如果栈顶元素优先级大于读入字符优先级
			{
				while (isp(op.GetTop())>icp(ch))	//只要栈外的运算符优先级高于栈内优先级即进行运算
				{                                   //实在懒得解释
					if(op.GetTop()=='(')
					{
						op.Pop();
						break;
					}
					DoOperator(op.GetTop());
					//cout<<op.GetTop();
					op.Pop();
				}
				if(ch=='+'||ch=='-'||ch=='*'||ch=='/')			
					op.Push(ch);		
			}
			else							//如果栈顶元素优先级等于于读入字符优先级
				op.Pop();
			break;
		default:						//发现读入字符不是运算符						
			cin.putback(ch);			//将字符放回输入流
			cin>>newOperand;			//读入操作数
			//cout<<newOperand;
			num.Push(newOperand);		//将操作数入栈
			break;
		}
		if(ch=='#')						//若果读到#  运算结束
			break;
	}
	if(op.Pop()=='#')					//操作符栈 只剩#  可以输出操作数栈的栈顶结果
		cout<<endl<<num.Pop()<<endl;
	Clear();
}

void Calculator::Clear()			//清空操作数和操作符栈
{
	num.MakeEmpty();				//清空操作数
	op.MakeEmpty();					//清空操作符栈
}

bool Calculator::Get2Operands(double& left,double& right)		//从操作数栈中提取两个操作数
{
	if(num.IsEmpty())							//判断栈空否
	{
		cerr<<"缺少右操作数！"<<endl;
		return false;
	}
	right=num.Pop();							//弹出操作数 并作为右操作数
	if(num.IsEmpty())							//判断栈空否
	{
		cerr<<"缺少左操作数！"<<endl;
		return false;
	}
	left=num.Pop();								//弹出操作数 并作为左操作数
	return true;
}

void Calculator::DoOperator(char Operator)		//进行一次运算操作
{
	double left,right,value;
	bool result=Get2Operands(left,right);
	if(result)
	{
		switch(Operator)					//选择运算符
		{
		case'+':							//执行加法运算
			value=left+right;
			num.Push(value);				//将运算结果压入栈中
			break;
		case'-':							//执行减法运算
			value=left-right;
			num.Push(value);				//将运算结果压入栈中
			break;
		case'*':							//执行乘法运算
			value=left*right;
			num.Push(value);				//将运算结果压入栈中
			break;
		case'/':							//执行除法运算
			if(right==0.0)					//除数不能为0
			{
				cerr<<"除数不能为0!"<<endl;
				Clear();					//清空双栈
			}
			else
			{
				value=left/right;
				num.Push(value);			//将运算结果压入栈中
			}
			break;
		}
	}
	else
		Clear();							//如果不能成功得到左右操作数 清空双栈
}
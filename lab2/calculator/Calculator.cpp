#include "Calculator.h"

int isp(char ch)					//ջ�ڷ������ȼ�
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

int icp(char ch)				//ջ��������ȼ�
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

void Calculator::Run()				//���������к���
{
	Clear();						//���˫ջ
	op.Push('#');					//��#ѹ�������ջ ���ڿ����������
	cout<<"�����������ʽ����#������";
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
			if(isp(op.GetTop())<icp(ch))			//���ջ��Ԫ�����ȼ�С�ڶ����ַ����ȼ�
				op.Push(ch);
			else if(isp(op.GetTop())>icp(ch))		//���ջ��Ԫ�����ȼ����ڶ����ַ����ȼ�
			{
				while (isp(op.GetTop())>icp(ch))	//ֻҪջ�����������ȼ�����ջ�����ȼ�����������
				{                                   //ʵ�����ý���
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
			else							//���ջ��Ԫ�����ȼ������ڶ����ַ����ȼ�
				op.Pop();
			break;
		default:						//���ֶ����ַ����������						
			cin.putback(ch);			//���ַ��Ż�������
			cin>>newOperand;			//���������
			//cout<<newOperand;
			num.Push(newOperand);		//����������ջ
			break;
		}
		if(ch=='#')						//��������#  �������
			break;
	}
	if(op.Pop()=='#')					//������ջ ֻʣ#  �������������ջ��ջ�����
		cout<<endl<<num.Pop()<<endl;
	Clear();
}

void Calculator::Clear()			//��ղ������Ͳ�����ջ
{
	num.MakeEmpty();				//��ղ�����
	op.MakeEmpty();					//��ղ�����ջ
}

bool Calculator::Get2Operands(double& left,double& right)		//�Ӳ�����ջ����ȡ����������
{
	if(num.IsEmpty())							//�ж�ջ�շ�
	{
		cerr<<"ȱ���Ҳ�������"<<endl;
		return false;
	}
	right=num.Pop();							//���������� ����Ϊ�Ҳ�����
	if(num.IsEmpty())							//�ж�ջ�շ�
	{
		cerr<<"ȱ�����������"<<endl;
		return false;
	}
	left=num.Pop();								//���������� ����Ϊ�������
	return true;
}

void Calculator::DoOperator(char Operator)		//����һ���������
{
	double left,right,value;
	bool result=Get2Operands(left,right);
	if(result)
	{
		switch(Operator)					//ѡ�������
		{
		case'+':							//ִ�мӷ�����
			value=left+right;
			num.Push(value);				//��������ѹ��ջ��
			break;
		case'-':							//ִ�м�������
			value=left-right;
			num.Push(value);				//��������ѹ��ջ��
			break;
		case'*':							//ִ�г˷�����
			value=left*right;
			num.Push(value);				//��������ѹ��ջ��
			break;
		case'/':							//ִ�г�������
			if(right==0.0)					//��������Ϊ0
			{
				cerr<<"��������Ϊ0!"<<endl;
				Clear();					//���˫ջ
			}
			else
			{
				value=left/right;
				num.Push(value);			//��������ѹ��ջ��
			}
			break;
		}
	}
	else
		Clear();							//������ܳɹ��õ����Ҳ����� ���˫ջ
}
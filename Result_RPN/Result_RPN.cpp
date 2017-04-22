// Result_RPN.cpp : �������̨Ӧ�ó������ڵ㡣
#include<iostream>
#include<stack>
#include<assert.h>
#include<string.h>
using namespace std;
enum Symbol
{
	OP_NUM,
	OP_SYMBOL,
	ADD,
	SUB,
	SUL,
	DIV
};
struct Cell
{
	char _symbol;//������
	int _value;//������
};
void testMinToLast()
{
	stack<int>s;
	Cell RPNArray[]=
	{
		{OP_NUM,9},
		{OP_NUM,3},
		{OP_NUM,1},
		{OP_SYMBOL,SUB},
		{OP_NUM,3},
		{OP_SYMBOL,SUL},
		{OP_SYMBOL,ADD},
		{OP_NUM,10},
		{OP_NUM,2},
		{OP_SYMBOL,DIV},
		{OP_SYMBOL,ADD}
	};
	size_t sz = sizeof(RPNArray) / sizeof(RPNArray[0]);
	for (size_t i = 0; i < sz; i++)
	{
		int right = 0, left = 0;
		if (RPNArray[i]._symbol == 0)
		{
			s.push(RPNArray[i]._value);
		}
		else
		{
			switch (RPNArray[i]._value)
			{
			case ADD:
				right = s.top();
				s.pop();
				left = s.top();
				s.pop();
				s.push(right + left);
				break;
			case SUB:
				right = s.top();
				s.pop();
				left = s.top();
				s.pop();
				s.push(left - right);
				break;
			case SUL:
				right = s.top();
				s.pop();
				left = s.top();
				s.pop();
				s.push(left*right);
				break;
			case DIV:
				right = s.top();
				s.pop();
				left = s.top();
				s.pop();
				s.push(left / right);
				break;
			default:
				break;
			}
		}
	}
	cout << s.top() << endl;
	s.pop();
}
int main()
{
	testMinToLast();
	system("pause");
	return 0;
}
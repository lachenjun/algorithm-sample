#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node 
{
	long data;
	Node* next;
};
//JOSEPHUS

Node * initjosephus(int n)
{
	// initjosephus
	Node * pnode = new Node;
	Node * phead = pnode;
	Node * pCur = pnode;
	pnode->data = 1;
	pnode->next = phead;
	for(long i = 2; i <= n; ++i)
	{
		Node * pnode = new Node;
		pnode->data = i;
		pnode->next = phead;
		pCur->next = pnode;
		pCur = pCur->next;
	}
	return phead;
}

//void printjosephus(Node* phead, int len)
//{
//	for (int i = 0; i < len; ++i)
//	{
//		cout << phead->data << " ";
//		phead = phead->next;
//	}
//}

Node * movejosephus(Node* phead, int offset)
{
	for (int i = 0; i < offset; ++i)
	{
		if (phead != NULL)
			phead = phead->next;
		else 
			return NULL;
	}
	return phead;
}

Node * deletejosephus(Node * prenode, Node * curnode)
{
	if (prenode != curnode)
	{
		prenode->next = curnode->next;
		delete curnode;
		return prenode->next;
	}
	else
	{
		delete prenode;
		return NULL;
	}
}

void JOSEPHUS(Node *phead, int begin, int offset)
{
	phead = movejosephus(phead, begin - 1);
	while(phead)
	{
		Node *prenode = movejosephus(phead, offset - 1);
		Node *curnode = movejosephus(prenode, 1);
		cout << curnode->data << " ";
		phead = deletejosephus(prenode, curnode);
	}
}

void main()
{
	Node * phead = initjosephus(8);
	JOSEPHUS(phead, 3, 3);
}
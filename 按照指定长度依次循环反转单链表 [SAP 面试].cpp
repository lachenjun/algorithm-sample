#include <iostream>
#include <windows.h>
using namespace std;

struct Node
{
	long data;
	Node * next;
};

Node * reversenlink(Node * phead, long len)
{
	if (!phead->next)
		return NULL;
	else
	{
		Node * prear = phead->next;
		Node * pindex = phead->next;
		while (pindex && len--)
		{
			Node * temp = pindex;
			pindex = pindex->next;
			temp->next = phead->next;
			phead->next = temp;
		}
		return prear;
	}
}

Node * step(Node * phead, long len)
{	
	if (!phead->next)
		return NULL;
	Node * pindex = phead->next;
	while (pindex && len--)
	{
		pindex = pindex->next;
	}
	return pindex;
}

Node * insertNode(Node * pCur, long value)
{
	Node * p = new Node;
	p->data = value;
	p->next = NULL;
	pCur->next = p;
	pCur = pCur->next;
	return pCur;
}

Node * initNode(long len)
{
	Node * phead = new Node;
	phead->next = NULL;
	Node * pCur = phead;
	for (long i = 1; i <= len; ++i)
	{
		pCur = insertNode(pCur, i);
	}
	return phead;
}

void printlink(Node * phead)
{
	Node * pCur = phead->next;
	while (pCur)
	{
		cout << pCur->data << " ";
		pCur = pCur->next;
	}
	cout << endl;
}

void reservelinkbyn(long len, long diveby)
{
	Node * phead = initNode(len);
	printlink(phead);

	long parts = len%diveby == 0 ? len/diveby : (len/diveby + 1);
	Node * rear  = phead;
	Node * pnext = phead;

	for (int i =0; i < parts; ++i)
	{
		pnext = step(rear, diveby);
		rear = reversenlink(rear, diveby);
		rear->next = pnext;
	}
	printlink(phead);
}
void main()
{	
	reservelinkbyn(11,-1);
}
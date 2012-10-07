struct Node
{
	long data;
	Node* next;
};

Node * initlink()
{
	Node *head = new Node;
	head->data = 0;
	head->next = NULL;
	Node *index = head;

	for (long i = 1; i < 20; ++i)
	{
		Node * node = new Node;
		node->data = i;
		node->next = NULL;
		index->next = node;
		index = index->next;
	}
	return head;
}

void reverselink(Node * p)
{
	Node * head = p;
	p = p->next;
	head->next = NULL;

	while(p)
	{
		Node * cur = p;
		p = p->next;
		Node * temp = head->next;
		head->next = cur;
		cur->next = temp;
	}
}

void printlink(Node * p)
{
	while(p->next)
	{
		p = p->next;
		cout << p->data << " ";
	}
	cout << endl;
}
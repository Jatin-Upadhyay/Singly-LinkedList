#include<iostream>
using namespace std;

class node
{
	public:
		int info;
		node *prev;
		node *next;
		void insert_middle(int n, int x);
		void insert_end(int n);
		void insert_beg(int n);
		void delete_middle(int x);
		void delete_end();
		void delete_beg();
		void print();
		void count_node();
		void search(int n);
		node();
}*last, *temp, *t;

node::node()
{
	last = NULL;
}

void node::insert_end(int n)
{
	if(last == NULL)
	{
		temp = new node;
		temp->info = n;
		temp->next = temp->prev = temp;
		last = temp;
	}
	else
	{
		temp = new node;
		temp->info = n;
		last->next = temp;
		temp->prev = last;
		last->prev = temp;
		temp->next = last;
		last = temp;
	}
}

void node::insert_beg(int n)
{
	temp = new node;
	temp->info = n;
	temp->next = last->next;
	last->next->prev = temp;
	temp->prev = last;
}

void node::insert_middle(int n, int x)
{
	temp = new node;
	temp->info = n;
	t = last->next;
	for(int i = 1; i<x; ++i)
		t = t->next;
	temp->next = t->next;
	t->next->prev = temp;
	temp->prev = t;
	t->next = temp;
}

void node::delete_end()
{
	temp = last->next;
	while(temp->next != last)
		temp = temp->next;
		last = temp;
		temp = temp->next;
		last->next = temp->next;
		temp->next->prev = last;
		delete temp;
}

void node::delete_beg()
{
	temp = last->next;
	temp->next->prev = last;
	last->next = temp->next;
	delete temp;
}

void node::delete_middle(int x)
{
	temp = last->next;
	for(int i = 1; i<x; ++i)
		temp = temp->next;
	t = temp->next;
	temp->next = t->next;
	t->next->prev = temp;
	delete t;
}

void node::count_node()
{
	int c = 0;
	do
	{
		temp = last->next;
		c++;
		temp = temp->next;
	}while(temp != last->next);
	cout<<"\nNo. of node are "<<c;
}

void node::search(int n)
{
	int c = 0, flag = 0;
	do
	{
		temp = last->next;
		c++;
		if(n == temp->info)
		{
			flag = 1;
			break;
		}
	}while(temp != last->next);
	if(flag)
		cout<<"\nNode found at "<<c;
	else
		cout<<"\nNode not found";
}

void node::print()
{
	temp = last->next;
	do
	{
		cout<<temp->info<<"->";
		temp = temp->next;
	}while(temp != last->next);
}

int main()
{
	node x;
	int a, n;
	lb:
	system("cls");
	cout<<"MENU";
	cout<<"\n1.Insert_end node"
		<<"\n2.Insert_beg node"
		<<"\n3.Insert_middle node"
		<<"\n4.Delete_middle node"
		<<"\n5.Delete_end node"
		<<"\n6.Delete_beg node"
		<<"\n7.Count no. of node"
		<<"\n8.Search"
		<<"\n9.Print"
		<<"\nEnter your choice:";
	cin>>a;
	switch(a)
	{
		case 1 : 
			cout<<"\nEnter the no. to be entered in a node:";
			cin>>n;
			x.insert_end(n);
			x.print();
			break;
		case 2 :
			cout<<"\nEnter the no. to be entered in a node:";
			cin>>n;
			x.insert_beg(n);
			x.print();
			break;
		case 3 : 
			int pos;
			cout<<"\nEnter the no. to be entered in a node:";
			cin>>n;
			cout<<"Enter the position:";
			cin>>pos;
			x.insert_middle(n);
			x.print();
			break;
		case 4 :
			cout<<"\nEnter the postion of node to be deleted:";
			cin>>n;
			x.delete_middle(n);
			x.print();
			break;
		case 5 :
			x.delete_end();
			x.print();
			break;
		case 6 :
			x.delete_beg();
			x.print();
			break;
		case 7 :
			x.count_node();
			break;
		case 8 :
			cout<<"Enter node to be searched for:";
			cin>>n;
			x.search(n);
			break;
		case 9 :
			x.print();
			break;	
	}
	cout<<"\nAgain?(1 for yes, 0 for no):";
	cin>>a;
	if(a == 1)
		goto lb;
	return 0;
}

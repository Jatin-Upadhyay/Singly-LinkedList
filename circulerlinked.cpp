#include<iostream>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		void insert_middle(int n, int x);
		void insert_end(int n);
		void insert_beg(int n);
		void delete_middle(int x);
		void delete_end();
		void delete_beg();
		void print();
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
		temp->next = temp;
		last = temp;
	}
	else
	{
		temp = new node;
		temp->info = n;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

void node::insert_beg(int n)
{
	temp = new node;
	temp->info = n;
	temp->next = last->next;
	last->next = temp;
}

void node::insert_middle(int n, int x)
{
	temp = new node;
	temp->info = n;
	t = last->next;
	for(int i = 1; i<x; ++i)
		t = t->next;
	temp->next = t->next;
	t->next = temp;
}

void node::delete_beg()
{
	temp = last->next;
	last->next = temp->next;
	delete temp;
}

void node::delete_end()
{
	temp = last->next;
	while(temp->next !=last)
		temp = temp->next;
	last = temp;
	temp = temp->next;
	last->next = temp->next;
	delete temp;
}

void node::delete_middle(int x)
{
	temp = t = last->next;
	for(int i = 1; i<x; ++i)
		t = t->next;
	temp = t->next;
	t->next = temp->next;
	delete temp;
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
		<<"\n7.Print"
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
			x.print();
			break;	
	}
	cout<<"\nAgain?(1 for yes, 0 for no):";
	cin>>a;
	if(a == 1)
		goto lb;
	return 0;
}

#include "StdAfx.h"
#include "Tree.h"


Tree::Tree(void)
{
	root=0;
}

Tree::~Tree(void)
{
	if (root==0)
		return;
	else
	{
		cout<<"Delete tree:";
		root->Delete();
		cout<<endl;
	}
}

void Tree:: Input()
{
	cout << "Input tree Keyes, 0 - Exit"<<endl;
	while(true)
	{
		int k;
		cin>>k;
		if(k==0)
			break;
		Add(k);
	}
}
void Tree::Add(int k)
{
	if(root==0)
	{
		root= new Node (k);
	}
	else
	{
		root=root->Add(k);
	}
}
void Tree:: OutPut()
{
	if(root==0)
	{
		cout<<"tree is empty"<<endl;
	}
	else
	{
		root->OutPut();
		cout<<endl;
	}
}
 void Tree:: DelElem ()
{
	/*Node* p=FindNode(k);
	if (p==0)
	{
		cout<<"Ключ не найден";
		return;
	}
	if (p->right==0)
	{
		Node* parent=FindParent(p);
		if (parent->left==p)
			parent->left=p->left;
		else
			parent->right=p->left;
		delete p;
	}
	Node* pMin=p->FindMin();*/

	if(root==0)
	{
		cout<<"tree is empty"<<endl;
	}
	else
	{
		int k;
		root=root->Remove(k);
	}
}
#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int key;
	Node *right, *left;
	unsigned height;

	Node(int k)
	{
		key=k;
		left=right=0;
		height=1;
	}

	unsigned Height()
	{
		return this->height;
	}

	int BalansFactor()
	{
		unsigned h1=left?left->Height():0;
		unsigned h2=right?right->Height():0;
		return h2-h1;
	}

	Node* RotateRight()
	{
		Node  *q=left;
		left=q->right;
		q->right=this;
		this->FixHeight();
		q->FixHeight();
		return q;
	}

	Node* RotateLeft()
	{
		Node  *q=right;
		right=q->left;
		q->left=this;
		this->FixHeight();
		q->FixHeight();
		return q;
	}

	Node* Balance()
	{
   		FixHeight();
		if (BalansFactor()==2)
		{
			if (right->BalansFactor()<0)
				right=right->RotateRight();
			return RotateLeft();
		}
		if (BalansFactor()==-2)
		{
			if (left->BalansFactor()>0)
				left=left->RotateLeft();
			return RotateRight();
		}
		return this;
	}

	void FixHeight()
	{
		unsigned h1=left?left->Height():0;
		unsigned h2=right?right->Height():0;
		height=(h1>h2?h1:h2)+1;
	}

	Node* Add(int k)
	{
		if(k<key)
		{
			if (left)
				left=left->Add(k);
			else 
				left=new Node(k);
		}
		else
		{
			if (right)
				right=right->Add(k);
			else 
				right=new Node(k);
		}
		return Balance();
	}

	void OutPut()
	{
		if(left)
			left->OutPut();
		cout<<key<<" ";
		if(right)
			right->OutPut();
	}

	void Delete()
	{
		if (left)
			left ->Delete();
		if (right)
			right->Delete();
		cout<<key<<" ";
		delete this;
	}

	Node* Remove(int k)
	{
		if (k<key)
		{
			left=left->Remove(k);
		}
		else if (k>key)
		{
			right=right->Remove(k);
		}
		else
		{
			Node* q=left;
			Node* r=right;
			//delete p;

			if (r==NULL)
				return q;
			Node* min=r->FindMin();
			min->right=r->RemoveMin();
			min->left=q;
			return min->Balance();
		}
		return Balance();
	}

	Node* FindMin()
	{
		if (left)
		{
			return left->FindMin();
		}
		else
			return this;
	}

	Node* RemoveMin()
	{
		if (left == 0)
			return this->right;
		left = left->RemoveMin();
		return Balance();

	}
};

class Tree
{
	Node *root;
public:
	Tree(void);
	~Tree(void);
	void Input();
	void Add(int k);
	void OutPut();
	void DelElem ();
};


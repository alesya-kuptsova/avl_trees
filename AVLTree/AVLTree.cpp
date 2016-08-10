// AVLTree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Tree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Tree T;
	T.Input();
	T.OutPut();

	cout<<"k=";
	int k;
	cin>>k;
	T.DelElem();
	T.OutPut();

	return 0;
}


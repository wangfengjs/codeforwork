/************************************************************************
* 生成[0, maxval]范围内的m个随机整数的有序序列(不重复)，实现的数据结构有6种
* 参考: 编程珠玑

* Feng Wang, wangfengjs@gmail.com
* Computer Science and Technology, BIT
* Copyright (c) 2006-2013. All rights reserved.                                                                    
************************************************************************/
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

// 抽象类
class IntSetMap {
public:
	IntSetMap() {};
	virtual void insert(int t) = 0;
	virtual int size() = 0;
	virtual void report(int *v) = 0;
};

// 采用STL中的set实现
class IntSetSTL : public IntSetMap
{
private:
	set<int> S;
public:
	IntSetSTL() {};
	int size() { return S.size(); }
	void insert(int t) { S.insert(t); }
	void report(int *v)
	{
		int j=0;
		set<int>::iterator i;
		for (i = S.begin(); i!=S.end(); i++)
		{
			v[j++] = *i;
		}

	}
	~IntSetSTL();
};

// 采用有序数组实现
class IntSetArray : public IntSetMap
{
public:
	IntSetArray(int maxelements, int maxval)
	{
		x = new int[1+maxelements];
		n = 0;
		x[0] = maxval;
	};

	void insert(int t)
	{
		int i;
		for (i=0; x[i] < t; i++);
		if (x[i] == t)
		{
			return;
		}
		for (int j=n; j>=i; j--)
		{
			x[j+1] = x[j];
		}
		x[i] = t;
		n++;
	}

	int size()
	{
		return n;
	}

	void report(int *v)
	{
		for (int i=0; i<n; i++)
		{
			v[i] = x[i];
		}
	}
	~IntSetArray();

private:
	int n, *x;
};

// 采用链表实现
class IntSetList : public IntSetMap
{
private:
	int n;
	struct node
	{
		int val;
		node *next;
		node(int v, node *p) { val = v, next = p; }
	};
	node *head, *sentinel;

public:
	IntSetList(int maxelements, int maxval)
	{
		sentinel = head = new node(maxval, 0);
		n = 0;
	};

	void report(int *v)
	{
		int j=0;
		for (node *p = head; p != sentinel; p = p->next)
		{
			v[j++] = p->val;
		}
	}

	void insert(int t)
	{
		head = rinsert(head, t);
	}

	node* rinsert(node *p, int t)
	{
		if (p->val < t)
		{
			p->next = rinsert(p->next, t);
		}
		else if(p->val > t)
		{
			p = new node(t, p);
			n++;
		}
		return p;
	}

	int size()
	{
		return n;
	}

	~IntSetList();


};

// 采用二分搜索树实现
class IntSetBST : public IntSetMap
{
private:
	int n, *v, vn;
	struct node{
		int val;
		node *left, *right;
		node(int i) { val = i; left = right = 0; }
	};
	node *root;
public:
	IntSetBST(int maxelements, int maxval) { root = 0; n = 0; }
	void insert(int t)
	{
		root = rinsert(root, t);
	}
	node* rinsert(node *p, int t)
	{
		if (p == 0)
		{
			p = new node(t);
			n++;
		}
		else if(t < p->val)
		{
			p->left = rinsert(p->left, t);
		}
		else if (t > p->val)
		{
			p->right = rinsert(p->right, t);
		}
		return p;
	}
	void transpose(node *p)
	{
		if (p==0)
		{
			return;
		}
		transpose(p->left);
		v[vn++] = p->val;
		transpose(p->right);
	}
	void report(int *x)
	{
		v = x;
		vn = 0;
		transpose(root);
	}
	int size()
	{
		return n;
	}
};

void gensets(int m, int maxval)
{
	int *v = new int[m];
	//IntSetMap *S = new IntSetBST(m, maxval);
	IntSetBST *S = new IntSetBST(m, maxval);

	srand((unsigned)time(NULL));
	while (S->size() < m)
	{
		S->insert(rand()%maxval);
	}
	
	S->report(v);
	

	for (int i=0; i<m; i++)
	{
		cout << v[i] << endl;
	}
}

int main()
{
	gensets(10, 100);
}




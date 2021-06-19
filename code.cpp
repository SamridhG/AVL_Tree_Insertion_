#include<iostream>
#include<math.h>
using namespace std;
class node{
	public:
	int val;
	int height;
	node *right,*left;
	node(int val)
	{
		this->val=val;
		height=0;
		right=left=NULL;
	}
};
class Avl_tree{
	public:
	node *root;
	Avl_tree()
	{
		root=NULL;
	}
		node * left_right(node *rt)
	{
		rt->left=right_right(rt->left);
		rt=left_left(rt);
		return rt;
	}
	node *right_left(node *rt)
	{
		rt->right=left_left(rt->right);
		rt=right_right(rt);
	}
	int height(node *rt)
	{
		return rt==NULL?-1:rt->height;
	}
	int max(int a,int b)
	{
		return a>b?a:b;
	}
	node * left_left(node *rt)
	{
		node *temp=rt->left;
		rt->left=temp->right;
		temp->right=rt;
		rt=temp;
		rt->right->height=max(height(rt->right->right),height(rt->right->left))+1;
		rt->height=max(height(rt->left),height(rt->right))+1;
		return rt;
	}
	node *right_right(node *rt)
	{
		node *temp=rt->right;
		rt->right=temp->left;
		temp->left=rt;
		rt=temp;
		rt->left->height=max(height(rt->left->left),height(rt->left->right))+1;
		rt->height=max(height(rt->left),height(rt->right))+1;
		return rt;
	}

	node * insert(node *rt,int data)
	{
		if(rt==NULL)
		{
			rt=new node(data);
	//	cout<<"hello";
		}
		else
		{
			if(data<rt->val)
			{
				rt->left=insert(rt->left,data);
				if(abs(height(rt->left)-height(rt->right)==2))
				{
					if(data<rt->left->val)
					{
						rt=left_left(rt);
					}
					else
					{
						rt=left_right(rt);
					}
				}
			}
			else
			{
				rt->right=insert(rt->right,data);
					if(abs(height(rt->left)-height(rt->right)==2))
				{
					if(data>rt->right->val)
					{
						rt=right_right(rt);
					}
					else
					{
						rt=right_left(rt);
					}
				}
			}
		}
		rt->height=max(height(rt->right),height(rt->left))+1;
		return rt;
	}
	void inorder(node *rt)
	{
		if(rt==NULL)
		{
			return;
		}
		inorder(rt->left);
		cout<<"data -"<<rt->val<<" height- "<<rt->height<<endl;
		inorder(rt->right);	
	}
};
int main()
{
		Avl_tree A;
	A.root=A.insert(A.root,5);
	A.root=A.insert(A.root,9);
		A.root=A.insert(A.root,11);
			A.root=A.insert(A.root,0);
				A.root=A.insert(A.root,7);
					A.root=A.insert(A.root,8);
					A.inorder(A.root);
}

#include <iostream>
#include <vector>

using namespace std;
int N;
typedef struct node *pnode;

typedef struct node
{
	int data;
	pnode leftnode;
	pnode rightnode;	
}node;

vector<node> nv;

void printa(int a)
{
	char ch = a + 'A';
	cout << ch;
}

void preorder(int x)
{
	printa(nv[x].data);
	if(nv[x].leftnode != NULL)
	 preorder(nv[x].leftnode->data);
	if(nv[x].rightnode != NULL)
	 preorder(nv[x].rightnode->data);
}

void inorder(int x)
{	
	if(nv[x].leftnode != NULL)
	 inorder(nv[x].leftnode->data);
	printa(nv[x].data);
	if(nv[x].rightnode != NULL)
	 inorder(nv[x].rightnode->data);
}

void postorder(int x)
{	
	if(nv[x].leftnode != NULL)
	 postorder(nv[x].leftnode->data);	
	if(nv[x].rightnode != NULL)
	 postorder(nv[x].rightnode->data);
	printa(nv[x].data);
}

int main(void)
{
	char a,b,c;
	int ia,ib,ic;

	node t_node;
	t_node.leftnode = NULL;
	t_node.rightnode = NULL;

	cin >> N;

	for(int i=0;i<N;i++)
	{
		t_node.data = i;
		nv.push_back(t_node);
	}
	
	for(int i=0;i<N;i++)
	{
		cin >> a >> b >> c;
		ia = a - 'A';
		ib = b - 'A';
		ic = c - 'A';
		if(b == '.')
		 nv[ia].leftnode = NULL;		
		else
		 nv[ia].leftnode = &nv[ib];
		if(c == '.')
		 nv[ia].rightnode = NULL;
		else
		 nv[ia].rightnode = &nv[ic];				 
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
}

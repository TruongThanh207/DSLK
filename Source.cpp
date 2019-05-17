#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* pNext;
};

struct List
{
	Node* pHead;
	Node* pTail;
};

void Input(List&);
void Output(List);
Node* GetNode(int);
void Init(List&);
void AddTail(List&, Node*);
Node* GetHead(List &);
void QuickSort(List &);

int main() {

	List l;
	Init(l);
	Input(l);
	Output(l);
	QuickSort(l);
	cout << endl << "Sorted Array: ";
	Output(l);
	GetHead(l);
	cout << endl;
	Output(l);
	system("pause");
	return 0;
}
void Init(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* GetNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(List &L, Node *p)
{
	if (L.pHead == NULL)
	{
		L.pHead = p;
		L.pTail = L.pHead;
	}
	else
	{
		L.pTail->pNext = p;
		L.pTail = p;
	}
}
void Input(List &l)
{
	int n;
	cout << "nhap n=:";
	cin >> n;
	cout << endl;
	Init(l);
	for (int i = 0; i < n; i++)
	{
		cout << "nhap ptu thu " << i + 1 << " : ";
		int x;
		cin >> x;
		Node*p = GetNode(x);
		if (p != NULL)
			AddTail(l, p);
	}
}
void Output(List l)
{

	for (Node *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->info << "  ";
	}
	cout << endl;
}
Node* GetHead(List &l)
{
	Node *p = l.pHead;
	l.pHead=l.pHead->pNext;
	return p;
}
void QuickSort(List &l)
{
	Node *p, *X;//X lưu địa chỉ của phần tử cầm canh
	List l1, l2;
	if (l.pHead == l.pTail) return;//đã có thứ tự
	Init(l1);
	Init(l2);
	X = l.pHead;
	l.pHead = X->pNext;
	while (l.pHead != NULL)//tách L = L1 va L2
	{
		p = l.pHead;
		l.pHead = p->pNext;
		p->pNext = NULL;
		if (p->info <= X->info)
			AddTail(l1, p);
		else
			AddTail(l2, p);
	}
	
	QuickSort(l1);//Gọi đệ quy sắp xếp L1
	QuickSort(l2);//Gọi đệ quy sắp xếp L2
	if (l1.pHead != NULL)//nối l1, l2 va X vao l
	{
		l.pHead = l1.pHead;
		l1.pTail->pNext = X;//nối X vào
	}
	else
	{
		l.pHead = X;
	}
	X->pNext = l2.pHead;
	if (l2.pHead != NULL) //l2 có trên một phần tử
		l.pTail = l2.pTail;
	else //l2 không có phần tử nào
		l.pTail = X;
}

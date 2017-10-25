#include "list.h"


//尾删
void test1()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	PopBack(&Head);
	PrintList(Head);
}


//头插
void test2()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	PushFront(&Head, 4);
	PrintList(Head);
}

//头删
void test3()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	PopFront(&Head);
	PrintList(Head);
}

//查询指定结点
void test4()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node* tmp = Find(Head, 7);
	printf("%d\n", tmp->data);
}

//指定位置插入
void test5()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node *ret = Find(Head, 8);
	Insert(&Head, ret, 2);
	PrintList(Head);
}

//指定位置删除
void test6()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node *ret = Find(Head, 8);
	Erase(&Head, ret);
	PrintList(Head);
}

//删除无头结点非尾的某个结点
void test7()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node *ret = Find(Head, 8);
	EraseNoTail(ret);
	PrintList(Head);
}

//插入X到无头非尾的指定位置
void test8()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node *ret = Find(Head, 8);
	InsertNoHead(ret, 6);
	PrintList(Head);
}

//Josephus约瑟夫环
void test9()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node* tmp = Find(Head, 6);
	tmp->next = Head;
	Node* temp = Josephus(&Head, 3);
	printf("%d \n", temp->data);
}

//链表逆置
void test10()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);
	Revers(&Head);
	PrintList(Head);
}

//冒泡排序
void test11()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);
	BullleSort(Head);
	PrintList(Head);
}

//两个链表合并排序
void test12()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node* Head1 = NULL;
	PushBack(&Head1, 1);
	PushBack(&Head1, 6);
	PushBack(&Head1, 5);
	PushBack(&Head1, 2);
	PushBack(&Head1, 0);
	PushBack(&Head1, 2);
	PushBack(&Head1, 3);
	PushBack(&Head1, 4);
	PrintList(Head1);

	BullleSort(Head);
	PrintList(Head);
	BullleSort(Head1);
	PrintList(Head1);

	Node*ret = MergeSort(Head, Head1);
	PrintList(ret);
}

//查找链表的中间结点
void test13()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node* ret = FindMidNode(Head);
	printf("%d\n", ret->data);
}

//查找倒数第K个结点
void test14()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	Node* cur = FindDownNode(Head, 3);
	printf("%d\n", cur->data);
}
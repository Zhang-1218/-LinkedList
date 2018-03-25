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

//判断是否带环
void test15()
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
	Node* tmp1 = Find(Head, 4);
	tmp->next = tmp1;
	Node *ret = JudgeNodeRing(Head);
	if (ret!=NULL)
	{
		printf("%d\n", ret->data);
	}
}

//求环的长度
void test16()
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
	Node* tmp1 = Find(Head, 4);
	tmp->next = tmp1;
	Node *ret = JudgeNodeRing(Head);
	size_t x = BegRingLength(ret);
	printf("环的长度为：%d\n", x);
}

//求环的入口点
void test17()
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
	Node* tmp1 = Find(Head, 4);
	tmp->next = tmp1;
	Node *ret = JudgeNodeRing(Head);
	size_t x = BegRingLength(ret);
	printf("环的长度为：%d\n", x);
	Node* prev = EntryNode(Head, ret);
	printf("环的入口点为：%d\n", prev->data);
}

//判断两无环链表是否相交	
void test18()
{
	Node* Head = NULL;
	Node* Head1 = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	PushBack(&Head1, 1);
	PushBack(&Head1, 6);
	PushBack(&Head1, 5);
	PushBack(&Head1, 2);
	PushBack(&Head1, 0);
	PushBack(&Head1, 2);
	PushBack(&Head1, 3);
	PushBack(&Head1, 4);
	PrintList(Head1);

	Node* tmp = Find(Head1, 4);
	Node* tmp1 = Find(Head, 8);
	tmp->next = tmp1;
	PrintList(Head1);

	JudgeIntersectNotRing(Head, Head1);
}

//查找无环链表相交结点	
void test19()
{
	Node* Head = NULL;
	Node* Head1 = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	PushBack(&Head1, 1);
	PushBack(&Head1, 6);
	PushBack(&Head1, 5);
	PushBack(&Head1, 2);
	PushBack(&Head1, 0);
	PushBack(&Head1, 2);
	PushBack(&Head1, 3);
	PushBack(&Head1, 4);
	PrintList(Head1);

	Node* tmp = Find(Head1, 4);
	Node* tmp1 = Find(Head, 8);
	tmp->next = tmp1;
	PrintList(Head1);

	Node* ret = BegInterPoint(Head, Head1);
	printf("%d\n", ret->data);
}

//判断两个带环链表相交
void test20()
{
	Node* Head = NULL;
	Node* Head1 = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	PushBack(&Head, 4);
	PushBack(&Head, 7);
	PushBack(&Head, 8);
	PushBack(&Head, 9);
	PushBack(&Head, 6);
	PrintList(Head);

	PushBack(&Head1, 1);
	PushBack(&Head1, 6);
	PushBack(&Head1, 5);
	PushBack(&Head1, 2);
	PushBack(&Head1, 0);
	PushBack(&Head1, 2);
	PushBack(&Head1, 3);
	PushBack(&Head1, 4);
	PrintList(Head1);

	Node* tmp = Find(Head, 6);
	Node* tmp1 = Find(Head, 7);
	Node* tmp2 = Find(Head1, 4);
	Node* tmp3 = Find(Head, 8);
	tmp->next = tmp1;
	tmp2->next = tmp3;

	Node* new = JudgeIntersectRing(Head, Head1);
	if (new != NULL)
	{
		printf("交点为：%d\n", new->data);
	}
}

//复杂链表的复制
void test21()
{
	Node* Head = NULL;
	PushBack(&Head, 1);
	PushBack(&Head, 3);
	PushBack(&Head, 5);
	//PushBack(&Head, 4);
	//PushBack(&Head, 7);
	//PushBack(&Head, 8);
	//PushBack(&Head, 9);
	//PushBack(&Head, 6);
	PrintList(Head);

	Node* rand1 = Find(Head, 1);
	Node* rand2 = Find(Head, 3);
	Node* rand3 = Find(Head, 5);

	rand1->random = rand3;
	rand2->random = NULL;
	rand3->random = rand2;

	Node* ret = CopyNode(Head);
	PrintList(ret);
}
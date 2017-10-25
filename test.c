#include "list.h"


//βɾ
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


//ͷ��
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

//ͷɾ
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

//��ѯָ�����
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

//ָ��λ�ò���
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

//ָ��λ��ɾ��
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

//ɾ����ͷ����β��ĳ�����
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

//����X����ͷ��β��ָ��λ��
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

//JosephusԼɪ��
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

//��������
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

//ð������
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

//��������ϲ�����
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

//����������м���
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

//���ҵ�����K�����
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
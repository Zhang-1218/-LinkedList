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

//�ж��Ƿ����
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

//�󻷵ĳ���
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
	printf("���ĳ���Ϊ��%d\n", x);
}

//�󻷵���ڵ�
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
	printf("���ĳ���Ϊ��%d\n", x);
	Node* prev = EntryNode(Head, ret);
	printf("������ڵ�Ϊ��%d\n", prev->data);
}

//�ж����޻������Ƿ��ཻ	
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

//�����޻������ཻ���	
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

//�ж��������������ཻ
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
		printf("����Ϊ��%d\n", new->data);
	}
}

//��������ĸ���
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
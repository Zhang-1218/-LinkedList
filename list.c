#include "list.h"

//�����µĽ��
Node *BuyNode(DataType x)
{
	Node *list = (Node*)malloc(sz);
	list->data = x;
	list->next = NULL;
	return list;
}

//β��
void PushBack(Node **pHead, DataType x)
{
	if (*pHead == NULL)
	{
		*pHead = BuyNode(x);
	}
	else
	{
		Node *tail = *pHead;
		//�ҵ�����һ�����λ��
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuyNode(x);
	}
}

//��ӡ
void PrintList(Node *Head)
{
	if (Head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	Node *cur = Head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//βɾ
void PopBack(Node **pHead)
{
	//����Ϊ��
	if (*pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}
	//����һ�����
	if ((*pHead)->next == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		return;
	}
	//�ж�����
	Node *cur = *pHead;
	Node *ret = NULL;
	while (cur->next != NULL)
	{
		ret = cur;
		cur = cur->next;
	}
	ret->next = NULL;
	free(cur);
}

//ͷ��
void PushFront(Node** pHead, DataType x)
{
	Node* cur = *pHead;
	*pHead = BuyNode(x);
	(*pHead)->next = cur;
}

//ͷɾ
void PopFront(Node** pHead)
{
	//����Ϊ��
	if (*pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}

	Node* cur = (*pHead)->next;
	free(*pHead);
	*pHead = cur;
}

//��ѯָ�����
Node* Find(Node* Head, DataType x)
{
	//����Ϊ��
	if (Head == NULL)
	{
		printf("list is empty\n");
		return NULL;
	}

	Node* cur = Head;
	while (cur != NULL)
	{
		if (cur->data != x)
		{
			cur = cur->next;
		}
		else
		{
			return cur;
		}
	}
	printf("find failed\n");
	return NULL;
}

//ָ��λ�ò���
void Insert(Node** pHead, Node* pos, DataType x)
{
	assert(*pHead);
	if (pos == *pHead)
	{
		PushFront(pHead, x);
	}
	else
	{
		Node *temp = *pHead;
		while (temp->next != pos)
		{
			temp = temp->next;
		}
		Node *ret = BuyNode(x);
		temp->next = ret;
		ret->next = pos;
	}
}

//ָ���ڵ�Ĳ���
void Erase(Node** pHead, Node* pos)
{
	assert(pos);
	if (pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}

	if (pos == *pHead)
	{
		PopFront(pHead);
		return;
	}

	Node *cur = *pHead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	Node *temp = cur->next;
	cur->next = temp->next;
	free(temp);
	temp = NULL;
}

//��β����ɾ��
void EraseNoTail(Node* pos)
{
	assert(pos && pos->next);
	Node *cur;
	//��pos���ֵ����pos
	cur = pos->next;
	pos->data = cur->data;
	//��posָ�����ڶ������
	pos->next = cur->next;
	free(cur);
}

//��ͷ���Ĳ���
void InsertNoHead(Node* pos, DataType x)
{
	assert(pos);
	Node* cur = pos->next;
	Node* ret = BuyNode(x);
	//������ڵ�ֵ���н���
	x = pos->data;
	pos->data = ret->data;
	ret->data = x;
	//�����ָ��任
	pos->next = ret;
	ret->next = cur;
}

//Լɪ��
Node* Josephus(Node** pHead, size_t k)
{
	assert(pHead);
	Node* cur = *pHead;
	while (cur->next != cur)
	{
		size_t count = k;
		while (--count)
		{
			cur = cur->next;
		}

		Node* prev = cur->next;
		cur->data = prev->data;
		cur->next = prev->next;
		free(prev);
	}
	return cur;
}

//��ת����
void Revers(Node **pHead)
{
	Node* n0, *n1, *n2;
	if (*pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}
	n0 = NULL, n1 = *pHead, n2 = (*pHead)->next;

	//����
	while (n1)
	{
		//ָ������
		n1->next = n0;

		//����
		n0 = n1;
		n1 = n2;
		if (n2)
		{
			n2 = n2->next;
		}
	}

	*pHead = n0;
}

//ð������
void BullleSort(Node *pHead)
{
	Node *tail = NULL;
	if (pHead == NULL || pHead->next == NULL)
	{
		printf("list is empty\n");
		return;
	}

	while (tail != pHead)
	{
		Node *cur = pHead;
		Node *prev = cur->next;
		int flag = 0;

		while (prev != tail)
		{
			if ((cur->data) > (prev->data))
			{
				DataType tmp = cur->data;
				cur->data = prev->data;
				prev->data = tmp;
				flag = 1;
			}
			cur = cur->next;
			prev = prev->next;

			//�Ż����ж��Ƿ��н���
		}
		if (flag == 0)
		{
			return;
		}
		tail = cur;
	}
}

//�������������ϲ�����
Node* MergeSort(Node *list1, Node *list2)
{
	Node *list = NULL;

	if (list1 == NULL)
	{
		return list2;
	}
	if (list2 == NULL)
	{
		return list1;
	}

	if (list1->data > list2->data)
	{
		list = list2;
		list2 = list2->next;
	}
	else
	{
		list = list1;
		list1 = list1->next;
	}

	//С�ĸ���cur
	Node* cur = list;
	while (list1 && list2)
	{
		if (list1->data > list2->data)
		{
			cur->next = list2;
			list2 = list2->next;
		}
		else
		{
			cur->next = list1;
			list1 = list1->next;
		}
		cur = cur->next;
	}

	//�����������ں��
	if (list1 == NULL)
	{
		cur->next = list2;
	}
	if (list2 == NULL)
	{
		cur->next = list1;
	}

	return list;
}

//�����м���
Node* FindMidNode(Node *pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}

	//����ָ��
	Node *fast = pHead, *slow = pHead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//���ҵ�����k�����
Node* FindDownNode(Node *pHead, size_t k)
{
	assert(k);
	if (pHead == NULL)
	{
		return NULL;
	}

	Node *fast = pHead, *slow = pHead;
	//��ָ������K��
	for (; k > 0; k--)
	{
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}
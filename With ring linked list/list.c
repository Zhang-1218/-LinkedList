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
	if (pHead == NULL || pHead->next==NULL)
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
Node* FindDownNode(Node *pHead,size_t k)
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

//�л�
Node* JudgeNodeRing(Node* pHead)
{
	assert(pHead);
	Node* fast=pHead, *slow=pHead;
	//����ָ��
	while (fast)
	{
		fast = fast->next->next;
		slow = slow->next;
		//�ж��Ƿ�����
		if (slow == fast)
		{
			printf("�л�\n");
			return slow;
		}
	}
	printf("�޻�\n");
	return NULL;
}

//�󻷵ĳ���
int BegRingLength(Node *list)
{
	assert(list);
	size_t count = 1;
	Node* cur = list->next;
	while (cur != list)
	{
		cur = cur->next;
		count++;
	}
	return count;
}

//�󻷵���ڵ�
Node* EntryNode(Node* pHead, Node* list)
{
	assert(pHead && list);
	//ͷ����������ͬʱ��
	while (pHead != list)
	{
		list = list->next;
		pHead = pHead->next;
	}
	
	return pHead;
}

//�ж����޻������ཻ
void JudgeIntersectNotRing(Node* list1, Node* list2)
{
	assert(list1 && list2);
	Node* cur1 = list1, *cur2 = list2;
	
	while (cur1->next)
	{
		cur1 = cur1->next;
	}
	while (cur2->next)
	{
		cur2 = cur2->next;
	}
	
	if (cur1 == cur2)
	{
		printf("�����޻������ཻ\n");
	}
	else
	{
		printf("�����޻������ཻ\n");
	}
}

//���޻������ཻ�Ľ���
Node* BegInterPoint(Node* list1, Node* list2)
{
	assert(list1 && list2);
	Node* cur1 = list1, *cur2 = list2;
	Node* Long = NULL, *Short = NULL;
	size_t count = 0, num = 0;

	while (cur1)
	{
		cur1 = cur1->next;
		count++;
	}
	while (cur2)
	{
		cur2 = cur2->next;
		num++;
	}
	
	int len = abs(count - num);
	if (count > num)
	{
		Long = list1;
		Short = list2;
	}
	else
	{
		Long = list2;
		Short = list1;
	}
	
	//�����������߲�ֵ����
	while (len--)
	{
		Long = Long->next;
	}
	//ͬʱ�ߣ�������Ϊ����
	while (Short != Long)
	{
		Short = Short->next;
		Long = Long->next;
	}
	return Long;
}

//�ж��������������ཻ
Node* JudgeIntersectRing(Node* list1, Node* list2)
{
	assert(list1 && list2);
	Node* Inter1 = JudgeNodeRing(list1);//list1�Ļ���������
	Node* Enter1 = EntryNode(list1, Inter1);//list1�Ļ���ڵ�
	Node* Inter2 = JudgeNodeRing(list2);//list2�Ļ���������
	Node* Enter2 = EntryNode(list2, Inter2);//list2�Ļ���ڵ�
	size_t len1 = 0, len2 = 0;
	
	//�����ڻ����ཻ
	if (Enter1 == Enter2)
	{
		printf("�������������ཻ\n");
	}

	Node* cur1 = list1, *cur2 = list2;
	Node* tmp1 = list1, *tmp2 = list2;

	while (cur1 != Enter1)
	{
		cur1 = cur1->next;
		len1++;
	}
	while (cur2 != Enter2)
	{
		cur2 = cur2->next;
		len2++;
	}

	int len = abs(len1 - len2);
	//�����������߲�ֵ����
	if (len1 > len2)
	{
		while (len--)
		{
			tmp1 = tmp1->next;
		}
	}
	else
	{
		while (len--)
		{
			tmp2 = tmp2->next;
		}
	}

	//ͬʱ�ߣ�������Ϊ����
	while (tmp1->next != Enter1->next && tmp2->next != Enter2->next)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if (tmp1 == tmp2)
		{
			return tmp1;
		}
	}

	//�����ڻ����ཻ
	Node* prev1 = Enter1->next, *prev2 = Enter2;
	while (prev1 != Enter1)
	{
		if (prev1 == prev2)
		{
			printf("�������������ཻ\n");
			return prev1;
		}
		prev1 = prev1->next;
	}
	printf("�������������ཻ\n");
	return NULL;
}

//���Ƹ�������
Node* CopyNode(Node* list)
{
	if (list == NULL)
	{
		return NULL;
	}

	//����nextָ��
	Node* new = BuyNode(list->data);
	Node* tail = new;
	Node* prev = list;

	while (prev->next)
	{
		prev = prev->next;
		tail->next = BuyNode(prev->data);
		tail = tail->next;
	}
	
	//����randomָ��
	Node* tmp = list, *newtmp = new;
	Node* cur=NULL,*newcur=NULL, *ret=NULL;
	size_t len = 0;

	while (tmp)
	{
		cur = list;
		newcur = new;
		ret = tmp->random;

		//randomΪ��
		if (ret == NULL)
		{
			newtmp->random = NULL;//������randomָ���
			newtmp = newtmp->next;
			tmp = tmp->next;
		}
		//random��Ϊ��
		else
		{
			while (cur != ret)//list�б������ұȽ���randomָ����Ĺ�ϵ
			{
				cur = cur->next;
				len++;//ȷ��randomָ�������
			}

			while (len--)
			{
				newcur = newcur->next;//new���ҵ���Ӧλ�õĽ�㣬����random��ָ����
			}

			newtmp->random = newcur;
			tmp = tmp->next;
			newtmp = newtmp->next;
			len = 0;
		}
	}
	return new;
}
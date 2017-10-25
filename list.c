#include "list.h"

//创建新的结点
Node *BuyNode(DataType x)
{
	Node *list = (Node*)malloc(sz);
	list->data = x;
	list->next = NULL;
	return list;
}

//尾插
void PushBack(Node **pHead, DataType x)
{
	if (*pHead == NULL)
	{
		*pHead = BuyNode(x);
	}
	else
	{
		Node *tail = *pHead;
		//找到最后的一个结点位置
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuyNode(x);
	}
}

//打印
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

//尾删
void PopBack(Node **pHead)
{
	//链表为空
	if (*pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}
	//仅有一个结点
	if ((*pHead)->next == NULL)
	{
		free(*pHead);
		*pHead = NULL;
		return;
	}
	//有多个结点
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

//头插
void PushFront(Node** pHead, DataType x)
{
	Node* cur = *pHead;
	*pHead = BuyNode(x);
	(*pHead)->next = cur;
}

//头删
void PopFront(Node** pHead)
{
	//链表为空
	if (*pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}

	Node* cur = (*pHead)->next;
	free(*pHead);
	*pHead = cur;
}

//查询指定结点
Node* Find(Node* Head, DataType x)
{
	//链表为空
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

//指定位置插入
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

//指定节点的擦除
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

//无尾结点的删除
void EraseNoTail(Node* pos)
{
	assert(pos && pos->next);
	Node *cur;
	//将pos后的值赋给pos
	cur = pos->next;
	pos->data = cur->data;
	//令pos指向后面第二个结点
	pos->next = cur->next;
	free(cur);
}

//无头结点的插入
void InsertNoHead(Node* pos, DataType x)
{
	assert(pos);
	Node* cur = pos->next;
	Node* ret = BuyNode(x);
	//将结点内的值进行交换
	x = pos->data;
	pos->data = ret->data;
	ret->data = x;
	//将结点指向变换
	pos->next = ret;
	ret->next = cur;
}

//约瑟夫环
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

//反转逆置
void Revers(Node **pHead)
{
	Node* n0, *n1, *n2;
	if (*pHead == NULL)
	{
		printf("list is empty\n");
		return;
	}
	n0 = NULL, n1 = *pHead, n2 = (*pHead)->next;

	//逆置
	while (n1)
	{
		//指向逆置
		n1->next = n0;

		//后移
		n0 = n1;
		n1 = n2;
		if (n2)
		{
			n2 = n2->next;
		}
	}

	*pHead = n0;
}

//冒泡排序
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

			//优化，判断是否有交换
		}
		if (flag == 0)
		{
			return;
		}
		tail = cur;
	}
}

//两个有序链表，合并排序
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

	//小的赋给cur
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

	//将长的链接在后边
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

//查找中间结点
Node* FindMidNode(Node *pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}

	//快慢指针
	Node *fast = pHead, *slow = pHead;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

//查找倒数第k个结点
Node* FindDownNode(Node *pHead, size_t k)
{
	assert(k);
	if (pHead == NULL)
	{
		return NULL;
	}

	Node *fast = pHead, *slow = pHead;
	//快指针先走K步
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
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
Node* FindDownNode(Node *pHead,size_t k)
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

//判环
Node* JudgeNodeRing(Node* pHead)
{
	assert(pHead);
	Node* fast=pHead, *slow=pHead;
	//快慢指针
	while (fast)
	{
		fast = fast->next->next;
		slow = slow->next;
		//判断是否相遇
		if (slow == fast)
		{
			printf("有环\n");
			return slow;
		}
	}
	printf("无环\n");
	return NULL;
}

//求环的长度
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

//求环的入口点
Node* EntryNode(Node* pHead, Node* list)
{
	assert(pHead && list);
	//头部，相遇点同时走
	while (pHead != list)
	{
		list = list->next;
		pHead = pHead->next;
	}
	
	return pHead;
}

//判断两无环链表相交
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
		printf("两个无环链表相交\n");
	}
	else
	{
		printf("两个无环链表不相交\n");
	}
}

//求无环链表相交的交点
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
	
	//长的链表先走差值步数
	while (len--)
	{
		Long = Long->next;
	}
	//同时走，相遇即为交点
	while (Short != Long)
	{
		Short = Short->next;
		Long = Long->next;
	}
	return Long;
}

//判断两个带环链表相交
Node* JudgeIntersectRing(Node* list1, Node* list2)
{
	assert(list1 && list2);
	Node* Inter1 = JudgeNodeRing(list1);//list1的环内相遇点
	Node* Enter1 = EntryNode(list1, Inter1);//list1的环入口点
	Node* Inter2 = JudgeNodeRing(list2);//list2的环内相遇点
	Node* Enter2 = EntryNode(list2, Inter2);//list2的环入口点
	size_t len1 = 0, len2 = 0;
	
	//链表在环外相交
	if (Enter1 == Enter2)
	{
		printf("两个带环链表相交\n");
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
	//长的链表先走差值步数
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

	//同时走，相遇即为交点
	while (tmp1->next != Enter1->next && tmp2->next != Enter2->next)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		if (tmp1 == tmp2)
		{
			return tmp1;
		}
	}

	//链表在环内相交
	Node* prev1 = Enter1->next, *prev2 = Enter2;
	while (prev1 != Enter1)
	{
		if (prev1 == prev2)
		{
			printf("两个带环链表相交\n");
			return prev1;
		}
		prev1 = prev1->next;
	}
	printf("两个带环链表不相交\n");
	return NULL;
}

//复制复杂链表
Node* CopyNode(Node* list)
{
	if (list == NULL)
	{
		return NULL;
	}

	//复制next指向
	Node* new = BuyNode(list->data);
	Node* tail = new;
	Node* prev = list;

	while (prev->next)
	{
		prev = prev->next;
		tail->next = BuyNode(prev->data);
		tail = tail->next;
	}
	
	//复制random指向
	Node* tmp = list, *newtmp = new;
	Node* cur=NULL,*newcur=NULL, *ret=NULL;
	size_t len = 0;

	while (tmp)
	{
		cur = list;
		newcur = new;
		ret = tmp->random;

		//random为空
		if (ret == NULL)
		{
			newtmp->random = NULL;//新链表random指向空
			newtmp = newtmp->next;
			tmp = tmp->next;
		}
		//random不为空
		else
		{
			while (cur != ret)//list中遍历查找比较与random指向结点的关系
			{
				cur = cur->next;
				len++;//确认random指向结点距离
			}

			while (len--)
			{
				newcur = newcur->next;//new中找到对应位置的结点，即是random的指向结点
			}

			newtmp->random = newcur;
			tmp = tmp->next;
			newtmp = newtmp->next;
			len = 0;
		}
	}
	return new;
}
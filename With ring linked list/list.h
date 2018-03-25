#ifndef _LIST_H__
#define _LIST_H__

#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;
	struct Node *random;

}Node;

#define sz (sizeof(Node))

void PrintList(Node* Head);//链表打印
void PushBack(Node** pHead, DataType x);//尾插
void PopBack(Node** pHead);//尾删
void PushFront(Node** pHead, DataType x);//头插
void PopFront(Node** pHead);//头删
Node* Find(Node* Head, DataType x);//查找指定结点
void Insert(Node** pHead, Node* pos, DataType x);//指定位置插入结点
void Erase(Node** pHead, Node* pos);//制定结点的擦除

void EraseNoTail(Node* pos);//无尾链表指定结点的删除
void InsertNoHead(Node* pos, DataType x);//无头链表指定结点的插入
Node* Josephus(Node** pHead, size_t k);//约瑟夫环
void Revers(Node** pHead);//链表逆置
void BullleSort(Node* pHead);//冒泡排序
Node* MergeSort(Node* list1, Node* list2);//两个有序链表合并排序
Node* FindMidNode(Node* pHead);//查询中间结点
Node* FindDownNode(Node* pHead, size_t k);//查询倒数第k个结点

Node* JudgeNodeRing(Node* pHead);//链表判环
int BegRingLength(Node* list);//带环链表环的长度
Node* EntryNode(Node* list);//环的入口点
void JudgeIntersectNotRing(Node* list1, Node* list2);//判断两无环链表是否相交
Node* BegInterPoint(Node* list1, Node* list2);//无环链表相交的结点
Node* JudgeIntersectRing(Node* list1, Node* list2);//判断两带环链表的相交
Node* CopyNode(Node* list);//复杂链表的赋值

#endif //_LIST_H__ 
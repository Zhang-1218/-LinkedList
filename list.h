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

void PrintList(Node* Head);//�����ӡ
void PushBack(Node** pHead, DataType x);//β��
void PopBack(Node** pHead);//βɾ
void PushFront(Node** pHead, DataType x);//ͷ��
void PopFront(Node** pHead);//ͷɾ
Node* Find(Node* Head, DataType x);//����ָ�����
void Insert(Node** pHead, Node* pos, DataType x);//ָ��λ�ò�����
void Erase(Node** pHead, Node* pos);//�ƶ����Ĳ���

void EraseNoTail(Node* pos);//��β����ָ������ɾ��
void InsertNoHead(Node* pos, DataType x);//��ͷ����ָ�����Ĳ���
Node* Josephus(Node** pHead, size_t k);//Լɪ��
void Revers(Node** pHead);//��������
void BullleSort(Node* pHead);//ð������
Node* MergeSort(Node* list1, Node* list2);//������������ϲ�����
Node* FindMidNode(Node* pHead);//��ѯ�м���
Node* FindDownNode(Node* pHead, size_t k);//��ѯ������k�����

#endif //_LIST_H__ 
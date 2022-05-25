#include"DoubleLinkedList.h"


// ��ͷ+˫��+ѭ��������ɾ���ʵ��
//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
	{
		exit(-1);
	}
	newNode->_data = 0;
	newNode->_next = newNode;
	newNode->_prev = newNode;
	return newNode;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	ListNode* next = cur->_next;
	while (cur != pHead)
	{
		free(cur);
		cur = next;
		next = next->_next;
	}
	free(pHead);
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead && pHead->_next != pHead);
	ListErase(pHead->_prev);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead && pHead->_next != pHead);
	ListErase(pHead->_next);
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));	
	if (!newNode)
	{
		exit(-1);
	}
	newNode->_data = x;
	newNode->_next = pos;
	newNode->_prev = pos->_prev;
	pos->_prev->_next = newNode;
	pos->_prev = newNode;
	
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos && pos->_next != pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	
}
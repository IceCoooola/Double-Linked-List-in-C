#include"DoubleLinkedList.h"


// 带头+双向+循环链表增删查改实现
//typedef int LTDataType;
//typedef struct ListNode
//{
//	LTDataType _data;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//}ListNode;

// 创建返回链表的头结点.
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
// 双向链表销毁
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
// 双向链表打印
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
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead && pHead->_next != pHead);
	ListErase(pHead->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead && pHead->_next != pHead);
	ListErase(pHead->_next);
}
// 双向链表查找
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

// 双向链表在pos的前面进行插入
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
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos && pos->_next != pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	
}
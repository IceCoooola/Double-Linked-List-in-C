#include"DoubleLinkedList.h"

int main()
{
	ListNode* newList = ListCreate();
	printf("Test ListPushBack 1,2,3,4,5 :\n");
	ListPushBack(newList, 1);
	ListPushBack(newList, 2);
	ListPushBack(newList, 3);
	ListPushBack(newList, 4);
	ListPushBack(newList, 5);
	ListPrint(newList);
	printf("\nTest ListPushFront 1,2,3,4,5 :\n");
	ListPushFront(newList, 1);
	ListPushFront(newList, 2);
	ListPushFront(newList, 3);
	ListPushFront(newList, 4);
	ListPushFront(newList, 5);
	ListPrint(newList);
	printf("\nTest ListPopFront:\n");
	ListPopFront(newList);
	ListPrint(newList);
	printf("\nTest ListPopBack:\n");
	ListPopBack(newList);
	ListPrint(newList);
	printf("\nTest ListFind [3]:\n");
	ListNode* pos = ListFind(newList, 3);
	printf("\nthe position address is %p\n", pos);
	printf("\nList destroying.\n");
	ListDestory(newList);

	return 0;
}
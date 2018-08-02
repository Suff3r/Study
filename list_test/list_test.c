/*************************************************************************
    > File Name: list_test.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Mon 30 Jul 2018 11:59:12 PM PDT
 ************************************************************************/
/* Includes */
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
/* Constants and defines */
/* Global variables  */
typedef struct node{
	int member;
	struct node *pNext;
}Node,*pNode;

/* Local variables  */

/* Local function prototypes  */
pNode CreateList();
void TraverseList(pNode);
int InsertNode(pNode ,int ,int );
int DelNode(pNode ,int );

/* Local functions */
pNode CreateList(){
	int i;
	int num;
	pNode pHead = (pNode)malloc(sizeof(Node));
	if (pHead == NULL){
		printf("Memory allocation failure");
		exit(-1);
	}
	pNode pTail = pHead;
	pTail->pNext = NULL;
	printf("Input list number\n");
	scanf("%d",&num);

	for (i = 0; i < num; i++){
		printf("Input list %d:data",i+1);
		pNode pNew = (pNode)malloc(sizeof(Node));
		if (pNew == NULL){
			printf("Memory allocation failure");
			exit(-1);
		}
		scanf("%d",&pNew->member);
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void TraverseList(pNode pHead){
	pNode p = pHead->pNext;
	int count = 0;
	while (NULL != p){
		printf("%d",p->member);
		count++;
		p = p->pNext;
	}
	printf("\ncount = %d\n",count);
}
int InsertNode(pNode pHead,int pos,int data){
	int i;
	pNode pTmp;
	pNode node = pHead;

	if ((pos < 1) || (NULL == node))
	{
		return -1;
	}

	for(i = 0;i < pos-1 ;i++){	
		node = node->pNext;
	}

	pTmp = node->pNext;
	pNode pNew = (pNode)malloc(sizeof(Node));
	node->pNext = pNew;
	pNew->member = data;
	pNew->pNext = pTmp;
	return 0;
}
int DelNode(pNode pHead,int pos){
	int i = 0;
	int data = 0;
	pNode node = pHead;
	pNode pTmp;

	if ((pos < 1) || (NULL == node)){
		return 0;
	}
	
	for(i = 0;i < pos-1 ;i++){	
		node = node->pNext;
	}
	pTmp = node->pNext;
	node->pNext = pTmp->pNext;
	data = pTmp->member;
	free(pTmp);
	return data;
}
int main(){
	int del_data;
	pNode pHead = CreateList();
	
	TraverseList(pHead);
	if (0 == InsertNode(pHead,3,6)){

	}else{
		printf("Inset data fail!!");
	}
	TraverseList(pHead);
// data default != 0
	del_data = DelNode(pHead,3);
	if (0 == del_data){

	}else{
		printf("Delete data:%d\n",del_data);
	}
	TraverseList(pHead);
}


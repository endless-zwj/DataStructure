#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>

#define QDataType int 

//队列组成元素为节点，故定义一个QueueNode的节点类型
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

//因为一个队列有头有尾，我们需要用到首尾指针，
//因此我们可以封装一个含头尾指针的结构体来作为我们的队列
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
	int _size;
}Queue;

//初始化队列
void InitQueue(Queue* pQ);

//排号
void PushQueue(Queue* pQ , int Max_Number);

//叫号
void PopQueue(Queue* pQ);

void SystemSet(int* num);
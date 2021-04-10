#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<windows.h>

#define QDataType int 

//�������Ԫ��Ϊ�ڵ㣬�ʶ���һ��QueueNode�Ľڵ�����
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
}QueueNode;

//��Ϊһ��������ͷ��β��������Ҫ�õ���βָ�룬
//������ǿ��Է�װһ����ͷβָ��Ľṹ������Ϊ���ǵĶ���
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
	int _size;
}Queue;

//��ʼ������
void InitQueue(Queue* pQ);

//�ź�
void PushQueue(Queue* pQ , int Max_Number);

//�к�
void PopQueue(Queue* pQ);

void SystemSet(int* num);
#define _CRT_SECURE_NO_WARNING	
#include"Queue.h"

//��ʼ������
void InitQueue(Queue* pQ)
{
	pQ->_head = NULL ;
	pQ->_tail = NULL;
	pQ->_size = 0 ;
}

//ϵͳ����
void SystemSet(int* num)
{
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t��ȷ��ÿ��������ҵ����:>");
	scanf("%d", num);
	printf("\t\t\t\t\tϵͳ���ҵ�������óɹ�!\n");
}



//�ź�
void PushQueue(Queue* pQ , int Max_Number)
{
	assert(pQ);

	static int order_number = 1 ;

	if (order_number > Max_Number)
	{
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t�𾴵Ŀͻ������ã�\n");
		printf("\t\t\t\t\t\t����ҵ��������Ѵ��������������!\n");
		Sleep(2000);
		return ;
	}

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)* 1) ;

	//��ʼ���ڵ�
	newNode->_data = order_number;
	newNode->_next = NULL;//��ʼ���ڵ㣬ָ������Ϊ��

	if (pQ->_head == NULL)
	{
		pQ->_head = newNode;
		pQ->_tail = newNode;
	}
	else
	{
		pQ->_tail->_next = newNode;
		//newNode = pQ->_tail;  �������ǽ� tail��ֵ���� newNode 
		//��û���𵽸ı�β������(tail����˭��ֵ��ָ��˭)
		pQ->_tail = newNode;
	}
	

	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t�źųɹ�!\n");
	printf("\t\t\t\t\t\t���ã������ڵĺ���Ϊ:[%d]\n" , order_number  );
	printf("\t\t\t\t\t\tĿǰ����ǰ�滹��[%d]�����ź�\n",pQ->_size);
	Sleep(2000);

	pQ->_size++;
	order_number++ ; 
}

//�к�
void PopQueue(Queue* pQ)
{
	assert(pQ);
	if (pQ->_head == NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\tĿǰ�����Ŷ�!\n");
		Sleep(2000);
		return ;
	}

	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t��[%d]�ŵ�ǰ̨������ҵ��!\n",pQ->_head->_data);
	Sleep(2000);

	QueueNode* head_next = pQ->_head->_next;//���ҵ�ͷ�ڵ����һ���ڵ㣨�Ա��ͷ�ͷ�������ҵ�����
	free(pQ->_head);//�ͷ�ͷ�ڵ�
	pQ->_head = head_next;//ת��ͷ�ڵ�
	if (head_next == NULL)
	{
		pQ->_tail = NULL;//����������䣬˵��ֻ��һ���ڵ㣬ɾ����β��Ϊ��
	}

	pQ->_size--;
}


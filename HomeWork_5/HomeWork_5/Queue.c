#define _CRT_SECURE_NO_WARNING	
#include"Queue.h"

//初始化队列
void InitQueue(Queue* pQ)
{
	pQ->_head = NULL ;
	pQ->_tail = NULL;
	pQ->_size = 0 ;
}

//系统设置
void SystemSet(int* num)
{
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t请确认每日最大办理业务量:>");
	scanf("%d", num);
	printf("\t\t\t\t\t系统最大业务量设置成功!\n");
}



//排号
void PushQueue(Queue* pQ , int Max_Number)
{
	assert(pQ);

	static int order_number = 1 ;

	if (order_number > Max_Number)
	{
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t尊敬的客户，您好！\n");
		printf("\t\t\t\t\t\t今日业务办理量已达最大，请明日再来!\n");
		Sleep(2000);
		return ;
	}

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode)* 1) ;

	//初始化节点
	newNode->_data = order_number;
	newNode->_next = NULL;//初始化节点，指针域置为空

	if (pQ->_head == NULL)
	{
		pQ->_head = newNode;
		pQ->_tail = newNode;
	}
	else
	{
		pQ->_tail->_next = newNode;
		//newNode = pQ->_tail;  这句代码是将 tail的值赋给 newNode 
		//并没有起到改变尾的作用(tail里存的谁的值便指向谁)
		pQ->_tail = newNode;
	}
	

	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t排号成功!\n");
	printf("\t\t\t\t\t\t您好，您现在的号码为:[%d]\n" , order_number  );
	printf("\t\t\t\t\t\t目前，您前面还有[%d]人在排号\n",pQ->_size);
	Sleep(2000);

	pQ->_size++;
	order_number++ ; 
}

//叫号
void PopQueue(Queue* pQ)
{
	assert(pQ);
	if (pQ->_head == NULL)
	{
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t目前无人排队!\n");
		Sleep(2000);
		return ;
	}

	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t请[%d]号到前台来办理业务!\n",pQ->_head->_data);
	Sleep(2000);

	QueueNode* head_next = pQ->_head->_next;//先找到头节点的下一个节点（以便释放头后仍能找到链表）
	free(pQ->_head);//释放头节点
	pQ->_head = head_next;//转换头节点
	if (head_next == NULL)
	{
		pQ->_tail = NULL;//进入这条语句，说明只有一个节点，删除后将尾置为空
	}

	pQ->_size--;
}


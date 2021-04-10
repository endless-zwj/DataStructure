#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

int main()
{
	Queue queue;
	int Max_Number;
	InitQueue(&queue);
	SystemSet(&Max_Number);
	int x;
	do
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t1.初始化队列\n");
		printf("\t\t\t\t\t\t2.排号\n");
		printf("\t\t\t\t\t\t3.叫号\n");
		printf("\t\t\t\t\t\t4.系统设置\n");
		printf("\t\t\t\t\t\t0.退出\n");
		printf("\t\t\t\t\t\t请选择:> ");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			system("cls");	
			InitQueue(&queue);
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t\t初始化完成!\n");
			Sleep(2000);
			break;
		case 2:
			system("cls");
			PushQueue(&queue , Max_Number);
			break;
		case 3:
			system("cls");
			PopQueue(&queue);
			break;
		case 4:
			system("cls");
			SystemSet(&Max_Number);
			Sleep(1000);
			break;
		case 0:
			printf("\t\t\t\t\t正在退出!\n");
			Sleep(1000);
			break;
		default:
			printf("\t\t\t\t\t\t输入错误，请重新输入\n");
			break;
		}
	} while (x);
	return 0;
}

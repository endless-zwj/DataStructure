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
		printf("\t\t\t\t\t\t1.��ʼ������\n");
		printf("\t\t\t\t\t\t2.�ź�\n");
		printf("\t\t\t\t\t\t3.�к�\n");
		printf("\t\t\t\t\t\t4.ϵͳ����\n");
		printf("\t\t\t\t\t\t0.�˳�\n");
		printf("\t\t\t\t\t\t��ѡ��:> ");
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			system("cls");	
			InitQueue(&queue);
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t\t��ʼ�����!\n");
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
			printf("\t\t\t\t\t�����˳�!\n");
			Sleep(1000);
			break;
		default:
			printf("\t\t\t\t\t\t�����������������\n");
			break;
		}
	} while (x);
	return 0;
}

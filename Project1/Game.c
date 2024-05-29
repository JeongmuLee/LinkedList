#include "LinkedList.h"
#include <windows.h>

void run()
{
	int stage = 1;
	int death = 0;
	linkedlist* gameSet = NULL;
	linkedlist* userSet = NULL;
	linkedlist* printSet = NULL;
	printf("������ �����մϴ� \n");
	printf("��Ģ: ���õ� ���ڰ� ������� ���� ���ڸ� �Է��ϸ� �˴ϴ�. ���ڴ� �� ���� �ϳ��� �Է��ϰ� ���ͷ� ���е˴ϴ�.\n");
	while (true)
	{
		gameSet = makeGameSet(stage);
		printSet = gameSet;
		while (printSet != NULL)
		{
			printf("%d\t", printSet->data);
			printSet = printSet->link;
		}
		Sleep(3000);
		system("cls");
		userSet = makeUserSet(stage);
		if (compareEachSet(gameSet, userSet) == true)
		{
			printf("%d�ܰ� ����. ���� �ܰ��(���� %dȸ)\n", stage, death);
			stage++;
		}
		else
		{
			death++;
			if (death >= 5)
			{
				printf("���� ����");
				break;
			}
			else
			{
				printf("%d�ܰ� ����. �ٽ� �õ��մϴ�.(���� %dȸ)\n", stage, death);
			}
		}
	}
}

int main()
{
	run();
	return 0;
}
#include "LinkedList.h"
#include <windows.h>

void run()
{
	int stage = 1;
	int death = 0;
	linkedlist* gameSet = NULL;
	linkedlist* userSet = NULL;
	linkedlist* printSet = NULL;
	printf("게임을 시작합니다 \n");
	printf("규칙: 제시된 숫자가 사라지면 같은 숫자를 입력하면 됩니다. 숫자는 한 번에 하나씩 입력하고 엔터로 구분됩니다.\n");
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
			printf("%d단계 성공. 다음 단계로(실패 %d회)\n", stage, death);
			stage++;
		}
		else
		{
			death++;
			if (death >= 5)
			{
				printf("게임 오버");
				break;
			}
			else
			{
				printf("%d단계 실패. 다시 시도합니다.(실패 %d회)\n", stage, death);
			}
		}
	}
}

int main()
{
	run();
	return 0;
}
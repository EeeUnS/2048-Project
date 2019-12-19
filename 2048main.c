#pragma warning(disable : 4996)

#include "./lib-cross.h"
#include "./mainfeatures.h"
#include <stdbool.h> //bool
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

//���� ������ �¸� true
bool wincounter = false;

bool status = false;



int moveable;

int numbers[SIZE][SIZE];
//����
int score;
//0�� �� ����
int zeros;

bool LoseCheck()
{
	for (int i = 0; i < SIZE-1; ++i)
	{
		for (int j = 0; j < SIZE-1; ++j)
		{
			if (numbers[i][j] == numbers[i + 1][j])
			{
				return false;
			}
			if (numbers[i][j] == numbers[i][j + 1])
			{
				return false;
			}
		}
		//������ ������ ��ġ���� üũ
		if (numbers[i][3] == numbers[i+1][3])
		{
			return false;
		}
		//������ ������ ��ġ���� üũ
		if (numbers[3][i] == numbers[3][i + 1])
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	//Initialize
	system("mode con: cols=30 lines=20"); //#include <stdlib.h> ȭ��ũ������
	//�ܼ� Ŀ�� ����
	hide_cursor();

	char command = -1;
	// get input
	srand(time(NULL));


	//���� ��ġ
	const int count = (rand() % 4) + 5;
	for (int i = 0; i < count; ++i)
	{
		number();
	}
	zeros = 16 - count;
	Draw(score);

	//Input 
	while ((command = getch()) != EOF)
	{
		moveable = 0;
		switch (command)
		{
		case 'a':
			screen_clear();
			score += move_left(numbers);
			break;

		case 'w':
			screen_clear();
			score += move_up(numbers);
			break;

		case 's':
			screen_clear();
			score += move_down(numbers);
			break;

		case 'd':
			screen_clear();
			score += move_right(numbers);
			break;
		default:
			continue;
			break;//not using
		}

		if (zeros > 0 && moveable > 0)
		{
			number();
		}

		Draw(score);

		if (wincounter == true && status == false)
		{
			printf("You Win!");
			status == true;
		}

		if (zeros == 0 && LoseCheck()) // Test losing condition
		{
			printf("You Lose!");
			break;
		}
	}
	show_cursor();
	
	return 0;
}

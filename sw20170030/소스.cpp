#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class BoardGame
{
private:
	int player1[4]; //�÷��̾� ��
	int board[21]; //����
	int dice[4]; //��
	int b_len; //����迭 ����
public:
	BoardGame(); //���¿�
	void roll(); //�� ������
	void move(int player); //�̵�
	int* moveNum; //�� ����
};
BoardGame::BoardGame()
{
	b_len = sizeof(board);
	for (int i = 0; i < 4; i++) { player1[i] = 0; } //�� ����
	for (int i = 0; i < b_len; i++) { board[i] = i; } //���� ����
	for (int i = 0; i < 4; i++) { dice[i] = 0; }
}
void BoardGame::roll()
{
	int i = 0;
	moveNum = (int*)malloc(sizeof(int) * (i + 1));
	while (1) {
		int roll = 0;
		for (int i = 0; i < 4; i++) { srand(time(NULL)); dice[i] = rand() % 2; roll += dice[i]; }
		switch (roll)
		{
		case 0:
			moveNum[i] = 5;
		case 1:
			if (dice[0] == 1)
				moveNum[i] = -1;
			else
				moveNum[i] = 1;
			break;
		case 2:
			moveNum[i] = 2;
			break;
		case 3:
			moveNum[i] = 3;
			break;
		case 4:
			moveNum[i] = 4;
		}
		i++;
	}
}
void BoardGame::move(int player)
{
	int num;
	printf("�̵� ������ ��");
	for (int i = 0; i < sizeof(moveNum); i++)
		printf("%d / ", moveNum[i]);
	printf("�̵� : ");
	//for(int i = 0; i< )
	scanf("%d", &num);
	player1[player] += moveNum[num];
}

//���ӽ��� -> �� Ȯ�� -> �� ������ -> �߰��� -> �� �����̱� -> �߰���/�¸�����Ȯ�� -> ������
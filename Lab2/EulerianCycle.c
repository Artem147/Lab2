/*
	EulerianCycle.
	������� � ��������� ������������� �������� �����,
	������� ���� �������� �����, ���� �� ����������.
	�������� �.�.
	��� - 13��
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//���� ������� ��������� � �������� �� ������������� �������� �����.
int input(int N, int** matrix)
{
	int i, j, counter = 0;//��������, ������� �������� ������.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (scanf("%d", &matrix[i][j]) < 1 || matrix[i][j] != 0 && matrix[i][j] != 1) return -1;
			//���� ������� �� ����� ��� �� 1 ��� 0 - return,
			if (matrix[i][j]) counter++;
		}
		if (counter % 2 == 1)
		{
			printf("EulerianCycle doesn't exist");
			return -1;
		}//���� ������� ������� �������� - �������� ����� �� ����������.
	}
	return 1;
}
//����������� ������� ���������.
int** CloneMatrix(int Number, int** source)
{
	int i, j;
	int** dst;
	dst = malloc(Number * sizeof(int));
	for (int i = 0; i < Number; i++)
		dst[i] = malloc(Number * sizeof(int*));
	for (i = 0; i < Number; i++)
		for (j = 0; j < Number; j++)
			dst[i][j] = source[i][j];
	return dst;
}
//����� �������� ����� � ������� ��������. ���������� ��������� �� ������ � ����� �������� �����.
int* FoundEulerianCycle(int** matrix, int N, int point, int* NumberEl, int* path)
{
	int i, j;
	i = point;//������� ������.
	int counter = (*NumberEl);//����� �������� �����.
	for (j = N - 1; j >= 0; j--)//� ������� point ���� � ����� � ������ �� ������� ���������.
	{
		if (matrix[i][j] != 0)//���� ���������� ���� ����� ����� �������.
		{
			matrix[i][j] = 0;
			matrix[j][i] = 0;//������� ����� ����� ����� �������.
			(*NumberEl)++;//����������� ���������� ����.
			point = j;//��������� �������� ���������� ����� ���������� �����.
			path = FoundEulerianCycle(matrix, N, point, NumberEl, path);
			//��������� �������� � ������� � ����� point.
			if (counter + 1 == (*NumberEl))
			{//��������� ������� � ��������� ������ ��� ����� ����, ����� �������� ��� �������.
				path = realloc(path, (*NumberEl) * sizeof(int));
				path[(*NumberEl) - 1] = 0;
			}
			path[counter - 1] = i;//������������ ���� ���������� �����.
		}
	}
	return path;//���������� ��������� �� ���� ��������� �����.
}
//����� ������� ���������.
void output(int N, int**matrix)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}
//������� ������� ���������.
void FreeMatrix(int N, int** matrix)
{
	for (int i = 0; i < N; i++)
		free(matrix[i]);
	free(matrix);
	return NULL;
}
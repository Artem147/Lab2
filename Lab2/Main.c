/*
	EulerianCycle.
	������� � ��������� ������������� �������� �����, ������� ���� �������� �����, ���� �� ����������.
	�������� �.�.
	��� - 13��
*/
#define _CRT_SECURE_NO_WARNINGS 
#include "EulerianCycle.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
	printf("Functions with checking the existence of an Euler cycle, searching\n");
	printf("for the path of an Eulerian cycle, if it exists.\n");
	printf("Shirkunov Artem IVT-13BO\n");
	int Number, NumberEl = 1; //���-�� ������, ���-�� �����.
	int i, j;
	int **matrix;//������� ���������.
	int*path;//���� �������� �����.
	path = malloc(sizeof(int));
	int* pointer;//��������� �� ���-�� �����.
	pointer = &NumberEl;
	printf("Number of edges: ");
	scanf("%d", &Number);
	printf("Adjacency matrix:\n");
	matrix = malloc(Number * sizeof(int));
	for (int i = 0; i < Number; i++)
	{
		matrix[i] = malloc(Number * sizeof(int*));
	}
	//���� ���������� ����� �� ���������� - return.
	if (input(Number, matrix) == -1)
		return;

	path = malloc(sizeof(int));//����� ������� ���� ��������� �����.
	int** MatrixCopy;//����� ������� ���������, ��� �������� �� ��� �����.
	MatrixCopy = CloneMatrix(Number, matrix);
	path = FoundEulerianCycle(MatrixCopy, Number, 0, pointer, path);
	printf("Path of Eulerian Cycle: ");
	for (int i = 0; i < NumberEl; i++)//����� ���� ���������� �����.
		printf("%d ", path[i]);
	free(path);//������������ ���� ���������� �����.
	FreeMatrix(Number, matrix);//������������ ������ ������� ���������.
	FreeMatrix(Number, MatrixCopy);//������������ ������ ����� ������� ���������.
	printf("\n");
	system("pause");
	return 0;
}
/*�����
�������� ��� ������� �����
3
0 1 1
1 0 1
1 1 0

5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0

��� ��������� �����
6
0 1 0 0 0 1
1 0 1 1 0 1
0 1 0 1 0 0
0 1 1 0 1 1
0 0 0 1 0 1
1 1 0 1 1 0

�� ���������� ��������� �����
0 1 1 1
1 0 1 0
1 1 0 0
0 1 0 1
*/
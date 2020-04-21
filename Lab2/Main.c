/*
	EulerianCycle.
	Функции с проверкой существования эйлерова цикла, поиском пути эйлерова цикла, если он существует.
	Ширкунов А.В.
	ИВТ - 13БО
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
	int Number, NumberEl = 1; //Кол-во вершин, кол-во ребер.
	int i, j;
	int **matrix;//Матрица смежности.
	int*path;//Путь эйлерова цикла.
	path = malloc(sizeof(int));
	int* pointer;//Указатель на кол-во ребер.
	pointer = &NumberEl;
	printf("Number of edges: ");
	scanf("%d", &Number);
	printf("Adjacency matrix:\n");
	matrix = malloc(Number * sizeof(int));
	for (int i = 0; i < Number; i++)
	{
		matrix[i] = malloc(Number * sizeof(int*));
	}
	//Если Эйлерового цикла не существует - return.
	if (input(Number, matrix) == -1)
		return;

	path = malloc(sizeof(int));//Иначе создаем путь эйлеровго цикла.
	int** MatrixCopy;//копия матрицы смежности, для удаления из нее ребер.
	MatrixCopy = CloneMatrix(Number, matrix);
	path = FoundEulerianCycle(MatrixCopy, Number, 0, pointer, path);
	printf("Path of Eulerian Cycle: ");
	for (int i = 0; i < NumberEl; i++)//Вывод пути Эйлерового цикла.
		printf("%d ", path[i]);
	free(path);//Освобождение пути эйлерового цикла.
	FreeMatrix(Number, matrix);//Освобождение памяти матрицы смежности.
	FreeMatrix(Number, MatrixCopy);//Освобождение памяти копии матрицы смежности.
	printf("\n");
	system("pause");
	return 0;
}
/*тесты
работает для полного графа
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

для неполного графа
6
0 1 0 0 0 1
1 0 1 1 0 1
0 1 0 1 0 0
0 1 1 0 1 1
0 0 0 1 0 1
1 1 0 1 1 0

не существует эйлеровго цикла
0 1 1 1
1 0 1 0
1 1 0 0
0 1 0 1
*/
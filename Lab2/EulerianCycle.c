/*
	EulerianCycle.
	Функции с проверкой существования эйлерова цикла,
	поиском пути эйлерова цикла, если он существует.
	Ширкунов А.В.
	ИВТ - 13БО
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//Ввод матрицы смежности и проверка на существовании эйлерова цикла.
int input(int N, int** matrix)
{
	int i, j, counter = 0;//Счетчики, счетчик степеней вершин.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (scanf("%d", &matrix[i][j]) < 1 || matrix[i][j] != 0 && matrix[i][j] != 1) return -1;
			//Если введено не число или не 1 или 0 - return,
			if (matrix[i][j]) counter++;
		}
		if (counter % 2 == 1)
		{
			printf("EulerianCycle doesn't exist");
			return -1;
		}//Если степень вершины нечетная - эйлерова цикла не существует.
	}
	return 1;
}
//Копирование матрицы смежности.
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
//Поиск эйлерова цикла с помощью рекурсии. Возвращает указатель на массив с путем эйлерова цикла.
int* FoundEulerianCycle(int** matrix, int N, int point, int* NumberEl, int* path)
{
	int i, j;
	i = point;//Вершина начала.
	int counter = (*NumberEl);//Номер текущего ребра.
	for (j = N - 1; j >= 0; j--)//В вершине point идем с конца к началу по матрице смежности.
	{
		if (matrix[i][j] != 0)//Если существует путь между двумя точками.
		{
			matrix[i][j] = 0;
			matrix[j][i] = 0;//удаляем ребро между двумя точками.
			(*NumberEl)++;//Увеличиваем количество ребр.
			point = j;//Следующей вершиной становится конец удаленного ребра.
			path = FoundEulerianCycle(matrix, N, point, NumberEl, path);
			//Запускаем рекурсию с началом в точке point.
			if (counter + 1 == (*NumberEl))
			{//Последний элемент и выделение памяти для всего пути, когда пройдена вся матрица.
				path = realloc(path, (*NumberEl) * sizeof(int));
				path[(*NumberEl) - 1] = 0;
			}
			path[counter - 1] = i;//Формирование пути эйлерового цикла.
		}
	}
	return path;//Возвращаем указатель на путь эйлеровго цикла.
}
//Вывод матрицы смежности.
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
//Очистка матрицы смежности.
void FreeMatrix(int N, int** matrix)
{
	for (int i = 0; i < N; i++)
		free(matrix[i]);
	free(matrix);
	return NULL;
}
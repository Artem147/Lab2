/*
	EulerianCycle.
	Функции с проверкой существования эйлерова цикла, поиском пути эйлерова цикла, если он существует.
	Ширкунов А.В.
	ИВТ - 13БО
*/
#ifndef EulerianCycle
#define EulerianCycle

//Ввод матрицы смежности и проверка на существовании эйлерова цикла.
int input(int N, int** matrix);

//Копирование матрицы смежности.
int** CloneMatrix(int Number, int** source);

//Поиск эйлерова цикла. Возвращает указатель на массив с путем эйлерова цикла. 
//!!Очистка памяти path осуществляется вне функции.
int* FoundEulerianCycle(int** matrix, int N, int point, int* NumberEl, int* path);

//Вывод матрицы смежности.
void output(int N, int**matrix);

//Очистка матрицы смежности.
int** FreeMatrix(int N, int** matrix);
#endif //EulerianCycle
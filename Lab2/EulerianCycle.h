/*
	EulerianCycle.
	������� � ��������� ������������� �������� �����, ������� ���� �������� �����, ���� �� ����������.
	�������� �.�.
	��� - 13��
*/
#ifndef EulerianCycle
#define EulerianCycle

//���� ������� ��������� � �������� �� ������������� �������� �����.
int input(int N, int** matrix);

//����������� ������� ���������.
int** CloneMatrix(int Number, int** source);

//����� �������� �����. ���������� ��������� �� ������ � ����� �������� �����. 
//!!������� ������ path �������������� ��� �������.
int* FoundEulerianCycle(int** matrix, int N, int point, int* NumberEl, int* path);

//����� ������� ���������.
void output(int N, int**matrix);

//������� ������� ���������.
int** FreeMatrix(int N, int** matrix);
#endif //EulerianCycle
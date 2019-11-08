#include <iostream>
#include <fstream>

using namespace std;

void get_int_from_keyboard(int& number);
int** get_matrix_from_keyboard(int& size);
void show_matrix(int** matrix, int size);
void show_matrix(int** matrix, int n, int m);
int** convert_to_banded(int** sparseMatrix, int size);


int main()
{
	int size;
	int** sparseMatrix;
	sparseMatrix = get_matrix_from_keyboard(size);
	show_matrix(sparseMatrix, size);
	convert_to_banded(sparseMatrix, size);

	return 0;
}

void get_int_from_keyboard(int& number)
{
	while (!(cin >> number) || (cin.get() != '\n'))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Неправильный ввод данных. Повторите попытку: ";
	}
}

int** convert_to_banded(int** sparseMatrix, int size)
{
	int p = 0, q = 0, column=0, row = 0;
	for (int i = 1; i < size; i++)
	{
		if (!sparseMatrix[i][column])
		{
			if (i == size - 1)
			{
				p = i-1;
				break;
			}
			p = i-1;
			row = i + 1;
			column++;
			bool isEmpty = false;
			while (!sparseMatrix[row][column])
			{
				if (row = size - 1)
				{
					p = i-1;
					isEmpty = true;
					break;
				}
				row++;
				column++;
			}
			column = 0;
			row = 0;
			if (isEmpty)
			{
				break;
			}
		}
		p = i;
	}

	for (int i = 1; i < size; i++)
	{
		if (!sparseMatrix[row][i])
		{
			if (i == size - 1)
			{
				q = i - 1;
				break;
			}
			q = i-1;
			column = i + 1;
			row++;
			bool isEmpty = false;
			while (!sparseMatrix[row][column])
			{
				if (column = size - 1)
				{
					q = i - 1;
					isEmpty = true;
					break;
				}
				row++;
				column++;
			}
			column = 0;
			row = 0;
			if (isEmpty)
			{
				break;
			}
		}
		q = i;
	}
	
	cout << "p: " << p << " q: " << q << endl;

	int m = p + q + 1;
	int** bandedMatrix = new int* [m];
	for (int i = 0; i < m; i++)
	{
		bandedMatrix[i] = new int[size];
	}


	return bandedMatrix;
}

int** get_matrix_from_keyboard(int& size)
{
	while (size <= 0)
	{
		cout << "Enter the sparse matrix size: ";
		get_int_from_keyboard(size);
	}

	int** sparseMatrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		sparseMatrix[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Enter element of " << i+1 << " row " << j+1 << " column: ";
			get_int_from_keyboard(sparseMatrix[i][j]);
			
		}
	}
	return sparseMatrix;
}



void show_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void show_matrix(int** matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
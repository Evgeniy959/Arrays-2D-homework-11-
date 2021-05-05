#include <iostream>
using namespace std;

void main()

{
	setlocale(LC_ALL, "RUS");
	const int ROWS = 3; // Количество строк
	const int COLS = 3; // Количество столбцов (элементов строки)
	int arr[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	cout << "Выберите действие +, *, d" << endl;
	cout << endl;
	cout << "Матрица А:" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "\n";
	char key;
	cin >> key;
	if (key == '+')
	{
		cout << "\n";
		cout << "Матрица B:" << endl;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "\n";
		cout << "=" << endl; cout << "\n"; cout << "Матрица С:" << endl;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << arr[i][j] + arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	if (key == '*')
	{
		cout << "\n";
		cout << "Матрица B:" << endl;
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "\n";
		cout << "=" << endl; cout << "\n"; cout << "Матрица С:" << endl;
		int C[ROWS][COLS]{};
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				for (int k = 0; k < COLS; k++)
					C[i][j] += arr[i][k] * arr[k][j];
				cout << C[i][j] << "\t";
			}
			cout << endl;
		}
	}
	if (key == 'd')
	{
		cout << "\n";
		cout << "Определитель (determinant) матрицы А:";
		int D[ROWS][COLS * 2]{};
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				D[i][j] = D[i][j + COLS] = arr[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS * 2; j++)
			{
				cout << D[i][j] << "\t";
			}
			cout << endl;
		}
		int determinant = 0;
		int sum_main_diag = 0;
		int sum_aux_diag = 0;
		for (int i = 0; i < ROWS; i++)
		{
			int product_main = 1;
			int product_aux = 1;
			for (int j = 0; j < COLS; j++)
			{
				product_main *= D[j][j + i];
				product_aux *= D[COLS - 1 - j][j + i];
			}
			sum_main_diag += product_main;
			sum_aux_diag += product_aux;
		}
		cout << "Сумма произведений элементов главной диагонали: " << sum_main_diag << endl;
		cout << "Сумма произведений элементов второстепенной диагонали: " << sum_aux_diag << endl;
		cout << "Определитель: " << (determinant = sum_main_diag - sum_aux_diag) << endl;
	}

}
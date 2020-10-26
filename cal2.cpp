#include <iostream>
using namespace std;

int small(int one_line[7])
{
	int value = one_line[0];
	for (int i = 1; i < 7; i++)
	{
		if (value > one_line[i])
			value = one_line[i];
	}
	return value;
}

void reset(int one_line[7])
{
	for (int i = 0; i < 7; i++)
		one_line[i] = 0;
}

void copy_s(int one_line[7], int d[][7], int matrix[][7], int i, int j)
{
	for (int x = 0; x < 7; x++)
		one_line[x] = d[i][x] + matrix[x][j];
}

void print_matrix(int matrix[][7], int m)
{
	cout << "m = " << m << endl;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void graph(int matrix[][7])
{
	int one_line[7];
	reset(one_line);
	int d[7][7];
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			d[i][j] = matrix[i][j];

	for (int m = 1; m < 6; m++)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				copy_s(one_line, d, matrix, i, j);
				d[i][j] = small(one_line);
				reset(one_line);
			}
		}
		print_matrix(d, m);
	}
}



int main(void)
{

	int matrix[7][7] = { 0,4,0,0,0,10,0,3,0,999,18,999,999,999,999,6,0,999,999,999,999,999,5,15,0,2,19,5,999,999,12,1,0,999,999,999,999,999,999,999,0,10,999,999,999,8,999,999,0 };
	print_matrix(matrix, -1);

	graph(matrix);


	return 1;
}
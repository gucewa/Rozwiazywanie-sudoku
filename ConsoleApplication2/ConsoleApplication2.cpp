#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

bool rozw(int a, int b);

int sudoku[9][9];
int akt[9][9];
bool czy_wstawic(int a, int b, int c) 
{
	for (int i = 0; i < 9; i++) 
	{
		if (c == akt[a][i] || c == akt[i][b] ||
			c == akt[a / 3 * 3 + i % 3][b / 3 * 3 + i / 3]) return false;
	} return true;
}

bool nast(int a, int b) 
{
	if (a == 8 && b == 8) return true;
	else if (a == 8) return rozw(0, b + 1);
	else return rozw(a + 1, b);
}

bool rozw(int a, int b) 
{
	if (sudoku[a][b] == 0) 
	{
		for (int i = 1; i <= 9; i++) 
		{
			if (czy_wstawic(a, b, i)) 
			{
				akt[a][b] = i;
				if (nast(a, b)) return true;
			}
		} akt[a][b] = 0; return false;
	} return nast(a, b);
}

int main()
{
	ifstream in("sudoku.txt");
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			in >> sudoku[i][j];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			akt[i][j] = sudoku[i][j];
		}
	}
	if (rozw(0, 0)) {
		for (int i = 0; i<9; i++) 
		{
			for (int j = 0; j<9; j++) 
			{
				cout << akt[i][j]<<endl;
			}
		}
	}
	else 
	{
		cout << "Niemożliwe do rozwiązania"<<endl;
	}
	system("PAUSE");
    return 0;
}


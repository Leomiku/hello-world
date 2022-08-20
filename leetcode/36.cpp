#include<stdio.h>
#include<string>
#include<math.h>
#include<iostream>
#include<vector>

using namespace std;


bool checkL[10][10];
bool checkR[10][10];
bool checkB[3][3][10];

void init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			checkL[i][j] = false;
			checkR[i][j] = false;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 1; k < 10; k++)
			{
				checkB[i][j][k] = false;
			}
		}
	}
}

bool checkLine(vector<vector<char>>& board, int idx)
{
	for (int i = 0; i < board[0].size(); i++)
	{
		int num = board[idx][i] - '0';
		if (num <= 0 || num > 9)
		{
			continue;
		}
		if (checkL[idx][num])
		{
			return false;
		}
		else
		{
			checkL[idx][num] = true;
		}
	}
	return true;
}

bool checkRow(vector<vector<char>>& board, int idx)
{
	for (int i = 0; i < board[0].size(); i++)
	{
		int num = board[i][idx] - '0';
		if (num <= 0 || num > 9)
		{
			continue;
		}
		if (checkR[idx][num])
		{
			return false;
		}
		else
		{
			checkR[idx][num] = true;
		}
	}
	return true;
}

bool checkBlock(vector<vector<char>>& board, int idxl, int idxr)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num = board[idxl * 3 + i][idxr * 3 + j] - '0';
			if (num <= 0 || num > 9)
			{
				continue;
			}
			if (checkB[idxl][idxr][num])
			{
				return false;
			}
			else
			{
				checkB[idxl][idxr][num] = true;
			}
		}
	}
	return true;
}


bool isValidSudoku(vector<vector<char>>& board) {
	for (int i = 0; i < 9; i++)
	{
		if (!checkLine(board, i))
			return false;
	}
	for (int i = 0; i < 9; i++)
	{
		if (!checkRow(board, i))
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!checkBlock(board, i, j))
				return false;
		}
	}
	return true;
}


int main()
{
	vector<vector<char>> board;

	for (int i = 0; i < 9; i++)
	{
		vector<char> t;
		for (int j = 0; j < 9; j++)
		{
			char ch;
			cin >> ch;
			t.push_back(ch);
		}
		board.push_back(t);
	}

	if (isValidSudoku(board))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	return 0;
}
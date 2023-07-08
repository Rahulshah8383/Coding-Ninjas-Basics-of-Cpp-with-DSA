/*
Sudoku Solver
Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
Input Format:
There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
Output Format:
The first and only line of output contains boolean value, either true or false, as described in problem statement.
Constraints:
The cell values lie in the range: [0, 9]
Time Limit: 1 second 
Note:
Input are given in a way that backtracking solution will work in the provided time limit.
Sample Input 1:
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output 1:
true
*/

#include <iostream>
using namespace std;

bool findEmptyLocation(int &current_row, int &current_column, int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                current_row = i;
                current_column = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int current_row, int current_column, int sudoku[9][9], int current)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[current_row][i] == current)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int current_row, int current_column, int sudoku[9][9], int current)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][current_column] == current)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInBox(int current_row, int current_column, int sudoku[9][9], int current)
{
    int row_factor = current_row - (current_row % 3);
    int column_factor = current_column - (current_column % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[i + row_factor][j + column_factor] == current)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int current_row, int current_column, int sudoku[9][9], int current)
{
    return isSafeInRow(current_row, current_column, sudoku, current) && isSafeInColumn(current_row, current_column, sudoku, current) && isSafeInBox(current_row, current_column, sudoku, current);
}

bool solve_sudoku(int sudoku[9][9])
{
    int current_row, current_column;
    if (!findEmptyLocation(current_row, current_column, sudoku))
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(current_row, current_column, sudoku, i))
        {
            sudoku[current_row][current_column] = i;
            if (solve_sudoku(sudoku))
            {
                return true;
            }
            sudoku[current_row][current_column] = 0;
        }
    }
    return false;
}

int main()
{
    int sudoku[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    if (solve_sudoku(sudoku))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
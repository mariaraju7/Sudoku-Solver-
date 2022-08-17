//my sudoku game solver

#include <iostream>

using namespace std;

int grid[9][9] = //grid, 0 is empty space
{
    {6,5,0,8,7,3,0,9,0},
    {0,0,3,2,5,0,0,0,8},
    {9,8,0,1,0,4,3,5,7},
    {1,0,5,0,0,0,0,0,0},
    {4,0,0,0,0,0,0,0,2},
    {0,0,0,0,0,0,5,0,3},
    {5,7,8,3,0,1,0,2,6},
    {2,0,0,0,4,8,9,0,0},
    {0,9,0,6,2,5,0,8,1}
   
};


bool colp(int row, int col, int num) //checking each col 
{

    for (int row=0; row<9; row++) //changing the row, checking the 1 col
    {
     if (grid[row][col]==num)
        return true;
    
    return false;
}

}

bool rowp(int row, int col, int num) //checking each 1 row by changing the col
{
    for (int col=0; col<9; col++)
{
    if (grid[row][col]==num)
        return true;}
     
    return false;
}



bool boxp(int boxr, int boxc, int num) //checking box 
{
    for (int row=0;row<3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxr][col+boxc]==num) //adding onto the boxr and boxc
                return true; 
    return false;
}

bool findempty(int &row, int&col) //finding location and changing it in empty spots
{
    for (row=0;row<9; row++)
        for (col = 0; col < 9; col++ )
            if (grid[row][col]==0) //adding onto the boxr and boxc
                return true; 
    return false;

}

bool isvalid (int row, int col, int num)
{
       //when item not found in col, row and current 3x3 box it is a valid space

       return !colp(row,col,num)&&!rowp(row,col,num)&&!boxp(row - row%3,col - col%3, num);

}


bool solve()
{
     int row,col;
    if (!findempty(row, col))
        return true; 
    for (int num =1; num <=9;num++){
     if (isvalid(row,col,num))
        {grid[row][col] = num;
        if (solve())
            return true; 
        grid[row][col] = 0; 
    }
 }

return false; 

}


void printsudoku() //printing the sudoku 
{
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++)
        {
            if (col==3||col==6) //or
            {
                cout<<"|";
            }

             cout << grid[row][col] <<" ";
        }
        if (row == 2 || row == 5)
        {
            cout << endl;

             for(int i = 0; i<9; i++)
                {cout << "---";}
        }
        cout << endl;
        }
}

int main ()
{
    if (solve() == true)
        printsudoku();
   else
      cout << "No solution exists";
}

//check num in row
//check num in col
//check num in box 
//change 0 to num 
//print sol
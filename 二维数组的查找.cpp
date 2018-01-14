#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
bool Find2(int target, vector<vector<int> > array)
{
    int columns = array[0].size();
    int rows = array.size();
    if(rows>0 && columns>0)
    {
        int row = 0;
        int col = columns-1;
        while(row < rows && col>=0)
        {
            if(target == array[row][col])
                return true;
            else if(array[row][col]>target)
                col--;
            else
                row++;
        }
    }
    return false;
}
bool Find(int target, vector<vector<int> > array)
{
    int column = array[0].size();
    int row = array.size();
    int i, j;
    for(i=0; i<row; i++)
    {
        if(target > array[i][column-1])
            continue;
        int low = 0;
        int high = column-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(target == array[i][mid])
                return true;
            else if(target < array[i][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return false;
}
int main()
{

}

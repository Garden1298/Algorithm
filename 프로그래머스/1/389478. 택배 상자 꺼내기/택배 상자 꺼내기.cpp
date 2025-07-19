#include <string>
#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

int solution(int n, int w, int num) {
    
    int totalbox = n, width = w, targetBox = num;
    int boxToRemove = 0, targetRow, targetCol, lastRow, lastCol;
    
    //targetBox 위치 구하기
    if(targetBox % width == 0)
    {
        targetRow = targetBox / width - 1;
        if(targetRow % 2 == 1)
        {
            targetCol = 0;
        }
        else
        {
            targetCol = width - 1;
        }
    }
    else
    {
        targetRow = targetBox / width;
        if(targetRow % 2 == 1)
        {
            targetCol = width - (targetBox % width);
        }
        else
        {
            targetCol = (targetBox % width) - 1;
        }
    }
    
    if(totalbox % width == 0)
    {
        lastRow = totalbox / width -1;
        if(lastRow % 2 == 1)
        {
            lastCol = 0;
        }
        else
        {
            lastCol = width - 1;
        }
    }
    else
    {
        lastRow = totalbox / width;
        if(lastRow % 2 == 1)
        {
            lastCol = width - (totalbox % width);
        }
        else
        {
            lastCol = (totalbox % width) - 1;
        }
    }
    
    boxToRemove = lastRow - targetRow +1;
    if(lastRow % 2 == 1)
    {
        if(lastCol > targetCol)
        {
            boxToRemove--;
        }
    }
    else
    {
        if(lastCol < targetCol)
        {
            boxToRemove--;
        }
    }

    
    return boxToRemove;
}
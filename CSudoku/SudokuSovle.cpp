/*********************************************
fileName:   Sudokusovle.cpp
description: this is a program lib that to solve sudoku

@Author:    yihuiemail@163.com
Date:       2015-8-29
*********************************************/


#include "SudokuSovle.h"

SudokuSovle::SudokuSovle():isInited(false),
                           isSolved(false),
                           isRead(false)
{
    //ctor
}

SudokuSovle::~SudokuSovle()
{
    //dtor
}

/*bool SudokuSovle::ReadMap()
{
    freopen("in_map3.in", "rt", stdin);
    //freopen("map2.out", "wt",stdout);
    printf("--- read start:\n\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j ++)
        {
            scanf("%d", &mapCon[i][j]);
            printf("%d ", mapCon[i][j]);
        }
        printf("\n");
    }
    printf("\n--- read over!\n");
    return true;
}*/
// override
bool SudokuSovle::ReadMap(const char * fileName)
{
    freopen(fileName, "rt", stdin);
    //freopen("map2.out", "wt",stdout);
    #ifdef _DEBUG
    printf("--- read start:\n\n");
    #endif // _DEBUG
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j ++)
        {
            scanf("%d", &mapCon[i][j]);
            if(mapCon[i][j]<0 && mapCon[i][j]>9){isRead = false; return false;}
            #ifdef _DEBUG
            printf("%d ", mapCon[i][j]);
            #endif // _DEBUG
        }
        #ifdef _DEBUG
        printf("\n");
        #endif // _DEBUG
    }
    memcpy(originalMap, mapCon, sizeof(originalMap));
    isRead = true;
    #ifdef _DEBUG
    printf("\n--- read over!\n");
    #endif // _DEBUG
}
// override
bool SudokuSovle::ReadMap(const int m[9][9])
{
    memcpy(originalMap, m, sizeof(originalMap));
    memcpy(mapCon, originalMap,sizeof(mapCon));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j ++)
        {
            if(mapCon[i][j]<0 && mapCon[i][j]>9){isRead = false; return false;}
        }
    }
}
/**
 * function : Run
 * description: solve the sudoku main program
 *
 * date     : 2015-8-28
*/
void SudokuSovle::Run()
{
    MapInit();
    if(!isInited)
    {
        printf("--- sudoku map has not initialed successful\n");
    }
    printf("\n--- start run solve\n");
    if(!FillNum())
    {
        printf("solve false\n");
    }
    /*for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%x ", state[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%d ", aviaNum[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 10; i ++)
    {
        printf("i = %d \n",priority[i][81]);
    }*/
    printf("--- solve over\n");
    #ifdef _DEBUG
    printf("\n--- result is: \n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j ++)
        {
            printf("%d ", mapCon[i][j]);
        }
        printf("\n");
    }
    #endif // _DEBUG
}
/**
 * function : UpdateState
 * description: update the position (i,j) with number num,
 *            : update the state of other position
 * date     : 2015-8-28
*/
bool SudokuSovle::ShowResult()
{
    PrintMap();
}
/**
 * function : UpdateState
 * description: update the position (i,j) with number num,
 *            : update the state of other position
 * date     : 2015-8-28
*/
bool SudokuSovle::UpdateState(int row, int col, int num)
{
    //if(mapCon[row][col] != 0) return false;
    if(num>9 || num <1) return false;
    state[row][col] = 0x0000;
    mapCon[row][col] = num;

    for(int j = 0; j < 9; j++)
    {
        if(j == col) continue;
        state[row][j] &= offset[num];
    }
    for(int i = 0; i < 9; i++)
    {
        if(i == row) continue;
        state[i][col] &= offset[num];
    }
    for(int i = (row/3)*3; i < (row/3+1)*3; i++)
    {
        for(int j = (col/3)*3; j < (col/3+1)*3; j++)
        {
            if(i == row || j == col) continue;
            state[i][j] &= offset[num];
        }
    }
    // update priority
    memset(priority, 0, sizeof(priority));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            aviaNum[i][j] = tableAviaNum[(state[i][j] & 0x000f)]
                        + tableAviaNum[(state[i][j]>>4) & 0x000f]
                        + tableAviaNum[state[i][j]>>8];
            if(mapCon[i][j] == 0 && aviaNum[i][j] == 0) return false;
            priority[aviaNum[i][j]][priority[aviaNum[i][j]][81]] = i*9+j;
            priority[aviaNum[i][j]][81] ++;
        }
    }
    //PrintMap(row, col);
    return true;
}
/**
 * function : MapInit
 * description: initial the map according to the read data
 *
 * date     : 2015-8-28
*/
void SudokuSovle::MapInit()
{
    // init the state
    if(!isRead)
    {
        printf("--- sudoku number has not read\n");
        return;
    }
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0;j < 9; j++)
        {
            state[i][j] = 0x01ff;
            aviaNum[i][j] = 9;
        }
    }
    memset(priority, 0, sizeof(priority));
    for(int i = 0; i < 9;i ++)
    {
        for(int j = 0; j< 9; j++)
        {
            if(mapCon[i][j] != 0)
            {
                UpdateState(i, j, mapCon[i][j]);
            }
        }
    }
    deepDegree = 0;
    isInited = true;
}

/**
 * function : FillNum
 * description: fill the blank number based on the rules
 *
 * date     : 2015-8-28
*/
bool SudokuSovle::FillNum()
{
    while(priority[0][81]<81)
    {
        if(HasOnlyVal())
        {
            int i = priority[1][0]/9, j = priority[1][0]%9;
            float ass = (float)state[i][j];
            int num = (*(unsigned long *) & ass >> 23) -126;
            if (!UpdateState(i, j, num)) return false;
        }
        else
        {
            return SearchPath();
            break;
        }
    }
    return true;
}
/**
 * function : HasOnlyVal
 * description: judge the if the map has ensured value
 *
 * date     : 2015-8-28
*/
bool SudokuSovle::HasOnlyVal()
{
    return priority[1][81] >= 1;
}
/**
 * function : SearchPath
 * description: search the answer where the candidate is more than one
 *
 * date     : 2015-8-28
*/
bool SudokuSovle::SearchPath()
{
    int minPri = GetMinPri();
    if(minPri < 0) return false;
    int pathNum = minPri;
    // back up the map state
    int backupMap[9][9];
    int backupState[9][9];
    int backupNum[9][9];
    int backPriority[10][82];
    memcpy(backupMap, mapCon, sizeof(backupMap));
    memcpy(backupState, state, sizeof(backupState));
    memcpy(backupNum, aviaNum, sizeof(backupNum));
    memcpy(backPriority, priority, sizeof(backPriority));

    int i = priority[minPri][0]/9, j = priority[minPri][0]%9;
    float ass = (float)state[i][j];
    int num = (*(unsigned long *) & ass >> 23) -126;
    deepDegree ++;
    for(int path = 0; path < pathNum; path ++)
    {
        #ifdef _DEBUG
        printf("--- search path deep - %d-%d\n", deepDegree, path);
        #endif // _DEBUG
        if(path > 0)
        {
            ass -= 1 << (num-1);
            num = (*(unsigned long *) & ass >> 23) -126;
        }
        if(UpdateState(i, j, num))
        {
            if(!FillNum())
            {
                // recovery the state when fill false
                memcpy(mapCon, backupMap, sizeof(backupMap));
                memcpy(state, backupState, sizeof(backupState));
                memcpy(aviaNum, backupNum, sizeof(backupNum));
                memcpy(priority, backPriority,sizeof(backPriority));
                #ifdef _DEBUG
                printf("--- recovery caused by fill\n");
                //PrintMap();
                #endif // _DEBUG
                continue;
            }
            else return true;
        }
        else
        {
            memcpy(mapCon, backupMap, sizeof(backupMap));
            memcpy(state, backupState, sizeof(backupState));
            memcpy(aviaNum, backupNum, sizeof(backupNum));
            memcpy(priority, backPriority,sizeof(backPriority));
            #ifdef _DEBUG
            printf("--- recovery caused by search path\n");
            //PrintMap();
            #endif // _DEBUG
            continue;
        }
    }
    deepDegree --;
    return false;
}

int SudokuSovle::GetMinPri()
{
    for(int i = 1; i < 10; i++)
    {
        if(priority[i][81] > 0) return i;
    }
    return -1;
}

/**
 * function : PrintMap
 * description: print map and state in real time
 *              for test
 * date     : 2015-8-29
*/
void SudokuSovle::PrintMap()
{
    printf("\nmap state\n---MAP:---\n\n");
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%d ", mapCon[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
// override
void SudokuSovle::PrintMap(int row, int col)
{
    printf("\nmap state\n---MAP:---\n\n");
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(i == row && j == col)  {printf("?%d ", mapCon[i][j]); continue;}
            printf("%d ", mapCon[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

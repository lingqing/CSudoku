#ifndef SUDOKUSOVLE_H
#define SUDOKUSOVLE_H

#include <stdio.h>
#include <string.h>
//#define _DEBUG

class SudokuSovle
{
    public:
        SudokuSovle();
        virtual ~SudokuSovle();

        //bool ReadMap();
        bool ReadMap(const char *);
        bool ReadMap(const int m[9][9]);
        bool ShowResult();
        void Run();
    protected:
    private:
        int mapCon[9][9];
        int originalMap[9][9];
        int state[9][9];
        int aviaNum[9][9];
        int priority[10][82];
        int deepDegree;
        bool isInited;
        bool isSolved;
        bool isRead;

        bool FillNum();
        bool SearchPath();
        bool HasOnlyVal();
        void MapInit();
        int GetMinPri();

        // @Test
        void PrintMap();
        void PrintMap(int i, int j);

        bool UpdateState(int i, int j, int num);
        /*static gridTable[][] = {{1,1,1,2,2,2,6,6,6},
                                {1,1,1,2,2,2,6,6,6},
                                {1,1,1,2,2,2,6,6,6},
                                {}{}{}{}{}{};*/
        const int offset[10] = {0x0000, 0xfffe, 0xfffd, 0xfffb, 0xfff7, 0xffef, 0xffdf, 0xfffbf, 0xfff7f, 0xfeff};
        const int tableAviaNum[16] = {0,1,1,2,1,
                                    2,2,3,1,2,
                                    2,3,2,3,3,4};
};

#endif // SUDUKUSOVLE_H

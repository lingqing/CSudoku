
#include "CSudoku/SudokuSovle.h"

int main()
{
    SudokuSovle ms;
    ms.ReadMap("test_map.in");
    ms.Run();
    ms.ShowResult();

    const int m[9][9]={ {9, 0, 0, 2, 0, 6, 0, 3, 0 },
                    {0, 2, 4, 0, 0, 9, 0, 0, 0 },
                    {6, 0, 0, 0, 0, 8, 0, 0, 7 },
                    {0, 0, 1, 0, 0, 3, 0, 0, 0 },
                    {2, 9, 0, 0, 8, 0, 0, 6, 3 },
                    {0, 0, 0, 6, 0, 0, 1, 0, 0 },
                    {5, 0, 0, 3, 0, 0, 0, 0, 6 },
                    {0, 0, 0, 8, 0, 0, 3, 7, 0 },
                    {0, 3, 0, 7, 0, 2, 0, 0, 1 },
                };
    ms.ReadMap(m);
    ms.Run();
    ms.ShowResult();

    return 0;
}

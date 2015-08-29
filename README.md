# CSudoku
=========
it is a program to solve sudoku

### Usage ###
* download this resp code
* run as follow steps

### Steps ###
* cd your path 
* run: git clone https://github.com/lingqing/CSudoku.git YourPath
* in your program   
  ｛
    ....   
     SudukuSolve ms;   
     ms.ReadMap(fileName);   
     ms.Run();   
     ms.ShowResult();   

    ....   
   ｝
* then you will get the answer

### Test ###
* in the files you download , there is a file named "test.cpp"
* you can test it use this file

### Input Format ###
* the sudoku map for input shoud have 81 elements, which likes follow   
   9 0 0 2 0 6 0 3 0   
   0 2 4 0 0 9 0 0 0   
   6 0 0 0 0 8 0 0 7   
   0 0 1 0 0 3 0 0 0   
   2 9 0 0 8 0 0 6 3   
   0 0 0 6 0 0 1 0 0   
   5 0 0 3 0 0 0 0 6   
   0 0 0 8 0 0 3 7 0   
   0 3 0 7 0 2 0 0 1   
   where the number 0 represent the number is no know for you
* the input can from file ,and file content must as above
* input number also can from code , like follow:
    {   
    ....   
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
    .....   
    }   

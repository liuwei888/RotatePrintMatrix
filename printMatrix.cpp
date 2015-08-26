/*************************************************************************
    > File Name: printMatrix.cpp
    > Author: liuwei
    > Mail: 271551048@qq.com 
    > Created Time: 2015年08月25日 星期二 12时25分19秒
    > 旋转打印数组
 ************************************************************************/

#include<iostream>
using namespace std;

void PrintEdge(int matrix[][4], int sR, int sC, int eR, int eC);

void PrintMatrixSpiralOrder(int matrix[][4] , int row, int column)
{
	int sR = 0;   //startRow
	int sC = 0;   //startColoum，这两个表示左上角起始点的坐标
	int eR = row - 1; //endRow
	int eC = column - 1; //endColum,这两个表示右下角结束点的坐标，这四个参数在一起可以表示一个矩阵

	while(sR <= eR && sC <= eC)
	{
		PrintEdge(matrix, sR++, sC++, eR--, eC--);
	}
}

void PrintEdge(int matrix[][4], int sR, int sC, int eR, int eC)
{
	if(sR == eR)  //startRow = endRow,即只有一行,则把所有元素打印出来即可
	{
		for(int i = sC; i < eC; i++)
			cout << matrix[sR][i] << endl;
	}
	else if(sC == eC)  //startColumn = endColumn,即只有一列,则把所有元素打印出来即可
	{
		for(int i = sR; i < eR; i++)
			cout << matrix[i][sC] << endl;
	}
	else  //一般情况
	{
		int curR = sR;
		int curC = sC;
		while(curC != eC)
		{
			cout << matrix[sR][curC] << " ";
			curC++;
		}
		while(curR != eR)
		{
			cout << matrix[curR][eC] << " ";
			curR++;
		}
		while(curC != sC)
		{
			cout << matrix[eR][curC] << " ";
			curC--;
		}
		while(curR != sR)
		{
			cout << matrix[curR][sC] << " ";
			curR--;
		}

	}
}

int main()
{
	int matrix[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14,15, 16}};
	PrintMatrixSpiralOrder(matrix, 4, 4);

	return 0;

}

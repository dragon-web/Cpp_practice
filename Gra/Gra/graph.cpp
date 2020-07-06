#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define MAX_DIST 65535
#define MAX_POINT 5

void calc_dist(int arr[MAX_POINT][MAX_POINT], int nSize, int nStart)
{
	int arrWeight[MAX_POINT];
	int arrPoints[MAX_POINT];
	int i = 0, j = 0;
	int min = 0;
	int nPoint = 0;

	// Get the distance of reference points
	for (i = 0; i < MAX_POINT; i++)
	{
		arrWeight[i] = arr[nStart][i];
		arrPoints[i] = 0;
	}

	arrPoints[nStart] = 1;
	arrWeight[nStart] = 0;

	for (i = 0; i < MAX_POINT; i++)
	{
		// Get the min distance of reference point
		min = MAX_DIST;
		nPoint = 0;

		for (j = 0; j < MAX_POINT; j++)
		{
			if (arrPoints[j] == 0
				&& arrWeight[j] != MAX_DIST
				&& arrWeight[j] < min)
			{
				min = arrWeight[j];
				nPoint = j;
			}
		}

		arrPoints[nPoint] = 1;
		printf("point:%d  dist:%d \n", nPoint, min);

		// Update the distance of the point from the start point
		for (j = 0; j < MAX_POINT; j++)
		{
			if ((arrPoints[j] == 0)
				&& (arrWeight[nPoint] + arr[nPoint][j] < arrWeight[j]))
			{
				arrWeight[j] = arrWeight[nPoint] + arr[nPoint][j];
			}
		}
	}

}

int main()
{
	int arrTest[MAX_POINT][MAX_POINT] =
	{
		MAX_DIST,       10, MAX_DIST,       30,      100,
		MAX_DIST, MAX_DIST,       50, MAX_DIST, MAX_DIST,
		MAX_DIST, MAX_DIST, MAX_DIST, MAX_DIST,       10,
		MAX_DIST, MAX_DIST,       20, MAX_DIST,       60,
		MAX_DIST, MAX_DIST, MAX_DIST, MAX_DIST, MAX_DIST,
	};
	int i = 0;

	calc_dist(arrTest, MAX_POINT, 0);

	scanf("%d", &i);
	return 0;
}

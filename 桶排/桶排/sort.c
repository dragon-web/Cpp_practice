#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include<windows.h>
#include<list>
//基数排序
/*static void RadixSort(int arr[], int length)
{
	//十个桶
	//不要这么分配二维数组
	/*int** Bucket = (int**)malloc(sizeof(int) *10 * length);
	int* Bucket[10];
	for (int i = 0; i < length; i++)
		Bucket[i] = (int*)malloc(sizeof(int*) * length);

	//每个桶实际存放了多少个数据
	int BucketElemCount[10] = { 0 };
	int n;//进制
	int maxLength = 0;//最大位数

	//计算最大的位数
	int max = 0;
	for (int i = 1; i < length; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	do {
		maxLength++;
		max /= 10;
	} while (max);


	//循环每个数
	for (int i = 0, n = 1; i < maxLength; i++, n *= 10) {
		//循环每个数的位数
		//存进桶
		for (int j = 0; j < length; j++) {
			//计算对应第n位的数字
			int digitofElement;
			digitofElement = arr[j] / n % 10;
			//放到对应位数的桶
			Bucket[digitofElement][BucketElemCount[digitofElement]] = arr[j];
			BucketElemCount[digitofElement]++;
		}
		//取出
		int index = 0;
		//k到最大一位
		for (int k = 0; k < (sizeof(BucketElemCount) / sizeof(BucketElemCount[0])); k++) {
			//如果BucketElemCount里面有数
			if (BucketElemCount[k] != 0) {
				//把每个桶的数据全部放入数组中
				for (int l = 0; l < BucketElemCount[k]; l++) {
					arr[index++] = Bucket[k][l];
				}
			}
			BucketElemCount[k] = 0;
		}
	}

	for (int i = 0; i < length; i++)
		free(Bucket[i]);
}

int main(int argc, char* argv)
{
	int arr[] = { 14,9,6,13,21,10,16,17,2,12 };
	int length = sizeof(arr) / sizeof(arr[0]);
	RadixSort(arr, length);
	printf("\n");
	for (int i = 0; i < length; i++)
		printf("%d  ", arr[i]);
	system("pause");
	return 0;
}
*/


#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include<windows.h>
#include<list>
//��������
/*static void RadixSort(int arr[], int length)
{
	//ʮ��Ͱ
	//��Ҫ��ô�����ά����
	/*int** Bucket = (int**)malloc(sizeof(int) *10 * length);
	int* Bucket[10];
	for (int i = 0; i < length; i++)
		Bucket[i] = (int*)malloc(sizeof(int*) * length);

	//ÿ��Ͱʵ�ʴ���˶��ٸ�����
	int BucketElemCount[10] = { 0 };
	int n;//����
	int maxLength = 0;//���λ��

	//��������λ��
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


	//ѭ��ÿ����
	for (int i = 0, n = 1; i < maxLength; i++, n *= 10) {
		//ѭ��ÿ������λ��
		//���Ͱ
		for (int j = 0; j < length; j++) {
			//�����Ӧ��nλ������
			int digitofElement;
			digitofElement = arr[j] / n % 10;
			//�ŵ���Ӧλ����Ͱ
			Bucket[digitofElement][BucketElemCount[digitofElement]] = arr[j];
			BucketElemCount[digitofElement]++;
		}
		//ȡ��
		int index = 0;
		//k�����һλ
		for (int k = 0; k < (sizeof(BucketElemCount) / sizeof(BucketElemCount[0])); k++) {
			//���BucketElemCount��������
			if (BucketElemCount[k] != 0) {
				//��ÿ��Ͱ������ȫ������������
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


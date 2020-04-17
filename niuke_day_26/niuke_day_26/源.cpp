#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
using namespace std;
class Arr
{
private:
	int Row;
	int Line;
public:
	void printArr(vector<vector<int>>& arr);
	void prinDiagonal_1(vector<vector<int>>& arr);
	void prinDiagonal_2(vector<vector<int>>& arr);
};
/*void Arr::prinDiagonal_1(vector<vector<int>>& arr)
{

}*/



int main()
{
	int row, line;
	cout << "请输入行" << endl;
	cin >> line;
	cout << "请输入列" << endl;
	cin >> row;
	/*int *p = new int[row*line];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < line; ++j)
		{
			cin >> p[i+j];
		}
	}*/

	istream ::operator>>(vector<vector<int>> dp)


	vector<vector<int>> dp(line, vector<int>(row));//line行row列
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < line; ++j)
		{
			cin >> dp[i + j];
		}
	}

	system("pause");
	return 0;
}






















/*
#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include<opencv2/imgproc/imgproc.hpp>
#include <cmath> 
using namespace cv;
using namespace std;

int main()
{
	double t = 9;
	int rate = 30;//帧率
	Mat src_in;
	VideoCapture cap("1.mp4");
	VideoWriter writer("1_1.avi", CV_FOURCC('M', 'J', 'P', 'G'), rate, Size(854, 480));
	if (!cap.isOpened()) {
		return -1;
	}
	while (1) {
		cap >> src_in;
		Mat src_clone = src_in.clone();

		Mat src = Mat(Size(src_in.cols * 1.0 / t, src_in.rows * 1.0 / t), src.type());
		Mat dst(src_in.size(), src_in.type(), Scalar(255, 255, 255));
		resize(src_in, src, Size(src_in.cols / t, src_in.rows / t), 2);

		string str[10] = { "9","8", "7", "6", "5", "4", "3", "2", "1", "0" };
		cvtColor(src, src, CV_BGR2GRAY);
		blur(src, src, Size(3, 3));
		for (int i = 0; i < src.rows; i++) {
			for (int j = 0; j < src.cols; j++) {
				int c = (int)src.at<uchar>(i, j);
				int b = (int)src_clone.at<Vec3b>(i + i * (t - 1), j + j * (t - 1))[0];
				int g = (int)src_clone.at<Vec3b>(i + i * (t - 1), j + j * (t - 1))[1];
				int r = (int)src_clone.at<Vec3b>(i + i * (t - 1), j + j * (t - 1))[2];
				putText(dst, str[(c * 9) / 255], Point(j + j * (t - 1), i + i * (t - 1)), FONT_HERSHEY_PLAIN,
					0.5, Scalar(b, g, r), 1, 8);

			}
		}
		imshow("效果图", dst);
		writer << dst;

		if (waitKey(rate) >= 0) {
			break;
		}
	}
	return 0;
}
*/

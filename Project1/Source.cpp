#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat mat_and(Mat drawing1, Mat drawing2);
Mat mat_or(Mat drawing1, Mat drawing2);
Mat mat_xor(Mat drawing1, Mat drawing2);
Mat mat_not(Mat drawing1);


int main()
{
	Mat drawing1 = Mat::zeros(Size(400, 200), CV_8UC1);
	Mat drawing2 = Mat::zeros(Size(400, 200), CV_8UC1);

	drawing1(Range(0, drawing1.rows), Range(0, drawing1.cols / 2)) = 255; imshow("drawing1", drawing1);
	drawing2(Range(100, 150), Range(150, 350)) = 255; imshow("drawing2", drawing2);

	Mat res;
	//bitwise_and(drawing1, drawing2, res);     imshow("AND", res);
	//bitwise_or(drawing1, drawing2, res);      imshow("OR", res);
	//bitwise_xor(drawing1, drawing2, res);     imshow("XOR", res);
	//bitwise_not(drawing1, res);              imshow("NOT", res);

	res = mat_and(drawing1,drawing2);
	imshow("AND2", res);
	res = mat_or(drawing1, drawing2);
	imshow("OR2", res);
	res = mat_xor(drawing1, drawing2);
	imshow("XOR2", res);
	res = mat_not(drawing1);
	imshow("OR2", res);
	waitKey(0);
	return(0);
}

Mat mat_and(Mat drawing1, Mat drawing2) {
	int a, b;
	Mat res = Mat::zeros(Size(400, 200), CV_8UC1);
	for (unsigned int i = 0; i < drawing1.rows; i++) {
		for (unsigned int j = 0; j < drawing1.cols; j++) {
			a = ((int)(drawing1.at<uchar>(i, j)));
			b = ((int)(drawing2.at<uchar>(i, j)));
			if (a == 255 && b == 255) {
				res.at<uchar>(i, j) = 255;
			}
			else {
				res.at<uchar>(i, j) = 0;
			}
		}
	}
	return res;
}

Mat mat_or(Mat drawing1, Mat drawing2) {
	int a, b;
	Mat res = Mat::zeros(Size(400, 200), CV_8UC1);
	for (unsigned int i = 0; i < drawing1.rows; i++) {
		for (unsigned int j = 0; j < drawing1.cols; j++) {
			a = ((int)(drawing1.at<uchar>(i, j)));
			b = ((int)(drawing2.at<uchar>(i, j)));
			if (a == 255 && b == 255) {
				res.at<uchar>(i, j) = 255;
			}
			else if (a == 255 || b == 255) {
				res.at<uchar>(i, j) = 255;
			}
			else {
				res.at<uchar>(i, j) = 0;
			}
		}
	}
	return res;
}

Mat mat_xor(Mat drawing1, Mat drawing2) {
	int a, b;
	Mat res = Mat::zeros(Size(400, 200), CV_8UC1);
	for (unsigned int i = 0; i < drawing1.rows; i++) {
		for (unsigned int j = 0; j < drawing1.cols; j++) {
			a = ((int)(drawing1.at<uchar>(i, j)));
			b = ((int)(drawing2.at<uchar>(i, j)));
			if (a == 255 && b == 255) {
				res.at<uchar>(i, j) = 0;
			}
			else if (a == 255 || b == 255) {
				res.at<uchar>(i, j) = 255;
			}
			else {
				res.at<uchar>(i, j) = 0;
			}
		}
	}
	return res;
}

Mat mat_not(Mat drawing1) {
	int a;
	Mat res = Mat::zeros(Size(400, 200), CV_8UC1);
	for (unsigned int i = 0; i < drawing1.rows; i++) {
		for (unsigned int j = 0; j < drawing1.cols; j++) {
			a = ((int)(drawing1.at<uchar>(i, j)));
			if (a == 255) {
				res.at<uchar>(i, j) = 0;
			}
			else {
				res.at<uchar>(i, j) =255;
			}
		}
	}
	return res;
}
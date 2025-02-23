// Visualize2imageSidebySide.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	int totalNumberofImages = 71;
	string imageBasePath = "C:/MultiviewImage/";
	string imagePathOriginal1, imagePathOriginal2;
	//Mat img = imread("C:/MultiviewImage/0-0.jpg");
	//imshow("test Image",img);
	//namedWindow("Image",WINDOW_NORMAL);
	//Mat img2= imread("C:/MultiviewImage/0-1.jpg");

	Mat img1, img2, outImg;
	Mat win_mat(Size(12000, 4000), CV_8UC3); //Creating an empty box to adjust 6000x4000 images

	for (int i = 0; i < totalNumberofImages; i++)
	{
		for (int j = i + 1; j < totalNumberofImages; j++)
		{
			
			imagePathOriginal1 = imageBasePath +"0-"+ to_string(i) + ".jpg";
			imagePathOriginal2 = imageBasePath +"0-" + to_string(j) + ".jpg";
			cout << imagePathOriginal1+" "+ imagePathOriginal2 << endl;
			
			img1 = imread(imagePathOriginal1);
			img2 = imread(imagePathOriginal2);

			img1.copyTo(win_mat(Rect(0, 0, 6000, 4000))); // Original image is 6000x4000
			img2.copyTo(win_mat(Rect(6000, 0, 6000, 4000)));

			resize(win_mat, outImg, Size(win_mat.cols * 0.25, win_mat.rows * 0.25), 0, 0, INTER_LINEAR); // resize the ooutput image
			imwrite("Output/"+to_string(i+1)+"-"+ to_string(j+1)+".jpg", outImg);
		}
	}
	/*
	
	img.copyTo(win_mat(Rect(0, 0, 6000, 4000))); // Original image is 6000x4000
	img2.copyTo(win_mat(Rect(6000, 0, 6000, 4000)));
	//imshow("Combined Image",win_mat);
	*/
	//Mat outImg;
	//resize(win_mat, outImg, Size(win_mat.cols * 0.25, win_mat.rows * 0.25), 0, 0, INTER_LINEAR); // resize the ooutput image
	//imwrite("Gray_Image.jpg", outImg);
	//imshow("Resized Image",outImg);

	waitKey(0);



    return 0;
}


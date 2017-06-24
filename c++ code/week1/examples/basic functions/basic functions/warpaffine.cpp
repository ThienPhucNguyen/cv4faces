#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <cmath>
#include <vector>

int main4()
{
	// read image
	cv::Mat source = cv::imread("../../../../../images/lena.jpg");

	// create 2 warp  matrices for diferent transformations
	cv::Mat warpMat1 = (cv::Mat_<double>(2, 3) << 1.2, 0.2, 2, -0.3, 1.3, 1);
	cv::Mat warpMat2 = (cv::Mat_<double>(2, 3) << 1.2, 0.3, 2, 0.2, 1.3, 1);

	cv::Mat result1, result2;

	// use warp affine
	cv::warpAffine(source, result1, warpMat1, cv::Size(source.cols, source.rows), cv::INTER_LINEAR, cv::BORDER_REFLECT_101);
	cv::warpAffine(source, result2, warpMat2, cv::Size(source.rows, source.cols), cv::INTER_LINEAR, cv::BORDER_REFLECT_101);

	// display image
	cv::imshow("Original", source);
	cv::imshow("Result1", result1);
	cv::imshow("Result2", result2);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
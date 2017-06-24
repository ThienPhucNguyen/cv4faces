#include <opencv2/opencv.hpp>

#include <iostream>
#include <cmath>
#include <vector>

int main5()
{
	// input triangle
	std::vector<cv::Point2f> tri1;
	tri1.push_back(cv::Point2f(50, 50));
	tri1.push_back(cv::Point2f(180, 140));
	tri1.push_back(cv::Point2f(150, 200));

	// output triangle
	std::vector<cv::Point2f> tri2;
	tri2.push_back(cv::Point2f(72, 51));
	tri2.push_back(cv::Point2f(246, 129));
	tri2.push_back(cv::Point2f(222, 216));

	// another output triangle
	std::vector<cv::Point2f> tri3;
	tri3.push_back(cv::Point2f(77, 76));
	tri3.push_back(cv::Point2f(260, 219));
	tri3.push_back(cv::Point2f(242, 291));

	// get the transformation matrices
	cv::Mat warp1 = cv::getAffineTransform(tri1, tri2);
	cv::Mat warp2 = cv::getAffineTransform(tri1, tri3);

	// display the matrices
	std::cout << warp1 << "\n\n\n" << warp2 << "\n";
	return EXIT_SUCCESS;
}
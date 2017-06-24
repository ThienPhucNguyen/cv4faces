#include <opencv2/opencv.hpp>

int main2()
{
	cv::Mat source, scaleDown, scaleUp;

	// read souce image
	source = cv::imread("../../../../../images/lena.jpg");

	// scaling factors
	double scaleX = 0.6;
	double scaleY = 0.6;

	// scaling down the image 0.6 times
	cv::resize(source, scaleDown, cv::Size(), scaleX, scaleY, cv::INTER_LINEAR);
	// scaling up the image 1.8 times
	cv::resize(source, scaleUp, cv::Size(), scaleX * 3, scaleY * 3, cv::INTER_LINEAR);

	// cropped image
	cv::Mat crop = source(cv::Range(50, 150), cv::Range(20, 200));

	// create dsiplay windows for all three images
	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Scale Down", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Scale Up", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Croped Image", cv::WINDOW_AUTOSIZE);

	// show image
	cv::imshow("Original", source);
	cv::imshow("Scale Down", scaleDown);
	cv::imshow("Scale Up", scaleUp);
	cv::imshow("Cropped Image", crop);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
#include <opencv2/opencv.hpp>

int main1() {
	// ead an image in grayscale
	cv::Mat src = cv::imread("../../../../../images/threshold.png", cv::IMREAD_GRAYSCALE);
	cv::Mat dst;

	// set threshold and maximum vlaues
	double thresh = 0;
	double maxValue = 255;

	// binary threshold
	// val > thresh -> val = MaxValue
	// val <= threh -> val = 0
	cv::threshold(src, dst, thresh, maxValue, cv::THRESH_BINARY);

	// display images
	cv::imshow("Original Image", src);
	cv::imshow("Threshold Image", dst);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
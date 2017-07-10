#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <string>

int thresholdValue = 150;
int thresholdType = 3;
int const maxValue = 255;
int const maxType = 4;
int const maxBinaryValue = 255;

cv::Mat img, gray, dst;

std::string windowName = "Threshold Demo";
std::string trackbarType = "Type:\n 0: Binary\n 1: Binary Inverted\n 2: Truncate\n 3: To zero\n 4: To Zero Inverted";
std::string trackbarValue = "Value";

void thresholdDemo(int, void*);

int main()
{
	// load image
	img = cv::imread("../../../../../images/threshold.png", cv::IMREAD_COLOR);

	// convert image to gray
	cv::cvtColor(img, gray, cv::COLOR_RGB2GRAY);

	// create a window to display results
	cv::namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	// create trackbar to choose type of threshold
	cv::createTrackbar(trackbarType, windowName, &thresholdType, maxType, thresholdDemo);
	cv::createTrackbar(trackbarValue, windowName, &thresholdValue, maxValue, thresholdDemo);
	// call he function to initialize
	thresholdDemo(0, 0);
	// wait until user finishes program
	while (true) {
		int c;
		c = cv::waitKey(20);
		if (static_cast<char>(c) == 27) break;
	}
	return EXIT_SUCCESS;
}

void thresholdDemo(int, void*) {
	/*
	0: Binary
	1: Binary Inverted
	2: Threshold Truncated
	3: Threshold to Zero
	4: Threshold to Zero Inverted
	*/
	cv::threshold(gray, dst, thresholdValue, maxBinaryValue, thresholdType);
	cv::imshow(windowName, dst);
}
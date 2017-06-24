#include <opencv2/opencv.hpp>

int main1()
{
	// read image
	cv::Mat image = cv::imread("../../../../../images/lena.jpg", cv::IMREAD_ANYCOLOR);

	// check for invalid input
	if (image.empty()) {
		std::cout << "Coutld not open or find image\n";
		return EXIT_FAILURE;
	}

	// convert color image to gray
	cv::Mat grayImage;
	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

	// create a window for display
	cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("Gray Image", CV_WINDOW_NORMAL);

	// display image
	cv::imshow("Image", image);
	cv::imshow("Gray Image", grayImage);

	// wait for a keystroke in the window
	cv::waitKey(0);

	return EXIT_SUCCESS;
}
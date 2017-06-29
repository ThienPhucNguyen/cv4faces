#include <opencv2/opencv.hpp>

#include <iostream>

int main2() {
	// read image in and store in cv::Mat image
	cv::Mat image = cv::imread("../../../../../images/truth.png", cv::IMREAD_COLOR);

	// create a structuring element
	int dilationSize = 6;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_CROSS,
		cv::Size(2 * dilationSize + 1, 2 * dilationSize + 1),
		cv::Point(dilationSize, dilationSize));

	// dilated image stored in cv::Mat
	cv::Mat dilatedImage;

	// dilation will increase brightness
	cv::dilate(image, dilatedImage, element);

	// display images
	cv::imshow("Original Image", image);
	cv::imshow("Dilated Image", dilatedImage);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
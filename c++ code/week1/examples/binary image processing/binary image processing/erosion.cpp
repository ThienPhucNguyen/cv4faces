#include <opencv2/opencv.hpp>

int main3() {
	cv::Mat image = cv::imread("../../../../../images/truth.png", cv::IMREAD_COLOR);

	int erosionSize = 6;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_CROSS,
		cv::Size(2 * erosionSize + 1, 2 * erosionSize + 1),
		cv::Point(erosionSize, erosionSize));

	cv::Mat erodedImage;
	cv::erode(image, erodedImage, element);

	cv::imshow("Original Image", image);
	cv::imshow("Eroded Image", erodedImage);

	cv::waitKey(0);
	return EXIT_SUCCESS;
}
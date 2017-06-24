#include <opencv2/opencv.hpp>

int main3() {
	cv::Mat source, M, result;
	// read image
	source = cv::imread("../../../../../images/lena.jpg", cv::IMREAD_COLOR);

	cv::Point2f center((source.cols / 2.0), (1.0 * source.rows / 2.0));
	double rotationAngle = 30;
	double scale = 1;

	// getting the matrix which will define the rotation
	M = cv::getRotationMatrix2D(center, rotationAngle, scale);

	// rotate the source and store in result
	cv::warpAffine(source, result, M, cv::Size(source.cols, source.rows));

	// create windows to display
	cv::namedWindow("Original Image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Rotated Image", cv::WINDOW_AUTOSIZE);

	// display images
	cv::imshow("Original Image", source);
	cv::imshow("Rotated Image", result);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
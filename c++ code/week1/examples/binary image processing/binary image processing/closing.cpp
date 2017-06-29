#include <opencv2/opencv.hpp>

int main()
{
	// read image
	cv::Mat image = cv::imread("../../../../../images/closing.png", cv::IMREAD_GRAYSCALE);

	// initialize number of iteration
	int iterations = 1;

	// create a structuring kernel
	int closingSize = 10;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE, 
		cv::Size(2 * closingSize + 1, 2 * closingSize + 1), 
		cv::Point(closingSize, closingSize));

	// apply morphological closing
	cv::Mat morphClosedImage;
	cv::morphologyEx(image, morphClosedImage, cv::MORPH_CLOSE, element, cv::Point(-1, -1), iterations);

	// display images
	cv::imshow("Original Image", image);
	cv::imshow("Closing Image", morphClosedImage);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
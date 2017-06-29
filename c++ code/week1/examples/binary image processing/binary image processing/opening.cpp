#include <opencv2/opencv.hpp>

int main4()
{
	// read image
	cv::Mat image = cv::imread("../../../../../images/opening.png", cv::IMREAD_GRAYSCALE);

	// initialize number of iterations
	int iterations = 3;

	// create struturing element
	int openingSize = 3;
	cv::Mat element = cv::getStructuringElement(cv::MORPH_ELLIPSE,
		cv::Size(2 * openingSize + 1, 2 * openingSize + 1),
		cv::Point(openingSize, openingSize));

	// apply morphological opening
	cv::Mat morphOpenedImage;
	cv::morphologyEx(image, morphOpenedImage, cv::MORPH_OPEN, element, cv::Point(-1, -1), iterations);

	// display images
	cv::imshow("Original Image", image);
	cv::imshow("Opening Image", morphOpenedImage);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}
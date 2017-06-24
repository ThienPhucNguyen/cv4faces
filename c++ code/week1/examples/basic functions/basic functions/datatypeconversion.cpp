#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat source;

	// scale will convert pixel values
	double scale = 1 / 255.0;
	double shift = 0;

	// read image
	source = cv::imread("../../../../../images/lena.jpg");

	// convert from usigned char to float-32 bit
	source.convertTo(source, CV_32FC3, scale, shift);

	// convert from float to unsigned char
	source.convertTo(source, CV_8UC3, 1.0 / scale, shift);

	return EXIT_SUCCESS;
}
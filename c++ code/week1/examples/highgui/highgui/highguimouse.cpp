#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <vector>
#include <cmath>

// points to store the center of the circle and a point on the circumference
cv::Point center, circumference;
// source image
cv::Mat source;

// function which will be called on mouse input
void drawCircle(int action, int x, int y, int flags, void *userdata) {
	// action to be taken when left mouse button is pressed
	if (action == cv::EVENT_LBUTTONDOWN) {
		center = cv::Point(x, y);
		// mark the center
		cv::circle(source, center, 1, cv::Scalar(255, 255, 0), 2, CV_AA);
	}
	// action to be taken when left mouse button is released
	else if (action == cv::EVENT_LBUTTONUP) {
		circumference = cv::Point(x, y);
		// calculate radius of the circle
		float radius = std::sqrt(std::pow(center.x - circumference.x, 2) + std::pow(center.y - circumference.y, 2));
		// draw the circle
		cv::circle(source, center, radius, cv::Scalar(0, 255, 0), 2, CV_AA);
		cv::imshow("Image", source);
	}
}

int main2() {
	source = cv::imread("../../../../../images/lena.jpg", 1);
	// make a dummy image, will be useful to clear the drawing
	cv::Mat dummy = source.clone();
	cv::namedWindow("Window");
	// highgui function called when mouse events occur
	cv::setMouseCallback("Window", drawCircle);
	int k = 0;
	// loop until escape character is pressed
	while (k != 27) {
		cv::imshow("Window", source);
		cv::putText(source, "Choose center, and drag, Press ESC to exit and c to clear", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(255, 255, 255), 2);
		k = cv::waitKey(20) & 0xFF;
		if (k == 99) dummy.copyTo(source);
	}
	return EXIT_SUCCESS;
}
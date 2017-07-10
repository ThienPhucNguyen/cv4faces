#include <opencv2/videoio/videoio.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

int main1() {
	// open webcam
	cv::VideoCapture cap(0);

	cv::Mat frame;
	int k = 0;

	// detect of webcam is working properly
	if (!cap.isOpened()) {
		std::cout << "Unable to detect webcam\n";
		return EXIT_FAILURE;
	}
	
	while (1) {
		// capture frame
		cap >> frame;

		if (k == 27) break;

		// identify if 'e' or 'E' is pressed
		if (k == 101 || k == 69) {
			cv::putText(frame, "E is pressed, press Z or ESC", cv::Point(100, 180), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 3);
		}
		if (k == 90 || k == 122) {
			cv::putText(frame, "Z is pressed", cv::Point(100, 180), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 255, 0), 3);
		}
		
		cv::imshow("Image", frame);

		// waitKey is increased so the the display is shown
		k = cv::waitKey(10000) & 0xFF;
	}
	return EXIT_SUCCESS;
}
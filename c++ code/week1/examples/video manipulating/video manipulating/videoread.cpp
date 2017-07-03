#include <opencv2/opencv.hpp>

int main1() {
	// create a VideoCapture objet and open the input file
	// if the input is the web camera, pass 0 instead of the video file name
	cv::VideoCapture cap("../../../../../videos/chaplin.mp4");

	// check if camera opened successfully and read a frame from the object cap
	if (!cap.isOpened()) {
		std::cout << "Error opening video stream or file\n";
		return EXIT_FAILURE;
	}

	while (1) {
		cv::Mat frame;

		// capture frame by frame
		cap >> frame;

		// if the frame is empty, break immediately
		if (frame.empty()) break;

		// display the resulting frame
		cv::imshow("Frame", frame);

		// press ESC on keyboard to exit
		char c = (char)cv::waitKey(25);

		if (c == 27) break;
	}

	// when everything done, release the video capture object
	cap.release();

	// close all the frames
	cv::destroyAllWindows();

	return EXIT_SUCCESS;
}
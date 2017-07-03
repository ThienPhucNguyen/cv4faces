#include <opencv2/opencv.hpp>

int main() {
	// create a VideoCapture object and use camera to capture the video
	cv::VideoCapture cap(0);

	// check if camera opened successfully
	if (!cap.isOpened()) {
		std::cout << "Error opening video stream\n";
		return EXIT_FAILURE;
	}

	// default resolution of the frame are obtained. The default resolutions system dependent.
	int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	// define the codec and create VideoWriter object. The output is stored in 'output.avi' file.
	cv::VideoWriter video("output.avi", CV_FOURCC('M', 'J', 'P', 'G'), 10, cv::Size(frame_width, frame_height));

	// read and save the feed from webcam until ESC is pressed.
	while (1) {
		cv::Mat frame;

		// capture frame by frame
		cap >> frame;

		// if the frame is empty, break immediately
		if (frame.empty()) break;

		// write the frame into the file 'output.avi'
		video.write(frame);

		// display the frame
		cv::imshow("Frame", frame);

		// press ESC to exit
		char c = (char)cv::waitKey(1);
		if (c == 27) break;
	}

	// when everything is done, release the video capture object
	cap.release();
	video.release();

	// close all the frames
	cv::destroyAllWindows();

	return EXIT_SUCCESS;
}
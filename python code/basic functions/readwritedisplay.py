import cv2

image = cv2.imread("../../images/lena.jpg")

# check for invalid input
if image is None:
    print("Could not open or find the image")

# convert color image to gray
grayImage = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# save result
cv2.imwrite("imageGray.jpg", grayImage)

# create a window for display
cv2.namedWindow("Image", cv2.WINDOW_AUTOSIZE)
cv2.namedWindow("Gray Image", cv2.WINDOW_NORMAL)

# display image
cv2.imshow("Image", image)
cv2.imshow("Gray Image", grayImage)

# wait for a keystroke in window
cv2.waitKey(0)

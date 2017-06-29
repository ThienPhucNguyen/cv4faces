import cv2

# read an image in grayscale
src = cv2.imread("../../images/threshold.png", cv2.IMREAD_GRAYSCALE)

# set threshold and maximum value
thresh = 0
maxValue = 255

# binary threshold
th, dst = cv2.threshold(src=src, thresh=thresh, maxval=maxValue, type=cv2.THRESH_BINARY)

# display images
cv2.imshow("Original Image", src)
cv2.imshow("Thresholded Image", dst)

cv2.waitKey(0)

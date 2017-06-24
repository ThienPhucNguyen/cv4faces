import cv2

# reading the image
source = cv2.imread("../../images/lena.jpg", flags=1)

scaleX = 0.6
scaleY = 0.6

# scaling down the image 0.6 times
scaleDown = cv2.resize(source, None, fx=scaleX, fy=scaleY, interpolation=cv2.INTER_LINEAR)

# scaling up the image 1.8 times
scaleUp = cv2.resize(source, None, fx=scaleY * 3, fy=scaleY * 3, interpolation=cv2.INTER_LINEAR)

# crop image
crop = source[50:150, 20:200]

# display all the images
cv2.imshow("Original", source)
cv2.imshow("Scaled Down", scaleDown)
cv2.imshow("Scaled Up", scaleUp)
cv2.imshow("Cropped Image", crop)

cv2.waitKey(0)

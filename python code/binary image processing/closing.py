import cv2

# read image
image = cv2.imread("../../images/closing.png", cv2.IMREAD_GRAYSCALE)

# initialize number of iteration
iterations = 1

# get structuring kernel
closingSize = 10
element = cv2.getStructuringElement(shape=cv2.MORPH_ELLIPSE,
                                    ksize=(2 * closingSize + 1, 2 * closingSize + 1),
                                    anchor=(closingSize, closingSize))

# apply morphological closing
morphClosingImage = cv2.morphologyEx(src=image, op=cv2.MORPH_CLOSE, kernel=element, iterations=iterations)

# display images
cv2.imshow("Original Image", image)
cv2.imshow("Closing Image", morphClosingImage)

cv2.waitKey(0)

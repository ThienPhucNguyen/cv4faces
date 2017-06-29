import cv2

# read image
image = cv2.imread("../../images/truth.png", cv2.IMREAD_COLOR)

# get structuring kernel which used for erosion
erosionSize = 6
element = cv2.getStructuringElement(shape=cv2.MORPH_CROSS,
                                    ksize=(2 * erosionSize + 1, 2 * erosionSize + 1),
                                    anchor=(erosionSize, erosionSize))

# erode the image
erodedImage = cv2.erode(src=image, kernel=element)

# display image
cv2.imshow("Original Image", image)
cv2.imshow("Eroded Image", erodedImage)

cv2.waitKey(0)

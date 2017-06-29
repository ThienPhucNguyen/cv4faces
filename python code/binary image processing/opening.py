import cv2

# read image
image = cv2.imread("../../images/opening.png", cv2.IMREAD_GRAYSCALE)

# initialize number of iteration
iterations = 3

# get structuring kernel
openingSize = 3
element = cv2.getStructuringElement(shape=cv2.MORPH_ELLIPSE,
                                    ksize=(2 * openingSize + 1, 2 * openingSize + 1),
                                    anchor=(openingSize, openingSize))

# apply morphological opening
morphOpenedImage = cv2.morphologyEx(src=image,
                                    op=cv2.MORPH_OPEN,
                                    kernel=element,
                                    iterations=3)

# display images
cv2.imshow("Original Image", image)
cv2.imshow("Opening Image", morphOpenedImage)

cv2.waitKey(0)

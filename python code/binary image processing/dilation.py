import cv2

# read image
image = cv2.imread("../../images/truth.png", cv2.IMREAD_COLOR)

# check for invalid input
if image is None:
    print("Could not open or find image")

# get structuring kernel which used for in dilation
dilationSize = 6
element = cv2.getStructuringElement(shape=cv2.MORPH_CROSS,
                                    ksize=(2 * dilationSize + 1, 2 * dilationSize + 1),
                                    anchor=(dilationSize, dilationSize))


# dilating the image
dilatedImage = cv2.dilate(src=image, kernel=element)

# display images
cv2.imshow("Original Image", image)
cv2.imshow("Dilated Image", dilatedImage)

cv2.waitKey(0)

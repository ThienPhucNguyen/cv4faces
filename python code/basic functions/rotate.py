import cv2

# read image
source = cv2.imread("../../images/lena.jpg", flags=1)

# get the dimensions of the image
dim = source.shape

rotationAngle = 180
scaleFactor = 1

# rotate the image by 90 degrees about the center
# dim[0] stores the number of rows and dim[1] stores the number of columns
rotationMatrix = cv2.getRotationMatrix2D((dim[1] / 2, dim[0] / 2), rotationAngle, scaleFactor)

result = cv2.warpAffine(source, rotationMatrix, (dim[1], dim[0]))

# show images
cv2.imshow("Original", source)
cv2.imshow("Rotated Image", result)

cv2.waitKey(0)

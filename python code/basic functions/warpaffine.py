import cv2
import numpy as np

# read image
source = cv2.imread("../../images/lena.jpg", flags=1)

# create 2 warp matrices / masks for different transformations
warpMat1 = np.float32([[1.2, 0.2, 2], [-0.3, 1.3, 1]])
warpMat2 = np.float32([[1.2, 0.3, 2], [0.2, 1.3, 1]])

# use warp affine
dim = source.shape

result1 = cv2.warpAffine(source, warpMat1, (int(1.5 * dim[0]), int(1.4 * dim[1])),
                         None, flags=cv2.INTER_LINEAR, borderMode=cv2.BORDER_REFLECT_101)

result2 = cv2.warpAffine(source, warpMat2, (int(1.5 * dim[0]), int(1.4 * dim[1])),
                         None, flags=cv2.INTER_LINEAR, borderMode=cv2.BORDER_REFLECT_101)

# display images
cv2.imshow("Original", source)
cv2.imshow("Result1", result1)
cv2.imshow("Result2", result2)

cv2.waitKey(0)

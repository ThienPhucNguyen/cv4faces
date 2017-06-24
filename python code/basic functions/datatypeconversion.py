import cv2
import numpy as np

# read image
source = cv2.imread("../../images/lena.jpg", flags=1)

scalingFactor = 1 / 255.0

# convert unsigned int to float
source = np.float32(source)
source = source * scalingFactor

# convert back to unsigned int
source = source * (1.0 / scalingFactor)
source = np.uint8(source)
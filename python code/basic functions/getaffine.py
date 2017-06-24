import cv2
import numpy as np

# input triangle
inp = np.float32([[50, 50], [180, 140], [150, 200]])

# output triangle
output1 = np.float32([[72, 51], [246, 129], [222, 216]])

# another output
output2 = np.float32([[77, 76], [260, 219], [242, 291]])

# get the transformation matrices
warpMat1 = cv2.getAffineTransform(inp, output1)
warpMat2 = cv2.getAffineTransform(inp, output2)

# display the matrices
print(warpMat1, '\n\n', warpMat2)
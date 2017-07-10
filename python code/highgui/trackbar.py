import cv2

thresholdValue = 200
thresholdType = 3
maxValue = 255
maxType = 4
maxBinaryValue = 255

windowName = "Threshold Demo"
trackbatType = "Type:​\n ​0: Binary​\n​ 1: Binary Inverted​\n ​2: Truncate\n ​3: To Zero​\n​ 4: To Zero Inverted"
trackbarValue = "Value"
# call the function to initialize
# 0: Binary
# 1: Binary Inverted
# 2: Threshold Truncated
# 3: Threshold to zero
# 4: Threshold to inverted

# load image
gray = cv2.imread('../../images/threshold.png', cv2.IMREAD_GRAYSCALE)

# create a window to display results
cv2.namedWindow(windowName, cv2.WINDOW_AUTOSIZE)

def thresholdTypeDemo(*args):
    global thresholdType
    thresholdType = args[0]
    thresh, result = cv2.threshold(gray, thresholdValue, maxBinaryValue, thresholdType)
    cv2.imshow(windowName, result)

def thresholdValueDemo(*args):
    global thresholdValue
    thresholdValue = args[0]
    thresh, result = cv2.threshold(gray, thresholdValue, maxBinaryValue, thresholdType)
    cv2.imshow(windowName, result)

# create trackbar to choos type of threshold
cv2.createTrackbar(trackbatType,
                   windowName,
                   thresholdType,
                   maxType,
                   thresholdTypeDemo)

cv2.createTrackbar(trackbarValue,
                   windowName,
                   thresholdValue,
                   maxValue,
                   thresholdValueDemo)

thresholdTypeDemo(0)

thresholdValueDemo(0)

#  wait until user finishes program
while True:
    c = cv2.waitKey(20)
    if c == 27:
        break

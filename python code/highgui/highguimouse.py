import cv2
import math

# lists to store points
center = []
circumference = []

def drawCircle(action, x, y, flags, userdata):
    # referencing global variables
    global center, circumference

    # action to be taken when left mouse button is pressed
    if action == cv2.EVENT_LBUTTONDOWN:
        center = [(x, y)]
        # mark the center
        cv2.circle(source,
                   center[0],
                   1,
                   (0, 255, 0),
                   2,
                   cv2.LINE_AA)

    # action to be taken when left mouse button is released
    if action == cv2.EVENT_LBUTTONUP:
        circumference = [(x, y)]
        # calculate radius of circle
        radius = math.sqrt(math.pow(center[0][0] - circumference[0][0], 2) +
                           math.pow(center[0][1] - circumference[0][1], 2))
        # draw circle
        cv2.circle(source,
                   center[0],
                   int(radius),
                   (0, 255, 0),
                   2,
                   cv2.LINE_AA)

    cv2.imshow("Window", source)

source = cv2.imread("../../images/lena.jpg", 1)

# make dummy image, will be useful t clear the drawing
dummy = source.copy()
cv2.namedWindow("Window")

# high-gui function called when mouse event occur
cv2.setMouseCallback("Window", drawCircle)

k = 0

# loop until escape character is pressed
while k != 27:
    cv2.imshow("Window", source)
    cv2.putText(source,
                'Choose center and drag, Press ESC to exit and c to clear',
                (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX,
                0.7,
                (255, 255, 255),
                2)
    k = cv2.waitKey(20) & 0xFF
    # another way to cloning
    if k == 99:
        source = dummy.copy()

cv2.destroyAllWindows()

import cv2

# opencv webcam
cap = cv2.VideoCapture(0)

k = 0

while True:
    # read frame
    ret, frame = cap.read()

    # identify if 'ESC' is pressed
    if k == 27:
        break

    # identify if 'e' or 'E' is pressed
    if k == 101 or k == 69:
        cv2.putText(frame,
                    'E is pressed, press Z or ESC',
                    (100, 180),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    1,
                    (0, 255, 0),
                    3)

    # identify if 'z' or 'Z' is pressed
    if k == 90 or k == 122:
        cv2.putText(frame,
                    'Z is pressed',
                    (100, 180),
                    cv2.FONT_HERSHEY_SIMPLEX,
                    1,
                    (0, 255, 0),
                    3)

    cv2.imshow("Image", frame)

    # increase waitkey to show display properly
    k = cv2.waitKey(10000) & 0xFF

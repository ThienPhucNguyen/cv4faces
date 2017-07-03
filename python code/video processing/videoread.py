import cv2

# create a VideoCapture object open the input file
# if the input is the web camera, pass 0 instead of the video file name
cap = cv2.VideoCapture('../../videos/chaplin.mp4')
# check if camera opened successfully
if not cap.isOpened():
    print("Error opening video stream or file")

while cap.isOpened():
    # capture frame by frame
    ret, frame = cap.read()
    if ret:
        # display the result
        cv2.imshow('Frame', frame)
        # press ESC to exit
        if cv2.waitKey(25) & 0xFF == 27:
            break
    # break the loop
    else:
        break

# when everything done, release the video capture object
cap.release()

# close all frames
cv2.destroyAllWindows()

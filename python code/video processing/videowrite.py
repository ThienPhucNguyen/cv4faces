import cv2

# create a VideoCapture object
cap = cv2.VideoCapture(0)

# check if camera opened successfully
if not cap.isOpened():
    print("Unable to read camera feed")

# default resolution of frame are obtained.
# the default resolution are system dependent.
# convert the resolution from float to integer.
frame_width = int(cap.get(3))
frame_height = int(cap.get(4))

# define the codec and create VideoWrite object
# store in 'output.avi' file
out = cv2.VideoWriter('output.avi',
                      cv2.VideoWriter_fourcc('M', 'J', 'P', 'G'),
                      10,
                      (frame_width, frame_height))

while True:
    ret, frame = cap.read()
    if ret:
        # write the frame to 'output.avi'
        out.write(frame)
        # display the result
        cv2.imshow('Frame', frame)
        if cv2.waitKey(25) & 0xFF == 27:
            break
    # break the loop
    else:
        break

# when everything is done, release video capture object
cap.release()
out.release()

# close all the windows
cv2.destroyAllWindows()

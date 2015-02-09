This method uses a MSER and template matching with Normalized Cross Correlation to find the best location. 
Output: Prints center of detected location.
I wrote all the code on my MAC OSX 10.9.5 using XCODE(6.0.1), OpenCV(2.4.9), cmake(3.0.2) 

How to run
1) Go into folder where main.cpp is present
2) Type : cmake .
3) Type : make
4) Run one of the following commands

**** To load a video *****
./main "robotX.mov" "cross.jpg”
./main "robotX.mov" "triangle.jpg"
./main "robotX.mov" "circle.jpg"

**** To access the camera *****
./main “camera” "cross.jpg”
./main “camera” "triangle.jpg"
./main “camera” "circle.jpg"

Note:
1) There are various other images of triangles and crosses that could be used but don’t give good results.
2) The circle image used as the template in this method is different from the one used in standard template matching. The reason is MSER extracts the region with very little background. The circle in MSER has very little white boundary compared to the circle used for standard template matching. Same for triangle template and cross template
3) The code might need some refinement based on the new data
4) If the camera part doesn’t run, you might have to change line 46. For my mac, the webcam was located at 0, but other cameras could be at 1,2,3 etc

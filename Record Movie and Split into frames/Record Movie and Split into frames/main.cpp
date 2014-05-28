//
//  main.cpp
//  Record Movie and Split into frames
//
//  Created by Jason Rebello on 5/27/14.
//  Copyright (c) 2014 Jason Rebello. All rights reserved.
//

#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <vector>
#include <sstream>

using namespace cv;
using namespace std;


// Record Video from camera
// Eg. If you want to save videos such as Temp1.avi, Temp2.avi etc. Change num everytime you start and stop. Num = 1; Click start, Once finished click stop. Change number to 2 and repeat
int main(int argc, const char* argv[])
{
    static int num = 1;  // <--- Change this number each time you record a new video
    int recording = 1; // This should be set to 1 to record. If 0 it displays the video in a window
    VideoCapture cap(0); // <--- Check where camera is connected
    
    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "ERROR: Cannot open the video file" << endl;
        return -1;
    }
    
    double fwidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double fheight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    
    Size frameSize(static_cast<int>(fwidth), static_cast<int>(fheight));
    
    string dir("****** Path where your executable is located + create a folder to save videos ****");
    stringstream stm;
    stm << "*** name of video you want to save ***" << num << ".avi";
    
    string path;
    path = dir+stm.str();
    
    VideoWriter oVideoWriter(path, CV_FOURCC('P','I','M','1'), 30, frameSize, true);
    
    if ( !oVideoWriter.isOpened() ) //if not initialize the VideoWriter successfully, exit the program
    {
        cout << "ERROR: Failed to write the video" << endl;
        return -1;
    }
    
    int start = 0; // To indiacate start of experiment. When start is displayed recording has started
    int readFlag = 0;

    while(1)
    {
        Mat frame;
        
        if(start==0) // Started recording
        {
            cout << "Start" << endl;
            start = 1;
        }
        
        bool suc0 = cap.read(frame);
        
        if(!suc0)
            cout << "Could not read 0";
        
        if(recording == 1)
        {
            oVideoWriter.write(frame);
        }
        else
            imshow("Video",frame);
        
    }
    return 0;
}


/*
// Split Video into frames
// This part takes in the list of videos recorded in the earlier part. Creates a filder with the same name as each video name and splits the videos into frames.
int main(int argc, const char * argv[])
{
    string location("*** Path to Executable ***")dir,temp;
    stringstream stm,tmp,loc;
    int flag=1,count = 1;;
    
    for(int i=1; i<=n; i++) // Change 'n' to the number of videos recorded.
    {
        
        // Create a folder for each block
        stm << "*** Folder name ****" << i;
        dir = "mkdir " + stm.str();
        system(dir.c_str());
        
        // Read in the particular Video
        tmp << "*** Folder Name/File Name ***" << i << ".avi";
        VideoCapture cap(tmp.str());
        
        // Check if video has successfully opened
        if (!cap.isOpened())
        {
            cout << "ERROR: Cannot open the video file" << endl;
            return -1;
        }
        
        cout << stm.str();
        vector<int> compression_patterns;
        compression_patterns.push_back(CV_IMWRITE_JPEG_QUALITY);
        compression_patterns.push_back(98);
        
        // Read in a single frame from video
        while(1)
        {
            Mat frame;
            
            bool bSuccess = cap.read(frame); // read a new frame from video
            if (!bSuccess) //if not success, break loop
            {
                cout << " Video Ended with " << endl;
                break;
            }
            
            loc << location << stm.str() << "/" << count << stm.str() << ".jpg";
            temp = loc.str();
            
            bool wSuccess = imwrite(temp,frame);
            if(!wSuccess)
            {
                cout << "Error could not write file" << endl;
                return -1;
            }
            count++;
            loc.str("");
            waitKey(300);
        }
        cout << count << " frames" << endl;
        count = 1;
        tmp.str("");
        stm.str("");
        dir = "";
        temp = "";
    }
    
    return 0;
}
*/

//
//  HOG_ppl_detection.cpp
//  opencv_proj
//
//  Created by Younghoon Ji on 3/26/19.
//  Copyright © 2019 Younghoon Ji. All rights reserved.
//


#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace cv::ml;

int flag_sel = 0;
Point selection;
int cnt_file_num = 1;
string File_name;

static void CallBackFunc( int event, int x, int y, int, void* )
{
    switch( event )
    {
        case EVENT_LBUTTONDOWN:
            printf("DOWN\n");
            flag_sel = 1;
            selection.x = x;
            selection.y = y;
            break;
    }
}

int main(int argc, const char * argv[]) {

    cout << "Opencv Version : " << CV_VERSION << endl;
    cout << "Major Version : " << CV_MAJOR_VERSION << endl;
    cout << "Minor Version : " << CV_MINOR_VERSION << endl;
    cout << "Subminor Version : " << CV_SUBMINOR_VERSION << endl;
    
    /// Create a videoreader interface
    //VideoCapture cap("tracking_sample.mp4");
    //VideoCapture cap("sample1.mov");
    VideoCapture cap("sample4.mov");
    
    Mat current_frame;
    
    namedWindow("detected person", 0);
    setMouseCallback("detected person", CallBackFunc, 0);
    
    /// Set up the pedestrian detector --> let us take the default one
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());

        
    while(true){
        /// Grab a single frame from the video
        cap >> current_frame;
        
        /// Check if the frame has content
        if(current_frame.empty()){
            cerr << "Video has ended or bad frame was read. Quitting." << endl;
            return 0;
        }
        
        
        /// run the detector with default parameters. to get a higher hit-rate
        /// (and more false alarms, respectively), decrease the hitThreshold and
        /// groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
            
        ///image, vector of rectangles, hit threshold, win stride, padding, scale, group th
        Mat img = current_frame.clone();
        //resize(img,img,Size(img.cols*1.5, img.rows*1.5));
        resize(img,img,Size(img.cols*0.9, img.rows*0.9));
        
        
        //save the cropped image
        Mat cropped;
        Mat clone_cropped = img.clone();
        
        vector<Rect> found;
        vector<double> weights;
        
        //output the objects found and number of objects in vector
        hog.detectMultiScale(img, found, weights);

        
        /// draw detections and store location
        for( size_t i = 0; i < found.size(); i++ )
        {
            Rect r = found[i];
            rectangle(img, found[i], cv::Scalar(0,255,0), 1);
            stringstream temp;
            temp << weights[i];
            putText(img, temp.str(),Point(found[i].x,found[i].y+50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0,0,255));
        }
        
        //save the selected person
        if(flag_sel == 1 && (found.size() >= 1)){
            for(int j = 0; j < found.size(); j++){
                
                if(selection.x >= found[j].x &&
                   selection.x <= found[j].x + found[j].width){
                    if(selection.y >= found[j].y &&
                       selection.y <= found[j].y + found[j].height){
                        
                        //found array stores the data rectangle
                        printf("ready2crop\n");
                        
                        rectangle(img, found[j], cv::Scalar(255,0,0), 1);
                        cropped = clone_cropped(found[j]);
                        
                        File_name = "img" + to_string(cnt_file_num) + ".jpg";
                        imwrite(File_name, cropped);
                        cnt_file_num++;
                        
                        flag_sel = 0;

                        break;
                    }
                }
            }
        }
        else
            flag_sel = 0;
        
        //print the number of ppl on screen
        string numDetection = to_string(found.size());
        putText(img, numDetection,Point(img.cols/10 * 9, img.rows/10 * 1), FONT_HERSHEY_SIMPLEX, 3, Scalar(0,0,0));
        //cout << numDetection << endl;
        
        /// Show
        imshow("detected person", img);
        
        waitKey(1);
        }
    
    return 0;
}

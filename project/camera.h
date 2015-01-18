#ifndef CAMERA_H
#define CAMERA_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <ctime>
#include <iostream>
using namespace std;
using namespace cv;

class Camera
{
public:
    //declare all variables
    bool debugMode;
    bool trackingEnabled;
    bool recording;
    bool startNewRecording;
    bool firstRun;
    bool pause;
    bool running;
    double dWidth;
    double dHeight;
    Mat frame1,frame2;
    Mat grayImage1,grayImage2;
    Mat differenceImage;
    Mat thresholdImage;
    VideoCapture capture;

    Camera();

    //int to string helper function
    string intToString (int number);
    //Return true if motion is detected
    bool detectMotion(Mat thresholdImage);
    //Time functions for time stamp and file name, returns current date and time
    string getTime ();
    string getTimeforFIle ();
    //functions to open extra video feeds
    void debug (bool &db);
    void debug2 (bool &db);
    //waits for key pressed
    void input();
    //run main program
    void run();

private:
    const static int SENSITIVITY_VALUE = 40;
    const static int BLUR_SIZE = 10;

};

#endif // CAMERA_H

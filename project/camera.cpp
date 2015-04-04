#include "camera.h"

Camera::Camera() : recording (false), startNewRecording (false),firstRun (true),pause (false),
    debugMode (false), trackingEnabled(true),running(true){
    cout<<"Motion activated camera recorder\n\t";
    cout<<"Options:\n\t\td\topens threshold, differentiated and blurred video feed\n\t\tn\twrite to new video file\n\t\tp\tpause video\n\t\tesc\texit\n\n";
}

string Camera::intToString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}

bool Camera::detectMotion(Mat thresholdImage){
    bool motionDetected = false;
    Mat temp;
    thresholdImage.copyTo(temp);
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(temp,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );
    if(contours.size()>0)motionDetected=true;
    else motionDetected = false;
    return motionDetected;
}

string Camera::getTime () {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer[80];
      time (&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
      string str(buffer);
      return str;
}

string Camera::getTimeforFIle () {
      time_t rawtime;
      struct tm * timeinfo;
      char buffer[80];
      time (&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(buffer,80,"%d_%m_%Y_%I_%M_%S",timeinfo);
      string str(buffer);
      return str;
}

void Camera::debug (bool &db){
    if(debugMode==true){
        imshow("Difference feed",differenceImage);
        imshow("Threshold feed", thresholdImage);
        db=true;
    }else if (!debugMode && db){
        destroyWindow("Difference feed");
        destroyWindow("Threshold feed");

    }
}
void Camera::debug2 (bool &db)  {
    if(debugMode==true){
        imshow("Blurred threshold feed",thresholdImage);
        db=true;

    }
    else if (!debugMode && db){
        destroyWindow("Blurred threshold feed");
    }
}
void Camera::input (){
    switch(waitKey(30)){
    case 27: //'esc'
        running=false;

    case 100: //'d'
        debugMode = !debugMode;
        if(debugMode == false) cout<<"Debug mode disabled."<<endl;
        else cout<<"Debug mode enabled."<<endl;
        break;
    case 112: //'p'
        pause = !pause;
        if(pause == true){ cout<<"Code paused, press 'p' again to resume"<<endl;
            while (pause == true){
                switch (waitKey()){
                case 112:
                    pause = false;
                    cout<<"Code Resumed"<<endl;
                    break;
                }
            }
        }

    case 110: //'n'
        startNewRecording = true;
        recording = true;
        cout << "New Recording Started" << endl;
        break;

    }
}
void Camera::run(){
    capture.open(0);
    VideoWriter oVideoWriter;
    dWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
    dHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
    Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

    if(!capture.isOpened()){
        cout<<"ERROR ACQUIRING VIDEO FEED\n";
        getchar();
        return;
    }
    bool db=false;

    while(running){
        capture.read(frame1);
        cvtColor(frame1,grayImage1,COLOR_BGR2GRAY);
        capture.read(frame2);
        cvtColor(frame2,grayImage2,COLOR_BGR2GRAY);
        absdiff(grayImage1,grayImage2,differenceImage);
        threshold(differenceImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);
        debug (db);
        blur(thresholdImage,thresholdImage,cv::Size(BLUR_SIZE,BLUR_SIZE));
        threshold(thresholdImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);
        debug2(db);

        rectangle(frame1,Rect(0,468,190,20),Scalar(255,255,255),-1);
        putText(frame1,getTime(),Point(0,480),1,1,Scalar(0,0,0));

        if(recording){
            if(firstRun == true || startNewRecording == true){
                string videoFileName=getTimeforFIle()+".avi";
                cout << "File opened for writing: " << videoFileName<<endl;
                cout << "Resolution: " << dWidth << "x" << dHeight << endl;
                oVideoWriter  = VideoWriter(videoFileName, CV_FOURCC('D', 'I', 'V', '3'), 20, frameSize, true);
                if ( !oVideoWriter.isOpened() )
                {
                    cout << "ERROR: Failed to write to file" << endl;
                    getchar();
                    return;
                }
                firstRun = false;
                startNewRecording = false;
            }
            oVideoWriter.write(frame1);
            putText(frame1,"REC",Point(0,60),2,2,Scalar(0,0,255),2);
        }

        if(detectMotion(thresholdImage)){
            putText(frame1,"MOTION DETECTED",cv::Point(0,420),2,2,cv::Scalar(0,255,0));
            recording=true;

        }else recording=false;
        imshow("Frame1",frame1);
        input ();
    }
}



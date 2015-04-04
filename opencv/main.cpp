#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

string intToString (int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}

int main(){

    bool recording =false;
    bool startNewRecording=true;
    int videoNumber=0;

    VideoCapture vcap(0);


   int frame_width=vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height= vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
   VideoWriter video;

   for(;;){
       Mat frame;
       if (startNewRecording){
           if(!vcap.isOpened()){
                  cout << "Error opening video stream" << endl;
                  return -1;
           }
            startNewRecording=false;
            recording=true;

            string filename="out"+intToString(videoNumber)+".avi";
               videoNumber++;
            video=VideoWriter(filename,CV_FOURCC('D','I','V','3'),10, Size(frame_width,frame_height),true);

       }
       vcap >> frame;
       if (recording){

           video.write(frame);
           putText(frame,"REC",Point(0,60),2,2,Scalar(0,0,255));
       }

       imshow( "Frame", frame );
       char c = (char)waitKey(33);
       if( c == 27 ) break;
       if (c==114){  //r key
           recording=!recording;
       }
       if (c==110){ //n key
           startNewRecording=true;
       }
    }
  return 0;
}

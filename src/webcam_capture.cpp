//opencv
#include "opencv2/opencv.hpp"

//std
#include <iostream>
#include <cstdlib>
using namespace std;
//main
int main(int argc, char *argv[])
{
    cv::VideoCapture camera; //OpenCV video capture object
    cv::Mat image; //OpenCV image object
	int cam_id; //camera id . Associated to device number in /dev/videoX
	int user_key; //user pressed key to quit
  int rang; //To define cross size
  int color;//To define color of the cross
  cv::Vec3b pixel_intensity; //pixel RGB intensity

	//check user args
	switch(argc)
	{
		case 1: //no argument provided, so try /dev/video0
			cam_id = 0;
			break;
		case 2: //an argument is provided. Get it and set cam_id
			cam_id = atoi(argv[1]);
			break;
		default:
			cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
			cout << "EXIT program." << std::endl;
			break;
	}

	//advertising to the user
	cout << "Opening video device " << cam_id << std::endl;

    //open the video stream and make sure it's opened
    if( !camera.open(cam_id) )
	{
        cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
        return -1;
    }

cout<<"Choose width and lengh for the cross (in pixels): "; cin>>rang;
cout<<"Chose a color for the cross, 1(red), 2(green) 3(blue), 4(black) or 5(white): "; cin>>color;

    //capture loop. Out of user press a key
    while(1)
	{
		//Read image and check it. Blocking call up to a new image arrives from camera.
        if(!camera.read(image))
		{
            cout << "No frame" << std::endl;
            cv::waitKey();
        }

		// get intensity of the central pixel. Ordered as BGR
		pixel_intensity = image.at<cv::Vec3b>(image.rows/2, image.cols/2);  // es defineix la posició del pixel(x,y)

    cout << "RGB: " 	<< (unsigned int)pixel_intensity[2] << ","
								<< (unsigned int)pixel_intensity[1] << ","
								<< (unsigned int)pixel_intensity[0] << std::endl;

          switch(color) {

                      case 1: pixel_intensity[0] = 0; pixel_intensity[1] = 0; pixel_intensity[2] = 255; break;
                      case 2: pixel_intensity[0] = 0; pixel_intensity[1] = 255; pixel_intensity[2] = 0; break;
                      case 3: pixel_intensity[0] = 255; pixel_intensity[1] = 0; pixel_intensity[2] = 0; break;
                      case 4: pixel_intensity[0] = 0; pixel_intensity[1] = 0; pixel_intensity[2] = 0; break;
                      case 5: pixel_intensity[0] = 255; pixel_intensity[1] = 255; pixel_intensity[2] = 255; break;
                    }

          for (float i=0; i<=rang/2; i++){

                    	image.at<cv::Vec3b>((image.rows/2)-i, image.cols/2) = pixel_intensity;
                      image.at<cv::Vec3b>((image.rows/2)+i, image.cols/2) = pixel_intensity;
                      image.at<cv::Vec3b>(image.rows/2, (image.cols/2)-i) = pixel_intensity;
                    	image.at<cv::Vec3b>(image.rows/2, (image.cols/2)+i) = pixel_intensity;
                    }





        //show image in a window
      cv::imshow("Output Window", image);

		//Waits 30 millisecond to check if 'q' key has been pressed. If so, breaks the loop. Otherwise continues.
    	if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break;
    }
}

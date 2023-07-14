// Include required header files from OpenCV directory
#include "/usr/include/opencv4/opencv2/objdetect.hpp"
#include "/usr/include/opencv4/opencv2/highgui.hpp"
#include "/usr/include/opencv4/opencv2/imgproc.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string>

using namespace std;
using namespace cv;
  
// Function for Face Detection
int eyesWithoutAFace(Point, Point, int );
void detectAndDraw( Mat& img, CascadeClassifier& cascade, 
                CascadeClassifier& nestedCascade, double scale );
string cascadeName, nestedCascadeName;


int main( int argc, const char** argv )
{
    // VideoCapture class for playing video for which faces to be detected
    VideoCapture capture; 
    Mat frame, image;
  
    // PreDefined trained XML classifiers with facial features
    CascadeClassifier cascade, nestedCascade; 
    double scale=1;
  
    // Load classifiers from "opencv/data/haarcascades" directory 
    nestedCascade.load( "/usr/share/opencv4/haarcascades/haarcascade_eye_tree_eyeglasses.xml" ) ;
  
    // Change path before execution 
    cascade.load( "/usr/share/opencv4/haarcascades/haarcascade_frontalcatface.xml" ) ; 
 
    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video
    capture.open(0); 
    if( capture.isOpened() )
    {
        // Capture frames from video and detect faces
        cout << "Face Detection Started...." << endl;
        while(1)
        {
            capture >> frame;
            if( frame.empty() )
                break;
            Mat frame1 = frame.clone();
	    detectAndDraw( frame1, cascade, nestedCascade, scale ); 
            char c = (char)waitKey(1);
            // Press q to exit from window
            if( c == 27 || c == 'q' || c == 'Q' ) 
                break;
        }
    }
    else
        cout<<"Could not Open Camera";
    return 0;
}
 
int eyesWithoutAFace(Point face, Point eye, int radius)
{
    int distanciaX = eye.x - face.x;
    int distanciaY = eye.y - face.y;
    int distanciaAoQuadrado = distanciaX * distanciaX + distanciaY * distanciaY;
    int raioAoQuadrado = radius * radius;

    if (distanciaAoQuadrado <= raioAoQuadrado) {
        return 0;
    } else {
        return 1;
    }
}

void detectAndDraw( Mat& img, CascadeClassifier& cascade,
                    CascadeClassifier& nestedCascade,
                    double scale)
{
    vector<Rect> faces, faces2;
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY ); // Convert to Gray Scale
    double fx = 1 / scale;
  
    // Resize the Grayscale Image 
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR ); 
    equalizeHist( smallImg, smallImg );
  
    // Detect faces of different sizes using cascade classifier 
    cascade.detectMultiScale( smallImg, faces, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30) );
  
    // Draw circles around the faces
    for ( size_t i = 0; i < faces.size(); i++ )
    {
	std::string password;
        char comando[100];	
        std::string nomeArquivo = "someone.jpg";
        Rect r = faces[i];
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        Point face,eye;
	Scalar color = Scalar(255, 0, 0); // Color for Drawing tool
        int radius=0, radius_eye=0;
        double aspect_ratio = (double)r.width/r.height;
        
	if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            face.x = cvRound((r.x + r.width*0.5)*scale);
            face.y = cvRound((r.y + r.height*0.5)*scale);
            radius = cvRound((r.width + r.height)*0.25*scale);
            //circle( img, face, radius, color, 3, 8, 0 );
	}
        else
            rectangle( img, cv::Point(cvRound(r.x*scale), cvRound(r.y*scale)),
                    cv::Point(cvRound((r.x + r.width-1)*scale), 
                    cvRound((r.y + r.height-1)*scale)), color, 3, 8, 0);
        
	if( nestedCascade.empty() )
            continue;
        
	smallImgROI = smallImg( r );
	 
        // Detection of eyes int the input image
        nestedCascade.detectMultiScale( smallImgROI, nestedObjects, 1.1, 2,
                                        0|CASCADE_SCALE_IMAGE, Size(30, 30) ); 
        // Draw circles around eyes
        for ( size_t j = 0; j < nestedObjects.size(); j++ ) 
        {
           Rect nr = nestedObjects[j];
           eye.x = cvRound((r.x + nr.x + nr.width*0.5)*scale);
           eye.y = cvRound((r.y + nr.y + nr.height*0.5)*scale);
           radius_eye = cvRound((nr.width + nr.height)*0.25*scale);
           //circle( img, eye, radius_eye, color, 3, 8, 0 );
       	}

	if(!eyesWithoutAFace(face,eye,radius))
	//if(radius || radius_eye)
	{
            cv::imwrite(nomeArquivo, img);
	    system("bash mageyBot_cleaner.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8");
	    system("bash mageyBot_photo.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803");
	    system("bash mageyBot_message.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803 'Entrada solicitada. Aguardando digitação de codigo ...'");
	    system("clear");
	    cout << "DISPLAY: Digite o codigo numérico: ";
	    cin >> password;
	    cout << "DISPLAY: Aguardando a verificação no sistema... ";
	    sprintf(comando, "bash executar_models.sh %s", password.c_str());
	    system(comando); sleep(20);
	    sprintf(comando, "bash mageyBot_yes.sh 5994091183:AAG4Zr57KCKglxo2fV5qqGbpcXYEOnM1Ma8 830725803 %s", password.c_str());
	    system(comando);
	} else 
	    system("echo 'Searching for somebody in front of the camera...'");
    }
    // Show Processed Image with detected faces
    //imshow( "Face Detection", img ); 
}

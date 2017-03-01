#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

double alpha; /**< Simple contrast control */
int beta;  /**< Simple brightness control */

int main( int argc, char** argv )
{
 /// Read image given by user
 Mat image = imread("foto.jpg", 0);
 Mat new_image = Mat::zeros( image.size(), image.type() );

 /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
 for( int y = 0; y < image.rows; y++ )
    { for( int x = 0; x < image.cols; x++ )
         { for( int c = 0; c < 3; c++ )
              {
      new_image.at<Vec3b>(y,x)[c] =
         saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
             }
    }
    }

 /// Create Windows
//namedWindow("Original Image", 1);
//namedWindow("New Image", 1);

 /// Show stuff
// imshow("Original Image", image);
//   imshow("New Image", new_image);
 QApplication a(argc, argv);
 MainWindow w;
 w.show();

QWidget *mainWindow = new QWidget;
mainWindow->setWindowTitle("Imagem");

QSlider *slider = new QSlider(Qt::Horizontal);
slider->setRange(1, 100);
 return a.exec();

 /// Wait until user press some key
// waitKey();
 //return 0;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_slider1_change()
{
    cv::Mat test_image = cv::imread("test_img.jpg", 0);


    cv::namedWindow("test image", cv::WINDOW_AUTOSIZE);
    cv::imshow("test image", test_image);
}

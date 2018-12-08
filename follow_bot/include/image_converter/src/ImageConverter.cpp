#include "ImageConverter.h"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

static const std::string OPENCV_WINDOW = "Image window";

ImageConverter::ImageConverter() : imageTransport(nh) {
    imageSubscriber = imageTransport.subscribe("/camera/rgb/image_raw", 1,
            &ImageConverter::imageCallback, this);

    // Create a display window
    cv::namedWindow(OPENCV_WINDOW);
}

ImageConverter::~ImageConverter() {
    // Close the display window
    cv::destroyWindow(OPENCV_WINDOW);
}

void ImageConverter::imageCallback(const sensor_msgs::ImageConstPtr& msg) {
    // convert the ROS image message to a CvImage
    cv_bridge::CvImagePtr cv_ptr;
    try {
        cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e) {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    // Draw an example circle at the center of the video stream
    if (cv_ptr->image.rows > 50 && cv_ptr->image.cols > 50) {
        int cx = cv_ptr->image.cols / 2;
        int cy = cv_ptr->image.rows / 2;
        cv::circle(cv_ptr->image, cv::Point(cx, cy), 25, CV_RGB(255, 0, 0));
    }

    // Update the GUI window
    cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    cv::waitKey(3);
}

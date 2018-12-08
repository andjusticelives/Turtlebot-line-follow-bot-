#include "ImageConverter.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "image_converter");
    ImageConverter imageConverter;
    ros::spin();
    return 0;
}

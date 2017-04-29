#include<iostream>
using namespace std;
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
int main (int argc,char**argv)
{
	cv::Mat image,image2,image3;
	image=cv::imread(argv[1]);
	image2=cv::imread(argv[2]);
        image3=cv::imread(argv[3]);
    if(image.data==nullptr||image2.data==nullptr)
	{
		cerr<<"Not find image."<<endl;
		return 0;
	}
	cv::Mat image_clone=image.clone();
        cv::Mat imageROI=image_clone(cv::Rect(image_clone.cols-image2.cols-3,174,image2.cols,image2.rows));
        cv::addWeighted(imageROI,0.3,image2,0.80,0.,imageROI);
        cv::Mat image_clone2=image_clone.clone();
        cv::Mat imageROI2=image_clone2(cv::Rect(image_clone2.cols-image3.cols-image2.cols-3,177,image3.cols,image3.rows));
        cv::addWeighted(imageROI2,0.3,image3,0.80,0.,imageROI2);
	cv::imshow("image",image_clone);
	cv::imwrite("output.jpg",image_clone2);
	return 0;
}

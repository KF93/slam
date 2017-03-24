#include<opencv2/opencv.hpp>
#include<boost/concept_check.hpp>
#include<vector>
#include<iostream>
using namespace cv;
int main()
{
 Mat srcImage,srcImage2;
 std::vector<Mat> channels;
 srcImage=imread("../image/1.jpg");
 if(!srcImage.data)
  {
    printf("读取图片错误");
    return-1;
  }
 //把一个3通道图像转换成3个单通道图像
 split(srcImage,channels);
 imshow("sample",channels.at(0));
 merge(channels,srcImage2);
 imshow("sample2",srcImage2);
 waitKey(0);
 return 0;
}
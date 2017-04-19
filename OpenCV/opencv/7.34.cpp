#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgcodecs.hpp"
#include <opencv2/imgproc.hpp>
#include<iostream>
#include <map>
using namespace cv;
using namespace std;
//--------------
#define WINDOW_NAME "窗口程序"
//--------------
Mat srcimage,dstimage;
Mat map_x,map_y;
//-------------------
int update_map(int key);

//----------------------
int main(int argc, char** argv)
{
  srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  dstimage.create(srcimage.size(),srcimage.type());
  map_x.create(srcimage.size(),CV_32FC1);
  map_y.create(srcimage.size(),CV_32FC1);
  namedWindow(WINDOW_NAME,CV_WINDOW_AUTOSIZE);
  imshow("image",srcimage);
  while(1)
  {
    int key=waitKey(0);
    if((key&255)==27)
    {
      cout<<"程序退出。。。。。\n";
      break;
    }
    update_map(key);
    //opencv2
    //remap(srcimage,dstimage,map_x,map_y,CV_INTER_LINEAR,BORER_CONSTANT,Scalar(0,0,0));
    remap(srcimage,dstimage,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
    imshow(WINDOW_NAME,dstimage);
  }
  return 0;
}
//-----------------
int update_map(int key)
{
  for(int j=0;j<srcimage.rows;j++)
  {
    for (int i=0;i<srcimage.cols;i++)
    {
      switch(key)
      {
	case '1':
	  if(i>srcimage.cols*0.25&&i<srcimage.cols*0.75&&j>srcimage.rows*0.25&&j<srcimage.rows*0.75)
	  {
	    map_x.at<float>(j,i)=static_cast<float>(2*(i-srcimage.cols*0.25)+0.5);
	    map_y.at<float>(j,i)=static_cast<float>(2*(j-srcimage.rows*0.25)+0.5);
	  }
	  else
	  {
	    map_x.at<float>(j,i)=0;
	    map_y.at<float>(j,i)=0;
	  }
	  break;
	case '2':
	  map_x.at<float>(j,i)=static_cast<float>(i);
	  map_y.at<float>(j,i)=static_cast<float>(srcimage.rows-j);
	  break;
	case '3':
	  map_x.at<float>(j,i)=static_cast<float>(srcimage.cols-i);
	  map_y.at<float>(j,i)=static_cast<float>(j);
	  break;
	case '4':
	  map_x.at<float>(j,i)=static_cast<float>(srcimage.cols-i);
	  map_y.at<float>(j,i)=static_cast<float>(srcimage.rows-j);
	  break;
      }
    }
  }
  return 1;
}

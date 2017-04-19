#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include<iostream>
using namespace cv;
using namespace std;
//---------------------
int main()
{
  Mat srcimage=imread("../image/1.jpg",0);
  imshow("image",srcimage);
  if(!srcimage.data)
  {
    cout<<"fail to load image"<<endl;
    return 0;
  }
  MatND dstHist;
  int dims=1;
  float hranges[]={0,255};
  const float *ranges[]={hranges};
  int size=256;
  int channels=0;
  calcHist(&srcimage,1,&channels,Mat(),dstHist,dims,&size,ranges);
  int scale=1;
  Mat dstimage(size*scale,size,CV_8U,Scalar(0));
  double minValue=0;
  double maxValue=0;
  minMaxLoc(dstHist,&minValue,&maxValue,0,0);
  int hpt=saturate_cast< int >(0.9*size);
  for(int i=0;i<256;i++)
  {
    float binValue=dstHist.at<float>(i);
    int realValue=saturate_cast< int >(binValue*hpt/maxValue);
    cout<<maxValue<<" "<<minValue<<"  "<<realValue<<"    ";
    rectangle(dstimage,Point(i*scale,size-1),Point((i+1)*scale-1,size-realValue),Scalar(255));
  }
  imshow("一维直方图",dstimage);
  waitKey(0);
  return 0;
}
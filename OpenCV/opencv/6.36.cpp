#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//---------------------
Mat srcimage,dstimage;
int TrackbarNumer=0;
int StructElementSize=3;
//---------------------
void Process();
void onTracckbarNumChange(int ,void *);
void onElementSizeChange(int,void *);
//------------------------
int main()
{
  system("color5E");
  srcimage=imread("../image/2.jpg");
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  imshow("原始图",srcimage);
  namedWindow("效果图");
  Mat element=getStructuringElement(MORPH_RECT,Size(2*StructElementSize+1,2*StructElementSize+1),Point(StructElementSize,StructElementSize));
  erode(srcimage,dstimage,element);
  imshow("效果图",dstimage);
  //----------------------------------
  createTrackbar("腐蚀/膨胀","效果图",&TrackbarNumer,1,onTracckbarNumChange);
  createTrackbar("内核尺寸","效果图",&StructElementSize,21,onElementSizeChange);
  //----------------------
  while(char(waitKey(1))!='q'){}
  return 0;
}
//------------------------------
void Process()
{
  Mat element=getStructuringElement(MORPH_RECT,Size(2*StructElementSize+1,2*StructElementSize+1),Point(StructElementSize,StructElementSize));
  if(TrackbarNumer==0)
    erode(srcimage,dstimage,element);
  else
    dilate(srcimage,dstimage,element);
  imshow("效果图",dstimage);
}
//---------------------------------
void onTracckbarNumChange(int, void*)
{
  Process();
}
//----------------------
void onElementSizeChange(int, void*)
{
  Process();
}



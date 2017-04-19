#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
//------------
Mat srcimage,dstimage1,dstimage2,dstimage3;
int BoxFilterValue=3;
int MeanBlurValue=3;
int GaussianBlurValue=3;
//-----------------------------
static void onBoxFilter(int,void *);
static void onMeanBlur(int,void *);
static void onGaussianBlur(int,void *);
//--------------------------
int main()
{
  system("color5E");
  srcimage=imread("../image/2.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  dstimage1=srcimage.clone();
  dstimage2=srcimage.clone();
  dstimage3=srcimage.clone();
  imshow("原图",srcimage);
  //----------------------
   namedWindow("方框滤波",1);
  createTrackbar("内核值","方框滤波",&BoxFilterValue,40,onBoxFilter);
  onBoxFilter(BoxFilterValue,0);
  //imshow("方框滤波",dstimage1);
  //-----------------------
  namedWindow("均值滤波",1);
  createTrackbar("内核值","均值滤波",&MeanBlurValue,40,onMeanBlur);
  onMeanBlur(MeanBlurValue,0);
  //imshow("均值滤波",dstimage2);
  //-------------------------------
  namedWindow("高斯滤波",1);
  createTrackbar("内核值","高斯滤波",&GaussianBlurValue,40,onGaussianBlur);
  onGaussianBlur(GaussianBlurValue,0);
  //------------------
  cout<<endl<<"请调整滚动条观察图像效果\n"<<"按q键退出\n";
  while(char(waitKey(1))!='q'){}
  return 0;
}
  //---------------------------
  static void onBoxFilter(int,void *)
  {
    boxFilter(srcimage,dstimage1,-1,Size(BoxFilterValue+1,BoxFilterValue+1));
    imshow("方框滤波",dstimage1);
  }
  //-------------------------
  static void onMeanBlur(int,void *)
  {
    blur(srcimage,dstimage2,Size(MeanBlurValue+1,MeanBlurValue+1));
    imshow("均值滤波",dstimage2);
  }
  //--------------------------
  static void onGaussianBlur(int,void *)
  {
    GaussianBlur(srcimage,dstimage3,Size(GaussianBlurValue*2+1,GaussianBlurValue*2+1),0,0);
    imshow("高斯滤波",dstimage3);
  }
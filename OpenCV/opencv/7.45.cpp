#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
//----------------------
#define WINDOW_NAME1 "原始窗口"
#define WINDOW_NAME2 "Warp后的图像"
#define WINDOW_NAME3 "Warp和Rotate后的图像"
//----------------------
int main()
{
  Point2f srcTriangle[3];
  Point2f dstTriange[3];
  Mat rotMat(2,3,CV_32FC1);
  Mat warpMAt(2,3,CV_32FC1);
  Mat srcimage,dstimage_warp,dstimage_warp_rotate;
  srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片错误\n");
    return false;
  }
  dstimage_warp=Mat::zeros(srcimage.rows,srcimage.cols,srcimage.type());
  srcTriangle[0]=Point2f(0,0);
  srcTriangle[1]=Point2f(static_cast<float>(srcimage.cols-1),0);
  srcTriangle[2]=Point2f(0,static_cast<float>(srcimage.rows-1));
  dstTriange[0]=Point2f(static_cast<float>(srcimage.cols*0.0),static_cast<float>(srcimage.rows*0.33));
  dstTriange[1]=Point2f(static_cast<float>(srcimage.cols*0.65),static_cast<float>(srcimage.rows*0.35));
  dstTriange[2]=Point2f(static_cast<float>(srcimage.cols*0.15),static_cast<float>(srcimage.rows*0.6));
  warpMAt=getAffineTransform(srcTriangle,dstTriange);
  warpAffine(srcimage,dstimage_warp,warpMAt,dstimage_warp.size());
  Point center=Point(dstimage_warp.cols/2,dstimage_warp.rows/2);
  double angle=-30.0;
  double scale=0.8;
  rotMat=getRotationMatrix2D(center,angle,scale);
  warpAffine(dstimage_warp,dstimage_warp_rotate,rotMat,dstimage_warp.size());
  imshow(WINDOW_NAME1,srcimage);
  imshow(WINDOW_NAME2,dstimage_warp);
  imshow(WINDOW_NAME3,dstimage_warp_rotate);
  waitKey(0);
  return 0;
  
}

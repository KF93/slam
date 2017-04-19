#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
using namespace cv;
//-------------------
int main()
{
  Mat srcimage,dstimage;
  srcimage=imread("../image/4.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片错误\n");
    return false;
  }
  cvtColor(srcimage,srcimage,COLOR_BGR2GRAY);
  imshow("image",srcimage);
  equalizeHist(srcimage,dstimage);
  imshow("equalizeHist",dstimage);
  waitKey(0);
  return 0;
}
#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/photo/photo.hpp"
#include <iostream>
using namespace std;
using namespace cv;
//---------------------
#define WINDOW_NAME1 "原始图"
#define WINDOW_NAME2 "修补后"
//----------------------
Mat srcimage1,inpaintMask;
Point previousPoint(-1,-1);
//-----------------------
static void onMouse(int event,int x,int y,int flags,void*)
{
  if(event==EVENT_LBUTTONUP||!(flags& EVENT_FLAG_LBUTTON))
    previousPoint=Point(-1,-1);
  else if(event==EVENT_LBUTTONDOWN)
    previousPoint=Point(x,y);
  else if(event==EVENT_MOUSEMOVE&&(flags& EVENT_FLAG_LBUTTON))
    {
      Point pt(x,y);
      if(previousPoint.x<0)
	previousPoint=pt;
      line(inpaintMask,previousPoint,pt,Scalar::all(255),5,8,0);
      line(srcimage1,previousPoint,pt,Scalar::all(255),5,8,0);
      previousPoint=pt;
      imshow(WINDOW_NAME1,srcimage1);
    }
}
//------------------------------
int main (int argc,char** argv)
{
  Mat srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  srcimage1=srcimage.clone();
  inpaintMask=Mat::zeros(srcimage1.size(),CV_8U);
  imshow(WINDOW_NAME1,srcimage1);
  setMouseCallback(WINDOW_NAME1,onMouse,0);
  while(1)
  {
    char c=(char)waitKey();
    if(c==27)
      break;
    if(c=='2')
    {
      inpaintMask=Scalar::all(0);
      srcimage.copyTo(srcimage1);
      imshow(WINDOW_NAME1,srcimage1);
    }
    if(c=='1'||c==' ')
    {
      Mat inpaintedimage;
      inpaint(srcimage1,inpaintMask,inpaintedimage,3,INPAINT_TELEA);
      imshow(WINDOW_NAME2,inpaintedimage);
    }
  }
  return 0;
}
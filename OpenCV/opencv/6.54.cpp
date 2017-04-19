#include<opencv2/imgproc/imgproc.hpp>
#include"opencv2/highgui/highgui.hpp"
#include<iostream>
#include <boost/concept_check.hpp>
using namespace std;
using namespace cv;
//--------------------------
Mat srcimage,dstimage,grayimage,maskimage;
int FillMood=1;
int LowDifference=20,UpDifference=20;
int Connectivity=4;
int bIsColor=true;
bool UseMask=false;
int NewMaskVal=255;
//---------------------------
static void onMouse(int event,int x,int y,int,void*)
{
  //鼠标没有按下
  //Opencv2
  //if(event!=CV_EVENT_LBUTTONDOWN)
  if(event!=EVENT_LBUTTONDOWN)
    return;
  //----------------调用floodFill函数之前的参数准备
  Point seed=Point(x,y);
  int LowDifference=FillMood==0?0:LowDifference;
  int UpDifference=FillMood==0?0:UpDifference;
  //标识符0~7为Connectivity,8~15位为NewMaskVal左移8位的值，16~31位为CV_FLOODFILL_FIXED_RANGE或者0
  //Opencv2
  //int flags =Connectivity+(NewMaskVal<<8)+(FillMood==1?CV_FLOODFILL_FIXED_RANGE:0);
  int flags=Connectivity+(NewMaskVal<<8)+(FillMood==1?FLOODFILL_FIXED_RANGE:0);
  //随机生成bgr值
  int b=(unsigned)theRNG()&255;
  int g=(unsigned)theRNG()&255;
  int r=(unsigned)theRNG()&255;
  Rect ccomp;//定义重绘区域的最小边界矩形区域
  Scalar newVal=bIsColor?Scalar(b,g,r):Scalar(r*0.299+g*0.587+b*0.114);//重绘区域像素新值
  Mat dst=bIsColor?dstimage:grayimage;
  int area;
  //----------------------------FLOODFILL函数
  if(UseMask)
  {
    //Opencv2
    //threshold(maskimage,maskimage,1,128,CV_THRESH_BINARY);
    threshold(maskimage,maskimage,1,128,THRESH_BINARY);
    area=floodFill(dst,maskimage,seed,newVal,&ccomp,Scalar(LowDifference,LowDifference,LowDifference),Scalar(UpDifference,UpDifference,UpDifference),flags);
    imshow("mask",maskimage);
  }
  else
  {
    area=floodFill(dst,seed,newVal,&ccomp,Scalar(LowDifference,LowDifference,LowDifference),Scalar(UpDifference,UpDifference,UpDifference),flags);
  }
  imshow("效果图",dst);
  cout<<area<<"个像素被重绘\n";
}
//---------------------------------------------
int main()
{
  srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  srcimage.copyTo(dstimage);
  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
  maskimage.create(srcimage.rows+2,srcimage.cols+2,CV_8UC1);
  //Opencv2
  //namedWindow("效果图",CV_WINDOW_AUTOSIZE);
  namedWindow("效果图",WINDOW_AUTOSIZE);
  //------------------
  createTrackbar("负差最大值", "效果图",&LowDifference,255,0);
  createTrackbar("正差最大值","效果图",&UpDifference,255,0);
  //鼠标回调函数
  setMouseCallback("效果图",onMouse,0);
  //循环轮询按键
  while(1)
  {
    imshow("效果图",bIsColor?dstimage:grayimage);
    int c=waitKey(0);
    if((c&255)==27)
    {
      cout<<"程序退出----------------\n";
      break;
    }
    switch((char)c)
    {
      case '1':
	if(bIsColor)
	{
	  cout<<"键盘1按下，切换彩色/灰度模式，当前操作将彩色切换为灰度\n";
	  cvtColor(srcimage,grayimage,COLOR_BGR2GRAY);
	  maskimage=Scalar::all(0);
	  bIsColor=false;
	}
	else
	{
	  cout<<"键盘1被按下，切换彩色/灰度模式，当前操作将灰度切换为彩色\n";
	  srcimage.copyTo(dstimage);
	  maskimage=Scalar::all(0);
	  bIsColor=true;
	}
	break;
      case '2':
	if(UseMask)
	{
	  destroyWindow("mask");
	  UseMask=false;
	}
	else
	{
	  namedWindow("mask",0);
	  maskimage=Scalar::all(0);
	  imshow("mask",maskimage);
	  UseMask=true;
	}
	break;
      case '3':
	cout<<"按键3被按下，恢复原始图像\n";
	srcimage.copyTo(dstimage);
	cvtColor(dstimage,grayimage,COLOR_BGR2GRAY);
	maskimage=Scalar::all(0);
	break;
      case '4':
	cout<<"按下4，使用空范围的漫水填充\n";
	FillMood=0;
	break;
      case '5':
	cout<<"按下5，使用渐变`固定范围的漫水填充\n";
	FillMood=1;
	break;
      case '6':
	cout<<"按下6，使用渐变`浮动范围的漫水填充\n";
	FillMood=2;
	break;
      case '7':
	cout<<"按下7，操作标志符的低八位使用4位的连接模式\n";
	Connectivity=4;
	break; 
      case '8':
	cout<<"按下8，操作标志符的低八位使用8位的连接模式\n";
	Connectivity=8;
	break;
	
    }
  }
  return 0;
}

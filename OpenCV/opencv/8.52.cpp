#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
//-------------------------
#define WINDOW_NAME "程序窗口"
Mat maskimage,srcimage;
Point prevPt(-1,-1);
//-----------------------
static void onMouse(int event,int x,int y,int flags,void*);
//---------------------
int main(int argc,char** argv)
{
  srcimage=imread("../image/5.jpg",1);
  imshow(WINDOW_NAME,srcimage);
  Mat srcImage,grayimage;
  srcimage.copyTo(srcImage);
  cvtColor(srcImage,maskimage,COLOR_BGR2GRAY);
  cvtColor(maskimage,grayimage,COLOR_GRAY2BGR);
  //imshow("grayimage",grayimage);
  //imshow("maskimage",maskimage);
  maskimage=Scalar::all(0);
  setMouseCallback(WINDOW_NAME,onMouse,0);
  while(1)
  {
    int c=waitKey(0);
    if((char)c==27)
      break;
    if((char)c=='2')
    {
      maskimage=Scalar::all(0);
      srcImage.copyTo(srcimage);
      imshow("WINDOW_NAME",srcimage);
    }
    if((char)c=='1'||(char)c==' ')
    {
      int i,j,compCount=0;
      vector<vector<Point> > contours;
      vector<Vec4i> hierarchy;
      findContours(maskimage,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE);
      //imshow("maskimage1",maskimage);
      if(contours.empty())
	continue;
      Mat maskImage(maskimage.size(),CV_32S);
      maskImage=Scalar::all(0);
      for(int index=0;index>=0;index=hierarchy[index][0],compCount++)	drawContours(maskImage,contours,index,Scalar::all(compCount+1),-1,8,hierarchy);
      if(compCount==0)
      continue;
      
      //imshow("maskImage",maskImage); 
      cout<<compCount<<endl;
      vector<Vec3b> colorTab;
      for(i=0;i<compCount;i++)
      {
	int b=theRNG().uniform(0,255);
	int g=theRNG().uniform(0,255);
	int r=theRNG().uniform(0,255);
	colorTab.push_back(Vec3b((uchar)b,(uchar)g,(uchar)r));
      }
      double dTime=(double)getTickCount(); 
      //for(i=0;i<maskImage.rows;i++)
	//for(j=0;j<maskImage.cols;j++)
      //cout<<maskImage.at<int>(i,j);
      //cout<<endl;
      watershed(srcImage,maskImage);
      //for(i=0;i<maskImage.rows;i++)
	//for(j=0;j<maskImage.cols;j++)
      //cout<<maskImage.at<int>(i,j);
      imshow("maskImage2",maskImage);
      dTime=(double)getTickCount()-dTime;
      printf("\t处理时间=%gms\n",dTime*1000./getTickFrequency());
      Mat watershedimage(maskImage.size(),CV_8UC3);
      for(i=0;i<maskImage.rows;i++)
	for(j=0;j<maskImage.cols;j++)
	{
	  int index=maskImage.at<int>(i,j);
	  //cout<<index<<" ";
	  if(index==-1)
	    watershedimage.at<Vec3b>(i,j)=Vec3b(255,255,255);
	  else if(index<=0||index>compCount)
	    watershedimage.at<Vec3b>(i,j)=Vec3b(0,0,0);
	  else
	    watershedimage.at<Vec3b>(i,j)=colorTab[index-1];
	}
	//imshow("watershedimage",watershedimage);
	watershedimage=watershedimage*0.5+grayimage*0.5;
	imshow("wathershed",watershedimage);
    }
  }
  return 0;
}
//------------------------------------------------------------
void onMouse(int event, int x, int y, int flags, void*)
{
  if(x<0||x>=srcimage.cols||y<0||y>=srcimage.rows)
    return;
  if(event==EVENT_LBUTTONUP||!(flags & EVENT_FLAG_LBUTTON))
    prevPt=Point(-1,-1);
  else if(event==EVENT_LBUTTONDOWN)
    prevPt=Point(x,y);
  else if(event==EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))
  {
    Point pt(x,y);
    if(prevPt.x<0)
      prevPt=pt;
    line(maskimage,prevPt,pt,Scalar::all(255),5,8,0);
    line(srcimage,prevPt,pt,Scalar::all(255),5,8,0);
    prevPt=pt;
    imshow(WINDOW_NAME,srcimage);
  }
}

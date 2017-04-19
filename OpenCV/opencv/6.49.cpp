#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <boost/concept_check.hpp>
using namespace std;
using namespace cv;
//-----------------------
Mat srcimage,dstimage;
int ElementShape=MORPH_RECT;
//-------------------------
int MaxIterationNum=10;
int OpenCloseNum=0;
int ErodeDilateNum=0;
int TopBlackHatNum=0;
//--------------------------
static void onOpenClose(int,void*);
static void onErodeDilate(int,void*);
static void onTopBlackHat(int,void*);
static void ShowHelpText();
//---------------------------
int main()
{
  srcimage=imread("../image/2.jpg");
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  imshow("原始图",srcimage);
  //-----------------------
  namedWindow("开运算/闭运算",1);
  namedWindow("腐蚀/膨胀",1);
  namedWindow("顶帽/黑帽",1);
  //----------------------
  OpenCloseNum=9;
  ErodeDilateNum=9;
  TopBlackHatNum=2;
  //----------------------
  createTrackbar("迭代值","开运算/闭运算",&OpenCloseNum,MaxIterationNum*2+1,onOpenClose);
  createTrackbar("迭代值","腐蚀/膨胀",&ErodeDilateNum,MaxIterationNum*2+1,onErodeDilate);
  createTrackbar("迭代值","顶帽/黑帽",&TopBlackHatNum,MaxIterationNum*2+1,onTopBlackHat);
  //----------------------------
  while(1)
  {
    int c;
    //---------------------
    onOpenClose(OpenCloseNum,0);
    onErodeDilate(ErodeDilateNum,0);
    onTopBlackHat(TopBlackHatNum,0);
    c=waitKey(0);
    if((char)c=='q'||(char)c==27)
      break;
    if((char)c==49)
      ElementShape=MORPH_ELLIPSE;
    else if((char)c==50)
      ElementShape=MORPH_RECT;
    else if((char)c==51)
      ElementShape=MORPH_CROSS;
    else if((char)c==' ')
      ElementShape=(ElementShape+1)%3;
  }
  return 0;
}
//---------------------------------------------------------
void onOpenClose(int, void*)
{ 
  int offset=OpenCloseNum-MaxIterationNum;
  int Absolute_offset=offset>0?offset:-offset;
  //------------------------------
  Mat element=getStructuringElement(ElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
  if(offset<0)
    //opencv2
    //morphologyEx(srcimage,dstimage,CV_MOP_OPEN,element);
    morphologyEx(srcimage,dstimage,MORPH_OPEN,element);
  else
    morphologyEx(srcimage,dstimage,MORPH_CLOSE,element);
  imshow("开运算/闭运算",dstimage);
}
//------------------------------------------------------------
void onErodeDilate(int, void*)
{
  int offset=ErodeDilateNum-MaxIterationNum;
  int Absolute_offset=offset>0?offset:-offset;
  Mat element=getStructuringElement(ElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
  if(offset<0)
    erode(srcimage,dstimage,element);
  else
    dilate(srcimage,dstimage,element);
  imshow("腐蚀/膨胀",dstimage);
}
//-----------------------------------------------------------
void onTopBlackHat(int, void*)
{
  int offset=TopBlackHatNum-MaxIterationNum;
  int Absolute_offset=offset>0?offset:-offset;
  Mat element=getStructuringElement(ElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
  if(offset<0)
    morphologyEx(srcimage,dstimage,MORPH_TOPHAT,element);
  else
    morphologyEx(srcimage,dstimage,MORPH_BLACKHAT,element);
  imshow("顶帽/黑帽",dstimage);
}



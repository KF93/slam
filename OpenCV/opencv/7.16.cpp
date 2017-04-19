#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <boost/concept_check.hpp>
using namespace cv;
//-------------------
Mat srcimage,srcgrayimage,dstimage;
Mat sobelGradient_x,sobelGradient_y;
Mat sobelAbsGradient_x,sobelAbsGradient_y;
int sobelKerelSize=1;
Mat scharrGradient_x,scharrGradient_y;
Mat scharrAbsGradient_x,scharrAbsGradient_y;
Mat cannyDetectedEdges;
int cannyLowThreshold=1;
//-----------------------------------
static void onCanny(int,void*);
static void onSobel(int,void*);
void Scharr();
//----------------------
int main()
{
  //system("color 2F");
  srcimage=imread("../image/5.jpg",1);
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  imshow("image",srcimage);
  dstimage.create(srcimage.size(),srcimage.type());
  cvtColor(srcimage,srcgrayimage,COLOR_BGR2GRAY);
  namedWindow("Canny",CV_WINDOW_AUTOSIZE);
  namedWindow("Sobel",CV_WINDOW_AUTOSIZE);
  createTrackbar("参数值","Canny",&cannyLowThreshold,120,onCanny);
  createTrackbar("参数值","Sobel",&sobelKerelSize,3,onSobel);
  onCanny(0,0);
  onSobel(0,0);
  Scharr();
  while((char(waitKey(1))!='q')){}
  return 0;
}
//----------------------------------------
void onCanny(int, void*)
{
  blur(srcgrayimage,cannyDetectedEdges,Size(3,3));
  Canny(cannyDetectedEdges,cannyDetectedEdges,cannyLowThreshold,cannyLowThreshold*3,3);
  dstimage=Scalar::all(0);
  srcimage.copyTo(dstimage,cannyDetectedEdges);
  imshow("Canny",dstimage);
}
//---------------------------------------------
void onSobel(int, void*)
{
  Sobel(srcimage,sobelGradient_x,CV_16S,1,0,(2*sobelKerelSize+1),1,1,BORDER_DEFAULT);
  convertScaleAbs(sobelGradient_x,sobelAbsGradient_x);
  Sobel(srcimage,sobelGradient_y,CV_16S,0,1,(2*sobelKerelSize+1),1,1,BORDER_DEFAULT);
  convertScaleAbs(sobelGradient_y,sobelAbsGradient_y);
  addWeighted(sobelAbsGradient_x,0.5,sobelAbsGradient_y,0.5,0,dstimage);
  imshow("Sobel",dstimage);
}
//--------------------------------------------------
void Scharr()
{
  Scharr(srcimage,scharrGradient_x,CV_16S,1,0,1,0,BORDER_DEFAULT);
  convertScaleAbs(scharrGradient_x,scharrAbsGradient_x);
  Scharr(srcimage,scharrGradient_y,CV_16S,0,1,1,0,BORDER_DEFAULT);
   convertScaleAbs(scharrGradient_y,scharrAbsGradient_y);
  addWeighted(scharrAbsGradient_x,0.5,scharrAbsGradient_y,0.5,0,dstimage);
  imshow("Scharr",dstimage);
}


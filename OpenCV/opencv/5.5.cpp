#include"opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
//-----------------------------
int main()
{
  Mat srcimage =imread("../image/2.jpg",0);
  if(!srcimage.data)
  {
    printf("读取图片错误，确定目录是否有图片存在！\n");
    return false;
  }
  imshow ("原始图像",srcimage);
  //ShowHelpText();
  //----------------
  int m=getOptimalDFTSize(srcimage.rows);
  int n=getOptimalDFTSize(srcimage.cols);
  cout<<m-srcimage.rows<<endl;
  cout<<n-srcimage.cols<<endl;
  Mat padded;
  
copyMakeBorder(srcimage,padded,0,m-srcimage.rows,0,n-srcimage.cols,
BORDER_CONSTANT, Scalar::all ( 0));
//-------------------------
Mat planes[]={Mat_<float>(padded),Mat::zeros(padded.size(),CV_32F)};
Mat complexI;
merge (planes,2,complexI);
//------------------------
dft(complexI,complexI);
//---------------------
split(complexI,planes);
magnitude(planes[0],planes[1],planes[0]);
Mat magnitudeImage=planes[0];
//--------------------
magnitudeImage+=Scalar::all(1);
log(magnitudeImage,magnitudeImage);
//------------------------
magnitudeImage=magnitudeImage(Rect(0,0,magnitudeImage.cols& -2,magnitudeImage.rows & -2));   
//magnitudeImage=magnitudeImage(Rect(0,0,srcimage.cols,srcimage.rows));   

//----------------------------
int cx=magnitudeImage.cols/2;
int cy=magnitudeImage.rows/2;
Mat q0(magnitudeImage,Rect(0,0,cx,cy));
Mat q1(magnitudeImage,Rect(cx,0,cx,cy));
Mat q2(magnitudeImage,Rect(0,cy,cx,cy));
Mat q3(magnitudeImage,Rect(cx,cy,cx,cy));
//-------
Mat tmp;
q0.copyTo(tmp);
q3.copyTo(q0);
tmp.copyTo(q3);
q1.copyTo(tmp);
q2.copyTo(q1);
tmp.copyTo(q2);
//-----------------------
//opencv2
//normalize(magnitudeImage,magnitudeImage,0,1,CV_MINMAX);
normalize(magnitudeImage,magnitudeImage,0,1,NORM_MINMAX);
//---------------------------------
imshow("频谱幅值",magnitudeImage);
waitKey();
return 0;
}
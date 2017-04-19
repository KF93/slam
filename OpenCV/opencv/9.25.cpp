#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <boost/concept_check.hpp>
using namespace cv;
int main()
{
  Mat srcimage;
  srcimage=imread("../image/1.jpg");
  imshow("image",srcimage);
  int bins=256;
  int hist_size[]={bins};
  float range[]={0,256};
  const float* ranges[]={range};
  MatND redHist,grayHist,blueHist;
  int channelsr[]={0};
  calcHist(&srcimage,1,channelsr,Mat(),redHist,1,hist_size,ranges,true,false);
  int channelsg[]={1};
  calcHist(&srcimage,1,channelsg,Mat(),grayHist,1,hist_size,ranges,true,false);
  int channelsb[]={2};
  calcHist(&srcimage,1,channelsb,Mat(),blueHist,1,hist_size,ranges,true,false);
  //-----------------------------------
  double maxValuer,maxValueg,maxValueb;
  minMaxLoc(redHist,0,&maxValuer,0,0);
  minMaxLoc(grayHist,0,&maxValueg,0,0);
  minMaxIdx(blueHist,0,&maxValueb,0,0);
  int scale=1;
  int histHieght=256;
  Mat histimage=Mat::zeros(histHieght,bins*3,CV_8UC3);
  for(int i=0;i<bins;i++)
  {
    float binValuer=redHist.at<float>(i);
    float binValueg=grayHist.at<float>(i);
    float binValueb=blueHist.at<float>(i);
    int intensityr=cvRound(binValuer*histHieght/maxValuer);
    int intensityg=cvRound(binValueg*histHieght/maxValueg);
    int intensityb=cvRound(binValueb*histHieght/maxValueb);
    rectangle(histimage,Point(i*scale,histHieght-1),Point((i+1)*scale-1,histHieght-intensityr),Scalar(255,0,0));
    rectangle(histimage,Point((i+bins)*scale,histHieght-1),Point((i+bins+1)*scale-1,histHieght-intensityg),Scalar(0,255,0));
    rectangle(histimage,Point((i+bins*2)*scale,histHieght-1),Point((i+bins*2+1)*scale-1,histHieght-intensityb),Scalar(0,0,255));
  }
  imshow("RGB直方图",histimage);
  waitKey(0);
  return 0;
}
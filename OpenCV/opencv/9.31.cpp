#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <boost/concept_check.hpp>
using namespace cv;
//------------------------
int main()
{
  Mat srcimage_base,hsvimage_base;
  Mat srcimage_test1,hsvimage_test1;
  Mat srcimage_test2,hsvimage_test2;
  Mat hsvimage_halfDown;
  srcimage_base=imread("../image/2.jpg",1);
  srcimage_test1=imread("../image/3.jpg",1);
  srcimage_test2=imread("../image/4.jpg",1);
  cvtColor(srcimage_base,hsvimage_base,COLOR_BGR2HSV);
  cvtColor(srcimage_test1,hsvimage_test1,COLOR_BGR2HSV);
  cvtColor(srcimage_test2,hsvimage_test2,COLOR_BGR2HSV);
  hsvimage_halfDown=hsvimage_base(Range(hsvimage_base.rows/2,hsvimage_base.rows-1),Range(0,hsvimage_base.cols-1));
  int h_bins=50;
  int s_bins=60;
  int histSize[]={h_bins,s_bins};
  float h_ranges[]={0,256};
  float s_ranges[]={0,180};
  const float* ranges[]={h_ranges,s_ranges};
  int channels[]={0,1};
  MatND baseHist;
  MatND halfDownHist;
  MatND testHist1;
  MatND testHist2;
  calcHist(&hsvimage_base,1,channels,Mat(),baseHist,2,histSize,ranges,true,false);
  normalize(baseHist,baseHist,0,1,NORM_MINMAX,-1,Mat());
  calcHist(&hsvimage_halfDown,1,channels,Mat(),halfDownHist,2,histSize,ranges,true,false);
  normalize(halfDownHist,halfDownHist,0,1,NORM_MINMAX,-1,Mat());
  calcHist(&hsvimage_test1,1,channels,Mat(),testHist1,2,histSize,ranges,true,false);
  normalize(testHist1,testHist1,0,1,NORM_MINMAX,-1,Mat());
  calcHist(&hsvimage_test2,1,channels,Mat(),testHist2,2,histSize,ranges,true,false);
  normalize(testHist2,testHist2,0,1,NORM_MINMAX,-1,Mat());
  for(int i=0;i<4;i++)
  {
    int compar_method=1;
    double base_base=compareHist(baseHist,baseHist,compar_method);
    double base_half=compareHist(baseHist,halfDownHist,compar_method);
    double base_text1=compareHist(baseHist,testHist1,compar_method);
    double base_text2=compareHist(baseHist,testHist2,compar_method);
  std::printf("method [%d] :\n\n[base_base]:%f,[base_half]:%f,[base_text1]:%f,[base_text2]:%f\n---------------------------------------------\n",i,base_base,base_half,base_text1,base_text2);
  }
  printf("检测结束");
  waitKey(0);
  return 0;  
}
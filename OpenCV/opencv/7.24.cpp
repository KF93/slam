#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
int main()
{
  Mat srcimage=imread("../image/3.jpg");
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  //cvtColor(srcimage,srcimage,CV_BGR2BGR555);
  Mat midimage,dstimage;
  Canny(srcimage,midimage,50,200,3);
  cvtColor(midimage,dstimage,CV_GRAY2BGR);
  vector<Vec2f> lines;
  HoughLines(midimage,lines,1,CV_PI/180,200,0,0);
  for(size_t i=0;i<lines.size();i++)
  {
    float rho=lines[i][0],theta=lines[1][1];
    Point pt1,pt2;
    double a=cos(theta),b=sin(theta);
    double x0=a*rho,y0=b*rho;
    pt1.x=cvRound(x0+1000*(-b));
    pt1.y=cvRound(y0+1000*(a));
    pt2.x=cvRound(x0-1000*(-b));
    pt2.y=cvRound(y0-1000*(a));
    //Opencv2
    //line(dstimage,pt1,pt2,Scalar(55,100,150),1,CV_AA);
    line(dstimage,pt1,pt2,Scalar(55,100,150),1,LINE_AA);
  }
  imshow("image",srcimage);
  imshow("Canny",midimage);
  imshow("HoughLines",dstimage);
  waitKey(0);
  return 0;
}
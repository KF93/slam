#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
//- ----------------------
int main()
{
  Mat src=imread("../image/5.jpg");
  Mat src1=src.clone();
  imshow("Cann",src);
  //Opencv2,3已失效
  //Canny(src,src,150,100,3);
  //imshow("Canny1",src);
  Mat dst,edge,gray;
  dst.create(src1.size(),src1.type());
  cvtColor(src1,gray,COLOR_BGR2GRAY);
  blur(gray,edge,Size(3,3));
  Canny(edge,edge,3,9,3);
  dst=Scalar::all(0);
  imshow("1",edge);
  src1.copyTo(dst,edge);
  imshow("Canny",dst);
  waitKey(0);
  return 0;
}
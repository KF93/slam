#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include <boost/concept_check.hpp>
using namespace cv;
using namespace std;
int main()
{
  Mat image(600,600,CV_8UC3);
  RNG& rng=theRNG();
  while(1)
  {
    int count=rng.uniform(3,103);
    vector<Point> points;
    for(int i=0;i<count;i++)
    {
      Point point;
      point.x=rng.uniform(image.cols/4,image.cols*3/4);
      point.y=rng.uniform(image.rows/4,image.rows*3/4);
      points.push_back(point);
    }
    Point2f center;
    float radius=0;
    minEnclosingCircle(Mat(points),center,radius);
    RotatedRect box=minAreaRect(Mat(points));// 圆形
    Point2f vertex[4];
    box.points(vertex);//矩形
    image=Scalar::all(0);
    for(int i=0;i<count;i++)
      circle(image,points[i],3,Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),FILLED,LINE_AA);
    circle(image,center,cvRound(radius),Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255)),2,LINE_AA);
    for (int i=0;i<4;i++)
      line(image,vertex[i],vertex[(i+1)%4],Scalar(100,200,211),2,LINE_AA);
    imshow("包围示例",image);
    char key=(char)waitKey();
    if(key==27||key=='q'||key=='Q')
      break;
  }
  return 0;
}
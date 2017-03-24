#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <boost/iterator/iterator_concepts.hpp>
using namespace cv;
int main()
{
  Mat image=imread("1.jpg");
  namedWindow("image");
  imshow("image",image);
  //图像混合
  Mat image2=imread("2.jpg",199);
  Mat image3=imread("3.jpg");
  namedWindow("image2");
  imshow("image2",image2);
  namedWindow("image3");
  imshow("image3",image3);
  Mat imageROI;
  imageROI=image2(Rect(800,350,image3.cols,image3.rows));
  //plan B
  //imageROI=image2(Range(350,350+image3.rows),Range(800,800+image3.cols));
  addWeighted(imageROI,0.5,image3,0.3,0.,imageROI);
  namedWindow("new image2");
  imshow("new image2",image2);
  imwrite("image.jpg",image2);
  waitKey();
  return 0;  
}
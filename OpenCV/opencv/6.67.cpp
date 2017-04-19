#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
//---------------------------
#define WINDOW_NAME "程序窗口"
//---------------------
Mat srcimage,dstimage,tmpimage;
int main()
{
  srcimage=imread("../image/1.jpg");
  if(!srcimage.data)
  {
    printf("读取图片失败\n");
    return false;
  }
  namedWindow(WINDOW_NAME,WINDOW_AUTOSIZE);
  imshow(WINDOW_NAME,srcimage);
  tmpimage=srcimage;
  dstimage=tmpimage;
  int key=0;
  while(1)
  {
    key=waitKey(9);
    switch(key)
    {
      case 27:
	return 0;
	break;
      case 'q':
	return 0;
	break;
	//------------------
      case 'a':
	pyrUp(tmpimage,dstimage,Size(tmpimage.cols*2,tmpimage.rows*2));
	printf("a键按下，开始进行pyrUp函数的图片向上采样：图片尺寸×2\n");
	break;
      case 'w':
	resize(tmpimage,dstimage,Size(tmpimage.cols*2,tmpimage.rows*2));
	printf("w键按下，开始进行resize函数的图片放大：图片尺寸×2\n");
	break;
      case '1':
	resize(tmpimage,dstimage,Size(tmpimage.cols*2,tmpimage.rows*2));
	printf("1键按下，开始进行resize函数的图片放大：图片尺寸×2\n");
	break;
      case '3':
	pyrUp(tmpimage,dstimage,Size(tmpimage.cols*2,tmpimage.rows*2));
	printf("3键按下，开始进行pyrUp函数的图片向上采样：图片尺寸×2\n");
	break;
	//--------------------------------------
      case 'd':
	pyrDown(tmpimage,dstimage,Size(tmpimage.cols/2,tmpimage.rows/2));
	printf("d键按下，开始进行pysDown函数的图片向下采样：图片尺寸/2\n");
	break; 
      case 's':
	resize(tmpimage,dstimage,Size(tmpimage.cols/2,tmpimage.rows/2));
	printf("s键按下，开始进行resize函数的图片缩小：图片尺寸/2\n");
	break;
      case '2':
	resize(tmpimage,dstimage,Size(tmpimage.cols/2,tmpimage.rows/2));
	printf("2键按下，开始进行resize函数的图片缩小：图片尺寸/2\n");
	break; 
      case '4':
	pyrDown(tmpimage,dstimage,Size(tmpimage.cols/2,tmpimage.rows/2));
	printf("4键按下，开始进行pysDown函数的图片向下采样：图片尺寸/2\n");
	break;
    }
    imshow(WINDOW_NAME,dstimage);
    tmpimage=dstimage;
  }
  return 0;
}
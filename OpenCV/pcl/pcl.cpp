#include <iostream>  
#include <stdlib.h>  
#include<opencv2/opencv.hpp>
#include <cv.h>  
#include <cxcore.h>  
#include <highgui.h>  
#include <math.h>  
#include<pcl/point_types.h>
#include<pcl/io/pcd_io.h>
#include<pcl/visualization/pcl_visualizer.h>
//#include <gl/glut.h>  
using namespace std;
using namespace cv;
float imgdata[1000][1000];
float texture[1000][1000][3];
int w = 0;
int h = 0;
float scalar = 100;//scalar of converting pixel color to float coordinates  

bool mouseisdown = false;
bool loopr = false;
int mx, my;
int ry = 10;
int rx = 10;
 typedef pcl::PointXYZRGB PointT;
 typedef pcl::PointCloud<PointT> PointCloud;
  //新建一个点云
  PointCloud::Ptr pointCloud(new PointCloud);
void displayDisparity(Mat disparity,Mat origin)
{
	//double xyscale=100;  
	int j = 0;
	int i = 0;
	Vec3b points = origin.at<Vec3b>(i, j);

	//accessing the image pixels  
	for (i = 0; i<h; i++)
	{
		for (j = 0; j<w; j++)
		{

			imgdata[i][j] = disparity.at<uchar>(i, j);//for disparity is a grey image.  
			texture[i][j][0] = origin.at<Vec3b>(i, j)[2];
			texture[i][j][1] = origin.at<Vec3b>(i, j)[1];
			texture[i][j][2] = origin.at<Vec3b>(i, j)[0];
			//cout << imgdata[i][j]<<endl;  
		}
	}
}


int main(int argc, char *argv[])
{
	cout << "OpenCV and OpenGL works together!" << endl;
	Mat imgGrey = imread("../image/disparity+.png", 0); //read image as
	//Mat imgGrey = imread("sgbm_disparity.bmp", 0); 
	Mat img = imread("../image/im0.png");
	//Mat imgGrey = imread("dispCensus.jpg", 0);
	//Mat imgGrey = imread("disp2.png", 0);
	GaussianBlur(imgGrey, imgGrey, Size(5, 5), 0, 0);
	if (!imgGrey.data || !img.data)
	{
		cout << "No valid image input." << endl;
		return 1;
	}
	w = imgGrey.cols;
	h = imgGrey.rows;


	displayDisparity(imgGrey,img);
	imshow("original", imgGrey);
	
	float imageCenterX = w*.5;
	float imageCenterY = h*.5;
	float x, y, z;

 
	for (int i = 0; i<h; i++){
		for (int j = 0; j<w; j++){
			// color interpolation  
			//glColor3f(1 - imgdata[i][j] / 255, imgdata[i][j] / 255, imgdata[i][j] / 255);//red,green,blue
			//glColor3f(texture[i][j][0] / 255, texture[i][j][1] / 255, texture[i][j][2] / 255);
			x = ((float)j - imageCenterX) / scalar;
			y = ((float)i - imageCenterY) / scalar;
			z = (255 - imgdata[i][j]) / scalar;
			//glVertex3f(x, y, z);
			PointT p;
	p.x=x;
	p.y=y;
	p.z=z;
	p.b=img.data[i*img.step+j*img.channels()];
	p.g=img.data[i*img.step+j*img.channels()+1];
	p.r=img.data[i*img.step+j*img.channels()+2];
	pointCloud->points.push_back(p);
		}
	}

	//------------------OpenGL-------------------------  
	/*glutInit(&argc, argv);//initialize the GLUT library  
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);//sets the initial display mode  
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("3D disparity image");
	glutDisplayFunc(renderScene);

	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutSpecialFunc(special);
	glutMainLoop();*/
        pointCloud->is_dense=false;
        cout<<"点云共有"<<pointCloud->size()<<"个点"<<endl;
        pcl::io::savePCDFileBinary("map.pcd",*pointCloud);

	//cvWaitKey(10);


	return 0;
}

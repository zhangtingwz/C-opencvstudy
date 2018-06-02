
#include "highgui.h";
#include "cv.h";

/*����ͼƬ*/
/*
int main(int argc, char** argv) {
	
	try
	{
		IplImage* img = cvLoadImage(argv[1]);
		cvNamedWindow("Exceple1", CV_WINDOW_AUTOSIZE);
		cvShowImage("Exceple1", img);
		cvWaitKey(0);
		cvReleaseImage(&img);
		cvDestroyWindow("Exceple1");
	}
	catch (const std::exception&)
	{
		throw ;
	}
	
	

}*/
/*������Ƶ*/
//main(int argc, char** argv) {
//	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
//	CvCapture* captrue = cvCreateFileCapture(argv[1]);//������Ƶ
//	IplImage* frame;
//	while (1) {
//		frame = cvQueryFrame(captrue);
//		if (!frame)break;
//		cvShowImage("Example2", frame);
//		char c = cvWaitKey(33);//�ȴ�33����
//		if (c == 27)break;
//	}
//	cvReleaseCapture(&captrue);
//	cvDestroyWindow("Example2");
//}
/*��Ƶ���ſ���*/
//int g_slider_position = 0;
//CvCapture * g_capture = NULL;
//void onTrackbarSlide(int pos) {
//	cvSetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_POS_FRAMES,
//		pos
//	);
//}
//
//int main(int arc, char**argv) {
//	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
//	g_capture = cvCreateFileCapture(argv[1]);
//	int frames = (int)cvGetCaptureProperty(
//		g_capture,
//		CV_CAP_PROP_FRAME_COUNT
//	);
//	if (frames != 0) {
//		cvCreateTrackbar(
//			"Position",
//			"Example3",
//			&g_slider_position,
//			frames,
//			onTrackbarSlide
//		);
//	}
//	IplImage *frame;
//	return (0);
//}
/*����ͼƬ��ƽ������*/
//#include "cv.h"
//#include "highgui.h"
//
// void main() {
//	 IplImage* src = cvLoadImage("rice.jpg");
//	cvNamedWindow("Example4-in");
//	cvNamedWindow("Example4-out");
//	cvShowImage("Example4-in", src);
//	IplImage* out = cvCreateImage(
//		cvGetSize(src),
//		IPL_DEPTH_8U,
//		3
//	);
//	cvSmooth(src, out, CV_GAUSSIAN, 3, 3);
//	cvShowImage("Example4-out", out);
//	cvReleaseImage(&out);
//	cvWaitKey(0);
//	cvDestroyAllWindows();
//}
/*һ������һ���ı仯*/
//IplImage* doPyrDown(
//	IplImage* in,
//	int filter = CV_GAUSSIAN_5x5
//	){
//	//assert(in->width%2==0&&in->height%2==0);
//	IplImage * out = cvCreateImage(
//		cvSize(in->width / 2, in->height / 2),
//		in->depth,
//		in->nChannels
//		);
//	
//	cvPyrDown(in, out);
//	return out;
//}
///*Canny��Ե��⽫���д��һ����ͨ��(�Ҷȼ�)*/
//IplImage* doCanny(
//	IplImage * in,
//	double lowThresh,
//	double highThresh,
//	double aperture
//) {
//	/*if (in->nChannels != 1)
//		return (0);//Cannyֻ�л�ɫ����*/
//	IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,1);
//	cvCanny(in, out, lowThresh, highThresh, aperture);
//	return (out);
//}
//void main() {
//	cvNamedWindow("1");
//	cvNamedWindow("2");
//	IplImage * in = cvLoadImage("rice.jpg");
//	cvShowImage("1", in);
//	IplImage* out;
//
//	out = doPyrDown(in, CV_GAUSSIAN_5x5);
//	out = doPyrDown(out, CV_GAUSSIAN_5x5);
//	out = doCanny(out, 10, 100, 3);
//	cvShowImage("2", out);
//	cvReleaseImage(&out);
//	cvvWaitKey(0);
//	return;
//}

//CvCapture* capture;
//if (argc == 1) {
//	capture = cvCreateCameraCapture(0);
//}
//else {
//	capture = cvCreateFileCapture(argv[1]);
//}
//assert(capture != NULL);

//argv[1]:input video file
//argv[2]:name of new output file 
/*��Ƶ*/
/*main(int argc, char* argv[]) {
	CvCapture* capture = 0;
	capture = cvCreateFileCapture(argv[1]);//���ȵ�����Ƶ
	if (!capture) {
		return -1;
	}
	IplImage *bgr_frame = cvQueryFrame(capture);//������Ƶ
	double fps = cvGetCaptureProperty(//�����Ƶ�ĸ�����Ҫ����
		capture,
		CV_CAP_PROP_FPS
	);
	CvSize size = cvSize(
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
		);
	CvVideoWriter *writer = cvCreateVideoWriter(
		argv[2],//�ļ�����
		CV_FOURCC('M', 'J', 'P', 'G'),//ѹ�������ʽ
		fps,//���ŵ�֡��
		size//ͼ���С
	);
	IplImage* logpolar_frame = cvCreateImage(
		size,
		IPL_DEPTH_8U,
		3
	);
	while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
		cvLogPolar(bgr_frame, logpolar_frame,
			CvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2),//������֡ͼ��ת��Ϊ����������
			40,
			CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		cvWriteFrame(writer, logpolar_frame);
	}//��֡д����Ƶ�ļ�
	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&logpolar_frame);
	cvReleaseCapture(&capture);
	return(0);
}*/
/*����Mat*/

/*��imageROI������ĳ��Χ������*/
//int main(int argc, char** argv) {
//	IplImage *src= cvLoadImage("rice.jpg");
//		int x = 0;//���ڶ���ת����
//		int y =0;
//		int width =50;
//		int height =50;
//		int add = 150;
//		cvSetImageROI(src, cvRect(x, y, width, height));//ȡһ����
//		cvAddS(src, CvScalar(add), src);
//		cvResetImageROI(src);
//		cvNamedWindow("Roi_Add", 1);
//		cvShowImage("Roi_Add", src);
//		cvvWaitKey(0);
//	return 0;
//}
//int main(int argc, char**argv) {
//	IplImage*src1, *src2;
//	argc = 9;
//	
//	if (argc == 9 && ((src1 = cvLoadImage("rice.jpg")) != 0) && ((src2 = cvLoadImage("rice.jpg")) != 0)) {
//		int x = atoi("20");
//		int y = atoi("20");
//		int width = atoi("200");
//		int height = atoi("200");
//		double alpha = (double)atof("1");//�������������
//		double beta = (double)atof("0.5");
//		cvSetImageROI(src1, cvRect(x, y, width, height));
//		cvSetImageROI(src2, cvRect(0, 0, width, height));
//		cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);//����ͼƬ�ں�
//		cvResetImageROI(src1);
//		cvNamedWindow("Alpha_blend");
//		cvShowImage("Alpha_blend", src1);
//		cvWaitKey(0);
//	}
//	return 0;
//
//}
/*���ص��¼�*/
//void my_mouse_callback(
//	int event, int x, int y, int flags, void * param
//)
//CvRect box;
//bool drawing_box = false;
//
//void draw_box(IplImage*img, CvRect rect) {
//	cvRectangle(
//		img,
//		cvPoint(box.x, box.y),
//		cvPoint(box.x + box.width,box.y+box.height),
//		cvScalar(0xff, 0x00, 0x00)
//	);
//}
//int main(int argc, char* argv[]) {
//	box = cvRect(-1, -1, 0, 0);
//	IplImage*image = cvCreateImage(
//		cvSize(200, 200),
//		IPL_DEPTH_8U,
//		3
//	);
//	cvZero(image);//��������Ὣ�����е�����ͨ����Ԫ�ص�ֵ������Ϊ0.
//	IplImage*temp = cvCloneImage(image);//�������Լ���һ���ڴ棬Ȼ���ƺ�image��������ݣ�Ȼ�������ڴ��е����ݷ���
//	cvNamedWindow("Box Example");
//	cvSetMouseCallback("Box Example", my_mouse_callback, (void*)image);
//
//	while (1) {
//		cvCopy(image, temp);
//		if (drawing_box) draw_box(temp, box);
//		cvShowImage("Box Example", temp);
//		if (cvWaitKey(15) == 27)break;
//	}
//
//	cvReleaseImage(&image);
//	cvReleaseImage(&temp);
//	cvDestroyWindow("Box Example");
//}
//
//void my_mouse_callback(int event,int x,int y,int flags,void*param) {
//	IplImage* image = (IplImage*)param;
//	switch (event)
//	{
//	case CV_EVENT_MOUSEMOVE: {
//		if (drawing_box) {
//			box.width = x - box.x;
//			box.height = y - box.y;
//		}
//	}break;
//	case CV_EVENT_LBUTTONDOWN: {
//		drawing_box = true;
//		box = cvRect(x, y, 0, 0);
//	}break;
//	case CV_EVENT_LBUTTONUP: {
//		drawing_box = false;
//		if (box.width < 0) {
//			box.x += box.width;
//			box.width *= -1;
//		}
//		if (box.height < 0) {
//			box.y += box.height;
//			box.height *= -1;
//		}
//		draw_box(image, box);
//		
//	}break;
//	default:
//		break;
//	}
//}

//void main() {
//	IplImage *src, *dst_blur, *dst_median, *dst_gaussian,*dst_Eorde, *dst_Dilate;
//	src = cvLoadImage("rice.jpg",1);//�������Ҷ�ͼ
//	dst_blur = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
//	dst_median = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
//	dst_gaussian = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
//	dst_Eorde = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
//	dst_Dilate= cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
//	cvNamedWindow("src", 1);
//	cvNamedWindow("blur", 1);
//	cvNamedWindow("median", 1);
//	cvNamedWindow("gaussian", 1);
//	cvNamedWindow("Eorde", 1);
//	cvNamedWindow("Dilate", 1);
//
//	IplConvKernel * x = cvCreateStructuringElementEx(
//		1, 2, 0, 0, CV_SHAPE_CROSS
//	);
//
//	cvSmooth(src, dst_blur, CV_BLUR, 3, 3, 0, 0);         //����ƽ���˲�  
//	//cvSmooth(src, dst_median, CV_MEDIAN, 3, 3, 0, 0);     //��ֵ�˲�   
//	//cvSmooth(src, dst_gaussian, CV_GAUSSIAN, 3, 3, 0, 0); //��˹�˲�  
//	
//	//cvErode(src, dst_Eorde);
//	//cvDilate(src, dst_Dilate);
//	//cvShowImage("src", src);
//	cvShowImage("blur", dst_blur);
//	cvShowImage("median", dst_median);
//	cvShowImage("gaussian", dst_gaussian);
//	cvShowImage("Eorde", dst_Eorde);
//	cvShowImage("Dilate", dst_Dilate);
//	cvWaitKey(0);
//	cvReleaseImage(&src);
//	cvReleaseImage(&dst_blur);
//	cvReleaseImage(&dst_median);
//	cvReleaseImage(&dst_gaussian);
//
//	return ;
//}
/*����ʶ��*/


#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
using namespace cv;


int main() {
	
		Mat image, image_gray;      //��������Mat���������ڴ洢ÿһ֡��ͼ��

		image = imread("2.jpeg");
		cvtColor(image, image_gray, CV_BGR2GRAY);//תΪ�Ҷ�ͼ
		equalizeHist(image_gray, image_gray);//ֱ��ͼ���⻯�����ӶԱȶȷ��㴦��

		CascadeClassifier eye_Classifier;  //���������
		CascadeClassifier face_cascade;

		string cascadeName = "haarcascade_eye.xml";
		eye_Classifier.load(cascadeName);
		//if (!eye_Classifier.load("haarcascade_eye.xml"))  //��Ҫ��xml�ĵ������Լ�ָ����·����
		//{
		//	cout << "Load haarcascade_eye.xml failed!" << endl;
		//	return 0;
		//}

		if (!face_cascade.load("haarcascade_frontalcatface.xml"))
		{
			cout << "Load haarcascade_frontalface_alt failed!" << endl;
			return 0;
		}

		//vector �Ǹ���ģ�� ��Ҫ�ṩ��ȷ��ģ��ʵ�� vector<Rect>���Ǹ�ȷ������ ģ���ʵ����
		vector<Rect> eyeRect;
		vector<Rect> faceRect;

		//�������۾���λλ��
		eye_Classifier.detectMultiScale(image_gray, eyeRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
		for (size_t eyeIdx = 0; eyeIdx < eyeRect.size(); eyeIdx++)
		{
			rectangle(image, eyeRect[eyeIdx], Scalar(0, 0, 255));   //�þ��λ�����⵽��λ��
		}

		//����������λ��
		face_cascade.detectMultiScale(image_gray, faceRect, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
		for (size_t i = 0; i < faceRect.size(); i++)
		{
			rectangle(image, faceRect[i], Scalar(0, 0, 255));      //�þ��λ�����⵽��λ��
		}

		imshow("����ʶ��ͼ", image);         //��ʾ��ǰ֡
		waitKey(0);
		return 0;
}              

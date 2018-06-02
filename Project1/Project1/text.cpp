
#include "highgui.h";
#include "cv.h";
/*加载图片*/
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
/*加载视频*/
//main(int argc, char** argv) {
//	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
//	CvCapture* captrue = cvCreateFileCapture(argv[1]);//创建视频
//	IplImage* frame;
//	while (1) {
//		frame = cvQueryFrame(captrue);
//		if (!frame)break;
//		cvShowImage("Example2", frame);
//		char c = cvWaitKey(33);//等待33毫秒
//		if (c == 27)break;
//	}
//	cvReleaseCapture(&captrue);
//	cvDestroyWindow("Example2");
//}
/*视频播放控制*/
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
/*载入图片并平滑处理*/
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
/*一个复杂一点点的变化*/
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
///*Canny边缘检测将输出写入一个单通道(灰度级)*/
//IplImage* doCanny(
//	IplImage * in,
//	double lowThresh,
//	double highThresh,
//	double aperture
//) {
//	/*if (in->nChannels != 1)
//		return (0);//Canny只有灰色才行*/
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
/*视频*/
/*main(int argc, char* argv[]) {
	CvCapture* capture = 0;
	capture = cvCreateFileCapture(argv[1]);//首先导入视频
	if (!capture) {
		return -1;
	}
	IplImage *bgr_frame = cvQueryFrame(capture);//读入视频
	double fps = cvGetCaptureProperty(//获得视频的各种重要属性
		capture,
		CV_CAP_PROP_FPS
	);
	CvSize size = cvSize(
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
		(int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
		);
	CvVideoWriter *writer = cvCreateVideoWriter(
		argv[2],//文件名称
		CV_FOURCC('M', 'J', 'P', 'G'),//压缩编码格式
		fps,//播放的帧率
		size//图像大小
	);
	IplImage* logpolar_frame = cvCreateImage(
		size,
		IPL_DEPTH_8U,
		3
	);
	while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
		cvLogPolar(bgr_frame, logpolar_frame,
			CvPoint2D32f(bgr_frame->width / 2, bgr_frame->height / 2),//并将各帧图像转换为对数极坐标
			40,
			CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
		cvWriteFrame(writer, logpolar_frame);
	}//逐帧写入视频文件
	cvReleaseVideoWriter(&writer);
	cvReleaseImage(&logpolar_frame);
	cvReleaseCapture(&capture);
	return(0);
}*/
/*创建Mat*/

/*用imageROI来增加某范围的像素*/
//int main(int argc, char** argv) {
//	IplImage *src= cvLoadImage("rice.jpg");
//		int x = 0;//将第二个转数字
//		int y =0;
//		int width =50;
//		int height =50;
//		int add = 150;
//		cvSetImageROI(src, cvRect(x, y, width, height));//取一部分
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
//		double alpha = (double)atof("1");//比例，过大会变白
//		double beta = (double)atof("0.5");
//		cvSetImageROI(src1, cvRect(x, y, width, height));
//		cvSetImageROI(src2, cvRect(0, 0, width, height));
//		cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);//两张图片融合
//		cvResetImageROI(src1);
//		cvNamedWindow("Alpha_blend");
//		cvShowImage("Alpha_blend", src1);
//		cvWaitKey(0);
//	}
//	return 0;
//
//}
/*鼠标回调事件*/
void my_mouse_callback(
	int event, int x, int y, int flags, void * param
)
CvRect box;
bool drawing_box = false;

void draw_box(IplImage*img, CvRect rect) {
	cvRectangle(
		img,
		cvPoint(box.x, box.y),
		cvPoint(box.x + box.width, box.y + box.height),
		cvScalar(0xff, 0x00, 0x00)
	);
}
int main(int argc, char* argv[]) {
	box = cvRect(-1, -1, 0, 0);
	IplImage*image = cvCreateImage(
		cvSize(200, 200),
		IPL_DEPTH_8U,
		3
	);
	cvZero(image);//这个函数会将数组中的所有通道的元素的值都设置为0.
	IplImage*temp = cvCloneImage(image);//函数会自己开一段内存，然后复制好image里面的数据，然后把这段内存中的数据返回
	cvNamedWindow("Box Example");
	cvSetMouseCallback("Box Example", my_mouse_callback, (void*)image);

	while (1) {
		cvCpoyImage(image, temp);
	}
}


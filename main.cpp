#include <cv.hpp>
#include <highgui.hpp>
#include <core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
        Mat src1=imread("1.jpg", 1);
        Mat src2=imread("2.jpg", 1);
        Mat src3=imread("3.jpg", 1);
        Mat src4=imread("4.jpg", 1);
        Mat src5=imread("5.jpg", 1);
        Mat src6=imread("6.jpg", 1);
        Mat src7=imread("7.jpg", 1);
        Mat src8=imread("8.jpg", 1);
        Mat src9=imread("9.jpg", 1);
        Mat src10=imread("10.jpg", 1);
//        Mat src11=imread("11.jpg", 1);
//        Mat src12=imread("12.jpg", 1);
//        Mat src13=imread("13.jpg", 1);
//        Mat src14=imread("14.jpg", 1);
//        Mat src15=imread("15.jpg", 1);
//        Mat src16=imread("16.jpg", 1);
//        Mat src17=imread("17.jpg", 1);
//        Mat src18=imread("18.jpg", 1);
//        Mat src19=imread("19.jpg", 1);
//        Mat src20=imread("20.jpg", 1);

        Mat current=imread("image285.jpg",0);


                imshow("src1",src1);
                waitKey();

        src1.convertTo(src1,CV_32F);
        src2.convertTo(src2,CV_32F);
        src3.convertTo(src3,CV_32F);
        src4.convertTo(src4,CV_32F);
        src5.convertTo(src1,CV_32F);
        src6.convertTo(src2,CV_32F);
        src7.convertTo(src3,CV_32F);
        src8.convertTo(src4,CV_32F);
        src9.convertTo(src1,CV_32F);
        src10.convertTo(src2,CV_32F);

//        src11.convertTo(src3,CV_32F);
//        src12.convertTo(src4,CV_32F);
//        src13.convertTo(src1,CV_32F);
//        src14.convertTo(src2,CV_32F);
//        src15.convertTo(src3,CV_32F);
//        src16.convertTo(src4,CV_32F);
//        src17.convertTo(src1,CV_32F);
//        src18.convertTo(src2,CV_32F);
//        src19.convertTo(src3,CV_32F);
//        src20.convertTo(src4,CV_32F);

        Mat mSum=src1.clone();
//        int i=0;
//        for(i=0;i<4;i++)
//        {

                accumulate(src1, mSum,Mat());
                accumulate(src2, mSum,Mat());
                accumulate(src3, mSum,Mat());
                accumulate(src4, mSum,Mat());
                accumulate(src5, mSum,Mat());
                accumulate(src6, mSum,Mat());
                accumulate(src7, mSum,Mat());
                accumulate(src8, mSum,Mat());
                accumulate(src9, mSum,Mat());
                accumulate(src10, mSum,Mat());
//                accumulate(src11, mSum,Mat());
//                accumulate(src12, mSum,Mat());
//                accumulate(src13, mSum,Mat());
//                accumulate(src14, mSum,Mat());
//                accumulate(src15, mSum,Mat());
//                accumulate(src16, mSum,Mat());
//                accumulate(src17, mSum,Mat());
//                accumulate(src18, mSum,Mat());
//                accumulate(src19, mSum,Mat());
//                accumulate(src20, mSum,Mat());

                mSum.convertTo(mSum,CV_32F,1.0/11.0);
                mSum.convertTo(mSum,CV_8U);
                imshow("sum",mSum);
                waitKey();

                //mSum.convertTo(mSum,CV_32F);
               cvtColor(mSum,mSum,CV_BGR2GRAY);
                imshow("bg",mSum);
                waitKey();

                Mat diff;
                absdiff(current,mSum,diff);
                Mat out;
                threshold(diff,out, 25, 255.0, CV_THRESH_BINARY);
                out.convertTo(out, CV_8U);
                     imshow("out",out);
                waitKey();

                Mat three_frame=imread("t_3qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq.png",0);
                imshow("t",three_frame);
                waitKey();
                Mat img;
                 bitwise_and(out,three_frame,img);
                                      imshow("img",img);
                waitKey();

 //     erode(img,img,Mat(), Point(-1,-1), 7);
    dilate(img,img,Mat());
        erode(img,img,Mat());
   //    dilate(img,img,Mat(), Point(-1,-1),15);
     //   erode(img,img,Mat(), Point(-1,-1), 5);
                                    imshow("img",img);
                waitKey();
        return 0;
}

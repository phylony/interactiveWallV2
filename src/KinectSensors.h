#pragma once 

#include "ofxKinectForWindows2.h"
#include "ofxOpenCv.h"

class KinectSensors {
	public:
		KinectSensors();
		~KinectSensors();

		void draw();
		void keyPressed(int);

	protected:
		int kWidth;
		int kHeight;
		bool bLearnBackground = false;
		bool first = true;

		int thresh_low;
		int thresh_high;

		int blur_amt;
		int blob_min_area;
		int blob_max_area;
		int blob_max_blobs;

		ofPoint					dest_cam_warp[4];
		ofPoint					src_cam_warp[4];
		ofxCvBlob					centroid[10];

		ofPixels				normalPixels;
		ofPixels				diffPixels;

		unsigned short *		orig_shorts; //reference
		unsigned short *		orig_shorts_diff; //deep copy

		ofxCvGrayscaleImage		grayScale;
		ofxCvGrayscaleImage		grayImage;
		ofxCvGrayscaleImage		CV_calc;
		ofxCvGrayscaleImage		CV_diff;

		ofxCvContourFinder		contours;
};
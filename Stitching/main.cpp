#include "opencv2/imgcodecs.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

int main()
{
	String img_names[2];
	img_names[0] = "images/left1.jpg";
	img_names[1] = "images/right1.jpg";

	vector<Mat> imgs;
	for (int i = 0; i < 2; ++i)
	{
		Mat img = imread(img_names[i]);
		imgs.push_back(img);
	}

	Mat pano;
	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA, false);
	stitcher->stitch(imgs, pano);

	imwrite("stitching_result.jpg", pano);
	return 0;
}
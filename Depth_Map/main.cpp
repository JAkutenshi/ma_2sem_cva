#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"

using namespace cv;
using namespace std;

int main()
{
	String img_names[2];
	img_names[0] = "images/right1.jpg";
	img_names[1] = "images/right2.jpg";

	vector<Mat> imgs;
	for (int i = 0; i < 2; ++i)
	{
		Mat img = imread(img_names[i], 0);
		imgs.push_back(img);
	}

	Mat disp, disp8;
	Ptr<StereoBM> bm = StereoBM::create(16, 5);
	bm->compute(imgs.at(0), imgs.at(1), disp);

	imwrite("depth_map_result.jpg", disp);

	return 0;
}




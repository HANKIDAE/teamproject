#pragma once

#include "stdafx.h"
#include "mythread.h"

void program_thread(std::stringstream & cmd)
{
	std::system(cmd.str().c_str());
}

void _camera(ti &o) {
	while (1) {
		o.cam.vc >> o.cam.image;

		if (!o.od->index) {
			memcpy(o.od->SIBimage[0]._pMem, o.cam.image.data, o.od->dsz);
		}
		else {
			memcpy(o.od->SIBimage[1]._pMem, o.cam.image.data, o.od->dsz);
		}

		o.od->ready_flag = true;
		boost::detail::Sleep(40);
	}
}

void _run(ti &t) {
	cv::Mat image, result;

	while (1) {
		image = cv::Mat(t.cam.image);
		if (t.od->run_flag) {
			for (int i = 0; i < t.od->nDetections; i++) {
				std::cout
					<< "classes: " << t.od->classes[i] << "\t"
					<< "scores : " << t.od->scores[i] << "\t"
					<< "boxes  : " << t.od->boxes[i].x << "\t" << t.od->boxes[i].y << "\t"
					<< t.od->boxes[i].width << "\t" << t.od->boxes[i].height
					<< std::endl;
				//#ifdef person


				for (int k = 0; k < 99; k++)
				{
					if (t.od->classes[i] == k) {
						cv::rectangle(image, t.od->boxes[i], cv::Scalar(0, 0, 255), 2);
					}
				}
				//#endif
#ifdef object 
				if (t.od->classes[i] < 70 && t.od->classes[i] != 1) {
					cv::rectangle(image, t.od->boxes[i], cv::Scalar(0, 0, 255), 2);
				}
#endif
			}

			t.od->run_flag = false;
		}
		else {
			boost::detail::Sleep(50);
		}

		result = image.clone();
		imshow("result", result);
		waitKey(20);
	}
}

/*
 * ProjectIO.h
 *
 * for saving and loading the current sfm work
 *
 *  Created on: Apr 9, 2016
 *      Author: yoyo
 */

#ifndef PROJECTIO_H_
#define PROJECTIO_H_

#include <string>
#include <opencv2/core/core.hpp>

class PtCloud;
class PolygonModel;
class ProjectIO {
public:
	ProjectIO();
	virtual ~ProjectIO();

	static void writeProject(	const std::string			&fname,
								const cv::Mat				&camIntrinsicMat,
								const cv::Mat 				&camDistortionMat,
								const PtCloud 				&ptCloud);

	static void readProject(	const std::string			&fname,			//including root
								cv::Mat						&camIntrinsicMat,
								cv::Mat 					&camDistortionMat,
								PtCloud 					&ptCloud);

	static void readGPS(		const std::string			&fname,
								PtCloud						&ptCloud);

	static void readPolygon(	const std::string			&fname,
								PolygonModel				&poly);
};

#endif /* PROJECTIO_H_ */

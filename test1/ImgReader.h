#ifndef ImgReader_H
#define ImgReader_H

#include"parameters.h"
#include <string>
#include<io.h>

#define pos 1
#define neg 0

class Sample
{
public:
	Sample(string _dirName, bool _pos);
	Sample(Mat _img, bool _pos);//test
	~Sample(){};
	bool isPos() const { return m_pos; };

	float m_G[width][heigh][d_set];

private:
	void preCalG(Mat image);

	Mat m_img;
	bool m_pos;

};

class ImgReader
{
	public:
		ImgReader();
		~ImgReader(){};
		vector<Sample> getPosSamples() { return posSamples; };
		vector<Sample> getNegSamples() { return negSamples; };

	private:
		void getFiles(string path, vector<string>& files);

		vector<string> posFiles;
		vector<string> negFiles;
		vector<Sample> posSamples;
		vector<Sample> negSamples;

};

#endif
#ifndef ImgReader_H
#define ImgReader_H

#include"parameters.h"
#include <vector>
#include <string>
#include<io.h>

#define pos 1
#define neg 0

class Sample
{
public:
	Sample(string _dirName, int _type);
	Sample(Mat _img, int _type);
	~Sample(){};
	float m_G[width][heigh][d_set];
	void setValue(float _value) { m_value = _value; };

private:
	void preCalG(Mat image);

	Mat m_img;
	int m_type;
	float m_weight;
	float m_value;

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
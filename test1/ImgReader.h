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
	~Sample(){};
	float m_G[width][heigh][d_set];
	
private:
	void preCalG(Mat image);

	Mat m_img;
	float m_weight;
	int m_type;
	float m_value;
	
};

class ImgReader
{
	public:
		ImgReader();
		~ImgReader(){};
		vector<Sample> posSamples;
		vector<Sample> negSamples;
	private:
		void getFiles(string path, vector<string>& files);

		vector<string> posFiles;
		vector<string> negFiles;

	
};

#endif
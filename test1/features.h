#ifndef features_h
#define features_h

#include"parameters.h"
#include"ImgReader.h"
#include <vector>

class HaarEvaluator
{
public:
	HaarEvaluator();
	~HaarEvaluator();
	
private:
	void generateFeatures();

	class Feature
	{
	public:
		Feature();
		~Feature();
		Feature(int x, int y, int t1, int t2, int type);
		Feature(int x, int y, int t1, int t2, int t3, int type);
		float calc(int type, float G[width][heigh][d_set]);//�����޸Ĳ���Ҫtype���߷ŵ�private���ӿ���ֱ�Ӽ���ֵ��.
	private:
		vector<Point2i> whitePoly;
		vector<Point2i> blackPoly;
	};

	vector<Feature> features;
	vector<Sample> samples;
	//ImgReader imgReader;
};

#endif
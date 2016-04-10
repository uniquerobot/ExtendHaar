#ifndef features_h
#define features_h

#include"parameters.h"
#include"ImgReader.h"
#include <vector>

# define A_1 1
# define B_1 2
# define C_1 3
# define D_1 4
# define E_1 5
# define F_1 6

class HaarEvaluator
{
public:
	HaarEvaluator();
	~HaarEvaluator() {};
	
private:
	void generateFeatures(); 
	void calcSamplesVal(int featureIdx);
	void setSamples();

	class Feature
	{
	public:
		Feature() {};
		~Feature() {};
		Feature(int x, int y, int t1, int t2, int type);
		Feature(int x, int y, int t1, int t2, int t3, int type);
		float calc(float G[width][heigh][d_set]);

	private:
		float fastPolyIntegration(vector<Point2i> vertices, float G[width][heigh][d_set]);
		vector<Point2i> whitePoly;
		vector<Point2i> blackPoly;
		float threshold;

	};

	vector<Feature> features;
	vector<Sample> samples;
	ImgReader imReader;
};

#endif
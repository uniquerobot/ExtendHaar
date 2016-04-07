#ifndef features_h
#define features_h
#include"parameters.h"
#include <vector>

class HaarEvaluator
{
	public:
		HaarEvaluator();
		~HaarEvaluator();
		void preCalG(Mat image);
		void generateFeatures();
	private:
		class Feature
		{
			public:
				Feature();
				~Feature();
				Feature(int x, int y, int t1, int t2, int type);
				Feature(int x, int y, int t1, int t2, int t3, int type);
				float calc(vector<Point2i> vertices, float G[width][heigh][d_set]);

				vector<Point2i> whitePoly;
				vector<Point2i> blackPoly;
		};

		vector<Feature> features;
		float G[width][heigh][d_set];
};

#endif
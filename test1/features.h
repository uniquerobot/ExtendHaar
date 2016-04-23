#ifndef features_h
#define features_h

#include"parameters.h"
#include"ImgReader.h"
#include <ctime>
#include <fstream>

# define A_1 1
# define B_1 2
# define C_1 3
# define D_1 4
# define E_1 5
# define F_1 6
//旋转90度
# define A_2 7 
# define B_2 8
# define C_2 9
# define D_2 12
# define E_2 15
# define F_2 18
//旋转180度
# define C_3 10
# define D_3 13
# define E_3 16
# define F_3 19
//旋转270度
# define C_4 11
# define D_4 14
# define E_4 17
# define F_4 20

# define G_1 1
# define H_1 2
//旋转90度
# define G_2 3
# define H_2 4
//旋转180度
# define G_3 5
# define H_3 6
//旋转270度
# define G_4 7
# define H_4 8

# define big true
# define small false

class Block
{
public:
	~Block() {};
	Block(float _val, int _Idx, bool _type) :b_value(_val), b_index(_Idx), b_positive(_type){};

	float getValue() const { return b_value; };
	int getIndex() const { return b_index; };
	bool isPos() const { return b_positive; };
	void setValue(float _val) { b_value = _val; };
	void setIndex(int _Idx) { b_index = _Idx; };
	void setPos(bool _type) { b_positive = _type; };

private:
	float b_value;
	int b_index;
	bool b_positive;

};

//特征值排序函数(升序)
bool comp(const Block &a, const Block &b);

class HaarEvaluator
{
public:
	HaarEvaluator();
	~HaarEvaluator() {};

private:
	void generateFeatures();
	void setSamples();

	void initial();
	void train();
	void normalize(float &all_face, float &all_non_face);
	void update_weights(int featureIdx);
	bool classifierJudge(float _G[width][heigh][d_set]);
	void outClassifiers();
	void inClassifiers();

	class Feature
	{
	public:
		Feature() {};
		~Feature() {};
		Feature(int x, int y, int t1, int t2, int type);
		Feature(int x, int y, int t1, int t2, int t3, int type);
		float calc(float G[width][heigh][d_set]);
		bool judge(float _value); //判断是否为人脸

		float getThreshold() { return f_threshold; };
		float getError() { return f_error; };
		bool getSign() { return f_sign; };

 		void setThreshold(float _threshold){ f_threshold = _threshold; };
		void setError(float _error) { f_error = _error; };
		void setSign(bool _sign) { f_sign = _sign; };

		int getX() { return f_x; };
		int getY() { return f_y; };
		int getT1() { return f_t1; };
		int getT2() { return f_t2; };
		int getT3() { return f_t3; };
		int getType() { return f_type; };
	private:
		float fastPolyIntegration(vector<Point2i> vertices, float G[width][heigh][d_set]);
		vector<Point2i> whitePoly;
		vector<Point2i> blackPoly;
		float f_threshold;
		float f_error;
		bool f_sign; //符合符号范围为人脸样本
		int f_x;
		int f_y;
		int f_t1;
		int f_t2;
		int f_t3;
		int f_type;

	};

	vector<Feature> features;
	vector<Feature> classifiers;
	vector<Sample> samples;
	ImgReader imReader;
	vector<vector<Block>> FMap;
	float weights[posNum + negNum];
};

#endif
#include "features.h"

//按照计算出的特征值，升序排列样本
bool comp(const Sample &a, const Sample &b)
{
	//return a.getValue() < b.getValue();
}

//--------------------- HaarEvaluator ----------------
HaarEvaluator::HaarEvaluator()
{
	//preCalG(srcImage);
	//samples.push_back(Sample("1.pgm", 1));
	//features.push_back(Feature(0, 5, 1, 1, A_1));
	//cout << "white" << endl;
	//features.at(0).calc(1, samples.at(0).m_G);
	//cout << endl << "black" << endl;
	//features.at(0).calc(0, samples.at(0).m_G);

	//Mat srcImage = imread("1.pgm", 0);
	//for (int i = 0; i < 19; i++)
	//{
	//	for (int j = 0; j < 19; j++)
	//	{
	//		srcImage.at<char>(i, j) = 1;
	//	}
	//}
	//samples.push_back(Sample(srcImage, 1));
	//cout<<features.at(0).calc(samples.at(0).m_G);
	//产生特征池
	generateFeatures();
	//添加样本
	setSamples();
	//权重初始化
	//for (int i = 0; i < samples.size(); i++)
	//{
	//	//初始化样本权重
	//	if (samples.at(i).getType() == pos)
	//	{
	//		samples.at(i).setWeight(1.0 / (2 * posNum));
	//	}
	//	else if (samples.at(i).getType() == neg)
	//	{
	//		samples.at(i).setWeight(1.0 / (2 * negNum));
	//	}
	//}
	//计算阈值
	//for (int i = 0; i < features.size(); i++)
	//{
	//	calcThreshold(i);
	//}
	
	//calcSamplesVal(1);


}

void HaarEvaluator::generateFeatures(){

	int cout1 = 0, cout2 = 0, cout3 = 0, cout4 = 0, cout5 = 0, cout6 = 0;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < heigh; y++)
		{
			for (int t1 = 1; t1 < winsize; t1++)
			{
				for (int t2 = 1; t2 < winsize; t2++)
				{
					//poly A_1
					if ((x + 2 * t1 < width) && (y - 2 * t1 - t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, A_1));
						cout1++;
					}
					//poly B_1
					if ((x + t1 + t2 < width) && (y - t1 - t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, B_1));
						cout2++;
					}
					//poly C_1
					if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 - t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, C_1));
						cout3++;
					}
					//poly D_1
					if ((x + t1 + 2 * t2 < width) && (y - 2 * t1 - 2 * t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, D_1));
						cout4++;
					}
					//poly E_1
					if ((x + t1 + t2 + 2 * t2 / sqrt2 < width) && (y - t1 - t2 - t2 / sqrt2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, E_1));
						cout5++;
					}
					//poly F_1
					if ((x + t1 + t1 / sqrt2 + 2 * t2 / sqrt2 < width) && (y - 2 * t2 - t1 / sqrt2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, F_1));
						cout6++;
					}

					//有t3
					for (int t3 = 1; t3 <= winsize; t3++)
					{

					}
				}
			}
		}
	}
	if (log)
	{
		cout << cout1 << endl
			<< cout2 << endl
			<< cout3 << endl
			<< cout4 << endl
			<< cout5 << endl
			<< cout6 << endl;
	}
}

void HaarEvaluator::setSamples()
{
	//读出正负样本向量
	vector<Sample> tPosSamples = imReader.getPosSamples();
	vector<Sample> tNegSamples = imReader.getNegSamples();

	//添加正，负样本进样本集
	for (int i = 0; i < posNum; i++)
	{
		samples.push_back(tPosSamples.at(i));
	}
	for (int i = 0; i < negNum; i++)
	{
		samples.push_back(tNegSamples.at(i));
	}

}

void HaarEvaluator::calcSampleVal(int featureIdx, int sampleIdx)
{
	float value = features.at(featureIdx).calc(samples.at(sampleIdx).m_G);
	//samples.at(sampleIdx).setValue(value);
}

void HaarEvaluator::calcThreshold(int featureIdx)
{
	float all_face = 0.5;
	float all_non_face = 0.5;
	float before_face = 0;
	float before_non_face = 0;
	float besterro = 1.0;
	float error = 0;
	int index = 0;
	
	for (int i = 0; i < samples.size(); i++)
	{
		//计算样本的特征值
		calcSampleVal(featureIdx, i);
	}

	//按照特征值对样本排序（升序）
	sort(samples.begin(), samples.end(), comp);

	//计算并求得每个元素的误差
	for (int i = 0; i < samples.size(); i++)
	{
		if (samples.at(i).getType() == pos)
		{
			//before_face += samples.at(i).getWeight();
		}
		else if (samples.at(i).getType() == neg)
		{
			//before_non_face += samples.at(i).getWeight();
		}

		//设置误差
		error = min(before_face + (all_non_face - before_non_face), before_non_face + (all_face - before_face));
		//samples.at(i).setError(error);

		if (error < besterro)
		{
			besterro = error;
			index = i;
		}
	}

	//features.at(featureIdx).setThreshold(samples.at(index).getValue());
	//features.at(featureIdx).setError(besterro);

	cout << "feature "<< featureIdx << " complete"<< endl;

}

//--------------------- Feature ----------------
HaarEvaluator::Feature::Feature(int x, int y, int t1, int t2, int type){

	//threshold = 0;

	//poly A_1
	if (type == A_1)
	{
		whitePoly.push_back(Point2i(x, y - t1 - t2));
		whitePoly.push_back(Point2i(x, y - t1));
		whitePoly.push_back(Point2i(x + t1, y));
		whitePoly.push_back(Point2i(x + t1, y - 2 * t1 - t2));

		blackPoly.push_back(Point2i(x + t1, y - 2 * t1 - t2));
		blackPoly.push_back(Point2i(x + t1, y));
		blackPoly.push_back(Point2i(x + 2 * t1, y - t1));
		blackPoly.push_back(Point2i(x + 2 * t1, y - t1 - t2));

	}

	//poly B_1
	if (type == B_1)
	{
		whitePoly.push_back(Point2i(x, y - t1 - t2));
		whitePoly.push_back(Point2i(x, y - t2));
		whitePoly.push_back(Point2i(x + t2, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y));

		blackPoly.push_back(Point2i(x, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1));
		blackPoly.push_back(Point2i(x + t1, y - t1 - t2));
	}

	//poly C_1
	if (type == C_1)
	{
		whitePoly.push_back(Point2i(x, y - t1 - t2));
		whitePoly.push_back(Point2i(x, y - t2));
		whitePoly.push_back(Point2i(x + t2, y - t2));
		whitePoly.push_back(Point2i(x + t2, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));

		blackPoly.push_back(Point2i(x, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y));
		blackPoly.push_back(Point2i(x + 2 * t1 + t2, y - t1));
		blackPoly.push_back(Point2i(x + 2 * t1 + t2, y - 2 * t1 - t2));
		blackPoly.push_back(Point2i(x + t1, y - 2 * t1 - t2));
	}

	//poly D_1
	if (type == D_1)
	{
		whitePoly.push_back(Point2i(x, y - 2 * t1 - 2 * t2));
		whitePoly.push_back(Point2i(x, y - 2 * t1 - t2));
		whitePoly.push_back(Point2i(x + t1, y - t1 - t2));
		whitePoly.push_back(Point2i(x, y - t2));
		whitePoly.push_back(Point2i(x, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));

		blackPoly.push_back(Point2i(x, y - 2 * t1 - 2 * t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x, y));
		blackPoly.push_back(Point2i(x + t2, y));
		blackPoly.push_back(Point2i(x + t1 + 2 * t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t2, y - 2 * t1 - 2 * t2));
	}

	//poly E_1
	if (type == E_1)
	{
		int t3 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;

		whitePoly.push_back(Point2i(x, y - t1 - t2 - t3));
		whitePoly.push_back(Point2i(x, y - t1 - t3));
		whitePoly.push_back(Point2i(x + t1, y - t1 - t3));
		whitePoly.push_back(Point2i(x, y - t3));
		whitePoly.push_back(Point2i(x + t3, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + 2 * t3, y - t1 - t2 - t3));

		blackPoly.push_back(Point2i(x, y - t1 - t3));
		blackPoly.push_back(Point2i(x, y - t3));
		blackPoly.push_back(Point2i(x + t1, y - t1 - t3));
	}

	//poly F_1
	if (type == F_1)
	{
		int t3 = t1 / sqrt2;
		int t4 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;
		if (t4 < 1)
			t4 = 1;

		whitePoly.push_back(Point2i(x, y - t2 - t3));
		whitePoly.push_back(Point2i(x, y - t3));
		whitePoly.push_back(Point2i(x + t1, y - t3));
		whitePoly.push_back(Point2i(x + t1 + t3, y));
		whitePoly.push_back(Point2i(x + t1 + t3 + t4, y - t4));
		whitePoly.push_back(Point2i(x + t1 - t2 + 2 * t4, y - t2 - t3));

		blackPoly.push_back(Point2i(x, y - 2 * t2 - t3));
		blackPoly.push_back(Point2i(x, y - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 - t2 + 2 * t4, y - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + t3 + t4, y - t4));
		blackPoly.push_back(Point2i(x + t1 + t3 + 2 * t4, y - 2 * t4));
		blackPoly.push_back(Point2i(x + t1 - 2 * t2 + 4 * t4, y - 2 * t2 - t3));
	}


}
HaarEvaluator::Feature::Feature(int x, int y, int t1, int t2, int t3, int type){



	//if (type == 1)
	//{
	//	whitePoly.push_back(Point2i());
	//	whitePoly.push_back(Point2i());

	//	blackPoly.push_back(Point2i());
	//	blackPoly.push_back(Point2i());

	//}


}

float HaarEvaluator::Feature::calc(float G[width][heigh][d_set])
{
	return fastPolyIntegration(whitePoly, G) - fastPolyIntegration(blackPoly, G);
}

float HaarEvaluator::Feature::fastPolyIntegration(vector<Point2i> vertices, float G[width][heigh][d_set]){

	int n = vertices.size();//顶点数	
	int d = 0;//斜率
	float sum = 0;//特征值
	Point2i a;
	Point2i b;

	for (int i = 0; i < n; i++)
	{
		//顺时针取两点
		a = vertices.at(i);
		if (i < n - 1)
			b = vertices.at(i + 1);
		else
			b = vertices.at(0);//是最后一个点，则应该返回初始点，构成闭环

		//计算斜率	
		if (b.x == a.x)
			d = d_set - 1;
		else
			d = (b.y - a.y) / (b.x - a.x);

		//检查是否有特征的边界设置错误
		if ((a.x < 0) || (b.x < 0))
		{
			cout << "x坐标出错!" << endl;
		}
		if ((a.y < 0) || (b.y < 0))
		{
			cout << "y坐标出错!" << endl;
		}

		//设置斜率
		if (log){
			//设置斜率
			switch (d)
			{
			case 0:
				d = 0; break;
			case 1:
				d = 1; break;
			case -1:
				d = 2; break;
			case d_set - 1:
				//cout << "斜率为无穷大" << endl; 
				break;
			default:
				cout << "斜率不在斜率集中" << endl;
				cout << "G[" << b.x << "][" << b.y << "][" << d << "] = " << G[b.x][b.y][d] << endl
					<< "G[" << a.x << "][" << a.y << "][" << d << "] = " << G[a.x][a.y][d] << endl;
				break;
			}
		}
		else
		{
			if (d == 0)
				d = 0;
			else if (d == 1)
				d = 1;
			else if (d == -1)
				d = 2;
		}

		//计算特征值
		if (a.x < b.x)
			sum += abs(G[b.x][b.y][d] - G[a.x][a.y][d]);
		else
			sum -= abs(G[b.x][b.y][d] - G[a.x][a.y][d]);

		//test
		//if (log)
		//{
		//	cout << "G[" << b.x << "][" << b.y << "][" << d << "] = " << G[b.x][b.y][d] << endl
		//		<< "G[" << a.x << "][" << a.y << "][" << d << "] = " << G[a.x][a.y][d] << endl;
		//	cout << "sum" << sum << endl;
		//}
	}
	return sum;
}


//--------------------- block ----------------


#include "features.h"

//--------------------- HaarEvaluator ----------------
HaarEvaluator::HaarEvaluator()
{
	//Mat srcImage = imread("1.pgm", 0);
	//for (int i = 0; i < 19; i++)
	//{
	//	for (int j = 0; j < 19; j++)
	//	{
	//		srcImage.at<char>(i, j) = 1;
	//	}
	//}
	//preCalG(srcImage);
	samples.push_back(Sample("1.pgm", 1));
	//generateFeatures();
	features.push_back(Feature(0, 5, 1, 2, 5));
	cout << "white" << endl;
	features.at(0).calc(1, samples.at(0).m_G);
	cout << endl << "black" << endl;
	features.at(0).calc(0, samples.at(0).m_G);

}

HaarEvaluator::~HaarEvaluator()
{
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
						features.push_back(Feature(x, y, t1, t2, 1));
						cout1++;
					}
					//poly B_1
					if ((x + t1 + t2 < width) && (y - t1 - t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, 2));
						cout2++;
					}
					//poly C_1
					if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 - t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, 3));
						cout3++;
					}
					//poly D_1
					if ((x + t1 + 2 * t2 < width) && (y - 2 * t1 - 2 * t2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, 4));
						cout4++;
					}
					//poly E_1
					if ((x + t1 + t2 + 2 * t2 / sqrt2 < width) && (y - t1 - t2 - t2 / sqrt2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, 5));
						cout5++;
					}
					//poly F_1
					if ((x + t1 + t1 / sqrt2 + sqrt2* t2 < width) && (y - 2 * t2 - t1 / sqrt2 >= 0))
					{
						features.push_back(Feature(x, y, t1, t2, 6));
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



//--------------------- Feature ----------------
HaarEvaluator::Feature::Feature(){

}
HaarEvaluator::Feature::~Feature(){

}
HaarEvaluator::Feature::Feature(int x, int y, int t1, int t2, int type){

	//poly A_1
	if (type == 1)
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
	if (type == 2)
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
	if (type == 3)
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
	if (type == 4)
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
	if (type == 5)
	{
		int t3 = t2 / sqrt2;

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
	if (type == 6)
	{
		int t3 = t1 / sqrt2;
		int t4 = t2 / sqrt2;

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
		blackPoly.push_back(Point2i(x + t1 + t3, y - 2 * t2 - t3));
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

/*
type = 1 计算whitePoly
type = 0 计算blackPoly
G 为对应样本的拓展积分图
*/
float HaarEvaluator::Feature::calc(int type, float G[width][heigh][d_set]){
	
	vector<Point2i> vertices;

	if (type == 1)
		vertices = whitePoly;
	if (type == 0)
		vertices = blackPoly;
	
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

		//设置斜率
		if (log){
			//检查是否有特征的边界设置错误
			if ((a.x < 0) || (a.y < 0) || (b.x < 0) || (b.y < 0))
			{
				cout << "坐标出错" << endl;
			}
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
				cout << "斜率为无穷大" << endl; break;
			default:
				cout << "斜率不在斜率集中" << endl; break;
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
		if (log)
		{
			cout << "G[" << b.x << "][" << b.y << "][" << d << "] = " << G[b.x][b.y][d] << endl
				<< "G[" << a.x << "][" << a.y << "][" << d << "] = " << G[a.x][a.y][d] << endl;
			cout << "sum" << sum << endl;
		}
	}
	return sum;
}




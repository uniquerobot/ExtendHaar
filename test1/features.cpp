#include "features.h"

//按照计算出的特征值，升序排列样本
bool comp(const Block &a, const Block &b)
{
	return a.getValue() < b.getValue();
}

//--------------------- HaarEvaluator ----------------
HaarEvaluator::HaarEvaluator()
{
	//产生特征池
	generateFeatures();
	cout << "特征池已生成！" << endl;
	//添加样本
	setSamples();
	cout << "样本已生成！" << endl;
	//初始化样本权重,map
	initial();

	//记录时间
	const clock_t begin_time = clock();
	//训练分类器
	train();
	//显示耗时
	float seconds = float(clock() - begin_time) / CLOCKS_PER_SEC;
	int days = int(seconds) / 60 / 60 / 24;
	int hours = (int(seconds) / 60 / 60) % 24;
	int minutes = (int(seconds) / 60) % 60;
	int seconds_left = int(seconds) % 60;
	cout << "Training has taken " << days << " days " << hours << " hours " << minutes << " minutes " << seconds_left << " seconds." << endl;

	//////test
	////for (int i = 0; i < samples.size(); i++)
	////{
	////	classifierJudge(samples.at(i).m_G);
	////}

	//outClassifiers();

	//inClassifiers();


}

void HaarEvaluator::generateFeatures(){

	int cout1 = 0, cout2 = 0, cout3 = 0, cout4 = 0, cout5 = 0, cout6 = 0, cout7 = 0, cout8 = 0, cout9 = 0, cout10 = 0, cout11 = 0, cout12 = 0,
		cout13 = 0, cout14 = 0, cout15 = 0, cout16 = 0, cout17 = 0, cout18 = 0, cout19 = 0, cout20 = 0, cout21 = 0, cout22 = 0, cout23 = 0, cout24 = 0, cout25 = 0, cout26 = 0, cout27 = 0, cout28 = 0;

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < heigh; y++)
		{
			for (int t1 = 1; t1 < winsize; t1++)
			{
				for (int t2 = 1; t2 < winsize; t2++)
				{
					////poly A_1
					//if ((x + 2 * t1 < width) && (y - 2 * t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, A_1));
					//	cout1++;
					//}
					////poly A_2
					//if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, A_2));
					//	cout8++;
					//}
					////poly B_1
					//if ((x + t1 + t2 < width) && (y - t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, B_1));
					//	cout2++;
					//}
					////poly B_2
					//if ((x + t1 + t2 < width) && (y - t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, B_2));
					//	cout9++;
					//}
					////poly C_1
					//if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, C_1));
					//	cout3++;
					//}
					////poly C_2
					//if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, C_2));
					//	cout10++;
					//}
					////poly C_3
					//if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, C_3));
					//	cout11++;
					//}
					////poly C_4
					//if ((x + 2 * t1 + t2 < width) && (y - 2 * t1 - t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, C_4));
					//	cout12++;
					//}
					////poly D_1
					//if ((x + t1 + 2 * t2 < width) && (y - 2 * t1 - 2 * t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, D_1));
					//	cout4++;
					//}
					////poly D_2
					//if ((x + 2*t1 + 2*t2 < width) && (y - t1 - 2 * t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, D_2));
					//	cout13++;
					//}
					////poly D_3
					//if ((x + t1 + 2 * t2 < width) && (y - 2*t1 - 2 * t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, D_3));
					//	cout14++;
					//}
					////poly D_4
					//if ((x + 2 * t1 + 2 * t2 < width) && (y - t1 - 2 * t2 >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, D_4));
					//	cout15++;
					//}
					////poly E_1
					//if ((x + t1 + t2 + 2 * ceil(t2 / sqrt2) < width) && (y - t1 - t2 - ceil(t2 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, E_1));
					//	cout5++;
					//}
					////poly E_2
					//if ((x + t1 + t2 + ceil(t2 / sqrt2) < width) && (y - t1 - t2 - 2 * ceil(t2 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, E_2));
					//	cout16++;
					//}
					////poly E_3
					//if ((x + t1 + t2 + 2 * ceil(t2 / sqrt2) < width) && (y - t1 - t2 - ceil(t2 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, E_3));
					//	cout17++;
					//}
					////poly E_4
					//if ((x + t1 + t2 + ceil(t2 / sqrt2) < width) && (y - t1 - t2 - 2 * ceil(t2 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, E_4));
					//	cout18++;
					//}
					////poly F_1
					//if ((x + t1 + ceil(t1 / sqrt2) + 2 * ceil(t2 / sqrt2) < width) && (y - 2 * t2 - ceil(t1 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, F_1));
					//	cout6++;
					//}
					////poly F_2
					//if ((x + 2 * t2 + ceil(t1 / sqrt2) < width) && (y - t1 - ceil(t1 / sqrt2) - 2 * ceil(t2 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, F_2));
					//	cout20++;
					//}
					////poly F_3
					//if ((x + t1 + ceil(t1 / sqrt2) + 2 * ceil(t2 / sqrt2) < width) && (y - 2 * t2 - ceil(t1 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, F_3));
					//	cout21++;
					//}
					////poly F_4
					//if ((x + 2 * t2 + ceil(t1 / sqrt2) < width) && (y - t1 - ceil(t1 / sqrt2) - 2 * ceil(t2 / sqrt2) >= 0))
					//{
					//	features.push_back(Feature(x, y, t1, t2, F_4));
					//	cout22++;
					//}
					//有t3
					for (int t3 = 1; t3 <= winsize; t3++)
					{
						//poly G_1
						if ((x + t1 + 2 * t3 + 4 * ceil(t2 / sqrt2) < width) && (y - 2 * t2 - t3 >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, G_1));
							cout7++;
						}
						//poly G_2
						if ((x + 2 * t2 + t3 < width) && (y - t1 - 2 * t3 - 4 * ceil(t2 / sqrt2) >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, G_2));
							cout23++;
						}
						//poly G_3
						if ((x + t1 + 2 * t3 + 4 * ceil(t2 / sqrt2) < width) && (y - 2 * t2 - t3 >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, G_3));
							cout24++;
						}
						//poly G_4
						if ((x + 2 * t2 + t3 < width) && (y - t1 - 2 * t3 - 4 * ceil(t2 / sqrt2) >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, G_4));
							cout25++;
						}
						//poly H_1
						if ((x + t1 + 2*t2 + t3 < width) && (y -t1 - 2 * t2 - t3 >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, H_1));
							cout19++;
						}
						//poly H_2
						if ((x + t1 + 2 * t2 + t3 < width) && (y - t1 - 2 * t2 - t3 >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, H_2));
							cout26++;
						}
						//poly H_3
						if ((x + t1 + 2 * t2 + t3 < width) && (y - t1 - 2 * t2 - t3 >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, H_3));
							cout27++;
						}
						//poly H_4
						if ((x + t1 + 2 * t2 + t3 < width) && (y - t1 - 2 * t2 - t3 >= 0))
						{
							features.push_back(Feature(x, y, t1, t2, t3, H_4));
							cout28++;
						}
					}
				}
			}
		}
	}
	if (log_test)
	{
		cout << cout1 << endl
			<< cout2 << endl
			<< cout3 << endl
			<< cout4 << endl
			<< cout5 << endl
			<< cout6 << endl
			<< cout7 << endl
			<< cout8 << endl
			<< cout9 << endl
			<< cout10 << endl
			<< cout11 << endl
			<< cout12 << endl
			<< cout13 << endl
			<< cout14 << endl
			<< cout15 << endl
			<< cout16 << endl
			<< cout17 << endl
			<< cout18 << endl
			<< cout19 << endl
			<< cout20 << endl
			<< cout21 << endl
			<< cout22 << endl
			<< cout23 << endl
			<< cout24 << endl
			<< cout25 << endl
			<< cout26 << endl
			<< cout27 << endl
			<< cout28 << endl;









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

void HaarEvaluator::initial()
{
	//初始化样本权重
	for (int i = 0; i < samples.size(); i++)
	{
		if (samples.at(i).isPos() == true)
		{
			weights[i] = 1.0 / (2 * posNum);
		}
		else if (samples.at(i).isPos() == false)
		{
			weights[i] = 1.0 / (2 * negNum);
		}
	}
	cout << "权重初始化完毕" << endl;

	//记录时间
	const clock_t begin_time = clock();

	float value = 0;
	//计算map
	for (int featureIdx = 0; featureIdx < features.size(); featureIdx++)
	{
		vector<Block> line;
		for (int sampleIdx = 0; sampleIdx < samples.size(); sampleIdx++)
		{
			value = features.at(featureIdx).calc(samples.at(sampleIdx).m_G);
			line.push_back(Block(value, sampleIdx, samples.at(sampleIdx).isPos()));
		}
		FMap.push_back(line);

		//按照特征值对样本排序（升序）
		sort(FMap.at(featureIdx).begin(), FMap.at(featureIdx).end(), comp);
	}
	cout << "Map计算完毕" << endl;

	//显示耗时
	float seconds = float(clock() - begin_time) / CLOCKS_PER_SEC;
	int days = int(seconds) / 60 / 60 / 24;
	int hours = (int(seconds) / 60 / 60) % 24;
	int minutes = (int(seconds) / 60) % 60;
	int seconds_left = int(seconds) % 60;
	cout << "Calculating Map has taken " << days << " days " << hours << " hours " << minutes << " minutes " << seconds_left << " seconds." << endl;
}

void HaarEvaluator::train()
{
	//计算误差相关统计量
	float all_face = 0.5;
	float all_non_face = 0.5;
	float before_face = 0;
	float before_non_face = 0;

	//记录最好弱分类器相关信息
	bool sign;
	bool featureSign;
	bool bestStageSign;

	float error = 0;
	float bestFeatureError = 1.0;
	float bestStageError = 1.0;

	int sample_index = 0;
	int bestSampleIdx = 0;

	int bestFeatureIdx = 0;

	for (int stage = 0; stage < MaxStage; stage++)
	{
		//权值归一化
		normalize(all_face, all_non_face);
		for (int featureIdx = 0; featureIdx < features.size(); featureIdx++)
		{
			before_face = 0;
			before_non_face = 0;
			bestFeatureError = 1.0;

			sample_index = 0;

			//计算并求得每个元素的误差
			for (int sampleIdx = 0; sampleIdx < FMap.at(featureIdx).size(); sampleIdx++)
			{
				if (FMap.at(featureIdx).at(sampleIdx).isPos() == true)
				{
					before_face += weights[FMap.at(featureIdx).at(sampleIdx).getIndex()];
				}
				else if (FMap.at(featureIdx).at(sampleIdx).isPos() == false)
				{
					before_non_face += weights[FMap.at(featureIdx).at(sampleIdx).getIndex()];
				}

				//计算误差,设置符号
				if ((before_face + (all_non_face - before_non_face)) < (before_non_face + (all_face - before_face)))
				{
					error = before_face + (all_non_face - before_non_face);
					sign = big;
				}
				else
				{
					error = before_non_face + (all_face - before_face);
					sign = small;
				}

				//记录每个特征最好误差，及相应样本索引用于计算阈值
				if (error < bestFeatureError)
				{
					bestFeatureError = error;
					sample_index = sampleIdx;
					featureSign = sign;
				}
			}

			//记录每个阶段最好的误差，及相应的特征索引
			if (bestFeatureError < bestStageError)
			{
				bestStageError = bestFeatureError;
				bestFeatureIdx = featureIdx;
				bestSampleIdx = sample_index;
				bestStageSign = featureSign;
			}

		}

		//设置阈值与相应误差
		features.at(bestFeatureIdx).setThreshold(FMap.at(bestFeatureIdx).at(bestSampleIdx).getValue());
		features.at(bestFeatureIdx).setError(bestStageError);
		features.at(bestFeatureIdx).setSign(bestStageSign);

		//最强弱分类器
		classifiers.push_back(features.at(bestFeatureIdx));

		if (bestStageError == 0) //如果全部分类正确
		{
			cout << "样本数不足，全部分类正确" << endl;
			cout << bestFeatureIdx << endl;
			return;
		}
		//更新权值
		update_weights(bestFeatureIdx);

		cout << bestFeatureIdx << endl;
	}
	
	
}

void HaarEvaluator::normalize(float &all_face, float &all_non_face)
{
	all_face = 0;
	all_non_face = 0;

	float sum = 0;
	for (int i = 0; i < samples.size(); i++)
	{
		sum += weights[i];
	}
	for (int i = 0; i < samples.size(); i++)
	{
		weights[i] /= sum;
		if (i < posNum)
			all_face += weights[i];
		else
			all_non_face += weights[i];
	}
	if (log_test)
	{
	cout << "all face" << all_face << endl
		<< "all non face " << all_non_face << endl;
	}
}

void HaarEvaluator::update_weights(int featureIdx)
{
	float value = 0;
	bool result = false; 

	float err = features.at(featureIdx).getError();
	float beta = (1 - err) / err;

	int index = 0;

	for (int i = 0; i < FMap.at(featureIdx).size(); i++)
	{
		value = FMap.at(featureIdx).at(i).getValue();
		result = features.at(featureIdx).judge(value);
		index = FMap.at(featureIdx).at(i).getIndex();

		//分类错误增大权值
		//判断是人脸,但样本是非人脸
		if ((result == true) && (index >= posNum))
			weights[index] *= beta;
		if ((result == false) && (index < posNum))//判断非人脸，但样本为人脸
			weights[index] *= beta;
	}
}

bool HaarEvaluator::classifierJudge(float _G[width][heigh][d_set])
{
	float val = 0;
	bool m_result;
	bool result = false;

	float err = 0;
	float alpha = 0;
	float sum_alpha = 0;
	float my_alpha = 0;

	for (int i = 0; i < classifiers.size(); i++)
	{
		//计算alpha
		err = classifiers.at(i).getError();
		alpha = log((1 - err) / err);
		sum_alpha += alpha;

		//弱分类器结果
		val = classifiers.at(i).calc(_G);
		m_result = classifiers.at(i).judge(val);
		if (m_result) //弱分类器输出正样本
			my_alpha += alpha;
	}
	if (my_alpha >= 0.5*sum_alpha)
		result = true;

	cout << result << endl;
	return result;
}

void HaarEvaluator::outClassifiers()
{
	string claDirName = ".\\\\";
	claDirName += ClassifierDir;
	claDirName += ".\\\\myClassifiers.txt";
	char * claFilePath = (char *)claDirName.c_str();

	//打开文件流
	ofstream outfile;
	outfile.open(claFilePath);
	if (!outfile)
		cout << "打开文件失败！" << endl;

	float threshold;
	float error;
	bool sign; //符合符号范围为人脸样本
	int x;
	int y;
	int t1;
	int t2;
	int t3;
	int type;

	Feature tempFea;
	//阶段数
	outfile << classifiers.size() << endl;
	
	for (int i = 0; i < classifiers.size(); i++)
	{
		tempFea = classifiers.at(i);
		threshold = tempFea.getThreshold();
		error = tempFea.getError();
		sign = tempFea.getSign();
		x = tempFea.getX();
		y = tempFea.getY();
		t1 = tempFea.getT1();
		t2 = tempFea.getT2();
		t3 = tempFea.getT3();
		type = tempFea.getType();

		//读取特征构建参数
		outfile << x << " " << y << " "
			<< t1 << " " << t2 << " " << t3 << " " << type << " "
			<< threshold << " "
			<< error << " "
			<< sign << " "<<endl;
	}
	//关闭文件流
	outfile.close();
}


void HaarEvaluator::inClassifiers()
{
	string claDirName = ".\\\\";
	claDirName += ClassifierDir;
	claDirName += ".\\\\myClassifiers.txt";
	char * claFilePath = (char *)claDirName.c_str();

	//打开文件流
	ifstream infile;
	infile.open(claFilePath);
	if (!infile)
		cout << "打开文件失败！" << endl;

	int n;
	infile >> n;
	
	int x;
	int y;
	int t1;
	int t2;
	int t3;
	int type;
	float threshold;
	float error;
	bool sign; //符合符号范围为人脸样本
	Feature tempFea;
	for (int i = 0; i < n; i++)
	{
		infile >> x >> y >> t1 >> t2 >> t3 >> type >> threshold >> error >> sign;
		if (t3 == 0)
			tempFea = Feature(x, y, t1, t2, type);
		tempFea.setThreshold(threshold);
		tempFea.setError(error);
		tempFea.setSign(sign);
		classifiers.push_back(tempFea);
	}
}

//--------------------- Feature ----------------
HaarEvaluator::Feature::Feature(int x, int y, int t1, int t2, int type){

	f_x = x;
	f_y = y;
	f_t1 = t1;
	f_t2 = t2;
	f_t3 = 0;
	f_type = type;

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

	//poly A_2
	if (type == A_2)
	{
		whitePoly.push_back(Point2i(x, y - t1));
		whitePoly.push_back(Point2i(x + t1, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y - t1));

		blackPoly.push_back(Point2i(x, y - t1));
		blackPoly.push_back(Point2i(x + 2*t1 + t2, y - t1));
		blackPoly.push_back(Point2i(x + t1 + t2, y - 2*t1));
		blackPoly.push_back(Point2i(x + t1, y - 2*t1));

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

	//poly B_2
	if (type == B_2)
	{
		whitePoly.push_back(Point2i(x, y));
		whitePoly.push_back(Point2i(x + t1, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t2));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t1 -t2));

		blackPoly.push_back(Point2i(x, y - t1));
		blackPoly.push_back(Point2i(x, y));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t2, y - t1 - t2));
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

	//poly C_2
	if (type == C_2)
	{
		whitePoly.push_back(Point2i(x + t1, y));
		whitePoly.push_back(Point2i(x + 2*t1, y));
		whitePoly.push_back(Point2i(x + 2*t1, y - t2));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y - t2));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y - t1 - t2));
		whitePoly.push_back(Point2i(x + t1, y - t1 -t2));

		blackPoly.push_back(Point2i(x, y - t1));
		blackPoly.push_back(Point2i(x + t1, y));
		blackPoly.push_back(Point2i(x + t1, y - t1 - t2));
		blackPoly.push_back(Point2i(x + 2 * t1 + t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - 2*t1 - t2));
		blackPoly.push_back(Point2i(x, y - 2*t1 - t2));
	}

	//poly C_3
	if (type == C_3)
	{
		whitePoly.push_back(Point2i(x + t1, y - 2*t1 - t2));
		whitePoly.push_back(Point2i(x + t1, y - t1));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y - t1));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y - 2*t1));
		whitePoly.push_back(Point2i(x + 2*t1, y - 2*t1));
		whitePoly.push_back(Point2i(x + 2*t1, y - 2*t1 - t2));

		blackPoly.push_back(Point2i(x, y - t1 - t2));
		blackPoly.push_back(Point2i(x, y));
		blackPoly.push_back(Point2i(x + t1 + t2, y));
		blackPoly.push_back(Point2i(x + 2*t1 + t2, y - t1));
		blackPoly.push_back(Point2i(x + t1, y - t1));
		blackPoly.push_back(Point2i(x + t1, y - 2*t1 - t2));
	}

	//poly C_4
	if (type == C_4)
	{
		whitePoly.push_back(Point2i(x, y - 2*t1));
		whitePoly.push_back(Point2i(x, y - t1));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t1));
		whitePoly.push_back(Point2i(x + t1 + t2, y - 2*t1 - t2));
		whitePoly.push_back(Point2i(x + t2, y - 2*t1 - t2));
		whitePoly.push_back(Point2i(x + t2, y - 2*t1));

		blackPoly.push_back(Point2i(x, y - t1));
		blackPoly.push_back(Point2i(x + t1, y));
		blackPoly.push_back(Point2i(x + 2*t1 + t2, y));
		blackPoly.push_back(Point2i(x + 2*t1 + t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - 2*t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1));
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

	//poly D_2
	if (type == D_2)
	{
		whitePoly.push_back(Point2i(x, y));
		whitePoly.push_back(Point2i(x + t2, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t1));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y));
		whitePoly.push_back(Point2i(x + 2*t1 + 2*t2, y));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));

		blackPoly.push_back(Point2i(x, y - t2));
		blackPoly.push_back(Point2i(x ,y));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + 2*t1 + 2*t2, y));
		blackPoly.push_back(Point2i(x + 2*t1 + 2*t2, y - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t1 -2*t2));
	}

	//poly D_3
	if (type == D_3)
	{
		whitePoly.push_back(Point2i(x + t2, y - t1 - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t2, y));
		whitePoly.push_back(Point2i(x + t1 + 2*t2, y - t2));
		whitePoly.push_back(Point2i(x + 2*t2, y - t1 - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t2, y - 2*t1 - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t2, y - 2*t1 - 2*t2));

		blackPoly.push_back(Point2i(x, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t2, y));
		blackPoly.push_back(Point2i(x + t2, y - t1 -t2));
		blackPoly.push_back(Point2i(x + t1 + 2*t2, y - 2*t1 - 2*t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - 2*t1 - 2*t2));
	}

	//poly D_4
	if (type == D_4)
	{
		whitePoly.push_back(Point2i(x, y - t1 - 2*t2));
		whitePoly.push_back(Point2i(x + t1 + t2, y - t2));
		whitePoly.push_back(Point2i(x + 2*t1 + 2*t2, y - t1 - 2*t2));
		whitePoly.push_back(Point2i(x + 2*t1 + t2, y - t1 - 2*t2));
		whitePoly.push_back(Point2i(x + t1 + t2, y - 2*t2));
		whitePoly.push_back(Point2i(x + t2, y - t1 - 2*t2));

		blackPoly.push_back(Point2i(x, y - t1 - 2*t2));
		blackPoly.push_back(Point2i(x, y - t1 - t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y));
		blackPoly.push_back(Point2i(x + 2*t1 + 2*t2, y - t1 - t2));
		blackPoly.push_back(Point2i(x + 2*t1 + 2*t2, y - t1 - 2*t2));
		blackPoly.push_back(Point2i(x + t1 + t2, y - t2));
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

	//poly E_2
	if (type == E_2)
	{
		int t3 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;

		whitePoly.push_back(Point2i(x, y));
		whitePoly.push_back(Point2i(x + t2, y));
		whitePoly.push_back(Point2i(x + t2, y - t1));
		whitePoly.push_back(Point2i(x + t1 + t2, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y - t3));
		whitePoly.push_back(Point2i(x, y - t1 - t2 - 2*t3));

		blackPoly.push_back(Point2i(x + t2, y));
		blackPoly.push_back(Point2i(x + t1 + t2, y));
		blackPoly.push_back(Point2i(x + t2, y - t1));

	}

	//poly E_3
	if (type == E_3)
	{
		int t3 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;

		whitePoly.push_back(Point2i(x, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + 2*t3, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + 2*t3, y - t2));
		whitePoly.push_back(Point2i(x + t2 + 2*t3, y - t2));
		whitePoly.push_back(Point2i(x + t1 + t2 + 2*t3, y - t1 - t2));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y - t1 - t2 - t3));

		blackPoly.push_back(Point2i(x + t2 + 2*t3, y - t2));
		blackPoly.push_back(Point2i(x + t1 + t2 + 2*t3, y - t2));
		blackPoly.push_back(Point2i(x + t1 + t2 + 2*t3, y - t1 -t2));

	}

	//poly E_4
	if (type == E_4)
	{
		int t3 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;

		whitePoly.push_back(Point2i(x, y - t1 - t2 - t3));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y - t1 - t2 -2*t3));
		whitePoly.push_back(Point2i(x + t1 + t3, y - t1 - t2 - 2*t3));
		whitePoly.push_back(Point2i(x + t1 + t3, y - t2 - 2*t3));
		whitePoly.push_back(Point2i(x + t3, y - t1 - t2 - 2*t3));

		blackPoly.push_back(Point2i(x + t3, y - t1 - t2 - 2*t3));
		blackPoly.push_back(Point2i(x + t1 + t3, y - t2 - 2 * t3));
		blackPoly.push_back(Point2i(x + t1 + t3, y - t1 - t2 - 2 * t3));

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

	//poly F_2
	if (type == F_2)
	{
		int t3 = t1 / sqrt2;
		int t4 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;
		if (t4 < 1)
			t4 = 1;

		whitePoly.push_back(Point2i(x + t2, y));
		whitePoly.push_back(Point2i(x + 2*t2, y));
		whitePoly.push_back(Point2i(x + 2*t2, y - t1));
		whitePoly.push_back(Point2i(x + 2*t2 + t3, y - t1 - t3));
		whitePoly.push_back(Point2i(x + 2*t2 + t3 - t4, y - t1 - t3 - t4));
		whitePoly.push_back(Point2i(x + t2, y - t1 + t2 - 2*t4));

		blackPoly.push_back(Point2i(x, y));
		blackPoly.push_back(Point2i(x + t2, y));
		blackPoly.push_back(Point2i(x + t2, y - t1 + t2 - 2*t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - t4, y - t1 - t3 - t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*t4, y - t1 - t3 - 2*t4));
		blackPoly.push_back(Point2i(x, y - t1 + 2*t2 - 4*t4));
	}

	//poly F_3
	if (type == F_3)
	{
		int t3 = t1 / sqrt2;
		int t4 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;
		if (t4 < 1)
			t4 = 1;

		whitePoly.push_back(Point2i(x + t4, y - 2*t2 - t3 + t4));
		whitePoly.push_back(Point2i(x + t2 + t3, y - t2));
		whitePoly.push_back(Point2i(x + t1 + t3 + 2*t4, y - t2));
		whitePoly.push_back(Point2i(x + t1 + t3 + 2*t4, y - 2*t2));
		whitePoly.push_back(Point2i(x + t3 + 2*t4, y - 2*t2));
		whitePoly.push_back(Point2i(x + 2*t4, y - 2*t2 - t3));

		blackPoly.push_back(Point2i(x, y - 2*t2 - t3 + 2*t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*t4, y));
		blackPoly.push_back(Point2i(x + t1 + t3 + 2*t4, y));
		blackPoly.push_back(Point2i(x + t1 + t3 + 2*t4, y - t2));
		blackPoly.push_back(Point2i(x + t2 + t3, y - t2));
		blackPoly.push_back(Point2i(x + t4, y - 2*t2 - t3 + t4));
	}

	//poly F_4
	if (type == F_4)
	{
		int t3 = t1 / sqrt2;
		int t4 = t2 / sqrt2;
		if (t3 < 1)
			t3 = 1;
		if (t4 < 1)
			t4 = 1;

		whitePoly.push_back(Point2i(x, y - 2*t4));
		whitePoly.push_back(Point2i(x + t4, y - t4));
		whitePoly.push_back(Point2i(x + t2 + t3, y - t2 - t3));
		whitePoly.push_back(Point2i(x + t2 + t3, y - t1 - t3 - 2*t4));
		whitePoly.push_back(Point2i(x + t3, y - t1 - t3 - 2*t4));
		whitePoly.push_back(Point2i(x + t3, y - t3 - 2*t4));

		blackPoly.push_back(Point2i(x + t4, y - t4));
		blackPoly.push_back(Point2i(x + 2*t4, y));
		blackPoly.push_back(Point2i(x + 2*t2 + t3, y - 2*t2 -t3 + 2*t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3, y - t1 - t3 - 2*t4));
		blackPoly.push_back(Point2i(x + t2 + t3, y - t1 - t3 - 2*t4));
		blackPoly.push_back(Point2i(x + t2 + t3, y - t2 - t3));
	}

}
HaarEvaluator::Feature::Feature(int x, int y, int t1, int t2, int t3, int type){
	f_x = x;
	f_y = y;
	f_t1 = t1;
	f_t2 = t2;
	f_t3 = t3;
	f_type = type;
	//poly G_1
	if (type == G_1)
	{
		int t4 = t2 / sqrt2;
		if (t4 < 1)
			t4 = 1;

		whitePoly.push_back(Point2i(x + t4, y - t4));
		whitePoly.push_back(Point2i(x + 2*t4, y));
		whitePoly.push_back(Point2i(x + t3 + 2*t4, y - t3));
		whitePoly.push_back(Point2i(x + t1 + t3 + 2*t4,y - t3));
		whitePoly.push_back(Point2i(x + t1 + 2*t3 + 2*t4, y));
		whitePoly.push_back(Point2i(x + t1 + 2*t3 + 3*t4, y - t4));
		whitePoly.push_back(Point2i(x + t1 - t2 + t3 + 4*t4, y - t2 - t3));
		whitePoly.push_back(Point2i(x + t2 + t3, y - t2 - t3));

		blackPoly.push_back(Point2i(x, y - 2*t4));
		blackPoly.push_back(Point2i(x + t4, y - t4));
		blackPoly.push_back(Point2i(x + t2 + t3, y - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 - t2 + t3 + 4 * t4, y - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + 2 * t3 + 3 * t4, y - t4));
		blackPoly.push_back(Point2i(x + t1 + 2*t3 +4*t4, y - 2*t4));
		blackPoly.push_back(Point2i(x + t1 - 2*t2 + t3 + 6*t4, y - 2*t2 - t3));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*t4, y - 2*t2 - t3));

	}

	//poly G_2
	if (type == G_2)
	{
		int t4 = t2 / sqrt2;
		if (t4 < 1)
			t4 = 1;

		whitePoly.push_back(Point2i(x + t2, y - t2 - t3));
		whitePoly.push_back(Point2i(x + 2*t2 + t3 - t4, y - t4));
		whitePoly.push_back(Point2i(x + 2*t2 + t3, y - 2*t4));
		whitePoly.push_back(Point2i(x + 2*t2, y - t3 - 2*t4));
		whitePoly.push_back(Point2i(x + 2*t2, y - t1 - t3 - 2*t4));
		whitePoly.push_back(Point2i(x + 2*t2 + t3, y - t1 - 2*t3 - 2*t4));
		whitePoly.push_back(Point2i(x + 2*t2 + t3 - t4, y - t1 - 2*t3 - 3*t4));
		whitePoly.push_back(Point2i(x + t2, y - t1 + t2 - t3 - 4*t4));

		blackPoly.push_back(Point2i(x, y - 2*t2 - t3 + 2*t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*t4, y));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - t4, y - t4));
		blackPoly.push_back(Point2i(x + t2, y - t2 - t3));
		blackPoly.push_back(Point2i(x + t2, y - t1 + t2 - t3 - 4*t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - t4, y - t1 - 2*t3 - 3*t4));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*t4, y - t1 - 2*t3 - 4*t4));
		blackPoly.push_back(Point2i(x, y - t1 + 2*t2 - t3 - 6*t4));

	}

	//poly G_3
	if (type == G_3)
	{
		int t4 = t2 / sqrt2;
		if (t4 < 1)
			t4 = 1;

		int a = 2 * t2 + t3 - 2 * t4;
		int b = t2 + t3 - t4;

		whitePoly.push_back(Point2i(x + t4, y - a - t4));
		whitePoly.push_back(Point2i(x + t4 + b, y - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t3 + 3*t4 - b, y - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t3 + 3*t4, y - a - t4));
		whitePoly.push_back(Point2i(x + t1 + 2*t3 + 2*t4, y - 2*t2 - t3));
		whitePoly.push_back(Point2i(x + t1 + t3 + 2*t4, y - 2*t2));
		whitePoly.push_back(Point2i(x + t3 + 2*t4, y - 2*t2));
		whitePoly.push_back(Point2i(x + 2*t4, y - a - 2*t4));

		blackPoly.push_back(Point2i(x, y - a));
		blackPoly.push_back(Point2i(x + a, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t3 + 4*t4 - a, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t3 + 4*t4, y - a));
		blackPoly.push_back(Point2i(x + t1 + 2*t3 + 3*t4, y - a - t4));
		blackPoly.push_back(Point2i(x + t1 + 2 * t3 + 3 * t4 - b, y - t2));
		blackPoly.push_back(Point2i(x + t4 + b, y - t2));
		blackPoly.push_back(Point2i(x + t4, y - a - t4));

	}

	//poly G_4
	if (type == G_4)
	{
		int t4 = t2 / sqrt2;
		if (t4 < 1)
			t4 = 1;

		int a = 2 * t2 + t3 - 2 * t4;
		int b = t2 + t3 - t4;

		whitePoly.push_back(Point2i(x, y - 2*t4));
		whitePoly.push_back(Point2i(x + t4, y - t4));
		whitePoly.push_back(Point2i(x + t2 + t3, y - b - t4));
		whitePoly.push_back(Point2i(x + t2 + t3, y - t1 - 2*t3 - 3*t4 + b));
		whitePoly.push_back(Point2i(x + t4, y - t1 - 2*t3 - 3*t4));
		whitePoly.push_back(Point2i(x, y - t1 - 2*t3 - 2*t4));
		whitePoly.push_back(Point2i(x + t3, y - t1 - t3 - 2*t4));
		whitePoly.push_back(Point2i(x + t3, y - t3 - 2*t4));

		blackPoly.push_back(Point2i(x + t4, y - t4));
		blackPoly.push_back(Point2i(x + 2*t4, y));
		blackPoly.push_back(Point2i(x + 2*t2 + t3, y - a));
		blackPoly.push_back(Point2i(x + 2*t2 + t3, y - t1 - 2*t3 - 4*t4 + a));
		blackPoly.push_back(Point2i(x + 2*t4, y - t1 - 2*t3 - 4*t4));
		blackPoly.push_back(Point2i(x + t4, y - t1 - 2*t3 - 3*t4));
		blackPoly.push_back(Point2i(x + t2 + t3, y - t1 - 2*t3 - 3*t4 + b));
		blackPoly.push_back(Point2i(x + t2 + t3, y - b - t4));

	}

	//poly H_1
	if (type == H_1)
	{
		int tx = (sqrt2 - 1)*t2;
		if (tx < 1)
			tx = 1;

		whitePoly.push_back(Point2i(x, y - t1 - t2 - t3));
		whitePoly.push_back(Point2i(x, y - t1 - t3));
		whitePoly.push_back(Point2i(x + t1, y - t1 - t3));
		whitePoly.push_back(Point2i(x + t1 + t3, y - t1));
		whitePoly.push_back(Point2i(x + t1 + t3, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y - t1 - tx));
		whitePoly.push_back(Point2i(x + t1 + tx, y - t1 - t2 -t3));

		blackPoly.push_back(Point2i(x, y - t1 - 2*t2 -t3));
		blackPoly.push_back(Point2i(x, y - t1 - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + tx, y - t1 - t2 -t3));
		blackPoly.push_back(Point2i(x + t1 + t2 + t3, y - t1 - tx));
		blackPoly.push_back(Point2i(x + t1 + t2 + t3, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t1 - 2*tx));
		blackPoly.push_back(Point2i(x + t1 + 2*tx, y - t1 - 2*t2 - t3));

	}

	//poly H_2
	if (type == H_2)
	{
		int a = (sqrt2 - 1)*t2;
		if (a < 1)
			a = 1;

		whitePoly.push_back(Point2i(x + t2, y));
		whitePoly.push_back(Point2i(x + 2*t2, y));
		whitePoly.push_back(Point2i(x + 2*t2, y - t1));
		whitePoly.push_back(Point2i(x + 2*t2 + t3, y - t1 - t3));
		whitePoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t1 - t3));
		whitePoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t1 - t2 - t3));
		whitePoly.push_back(Point2i(x + 2 * t2 + t3 - a, y - t1 - t2 - t3));
		whitePoly.push_back(Point2i(x + t2, y - t1 - a));

		blackPoly.push_back(Point2i(x, y));
		blackPoly.push_back(Point2i(x + t2, y));
		blackPoly.push_back(Point2i(x + t2, y - t1 - a));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - a, y - t1 - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t1 - t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t1 - 2*t2 - t3));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*a, y - t1 - 2*t2 - t3));
		blackPoly.push_back(Point2i(x, y - t1 - 2*a));

	}

	//poly H_3
	if (type == H_3)
	{
		int a = (sqrt2 - 1)*t2;
		if (a < 1)
			a = 1;

		whitePoly.push_back(Point2i(x + t2, y - t1 - 2*t2 - t3));
		whitePoly.push_back(Point2i(x + t2, y - 2*t2 - t3 + a));
		whitePoly.push_back(Point2i(x + 2*t2 + t3 - a, y - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t2));
		whitePoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - 2*t2));
		whitePoly.push_back(Point2i(x + 2*t2 + t3, y - 2*t2));
		whitePoly.push_back(Point2i(x + 2*t2, y - 2*t2 - t3));
		whitePoly.push_back(Point2i(x + 2*t2, y - t1 - 2*t2 - t3));

		blackPoly.push_back(Point2i(x, y - t1 - 2*t2 - t3));
		blackPoly.push_back(Point2i(x, y - 2*t2 - t3 + 2*a));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - 2*a, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t2));
		blackPoly.push_back(Point2i(x + 2*t2 + t3 - a, y - t2));
		blackPoly.push_back(Point2i(x + t2, y - 2*t2 - t3 + a));
		blackPoly.push_back(Point2i(x + t2, y - t1 -2*t2 - t3));

	}

	//poly H_4
	if (type == H_4)
	{
		int a = (sqrt2 - 1)*t2;
		if (a < 1)
			a = 1;

		whitePoly.push_back(Point2i(x, y - 2*t2));
		whitePoly.push_back(Point2i(x, y - t2));
		whitePoly.push_back(Point2i(x + t1 + a, y - t2));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y - 2*t2 - t3 + a));
		whitePoly.push_back(Point2i(x + t1 + t2 + t3, y - t1 - 2*t2 - t3));
		whitePoly.push_back(Point2i(x + t1 + t3, y - t1 - 2*t2 - t3));
		whitePoly.push_back(Point2i(x + t1 + t3, y - 2*t2 - t3));
		whitePoly.push_back(Point2i(x + t1, y - 2*t2));

		blackPoly.push_back(Point2i(x, y - t2));
		blackPoly.push_back(Point2i(x, y));
		blackPoly.push_back(Point2i(x + t1 + 2*a, y));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - 2*t2 - t3 + 2*a));
		blackPoly.push_back(Point2i(x + t1 + 2*t2 + t3, y - t1 - 2*t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + t2 + t3, y - t1 - 2 * t2 - t3));
		blackPoly.push_back(Point2i(x + t1 + t2 + t3, y - 2*t2 - t3 + a));
		blackPoly.push_back(Point2i(x + t1 + a, y - t2));

	}
}

float HaarEvaluator::Feature::calc(float G[width][heigh][d_set])
{
	return fastPolyIntegration(whitePoly, G) - fastPolyIntegration(blackPoly, G);
}

bool HaarEvaluator::Feature::judge(float _value)
{
	bool result = false;

	if ((f_sign == big) && _value > f_threshold) 
		result = true;
	else if ((f_sign == small) && _value < f_threshold)
		result = true;

	return result;
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
			cout << i << endl;
		}

		//设置斜率
		if (log_test){
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
		//if (log_test)
		//{
		//	cout << "G[" << b.x << "][" << b.y << "][" << d << "] = " << G[b.x][b.y][d] << endl
		//		<< "G[" << a.x << "][" << a.y << "][" << d << "] = " << G[a.x][a.y][d] << endl;
		//	cout << "sum" << sum << endl;
		//}
	}
	return sum;
}





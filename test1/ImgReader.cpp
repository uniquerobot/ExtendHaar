#include "ImgReader.h"

//--------------------- ImgReader ----------------
ImgReader::ImgReader(){

	string posDirName = ".\\\\";
	posDirName += posDir;

	string negDirName = ".\\\\";
	negDirName += negDir;

	char * posFilePath = (char *)posDirName.c_str();
	char * negFilePath = (char *)negDirName.c_str();

	//设置正负样本的string向量
	getFiles(posFilePath, posFiles);
	getFiles(negFilePath, negFiles);

	//添加正负样本
	for (int i = 0; i < posFiles.size(); i++)
	{
		posSamples.push_back(Sample(posFiles.at(i), 1));
	}
	for (int i = 0; i < negFiles.size(); i++)
	{
		negSamples.push_back(Sample(negFiles.at(i), 0));
	}
	
	
}

void ImgReader::getFiles(string path, vector<string>& files)
{
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(p.assign(path).append("\\\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
//--------------------- Sample ----------------
/*
type 1 为正样本
type 0 为负样本
*/
Sample::Sample(string _dirName, int _type){
	m_img = imread(_dirName, 0);
	preCalG(m_img);
	m_weight = 0;
	m_value = 0;
	m_type = _type;
}

void Sample::preCalG(Mat image){
	
		//计算积分图(d = 0)
		int s = 0;
		for (int j = 0; j < heigh; j++)
		{
			s = 0;
			for (int i = 0; i < width; i++)
			{
				s += image.at<char>(heigh - 1 - j, i);//默认图像(rows,cols)原点在左下角
				if (j > 0)
					m_G[i][j][0] = s + m_G[i][j - 1][0];
				else
					m_G[i][j][0] = s;
			}
		}
	
		//计算带斜率的积分图(d != 0)
		int x_d, y_d, x_c, y_c;
		for (int d = 1; d < d_set; d++)
		{
			//设置斜率相应x_d，y_d
			if (d == 1)
				x_d = 1;
			else if (d == 2)
				x_d = -1;
			y_d = 1;
	
			//计算
			for (int j = 0; j < heigh; j++)
			{
				for (int i = 0; i < width; i++)
				{
					if (d == d_set - 1)//斜率为无穷大
					{
						m_G[i][j][d] = 0;
					}
					else{
						if ((i - x_d < 0) || (j - y_d < 0))
							m_G[i][j][d] = 0;//x_c,y_c点不在图像范围内
						else
						{
							x_c = i - x_d;
							y_c = j - y_d;
							m_G[i][j][d] = abs(m_G[i][y_c][0] - m_G[x_c][y_c][0]) + m_G[x_c][y_c][d];
						}
						m_G[i][j][d] += 0.5 * image.at<char>(heigh - 1 - j, i);//默认图像(rows,cols)原点在左下角
					}
				}
			}
		}
}
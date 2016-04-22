#include "ImgReader.h"

//--------------------- Sample ----------------
/*
type pos Ϊ������
type neg Ϊ������
*/
Sample::Sample(string _dirName, bool _pos){
	m_img = imread(_dirName, 0); //0--�Ҷ�ͼ
	preCalG(m_img);
	m_pos = _pos;
}

Sample::Sample(Mat _img, bool _pos){
	m_img = _img; //0--�Ҷ�ͼ
	preCalG(m_img);
	m_pos = _pos;
}

void Sample::preCalG(Mat image){

	//�������ͼ(d = 0)
	int s = 0;
	for (int j = 0; j < heigh; j++)
	{
		s = 0;
		for (int i = 0; i < width; i++)
		{
			s += image.at<char>(heigh - 1 - j, i);//Ĭ��ͼ��(rows,cols)ԭ�������½�
			if (j > 0)
				m_G[i][j][0] = s + m_G[i][j - 1][0];
			else
				m_G[i][j][0] = s;
		}
	}

	//�����б�ʵĻ���ͼ(d != 0)
	int x_d, y_d, x_c, y_c;
	for (int d = 1; d < d_set; d++)
	{
		//����б����Ӧx_d��y_d
		if (d == 1)
			x_d = 1;
		else if (d == 2)
			x_d = -1;
		y_d = 1;

		//����
		for (int j = 0; j < heigh; j++)
		{
			for (int i = 0; i < width; i++)
			{
				if (d == d_set - 1)//б��Ϊ�����
				{
					m_G[i][j][d] = 0;
				}
				else{
					if ((i - x_d < 0) || (j - y_d < 0))
						m_G[i][j][d] = 0;//x_c,y_c�㲻��ͼ��Χ��
					else
					{
						x_c = i - x_d;
						y_c = j - y_d;
						m_G[i][j][d] = abs(m_G[i][y_c][0] - m_G[x_c][y_c][0]) + m_G[x_c][y_c][d];
					}
					m_G[i][j][d] += 0.5 * image.at<char>(heigh - 1 - j, i);//Ĭ��ͼ��(rows,cols)ԭ�������½�
				}
			}
		}
	}
}

//--------------------- ImgReader ----------------
ImgReader::ImgReader(){

	string posDirName = ".\\\\";
	posDirName += posDir;

	string negDirName = ".\\\\";
	negDirName += negDir;

	char * posFilePath = (char *)posDirName.c_str();
	char * negFilePath = (char *)negDirName.c_str();

	//��������������string����
	getFiles(posFilePath, posFiles);
	getFiles(negFilePath, negFiles);

	//�����������
	for (int i = 0; i < posFiles.size(); i++)
	{
		posSamples.push_back(Sample(posFiles.at(i), pos));
	}
	for (int i = 0; i < negFiles.size(); i++)
	{
		negSamples.push_back(Sample(negFiles.at(i), neg));
	}
	
	
}

void ImgReader::getFiles(string path, vector<string>& files)
{
	//�ļ����  
	long   hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
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

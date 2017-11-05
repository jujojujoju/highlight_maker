#include "HighlightMaker.h"

void HighlightMaker::makeHighlightVideo(string src_path, string dst_path, vector<pair<int,int>> time_log, string time_length)
{
	//��,��,�� ��꿡 �ʿ��� ���� ����
	int s_hour = 0;
	int s_minute = 0;
	int s_second = 0;
	int s_temp = 0;
	
	//��,��,�ʸ� string���� ǥ��
	string str_temp;
	string str_du;
	ofstream outf("list.txt");
	outf.clear();

	int count = 0;
	for (auto it = time_log.begin(); it != time_log.end(); it++)
	{
		count++;
		//��,��,�� ���
		s_temp = (*it).first;
		s_hour = s_temp / 3600;
		s_temp %= 3600;
		s_minute = s_temp / 60;
		s_temp %= 60;
		s_second = s_temp;
		str_temp = to_string(s_hour) + ":" + to_string(s_minute) + ":" + to_string(s_second);
		str_du = to_string((*it).second);

		string filename = ".\\video\\highlight" + to_string(count) + ".avi";
		//ffmpeg - i input.mp4 - vcodec copy - acodec copy - copyinkf - ss 00:36 : 18 - to 00 : 39 : 50 output.mp4
		string command = ".\\bin\\ffmpeg.exe -y -i 1.avi -ss " + str_temp + " -codec copy -t " + str_du + " " + filename;
		system(command.c_str());

		//split video���� ��ġ�� ���� �۾�
		//split file���� list.txt�� ����
		string fileCommand = "file '" + filename + "'\n";
		outf << fileCommand;
	}
	outf.close();
	//list.txt�� ����� file���� concatenate �ؼ� result.avi ����
	if (time_log.size() != 0) {
		string resultCommand = ".\\bin\\ffmpeg.exe -y -f concat -safe 0 -i list.txt -c copy .\\video\\result.avi";
		system(resultCommand.c_str());
	}
}
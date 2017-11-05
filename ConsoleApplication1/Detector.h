#pragma once
#include "MyThread.h"
#include "opencv2/opencv.hpp"
#include <vector>
#include <chrono>

//#include "emoDetection.h"
using namespace std;
using namespace cv;
using namespace chrono;

class Detector : public MyThread {
public:
	virtual void process();
	vector <pair<int, int>> getTimeLog();
	bool initializeCascade();

private:
	//������ �޾ƿ��� ��ü
	VideoCapture cap;

	//img : �����̹���
	//gray : �����̹����� gray�� �ٲ� �̹���, detection�� ���
	Mat img;
	Mat gray;
	//���� �� ������ ������ cascade ����

	//1. face_cascade : ���� ������ cascade
	//�̼ҿ� ���� ������ ��, �� ��ü�� �������� �����ϰ� �Ǹ� �ν��� ��Ȯ���� ��������(�ϰ������� �ƴ� �ٸ� �������� �����)
	//���� ���� ������ �ϰ����� �������ְ�, �̼ҿ� ���� �����Ѵ�
	//2. mouth_cascade : ���� ������ cascade
	//3. smile_cascade : �̼Ҹ� ������ cascade
	//4. eye_cascade : ���� ������ cascade
	CascadeClassifier face_cascade;
	CascadeClassifier smile_cascade;
	CascadeClassifier mouth_cascade;
	CascadeClassifier eye_cascade;
	//intŸ��(��)�� �ð��α׸� ����ϴ� vector
	//vector<int> time_log;
	vector<pair<int, int>> new_time_log;
};
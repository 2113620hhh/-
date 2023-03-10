#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

class TimerCounter {
	public:
		TimerCounter(void);//���캯��
		~TimerCounter(void);//��������
	private:
		LARGE_INTEGER startCount;//��¼��ʼʱ��

		LARGE_INTEGER endCount;//��¼����ʱ��

		LARGE_INTEGER freq;//����CPUʱ��Ƶ��
	public:
		double dbTime;//�������е�ʱ�䱣��������

	public:
		void Start();//�������ʼ�㴦��ʼ��ʱ
		void Stop();//�����������㴦������ʱ
};

TimerCounter::TimerCounter(void) {
	QueryPerformanceFrequency(&freq);//��ȡ����CPUʱ��Ƶ��
}

TimerCounter::~TimerCounter(void) {
}

void TimerCounter::Start() {
	QueryPerformanceCounter(&startCount);//��ʼ��ʱ
}

void TimerCounter::Stop() {
	QueryPerformanceCounter(&endCount);//ֹͣ��ʱ

	dbTime = ((double)endCount.QuadPart - (double)startCount.QuadPart) / (double)freq.QuadPart; //��ȡʱ���

}
double run(int **arr, int *bian, int n) {
	TimerCounter tc;
	int *jieguo = new int[n];
	tc.Start();

	{
		for (int i = 0; i < n; i++) {
			jieguo[i] = 0;
			for (int j = 0; j < n; j++) {

				jieguo[i] += arr[j][i] * bian[j];
			}
		}
		tc.Stop();
		for (int i = 0; i < n; i++) {
			cout << jieguo[i] << " ";
		}
	}
	cout << "The run time is:" << tc.dbTime * 1000 << "ms" << endl;
	return tc.dbTime;
}
int main() {

	int n = 32500;
	double sum = 0.0;

	int **arr = new int *[n];
	int **arrfuben = new int *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int [n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = i + j ;
		}
	}
	int *bian = new int[n];
	cout << "=============================" << endl;

	for (int i = 0; i < n; i++) {
		bian[i] = i;
	}

	for (int i = 0; i < 10; i++) {
		sum += run(arr, bian, n);
	}
	cout << sum << "s" << endl;
}
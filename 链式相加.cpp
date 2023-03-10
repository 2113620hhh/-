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

double run(int *arr, int n) {

	TimerCounter tc;

	int sum = 0;

	tc.Start();

	for (int i = 0; i < n; i++) {

		sum += arr[i];

	}
	tc.Stop();

	cout << sum << " ";

	cout << "The run time is:" << tc.dbTime * 1000 << "ms" << endl;

	return tc.dbTime * 1000;

}

int num(int n) {
	if (n == 0) {
		return 1;
	} else {
		return 2 * num(n - 1);
	}
}

int main() {

	double sum = 0;
	int n = 50000;
	int *arr = new int [n];
	for (int i = 0; i < n; i++) {
		arr[i] = num(i);
	}
	for (int i = 0; i < 10; i++) {
		sum += run(arr, n);
	}
	cout << sum / 10 << "s" << endl;
}
#include <stdio.h>
#include <math.h>

#define N 10

int main() {
	double data[N];
	int rank[N];
	double sum = 0.0;

	printf("---%d개의 임의의 실수를 입력하세요---\n", N);
	for (int i = 0; i < N; i++) {
		printf(" %d번째 실수 입력: ", i + 1);
		if (scanf_s("%lf", &data[i]) != 1) {
			printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
		
			while (getchar() != '\n');
			return 1;
		}
		sum += data[i];
	}

	double average = sum / N;
	double variance_sum = 0.0;

	for (int i = 0; i < N; ++i) {
	
		variance_sum += pow(data[i] - average, 2);

		rank[i] = 1;
		
		for (int j = 0; j < N; j++) {
			
			if (data[i] < data[j]) {
				rank[i]++;
			}
		}
	}

	
	double variance = (N > 1) ? (variance_sum / (N - 1)) : 0.0;
	double std_dev = sqrt(variance);

	printf("\n---계산 결과---\n");
	printf("평균: %.3f\n", average);

	

	printf("표본 분산 (N-1로 나눔): %.3f\n", variance);
	printf("표준편차: %.3f\n", std_dev);

	printf("\n---입력 데이터 및 순위---\n");
	
	printf("---------------------------\n");
	printf("| 번호 |   데이터   |  순위  |\n");
	printf("---------------------------\n");
	for (int i = 0; i < N; i++) {
		printf("| %4d | %8.3f | %5d |\n", i + 1, data[i], rank[i]);
	}
	printf("---------------------------\n");

	return 0;
}
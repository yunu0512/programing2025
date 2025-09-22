#include <stdio.h>

#define PI_VALUE 3.14159265358979323846

int main(void)
{
	const int year = 2025;

	const char* title = "C\"print\"demo:";
	int widt_demo_num = 123;

	char sample_char = 'A';

	printf("===Constants & Formats ===\n");

	printf("Coures: C programming (v1, %u))\n", year);

	printf("Title : %s\n", title);

	printf("PI default \t : %f\n", PI_VALUE);
	printf("PI 2 digits \t : %.2f\n", PI_VALUE);

	printf("width demo \t :[%8d}\n", widt_demo_num);

	printf("char sample \t : %c\n", sample_char);
	printf("Backslach \t :\\\n");
	return 0;
}

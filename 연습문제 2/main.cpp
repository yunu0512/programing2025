#include <stdio.h>

int main(void)
{
	int age = 28;
	unsigned int count = 3000000000;
	float score = 93.5f;
	const char* title = "Basic constants";
	const char* name = "Taejun";
	char initial = name[0];
	printf("=== %s ===\n Name \t : %s\n lnitial : %c\n age : %d\n score \t : %.6f\n count \t : %u\n", title,name,initial,age,score,count);
}

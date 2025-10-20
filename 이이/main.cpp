#include <stdio.h>

int main(void)
{
	int nAge = 99;
	float fHeight = 999.0f;
	double dWeight = 999.0;

	
	char chTemp = '\0';
	char chString[100] = "";

	printf("input your alphabet and word:\n");
	scanf_s("%c%s", &chTemp, sizeof(chTemp), chString, sizeof(chString));
	printf("input your information(age, height,weight):\n");
	scanf_s("%d%f%lf", &nAge, &fHeight, &dWeight);
	printf("Output\n");
	printf("(Alphabet: %c)(Word: %s)\n", chTemp, chString);
	printf("(Age:%d)(Height:%.2f)(Weight:%.1lf)\n", nAge, fHeight, dWeight);

	return 0;
}
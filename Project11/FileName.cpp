#include <stdio.h>
double centi_to_mater(int cm);

int main(void)
{
	int centimeters = 187; 
	double res;

	res = centi_to_mater(centimeters); 
	printf("%.2fm\n", res);
	return 0;
}
double centi_to_mater(int cm)
{
	double meter = (double)cm / 100;
	return meter;
}
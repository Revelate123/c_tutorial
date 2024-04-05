#include <stdio.h>

/* count digits, white space, others */
/* display as histogram vertically */
int main(void)
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}
	/* needs to place a space if no value and an x if value */
	/* Need to get largest value of histogram */
	int max_value = 0;

	for (i = 0; i < 10; ++i){
		if (ndigit[i] > max_value)
			max_value = ndigit[i];
	}
	int counter = max_value;
	for (i = 0; i < max_value; ++i){
		for (int j = 0; j < 10; ++j){
			if (ndigit[j] >= counter){
				printf(" x");
			}
			else
				printf("  ");
		}
		printf("\n");
		--counter;
	}	
	for (i = 0; i < 10; ++i)
		printf(" -");
	
	printf("\n");
	for (i = 0; i < 10; ++i){
		printf(" %d",i);
	
	}
	printf(", white space = %d, other = %d\n",
			nwhite, nother);

	return 0;
}

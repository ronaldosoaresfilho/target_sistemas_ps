#include <stdio.h>

int main(void)
{
    int index = 13;
	int sum = 0;
	int k = 0;

	while(k < index) {
    	k = k + 1;
    	sum = sum + k;
	}
	printf("%d\n", sum);

	return 0;
}

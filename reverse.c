#include <stdio.h>

void reverse(char *str) {
    int i = 0;
	int j = 0;
	char tmp;

    while (str[j] != '\0') { 
		j++;
	}
    j--;

    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++; 
		j--;
    }
}

int main() {
    char str[] = "Ronaldo";
    
	reverse(str);
    printf("Reversed string: %s\n", str);
    
	return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char message[100], ch;
	int i, key, inc, mult;

	inc = 0;
	printf("what you want to decrypt here: \n");
	gets(message);
	printf("incremental? 1 or 0: \n");
	scanf("%d", &inc);
	printf("step size: \n");
	scanf("%d", &key);

	for (i = 0; message[i] != '\0'; ++i) {
		ch = message[i];

		if (ch >= '!' && ch <= '~') {
			if (inc == 0) {
				ch = ch - key;
			}
			else {
				ch = ch - (key * i);
			}

			if (ch < '!') {
				ch = ch + '~' - '!' + 1;
			}

			message[i] = ch;
		}
	}

	printf("%s", message);
	printf("\n");
	system("pause");

	return 1;
}

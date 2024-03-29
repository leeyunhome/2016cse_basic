#include <stdio.h>

#define MAX_STR 256

int main()
{
	char input_string[MAX_STR];
	char encrypted_string[MAX_STR];

	int flag = scanf("%s", input_string);

	for (int i = 0; i < MAX_STR; i = i + 1)
	{
		char c = input_string[i];

		encrypted_string[i] = c;

		if (c == '\0')
			break;

		int ascii = (int)c;	// casting char to int
		int ascii_en = ascii - 3;

		if (ascii_en < 65)
			ascii_en += 26;

		char c_en = (char)ascii_en;
		encrypted_string[i] = c_en;

		//printf("%c", c_en);
	}

	printf("%s\n", encrypted_string);

	for (int i = 0; i < MAX_STR; i = i + 1)
	{
		char c = encrypted_string[i];

		if (c == '\0')
			break;

		int ascii = (int)c;	// casting char to int
		int ascii_de = ascii + 3;

		if (ascii_de > 'Z')
			ascii_de -= 26;

		char c_de = (char)ascii_de;

		printf("%c", c_de);
	}

	return 0;
}




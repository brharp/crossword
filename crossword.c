#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define MAX_WORD 500
#define BLANK '_'

int main(int argc, char *argv[])
{
	char word[MAX_WORD];
	char pat[MAX_WORD];
	char scratch[MAX_WORD];
	int i, n;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s WORD\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	strcpy(pat, argv[1]);

	while (fgets(word, MAX_WORD-1, stdin) != NULL)
	{
		n = strlen(word);

		if (word[n-1] == '\n')
		{
			word[n-1] = '\0';
			n--;
		}

		strcpy(scratch, pat);
		for (i = 0; scratch[i] && word[i]; i++)
		{
			if (scratch[i] == BLANK)
			{
				scratch[i] = word[i];
			}
		}

		if (strcmp(word, scratch) == 0)
		{
			printf("%s\n", word);
		}
	}

	exit(EXIT_SUCCESS);
}



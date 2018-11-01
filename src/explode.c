#include <stdlib.h>
#include <string.h>

char **explode(char *str, const char *delim)
{
	char **tab = malloc(sizeof(char *));

	if (!tab)
		return NULL;
	tab[0] = strtok(str, delim);
	for (size_t i = 0; tab[i] != NULL; ) {
		i++;
		tab = realloc(tab, sizeof(char *) * (i + 1));
		if (!tab)
			return NULL;
		tab[i] = strtok(NULL, delim);
	}
	return tab;
}

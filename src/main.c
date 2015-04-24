#include "config.h"
#include <stdio.h>
#include "foo.h"

#if defined(USE_LIBCONFIG)

void load_config(int *verbose)
{
	config_t cfg;
	config_setting_t *setting;
	const char *str;

	config_init(&cfg);

	if (config_read_file(&cfg, "bar.cfg") == CONFIG_FALSE)
	{
		config_destroy(&cfg);
		*verbose = 0;
		return;
	}

	if (config_lookup_string(&cfg, "verbose", &str) == CONFIG_FALSE)
	{
		config_destroy(&cfg);
		*verbose = 0;
		return;
	}

	if (strcmp(str, "yes"))
		*verbose = 1;

	config_destroy(&cfg);
	return;
}
#else /* USE_LIBCONFIG */
void load_config(int *verbose)
{
	*verbose = 0;
}
#endif /* USE_LIBCONFIG */

int main(void)
{
	int verbose;
	int result;

	load_config(&verbose);

	result = libfoo_add(2, 3);

	if (verbose)
		printf("Result of the addition: %d\n", result);
	else
		printf("%d\n", result);

	return 0;
}

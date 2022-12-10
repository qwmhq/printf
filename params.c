#include "main.h"

/**
 * init_params - initialize parameters struct
 *
 * Return: pointer to parameters struct
 */
params_t *init_params(void)
{
	params_t *params = malloc(sizeof(params_t));

	if (params == NULL)
		exit(1);
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hash_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;

	return (params);
}

/**
 * free_params - free a parameter struct
 *
 * @params: the parameter struct
 */
void free_params(params_t *params)
{
	free(params);
}

#include "main.h"

/**
 * init_params - Initializes the parameters struct with default values.
 * @params: The parameters struct to initialize.
 * @ap: The argument pointer (unused).
 */
void init_params(params_t *params, va_list ap)
{
    // Clear all struct fields.
    params->unsign = params->plus_flag = params->space_flag = params->hashtag_flag = 0;
    params->zero_flag = params->minus_flag = params->h_modifier = params->l_modifier = 0;

    // Reset width and precision.
    params->width = 0;
    params->precision = UINT_MAX;

    (void)ap; // Avoid unused argument warning.
}

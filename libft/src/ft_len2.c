#include "libft.h"

int                 ft_len2(char **s)
{
    int             i;

    i = 0;
    while (s[i] != NULL)
        i++;
    return (i);
}

#include "libft.h"

static int	skipwhitespace(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static long long	update_num_value(char digit, int base, int num)
{
	char					*digits;
	long long			i;

	i = 0;
	digits = ft_strdup("0123456789abcdef");
	while (digits[i] && digits[i] != digit)
		++i;
	num *= base;
	num += i;
	free(digits);
	return (num);
}

long long		ft_atoi_base(const char *str, int base)
{
	int				i;
	int				negative;
	long long	num;
	char			digit;

	num = 0;
	negative = 0;
	i = skipwhitespace(str);
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') ||
																		(str[i] >= 'a' && str[i] <= 'f') ||
																		(str[i] >= 'A' && str[i] <= 'F')))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			digit = ft_tolower(str[i]);
		else
			digit = str[i];
		num = update_num_value(digit, num, base);
		i++;
	}
	if (negative)
		num = -num;
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:43:27 by hehuang           #+#    #+#             */
/*   Updated: 2016/10/20 23:56:59 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *s, char c, int i)
{
	int	word_end;
	int len;

	word_end = i;
	while (s[word_end] != c && s[word_end] != '\0')
		word_end++;
	len = word_end - i;
	return (len);
}

static int	word_count(char const *s, char c)
{
	int		cnt_iter;
	int		count;

	cnt_iter = 0;
	count = 0;
	while (s[cnt_iter] != '\0')
	{
		while (s[cnt_iter] == c && s[cnt_iter] != '\0')
			cnt_iter++;
		if (s[cnt_iter] != '\0' && s[cnt_iter])
			count++;
		while (s[cnt_iter] != c && s[cnt_iter] != '\0')
			cnt_iter++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int i)
{
	int		wrd_iter;
	int		len;
	char	*word;

	wrd_iter = 0;
	len = get_word_len(s, c, i);
	word = (char*)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (wrd_iter < len)
		word[wrd_iter++] = s[i++];
	word[wrd_iter] = '\0';
	return (word);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (word_count(s, c) + 1));
	if (!ret)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			ret[j++] = get_word(s, c, i);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	ret[j] = NULL;
	return (ret);
}

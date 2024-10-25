/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmoril <jesmoril@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:09:25 by jesmoril          #+#    #+#             */
/*   Updated: 2024/09/30 12:09:27 by jesmoril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free(char **s, int size)
{
	while (size--)
		free(s[size]);
	return (1);
}

size_t	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

int	ft_cut_word(char **cuts, const char *s, char c)
{
	int	i;
	int	word;
	int	wordlen;

	i = 0;
	word = 0;
	wordlen = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || s[i] == '\0') == 1)
			i++;
		else
		{
			wordlen = 0;
			while ((s[i + wordlen] == c || s[i + wordlen] == '\0') == 0)
				wordlen++;
			cuts[word] = (char *)malloc(sizeof(char) * (wordlen + 1));
			if (cuts[word] == 0)
				return (ft_free(cuts, word - 1));
			ft_strlcpy(cuts[word], s + i, wordlen + 1);
			i += wordlen;
			word++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**cuts;
	size_t	words;

	words = ft_count_words(s, c);
	cuts = (char **)malloc((words + 1) * sizeof(char *));
	if (cuts == 0)
		return (0);
	cuts[words] = 0;
	if (ft_cut_word(cuts, s, c))
		return (0);
	return (cuts);
}

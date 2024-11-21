/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:45:25 by aternero          #+#    #+#             */
/*   Updated: 2024/11/20 14:46:07 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str, int letter)
{
	while (letter > 0)
	{
		if (str[letter - 1])
		{
			free(str[letter - 1]);
			str[letter - 1] = NULL;
		}
		letter--;
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	fill_words(const char *s, char c, char **str, size_t *length)
{
	length[1] = 0;
	while (*s)
	{
		if (*s != c)
		{
			length[0] = 0;
			while (*s && *s != c)
			{
				s++;
				length[0]++;
			}
			str[length[1]] = ft_substr(s - length[0], 0, length[0]);
			if (!str[length[1]])
			{
				ft_free(str, length[1]);
				return ;
			}
			length[1]++;
		}
		else
			s++;
	}
	str[length[1]] = 0;
}

static size_t	word_counter(const char *s, char c)
{
	size_t	index;
	size_t	word;

	index = 0;
	word = 0;
	while (s[index] != '\0')
	{
		if (s[index++] != c && (s[index] == c || s[index] == '\0'))
			word++;
	}
	return (word);
}

char	**allocate_memory(const char *s, char c)
{
	char	**str;

	str = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	length[2];

	str = allocate_memory(s, c);
	if (!str)
		return (NULL);
	fill_words(s, c, str, length);
	return (str);
}

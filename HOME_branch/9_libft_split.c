/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:01:00 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 20:05:11 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			str[length[1]] = substr(s - length[0], 0, length[0]);
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

size_t	word_counter(const char *s, char c)
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

char	**split(const char *s, char c)
{
	char	**str;
	size_t	length[2];

	str = allocate_memory(s, c);
	if (!str)
		return (NULL);
	fill_words(s, c, str, length);
	if (str)
		return (str);
	return (NULL);
}

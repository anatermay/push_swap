/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:33:15 by aternero          #+#    #+#             */
/*   Updated: 2024/11/17 20:11:07 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	index[2];

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	while (s1[index[0]])
	{
		str[index[0]] = s1[index[0]];
		index[0]++;
	}
	while (s2[index[1]])
		str[index[0]++] = s2[index[1]++];
	str[index[0]] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n && (s1[index] != '\0' || s2[index] != '\0'))
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

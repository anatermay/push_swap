/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_continue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:57:12 by aternero          #+#    #+#             */
/*   Updated: 2024/11/20 14:48:33 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	y;
	size_t	len;
	size_t	x;

	y = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (dstsize == 0)
	{
		return (len);
	}
	x = dstsize - 1;
	while (y < x && src[y] != '\0')
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*box;
	size_t	len;

	len = ft_strlen(s1) + 1;
	box = malloc(len);
	if (box == 0)
		return (0);
	ft_strlcpy(box, s1, len);
	return (box);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen)
		return (ft_strdup(""));
	sublen = len;
	if (start + sublen > slen)
		sublen = slen - start;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sublen + 1);
	sub[sublen] = '\0';
	return (sub);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsplit_continue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:06:16 by aternero          #+#    #+#             */
/*   Updated: 2024/10/29 20:08:28 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}

size_t	strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	y;
	size_t	len;
	size_t	x;

	y = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	x = dstsize - 1;
	while (y < x && src[y] != '\0')
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (len);
}

char	*strdup(const char *s1)
{
	char	*box;
	size_t	len;

	len = strlen(s1) + 1;
	box = malloc(len);
	if (box == 0)
		return (0);
	strlcpy(box, s1, len);
	return (box);
}

char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = strlen((char *)s);
	if (start >= slen)
		return (strdup(""));
	sublen = len;
	if (start + sublen > slen)
		sublen = slen - start;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	strlcpy(sub, s + start, sublen + 1);
	sub[sublen] = '\0';
	return (sub);
}

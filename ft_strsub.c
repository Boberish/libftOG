/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:38:52 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/05 15:46:39 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	char	*beg;
	size_t	n;

	n = len;
	if (!s)
		return (NULL);
	new = (char*)malloc(sizeof(*new) * (len + 1));
	if (!new)
		return (NULL);
	beg = new;
	while (n--)
		*(new++) = s[start++];
	*new = '\0';
	return (beg);
}

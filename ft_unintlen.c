/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:50:41 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/07 17:57:50 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unintlen(uintmax_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
		return (11);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:26:25 by jaylor            #+#    #+#             */
/*   Updated: 2016/12/06 19:11:22 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
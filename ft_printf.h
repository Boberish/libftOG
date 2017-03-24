/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:00:30 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/24 10:24:01 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define WIDTH_HH 1
# define WIDTH_H 2
# define WIDTH_NORMAL 3
# define WIDTH_L 4
# define WIDTH_LL 5
# define WIDTH_J 6
# define WIDTH_Z 7

typedef struct		s_print
{
	int             just;
    char            sign;
    char            *s;
    char            *eval;
    int             i;
    va_list         ap;
    int             spa;
    int             pad;
    int             hash;
    int             wid;
    int             prec;
    int             len;
    int             h;
    int             hh;
    int             lh;
    int             l;
    int             ll;
    int             z;
    int             j;
    char            spe;
    size_t          slen;
    intmax_t      ifree;
    int             neg;
    int             ilen;
    char            *ms;
    int             *ret;
    int             cast;
    uintmax_t       inofree;
    
    
    
}					t_print;
int strprint(t_print *h);
int ftsort(t_print *h);
int parse(t_print *h);

int		ft_printf(char	*format, ...);
#endif

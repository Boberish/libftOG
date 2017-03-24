/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:14:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/11 14:51:19 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void    ft_unputnbr(uintmax_t n)
{
    uintmax_t    nb;
    
    nb = n;
    if (nb > 9)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
    {
        ft_putchar(nb + '0');
    }
}
int intprint(t_print *h);

int pfilter(t_print *h)
{
    if (h->prec < 1 && (ft_strchr(h->eval, '.')) && h->ifree == 0)
    {
       *(h->ret) = *(h->ret) - 1;
      
        return (1);
    }
    if (h->ifree < 0)
        h->ifree *= -1;
    if (h->sign == '-' && !(h->pad))
        ft_pfpchar('-', h->ret);
    ft_unputnbr(h->ifree);
  //  else
       // ft_putnbr(ft_abs(h->ifree));
    return (0);
}

char    *checkHashPad(t_print *h)
{
    char *new;
    int     i;
    
    new = (char*)malloc(sizeof(char) * (ft_strlen(h->s) + h->wid + 3));
    i = 0;
 
    h->wid -= h->ilen;
    
    
    new[i++] = '0';
    new[i++] = 'x';
    while ((h->wid)--)
    {
        new[i] = '0';
        i++;
    }
    ft_strcpy(&new[i], h->s);
    h->s = new;
    h->hash = 0;
    return (new);
}

char    *crazy(t_print *h)
{
    char *new;
    int     i;
    
    new = (char*)malloc(sizeof(char) * (ft_strlen(h->s) + h->wid + 3));
    i = 0;
    if (h->pad && h->wid)
    {
      //  if (h->hash)
     //       h->wid -= 2;
        h->wid -= h->ilen;
    }
    if (h->hash)
    {
        new[i++] = '0';
        new[i++] = 'x';
    }
    while ((h->wid)--)
    {
        new[i] = '0';
        i++;
    }
    ft_strcpy(&new[i], h->s);
    h->s = new;
    h->hash = 0;
    return (new);
}


int wid(t_print *h)
{
    if (h->wid > h->ilen)
    {
        if (h->pad)
        {
            if (h->sign)
                ft_putxchar('0', h->wid - h->ilen - 1, h->ret);
            else
                ft_putxchar('0', h->wid - h->ilen, h->ret);
        }
        else
        {
            if (h->sign)
                ft_putxchar(' ', h->wid - h->ilen - 1, h->ret);
            else
                ft_putxchar(' ', h->wid - h->ilen, h->ret);
        }
    }
    return (0);
}

int hexwid(t_print *h)
{
    if (h->wid > h->ilen)
    {
        ft_putxchar(' ', h->wid - h->ilen, h->ret);
    }
    return (0);
}


void    clearstr(t_print *h)
{
    h->just = 0;
    h->sign = '\0';
    h->s = NULL;
    h->spa = 0;
    h->pad = 0;
    h->hash = 0;
    h->wid = 0;
    h->prec = 0;
    h->len = 0;
    h->hh = 0;
    h->lh = 0;
    h->l = 0;
    h->ll = 0;
    h->z = 0;
    h->j = 0;
    h->slen = 0;
    h->ifree = 0;
    h->neg = 0;
    h->ilen = 0;
    h->cast = 1;
}
int ifmod(t_print *h)
{
    if (h->hh == 1)
    {
        h->ifree = va_arg(h->ap, int);  //its a char
        h->ifree = (char)h->ifree;
        return (1);
    }
    else if (h->lh == 1)
    {
        h->ifree = va_arg(h->ap, int); // short
        h->ifree = (short)h->ifree;
        return (1);
    }
    else if (h->l == 1)
    {
        
        if (h->spe == 'u')
           h->ifree = (uintmax_t)(unsigned long)va_arg(h->ap, unsigned long);
        else
            h->ifree = va_arg(h->ap, long);
        //h->inofree = (unsigned long)h->ifree;
        return (1);
    }
    else if (h->ll == 1)
    {
        h->ifree = va_arg(h->ap, long long);
        return (1);
    }
    else if (h->z == 1)
    {
        h->ifree = va_arg(h->ap, size_t);
        return (1);
    }
    else if (h->j == 1)
    {
        h->ifree = va_arg(h->ap, intmax_t);
        return (1);
    }
    else
        return (0);
}

char *UnItoaIntMaxT(uintmax_t num, int base)
{
    char    *thing;
    long long     hold;
    int     i;
    char    digits[] = "0123456789abcdef";
    
    hold = 1;
    i = 0;
    thing = (char*)malloc(sizeof(char) * (1000));
    while (hold < (int)(num / base))
        hold *= base;
    while (hold)
    {
        thing[i] = digits[num/hold];
        num %= hold;
        hold /= base;
        i++;
    }
    thing[i] = '\0';
    return (thing);
}

int ifhash(t_print *h)
{
    if (h->hash)
    {
        if (h->spe == 'X')
            ft_putstr("0X");
        else
            ft_putstr("0x");
    }
    return (0);
}

char				*UnItoaIntMaxTs(uintmax_t value, unsigned short base)
{
    char	*ret;
    char	*dig;
    int		i;
    
    dig = "0123456789abcdef";
    
    if ((ret = malloc(sizeof(*ret) * (1000))))
    {
        i = 0;
        while (value != 0 || (i == 0))
        {
            ret[i++] = dig[value % base];
            value /= base;
        }
        ret[i] = 0;
        ft_strrev(ret);
    }
    return (ret);
}

int hexprint(t_print *h)
{
    if (ifmod(h) == 0)
        h->ifree = va_arg(h->ap, unsigned int);
   // h->sign = (h->ifree < 0) ? '-' : h->sign;
    if (h->hash)
        h->wid -= 2;
    //h->ilen = (h->prec < 1 && (ft_strchr(h->eval, '.')) && h->ifree == 0) ? h->ilen - 1 : 0;
    if (h->ifree == 0)
    {
        intprint(h);
        return (0);
    }
    h->s = UnItoaIntMaxTs(h->ifree, 16);
    h->ilen = (int)ft_strlen(h->s);
    if (h->wid > h->ilen && h->pad && !(h->just))
        h->s = crazy(h);
    h->ilen = (int)ft_strlen(h->s);
    if (h->just)
    {
        (h->prec < h->ilen)?  h->prec : ft_putxchar('0', h->prec - h->ilen, h->ret);
        ifhash(h);
        ft_putstr(h->s);
      //  *h->ret += ft_strlen(h->s);
        if (h->wid > h->ilen)
        {
            if (h->prec < h->ilen)
                ft_putxchar(' ', h->wid - h->ilen, h->ret);
            else
                ft_putxchar(' ', h->wid - h->prec, h->ret);
        }
    }
    else
    {
        h->pad = (h->prec) ? 0 : h->pad;
        if (h->prec > h->ilen)
        {
            h->prec -= h->ilen;
            if (h->wid)
                h->wid -= h->prec;
        }
        else
            h->prec = -1;
       // if (h->pad)
        hexwid(h);
        (h->prec > 0) ? ft_putxchar('0', h->prec, h->ret) : h->prec;
        ifhash(h);
        if (h->spe == 'X')
            ft_putstr(ft_allup(h->s));
        else
            ft_putstr(h->s);
   
       // *h->ret +=  (h->hash) ? ft_strlen(h->s) + 2 :  ft_strlen(h->s);
    }
    *h->ret +=  (h->hash) ? ft_strlen(h->s) + 2 :  ft_strlen(h->s);
    return (0);
}

int intprint(t_print *h)
{
    h->pad = (h->prec) ? 0 : h->pad;
    if (h->prec > h->ilen)
    {
        h->prec -= h->ilen;
        if (h->wid)
            h->wid -= h->prec;
    }
    else
        h->prec = -1;
    if (h->pad)
    {
        if (h->sign)
            (h->sign != '-' || h->pad) ? ft_pfpchar(h->sign, h->ret) : h->sign;
        wid(h);
    }
    else
    {
        wid(h);
      if (h->sign)
          if (h->sign != '-' || h->pad || h->prec)
          {
              ft_pfpchar(h->sign, h->ret);
              h->sign = '\0';
          }
              //  (h->prec > 0) ? ft_putxchar('0', h->prec) : h->prec;
    }
    (h->prec > 0) ? ft_putxchar('0', h->prec, h->ret) : h->prec;
    if (h->spe == 'o' && h->hash)
        ft_pfpchar('0', h->ret);
    pfilter(h);
    *h->ret += ft_intlen(h->ifree);
    return (0);
}

int justwid(t_print *h)
{
    
    if (h->wid > h->ilen)
    {
        if (h->prec < h->ilen)
            ft_putxchar(' ', h->wid - h->ilen, h->ret);
        else
            (h->sign)? ft_putxchar(' ', h->wid - h->prec, h->ret): ft_putxchar(' ', h->wid - h->prec, h->ret);
        
    }
    return (0);
}


int justintprint(t_print *h)
{
    if (h->spe == 'u' ||  h->spe == 'U')
    {
        if(h->spe == 'U')
            h->ifree = (uintmax_t)(unsigned long)va_arg(h->ap, long);
        else
        {
            if(ifmod(h) == 0)
                h->ifree = va_arg(h->ap, unsigned int);
        }
        h->sign = '\0';
    }
    else if (ifmod(h) == 0)
    {
        h->cast = 0;
        h->ifree = va_arg(h->ap, int);
    }
    
    if (h->spe == 'o')
    {
        h->s = UnItoaIntMaxTs(h->ifree, 8);
        h->ifree = ft_atoi(h->s);
    }
    if (h->spe == 'o' && h->hash) // MOVE THIS
        h->wid -= 1;
    h->sign = (h->ifree < 0) ? '-' : h->sign;
    h->ilen = ft_intlen(h->ifree);
    h->ilen = (h->prec < 1 && (ft_strchr(h->eval, '.')) && h->ifree == 0) ? 0 : h->ilen;
    if (h->just)
    {
        if (h->sign)
        {
            ft_pfpchar(h->sign, h->ret);
            h->sign = '\0';
             h->wid -= 1;
        }
        (h->prec < h->ilen)?  h->prec : ft_putxchar('0', h->prec - h->ilen, h->ret);
        if (h->spe == 'o' && h->hash)
            ft_pfpchar('0', h->ret);
        pfilter(h);
        *h->ret += ft_intlen(h->ifree);
        justwid(h);
    }
    else
        intprint(h);
    return 0;
}
int charprint(t_print *h)
{
    h->ifree = va_arg(h->ap, int);
    if (h->just)
    {
        if (h->wid)
        {
            ft_pfpchar(h->ifree, h->ret);
            ft_putxchar(' ', h->wid - 1, h->ret);
        }
    }
    else
    {
        if (h->wid)
        {
            if (h->pad)
                ft_putxchar('0', h->wid - 1, h->ret);
            else
                ft_putxchar(' ', h->wid - 1, h->ret);
        }
        ft_pfpchar(h->ifree, h->ret);
    }
    return (0);
        
}
int ft_sort(t_print *h)
{
    if (h->spe == 's' || h->spe == '%')
        strprint(h);
    if (h->spe == 'i' || h->spe == 'd' || h->spe == 'o' || h->spe == 'u'|| h->spe == 'U')
        justintprint(h);
    //if (h->spe == '%')
    if (h->spe == 'x' || h->spe == 'X')
        hexprint(h);
    if (h->spe == 'c')
        charprint(h);
    return (0);
}

int strprint(t_print *h)
{
    if (h->spe != '%')
    {
        h->s = va_arg(h->ap, char*);
        if (h->s == NULL)
        {
            ft_putstr("(null)");
            return (0);
        }
    }
    else
        h->s = "%";
    if (h->s == NULL)
    {
        ft_putstr("(null)");
        return (0);
    }
    if (h->prec)
    {
        if ((int)ft_strlen(h->s) >= h->prec)
            h->s[h->prec] = '\0';
    }
    h->slen = ft_strlen(h->s);
    if (h->wid > (int)h->slen)
    {
        (h->just == 1)? ft_putstr(h->s) : ft_putxchar(' ', h->wid - (int)h->slen, h->ret);
        (h->just == 1)? ft_putxchar(' ', h->wid - (int)h->slen, h->ret) : ft_putstr(h->s);
    }
    else
        ft_putstr(h->s);
    *h->ret += (ft_strlen(h->s));
   return 0;
}

int parse(t_print *h)
{
    h->just = ft_strchr(h->eval, '-') != NULL ? 1 : 0;
    if ((ft_strchr(h->eval, '.')))
        h->prec = ft_atoi((ft_strchr(h->eval, '.') + 1));
    h->sign = ft_strchr(h->eval, ' ') != NULL ? ' ' : h->sign;
    if ((h->s = ft_strchrfull("123456789", h->eval)))
    {
            if (*(h->s - 1) != '.')
                h->wid = ft_atoi(ft_strchrfull("123456789", h->eval));
    }
    h->sign = ft_strchr(h->eval, '+') != NULL ? '+': h->sign;
    h->hash = ft_strchr(h->eval, '#') != NULL ? 1 : 0;
    h->pad = ft_first(h->eval, '0');
    if (ft_strchr(h->eval, 'h'))
    {
        if (*(ft_strchr(h->eval, 'h') + 1) == 'h')
            h->hh = 1;
        else
            h->lh = 1;
    }
    if (ft_strchr(h->eval, 'l'))
    {
        if (*(ft_strchr(h->eval, 'l') + 1) == 'l')
            h->ll = 1;
        else
            h->l = 1;
    }
    h->z = ft_strchr(h->eval, 'z') != NULL ? 1 : 0;
    h->j = ft_strchr(h->eval, 'j') != NULL ? 1 : 0;
    return 0;
}

int		ft_printf(char	*format, ...)
{
	t_print     *h;
 
    h = ft_memalloc(sizeof(t_print));
    va_start(h->ap, format);
    h->i = 0;
    h->ret = (int*)malloc(sizeof(int));
   // h->s = (char*)malloc(sizeof(char)+ 1);
    *(h->ret) = 0;
    while (format[h->i] != '\0')
    {
        while (format[h->i] != '%' && format[h->i] != '\0')
        {
            ft_pfpchar(format[h->i], h->ret);
            h->i++;
        }
        if (format[h->i] == '\0')
            break;
        h->eval = &format[h->i];
        while (!(ft_strchr("sSpdDioOuUxXcC%", *(h->eval + 1))))
            h->eval++;
        h->spe = *(ft_strchr("sSpdDioOuUxXcC%", *(h->eval + 1)));
        h->eval = ft_strsub(format, h->i , h->eval - &format[h->i - 1]);
        clearstr(h);
        parse(h);
        ft_sort(h);
        h->i += (ft_strlen(h->eval) + 1);
    }
     return (*h->ret);
}
/*
int main()
{
 //  char  z[] = "testing 123";
//char    e[] = "keaton";
   long long     n;
    int k;
    int s;
    k = 942;
   n = 8223372036854775807;
    s = -32768;
    int s2 = -32768;
    int rr = -42;
    //ft_putstr(UnItoaIntMaxT(123456, 16));
   //ft_printf("do you know %20lld jkfdjfkd", n);
  //  ft_printf("some %% stuff %+10.6d and %% this is more %+10.6d", k, s);
 // ft_printf("lets try this %-s" , z);
//ft_printf("ft_printf: %d % 0*.10ld %i %%\n", 13, 18, 3049600000, -4078);
 // ft_printf("ft_printf: %s %d %-.5s %i %%\n", "keaton", 13, "testing 123", -4078);
 //   printf("ft_printf: %s %d %-.5s %i %%\n", "keaton", 13, "testing 123", -4078);
    //ft_printf("ft_printf: %d % 013.10ld %i %%\n", 18, 3049600000, -4078);
// ft_printf("ft_printf: %.0d", 0); dont forget this one bill.!!!!!!!!!
 // printf("ft_printf: %.0d", 0);
  //  ft_printf("%4%");
    
//ft_putnbr(ft_printf("this is stuff %s", "abc"));
//   printf("% 05d\n", k);
  //  ft_printf("% 05d\n----------------------------1\n", k);
    //printf("%-11.6d\n", k);
 //  ft_printf("%-11.6d\n----------------------------\n", k);
//    printf("%+5d\n", k);
  //  ft_printf("%+5d\n----------------------------\n", k);
    //printf("% 010d\n", k);
//    ft_printf("% 010d\n----------------------------\n", k);
  //  printf("%-5.2d\n", k);
  //  ft_printf("%-5.2d\n----------------------------\n", k);
   // ft_printf("%5d", 42);
 // ft_printf("%d", 2147483648);
  //  ft_printf("%-5d", -42);
 //ft_printf("%-+10.5d", 4242);
 //ft_printf("%5%");
    //ft_printf("%hd", s2);

 //ft_printf("%x", rr);
    //ft_printf("%hd", s2);
 //ft_printf("%#x", 42);
 //   ft_printf("%#08x", 42);
  //   ft_printf("%08x", 42);
  //    ft_printf("%#8x", 42);
  // ft_printf("%X", 42);
 //ft_printf("%#o", 40);
   // ft_printf("%-#6o", 2500);
   // ft_printf("%u", 4294967295);
 //ft_printf("%-5o", 42);
// ft_printf("%.d", 0);
 }

*/
/*

int main()
{
  //  ft_printf("%.d", 0);
   // ft_printf("@moulitest: %5.o %5.0o", 0, 0);
  //  ft_printf("@moulitest: %.x %.0x", 0, 0);
 //ft_printf("%-15x", 542);
 //   ft_printf("@moulitest: %s", NULL);
 //ft_printf("1:%hhd\n", 128);
 //   ft_printf("%hd", 32767);
 //   ft_printf("%hd", 32768);
   // ft_printf("%hd", -32768);
 //   ft_printf("%hhd", 128);
 //ft_printf("%ld", -2147483648);
    //ft_printf("1:%lld\n", -9223372036854775808);
// ft_printf("%d", -4242);
   // ft_printf("%0d", -42);
// ft_printf("%5d", 42);
// ft_printf("@moulitest: %#.x %#.0x", 0, 0);
// ft_printf("%05d", -42);
 //ft_printf("%-5d", -42);
// ft_printf("%03.2d", -1);
  //  ft_printf("%03.2d", -1);
 //ft_printf("%lx", 4294967296);
 //ft_printf("%lu", "4294967296");
// ft_printf("%U", "4294967295");
   // ft_printf("%hU", "4294967296");
//    ft_printf("%lu", -42);
   // ft_printf("3:%hx\n", 4294967296);
    ft_printf("%x", -42);
 return (0);
}
*/

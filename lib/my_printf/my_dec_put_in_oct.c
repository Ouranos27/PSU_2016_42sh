/*
** my_dec_put_in_bin.c for my_dec_put_in_bin in /home/amaury.bernard/PSU_2016_my_printf
**
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.net>
**
** Started on  Tue Nov 15 20:02:52 2016 Amaury Bernard
** Last update Tue May 16 12:00:25 2017 Amaury Bernard
*/

#include "my.h"
#include <stdlib.h>

int	my_nbr_digits_oct(unsigned long long nb)
{
  int	k;

  k = 1;
  while (nb > 7)
    {
      nb = nb / 8;
      k++;
    }
  return (k);
}

void	my_dec_put_in_oct(unsigned long long nb, int *len)
{
  int	i;
  char	*str;

  i = my_nbr_digits_oct(nb);
  if ((str = malloc(i)) == NULL)
    return ;
  str[i--] = '\0';
  while (i >= 0)
    {
      str[i--] = '0' + (nb % 8);
      nb = nb / 8;
    }
  my_putstr(str, len);
  free(str);
}

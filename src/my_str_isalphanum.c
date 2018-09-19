/*
** my_str_isalphanum.c for 42sh in /home/ouranos27/my_desktop/PSU/PSU_2016_42sh/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Mon May 15 15:16:39 2017 philippe kam
** Last update Sun May 21 09:00:41 2017 Nicolas Marsan
*/

#include "sh.h"

int	my_str_isalphanum(char *check)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (check[i] != '\0')
    {
      if ((check[i] >= 'A' && check[i] <= 'Z') ||
	  (check[i] >= 'a' && check[i] <= 'z') ||
	  (check[i] >= '0' && check[i] <= '9'))
	++j;
      ++i;
    }
  if (i != j)
    return (FALSE);
  return (TRUE);
}

/*
** cmd_echo.c for echo in /home/maximed/EPIREBOOT/PSU_2016_42sh/src
** 
** Made by duhommet maxime
** Login   <maximed@epitech.net>
** 
** Started on  Mon May 15 15:32:28 2017 duhommet maxime
** Last update Sun May 21 09:01:23 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

int	cmd_echo(__attribute__((unused)) t_use_env *use_env, char **argv)
{
  int	i;

  i = 1;
  if (argv[1] == NULL)
    {
      my_printf("\n");
      return (0);
    }
  while (argv[i])
    {
      my_printf("%s", argv[i++]);
      if (argv[i])
	my_printf(" ");
    }
  my_printf("\n");
  return (0);
}

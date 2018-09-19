/*
** control_c.c for control_c in /home/ouranos27/my_desktop/PSU/PSU_2016_42sh/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed May 17 14:57:07 2017 philippe kam
** Last update Sun May 21 09:01:14 2017 Nicolas Marsan
*/

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "sh.h"

void		control_c()
{
  char		*pwd;
  int		size;

  size = pathconf(".", _PC_PATH_MAX);
  size = (size > 10240) ? 10240 : size;
  if (!(pwd = malloc(sizeof(char) * size)))
    return ;
  if (!(getcwd(pwd, size)))
    return ;
  my_printf("\n:");
  my_printf("%s", pwd);
  my_printf("> ");
  free(pwd);
}

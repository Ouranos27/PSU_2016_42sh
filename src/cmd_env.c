/*
** cmd_env.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat Jan 21 16:10:16 2017 Amaury Bernard
** Last update Sun May 21 09:01:34 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

int	cmd_env(t_use_env *use_env, __attribute__((unused)) char **argv)
{
  int	i;

  i = 0;
  while (use_env->env[i] != NULL)
    my_printf("%s\n", use_env->env[i++]);
  return (0);
}

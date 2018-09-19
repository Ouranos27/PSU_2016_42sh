/*
** init_env.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat Apr  8 16:28:06 2017 Amaury Bernard
** Last update Sun May 21 09:01:58 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

int	nb_member_dble_tab(char **tab)
{
  int	nb;

  nb = 0;
  while (tab[nb] != NULL)
    ++nb;
  return (nb);
}

char	**init_env(char **env)
{
  int	nb;
  char	**new;

  if ((new = malloc(sizeof(char *) * (nb_member_dble_tab(env) + 1))) == NULL)
    return (NULL);
  nb = 0;
  while (*env != NULL)
    {
      new[nb++] = my_strdup(*env);
      ++env;
    }
  new[nb] = NULL;
  return (new);
}

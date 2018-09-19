/*
** get_input_cmd.c for 42sh in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue May 16 19:26:37 2017 Amaury Bernard
** Last update Sun May 21 09:01:50 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"
#include "cmd.h"

static char	is_a_redir(char *arg)
{
  if (str_are_equal(arg, REDIR_STR_OUT) == TRUE)
    return (REDIR_OUT);
  if (str_are_equal(arg, REDIR_STR_OUT2) == TRUE)
    return (REDIR_OUT2);
  if (str_are_equal(arg, REDIR_STR_IN) == TRUE)
    return (REDIR_IN);
  if (str_are_equal(arg, REDIR_STR_IN2) == TRUE)
    return (REDIR_IN2);
  return (FALSE);
}

static int	handle_redir(t_instru *instru)
{
  int		i;
  int		rt;

  instru->redir_file = NULL;
  i = -1;
  while (instru->av[++i] != NULL)
    {
      if ((rt = is_a_redir(instru->av[i])) != FALSE
	  && instru->av[i + 1] != NULL)
	{
	  instru->redir_type = is_a_redir(instru->av[i]);
	  instru->redir_file = instru->av[i + 1];
	  instru->av[i] = NULL;
	}
    }
  return (0);
}

int		get_input_cmd(t_in_cmd *cmd)
{
  char		**argv;
  int		rt;
  t_def		*temp;
  int		i;

  cmd->instru = NULL;
  cmd->separator = NULL;
  if ((rt = get_input_argv(&argv)) != 0)
    return (rt);
  if (*argv == NULL)
    {
      free(argv);
      return (0);
    }
  if ((rt = handle_separator(cmd, argv)) != 0)
    return (rt);
  temp = cmd->separator;
  i = 0;
  while (temp)
    {
      handle_redir(&cmd->instru[i++]);
      temp = temp->next;
    }
  free(argv);
  return (0);
}

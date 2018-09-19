/*
** get_in_handle_sep.c for  in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun May 21 12:12:37 2017 Amaury Bernard
** Last update Sun May 21 12:12:37 2017 Amaury Bernard
*/

#include <stdlib.h>
#include "sh.h"
#include "cmd.h"

static char	is_a_separator(char *arg)
{
  if (str_are_equal(arg, SEP_STR_AND) == TRUE)
    return (SEP_AND);
  if (str_are_equal(arg, SEP_STR_OR) == TRUE)
    return (SEP_OR);
  if (str_are_equal(arg, SEP_STR_POINT) == TRUE)
    return (SEP_POINT);
  if (str_are_equal(arg, SEP_STR_PIPE) == TRUE)
    return (SEP_PIPE);
  return (FALSE);
}

static int	new_sep_add_instu_av(t_instru *instru, char **argv, int i_argv)
{
  int		i_instru;

  if (!(instru->av = malloc(sizeof(char *) * (i_argv + 1))))
    return (ERR_FATAL);
  instru->av[i_argv] = NULL;
  i_instru = 0;
  while (i_instru < i_argv)
    {
      instru->av[i_instru] = argv[i_instru];
      ++i_instru;
    }
  return (0);
}

static int	new_def_separator(t_in_cmd *cmd, char type)
{
  t_def		*new;
  t_def		*temp;

  if (!(new = malloc(sizeof(t_def))))
    return (ERR_FATAL);
  new->value = type;
  new->next = NULL;
  if (!cmd->separator)
    cmd->separator = new;
  else
    {
      temp = cmd->separator;
      while (temp->next)
	temp = temp->next;
      temp->next = new;
    }
  return (0);
}

static int	count_sep(char **argv)
{
  int		count;
  int		i;

  i = 0;
  count = 0;
  while (argv[i] != NULL)
    {
      if (is_a_separator(argv[i]) != FALSE)
	++count;
      ++i;
    }
  return (count);
}

int		handle_separator(t_in_cmd *cmd, char **argv)
{
  int		i_argv;
  char		type;
  int		nb_instru;

  if (!(cmd->instru = malloc(sizeof(t_instru) * (count_sep(argv) + 1))))
    return (ERR_FATAL);
  nb_instru = 0;
  i_argv = -1;
  while (argv[++i_argv] != NULL)
    {
      if ((type = is_a_separator(argv[i_argv])) != FALSE
	  && argv[i_argv + 1] != NULL)
	{
	  new_def_separator(cmd, type);
	  new_sep_add_instu_av(&cmd->instru[nb_instru++], argv, i_argv);
	  argv = &argv[i_argv + 1];
	  i_argv = -1;
	}
     }
  if (i_argv > 1 && is_a_separator(argv[i_argv - 1]) != FALSE)
    --i_argv;
  new_sep_add_instu_av(&cmd->instru[nb_instru], argv, i_argv);
  new_def_separator(cmd, SEP_END);
  return (0);
}

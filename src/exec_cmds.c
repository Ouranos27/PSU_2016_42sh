/*
** exec_cmds.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Fri Apr  7 14:31:55 2017 Amaury Bernard
** Last update Sun May 21 12:10:52 2017 Nicolas Marsan
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "sh.h"
#include "msgs.h"

void	exec_error(char *cmd_name)
{
  if (errno == EXEC_FORMAT_ERR)
    my_printf("%e: %e. %e", cmd_name , strerror(errno), FILE_NOT_EXEC);
  else if (errno == PERMISSION_DENIED)
    my_printf("%e: %e.\n", cmd_name, strerror(errno));
}

int	exec_shell_cmds(t_cmd *cmds, char **argv, t_use_env *use_env, int *rt)
{
  int	i;

  i = 0;
  while (cmds[i].cmd != NULL)
    {
      if (str_are_equal(argv[0], cmds[i].cmd) == TRUE)
	{
	  *rt = cmds[i].fct(use_env, argv);
	  return (TRUE);
	}
      ++i;
    }
  return (FALSE);
}

int	exec_sys_cmds(t_sys_cmd *sys_cmd, char **argv, char **env, int *rt)
{
  int	i;
  pid_t	pid;

  i = 0;
  while (sys_cmd[i].cmd != NULL)
    {
      if (str_are_equal(argv[0], sys_cmd[i].cmd) == TRUE)
	{
	  if ((pid = fork()) == -1)
	    return (ERR_FATAL);
	  else if (pid == 0)
	    {
	      if (execve(sys_cmd[i].filename, argv, env) != 0)
		{
		  exec_error(sys_cmd[i].filename);
		  exit(ERR_STD);
		}
	    }
	  else
	    *rt = father();
	  return (TRUE);
	}
      ++i;
    }
  return (FALSE);
}

static char	is_right_path(char *str)
{
  int		i;

  i = 0;
  if (access(str, F_OK) == -1)
    return (FALSE);
  while (str[i] != 0)
    {
      if (str[i] == '/')
	return (TRUE);
      ++i;
    }
  return (FALSE);
}

int	exec_file(char **argv, char **env, int *rt)
{
  pid_t	pid;

  if (is_right_path(argv[0]) == TRUE)
    {
      if ((pid = fork()) == -1)
	return (ERR_FATAL);
      else if (pid == 0)
	{
	  if (execve(argv[0], argv, env) != 0)
	    {
	      exec_error(argv[0]);
	      exit(ERR_STD);
	    }
	}
      else
	*rt = father();
      return (TRUE);
    }
  return (FALSE);
}

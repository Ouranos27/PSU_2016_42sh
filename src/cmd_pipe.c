/*
** cmd_pipe.c for 42sh in /home/ouranos27/my_desktop/PSU/PSU_2016_42sh/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Sun May 21 18:52:41 2017 philippe kam
** Last update Sun May 21 18:52:41 2017 philippe kam
*/

#include "minishell1.h"

int	cmd_pipe()
{
  int	fd[2];
  int	pid;

  if (pipe(fd) == -1
      || (pid = fork()) == -1)
  return (FALSE);
  if (pid == 0)
    {
      if (dup2(fd[0], 0) == -1 || dup2(fd[1], 1) == -1)
	return (FALSE);
    }
  if (close(fd[0]) == -1 || close(fd[1]) == -1)
    return (FALSE);
  return (TRUE);
}

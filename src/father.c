/*
** father.c for  in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun May 21 17:57:16 2017 Amaury Bernard
** Last update Sun May 21 17:57:16 2017 Amaury Bernard
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "sh.h"
#include "msgs.h"

static int	core_dumped(int status)
{
  int		nb;

  if ((nb = WTERMSIG(status)) == SIGSEGV)
    my_printf("%e", SEGFAULT_CD);
  else if (nb == SIGABRT)
    my_printf("%e", ABORT_CD);
  else if (nb == SIGFPE)
    my_printf("%e", FPE_CD);
  return (nb + START_SIGNALS);
}

static int	without_core_dumped(int status)
{
  int		nb;

  if ((nb = WTERMSIG(status)) == SIGSEGV)
    my_printf("%e", SEGFAULT);
  else if (nb == SIGABRT)
    my_printf("%e", ABORT);
  else if (nb == SIGFPE)
    my_printf("%e", FPE);
  return (nb + START_SIGNALS);
}

int	father(void)
{
  int	status;

  if (wait(&status) == -1)
    {
      perror("wait");
      exit(EXIT_FAILURE);
    }
  if (WIFSIGNALED(status))
    {
      if (WCOREDUMP(status))
	return (core_dumped(status));
      else
	return (without_core_dumped(status));
    }
  if (status != 0)
    return (ERR_STD);
  return (status);
}

/*
** handler.c for handler in /home/ouranos27/my_desktop/PSU/PSU_2016_42sh/src
** 
** Made by philippe kam
** Login   <philippe.kam@epitech.eu>
** 
** Started on  Wed May 17 15:34:12 2017 philippe kam
** Last update Sun May 21 09:00:53 2017 Nicolas Marsan
*/

#include <signal.h>
#include <stdlib.h>
#include "sh.h"

int			handler()
{
  if (signal(SIGINT, control_c) != SIG_ERR)
    return (TRUE);
  return (FALSE);
}

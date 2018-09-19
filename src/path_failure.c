/*
** path_failure.c for 42sh in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat May 20 18:44:57 2017 Amaury Bernard
** Last update Sun May 21 09:00:36 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

char		**path_failure()
{
  char		**path;

  if (!(path = malloc(sizeof(char *) * 2)))
    return (NULL);
  path[0] = my_strdup(DEFAULT_PATH);
  path[1] = NULL;
  return (path);
}

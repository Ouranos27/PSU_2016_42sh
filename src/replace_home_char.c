/*
** replace_home_char.c for  in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue May 16 13:44:10 2017 Amaury Bernard
** Last update Sun May 21 09:02:16 2017 Nicolas Marsan
*/

#include "stdlib.h"
#include "sh.h"

char	*replace_home_char(char *str, char *home)
{
  char	*new;

  if (*str == '~')
    {
      new = my_2str_in1(home, str + 1);
      free(str);
      return (new);
    }
  return (str);
}

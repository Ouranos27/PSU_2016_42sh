/*
** rt_with_msg.c for 42sh in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Mon May 15 14:40:02 2017 Amaury Bernard
** Last update Sun May 21 09:00:31 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

int	rt_with_msg(int to_rt, char *to_show1, char *to_show2)
{
  if (to_show2 != NULL)
    my_printf("%e%e", to_show1, to_show2);
  else
    my_printf("%e", to_show1);
  return (to_rt);
}

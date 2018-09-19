/*
** free_my_tab.c for free my tab in /home/maximed/EPIREBOOT/PSU_2016_42sh/src
** 
** Made by duhommet maxime
** Login   <maximed@epitech.net>
** 
** Started on  Fri May 19 15:00:00 2017 duhommet maxime
** Last update Fri May 19 15:02:43 2017 duhommet maxime
*/

#include <unistd.h>
#include <stdlib.h>

void		free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

/*
** my_get_nbr.c for  in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Fri Apr  7 19:04:13 2017 Amaury Bernard
** Last update Fri Apr  7 19:04:13 2017 Amaury Bernard
*/

int	my_get_nbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  if (str[0] == '-')
    ++i;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  nb = nb * 10;
	  nb = nb + str[i] - '0';
	}
      ++i;
    }
  if (str[0] == '-')
    nb = -nb;
  return (nb);
}

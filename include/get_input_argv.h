/*
** get_input_argv.h for 42sh in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu May 18 10:55:49 2017 Amaury Bernard
** Last update Thu May 18 10:55:49 2017 Amaury Bernard
*/

#ifndef GET_INPUT_ARGV_H_
# define GET_INPUT_ARGV_H_

#define ARG_DELIM	" \t\""
#define ARG_START	1
#define ARG_LOAD	2
#define ARG_END		3

int		char_allowed(char c, char *allowed);

#endif /* !GET_INPUT_ARGV_H_ */

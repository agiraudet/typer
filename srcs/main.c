/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:09:48 by agiraude          #+#    #+#             */
/*   Updated: 2023/02/03 19:36:19 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ncurses.h>
#include "vec.h"
#include "stat.h"

size_t	randNum(size_t max)
{
	static char	seeded = 0;

	if (!seeded)
	{
		srand(time(NULL));
		seeded = 1;
	}
	return rand() % max;
}

t_vec	*loadDic(const char* filename)
{
	FILE*	stream;
	char*	line = NULL;
	size_t	len = 0;
	ssize_t	nread;
	t_vec*	vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
	{
		dprintf(STDERR_FILENO, "Memory failure\n");
		return NULL;
	}
	vecInit(vec);
	stream = fopen(filename, "r");
	if (!stream)
	{
		dprintf(STDERR_FILENO, "Could not open: %s\n", filename);
		free(vec);
		return NULL;
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		if (!nread)
			break;
		if(line[nread - 1] == '\n')
			line[nread - 1] = 0;
		vecPushBack(vec, strdup(line));
	}
	free(line);
	fclose(stream);
	return vec;
}

void	delete(char* str)
{
	free(str);
}

void	typeWord(char* word, int* keepGoing, t_stat* stat)
{
	int c;
	size_t	bad_char = 0;
	size_t	wlen = strlen(word);

	move(0, 0);
	clrtoeol();
	move(1, 0);
	clrtoeol();
	mvaddstr(0, 0, word);
	move(1, 0);

	for (size_t i = 0; i < wlen; i++)
	{
		c = getch();
		if (c == 27)
		{
			*keepGoing = 0;
			break;
		}
		if (c != word[i])
		{
			i--;
			bad_char++;
			continue;
		}
		mvaddch(1, i, c);
	}
	if (stat)
		statAddWord(stat, wlen, bad_char);
}

void	mainLoop(t_vec* dict, t_stat* stat)
{
	int		keepGoing = 1;

	while (keepGoing)
	{
		typeWord(vecAt(dict, randNum(dict->size)), &keepGoing, stat);
		statDisplay(stat, 3);
	}
}

int main(int argc, char **argv)
{
	t_vec*	dict = NULL;
	t_stat	stat;

	if (argc < 2)
		dict = loadDic("/usr/share/dict/words");
	else
		dict = loadDic(argv[1]);
	if (!dict)
		return 1;

	initscr();
	cbreak();
	noecho();

	statInit(&stat);
	mainLoop(dict, &stat);	
	endwin();
	statPrintSession(&stat);

	vecForEach(dict, delete);
	free(dict->data);
	free(dict);
	return 0;
}

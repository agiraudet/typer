/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:50:58 by agiraude          #+#    #+#             */
/*   Updated: 2023/02/03 19:37:28 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <ncurses.h>
#include "stat.h"

static double whatTimeIsIt(void)
{
	struct timespec	now;
	clock_gettime(CLOCK_REALTIME, &now);
	return now.tv_sec + now.tv_nsec*1e-9;
}

void	statInit(t_stat* stat)
{
	stat->wpm = 0;
	stat->prec = 0;
	stat->wcount = 0;
	stat->ccount = 0;
	stat->bad_char = 0;
	stat->timer = whatTimeIsIt();
}

void	statAddWord(t_stat* stat, size_t len, size_t bad_char)
{
	stat->wcount++;
	stat->ccount += (len + bad_char);
	stat->bad_char += bad_char;

	stat->wpm = 60. / ((whatTimeIsIt() - stat->timer) / stat->wcount);
	stat->prec = 100 - (((double)stat->bad_char / (double)stat->ccount) * 100);
}

void	statDisplay(t_stat* stat, int y)
{
	char	buf[30];

	snprintf(buf, 30, "%.0f wpm  %.1f%% prec", stat->wpm, stat->prec);
	move(y, 0);
	clrtoeol();
	mvaddstr(y, 0, buf);
}

void	statPrintSession(t_stat* stat)
{
	printf("Session duration: %.1fm\nWpm: %.1f\nWord typed: %lu\nPrecision: %.1f%%\nTotal characters: %lu\nMistakes: %lu\n", (whatTimeIsIt() - stat->timer) / 60, stat->wpm, stat->wcount, stat->prec, stat->ccount, stat->bad_char);
}

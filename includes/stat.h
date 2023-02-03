/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <agiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:48:48 by agiraude          #+#    #+#             */
/*   Updated: 2023/02/03 19:34:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAT_H
# define STAT_H

typedef struct	s_stat
{
	double	wpm;
	double	prec;
	size_t	wcount;
	size_t	ccount;
	size_t	bad_char;
	time_t	timer;
}				t_stat;

void	statInit(t_stat* stat);
void	statAddWord(t_stat* stat, size_t len, size_t bad_char);
void	statDisplay(t_stat* stat, int y);
void	statPrintSession(t_stat* stat);

#endif

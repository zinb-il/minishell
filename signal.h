/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:21:46 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/14 17:14:18 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SIGNAL_H
# define SIGNAL_H

void	signals(int pro);
void	handler_sigint_parent(int sigid);
void	handler_sigint_child(int sigid);
void	handler_sigquit_child(int sigid);
void	handler_sigquit_herdoc(int sigid);

#	endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stamim <stamim@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:53 by stamim            #+#    #+#             */
/*   Updated: 2022/10/28 18:15:18 by stamim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H


bool	is_rt_arg(const char *arg);
bool	fill(t_spc *obj);
int		destroy(void *param);
void	run(t_spc spc);
#endif
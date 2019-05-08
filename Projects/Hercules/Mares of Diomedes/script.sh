#!/bin/sh

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/22 18:52:16 by akharrou          #+#    #+#              #
#    Updated: 2019/04/22 18:52:16 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# PART - 0 ———————————————————————————————————————————————————————————————
# Run 'manger', Observe

./manger &

sleep 5

# PART - 1 ———————————————————————————————————————————————————————————————
# Find names of child processes of manger (w/ hexdump), kill them, kill manger

kill -s KILL $(pgrep crap lampon ruins xanthos yes)
kill -s KILL $(top -l 1 | grep manger | cut -d' ' -f1)
rm crap*


# PART - 2 ———————————————————————————————————————————————————————————————
# Compile, Run, Observe, Kill my 'manger': forkBomb

gcc forkBomb.c -o forkBomb

./forkBomb &

sleep 20

killall forkBomb

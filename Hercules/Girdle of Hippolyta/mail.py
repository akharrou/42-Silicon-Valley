# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mail.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 15:43:07 by akharrou          #+#    #+#              #
#    Updated: 2019/04/26 20:35:13 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Find all Server Domains & Ports here:
# https://www.arclab.com/en/kb/email/list-of-smtp-and-pop3-servers-mailserver-list.html

# Here are a few:
#
# Gmail:    smtp.gmail.com       @ 465
# Hotmail:  smtp.live.com        @ 465
# Yahoo:    smtp.mail.yahoo.com  @ 465

import smtplib
import getpass
import time

print('————————————————————————————————')
print('Login: \n')

user         =  input('User: ')
password     =  getpass.getpass('Password: ')
serverDomain =  str(input("Server Domain: "))
serverPort   =  int(input("Server Port: "))
print('————————————————————————————————\n')

print('Connecting to server ...')
with smtplib.SMTP_SSL(serverDomain, serverPort) as smtpClient:

	time.sleep(1)
	if (user != 'localhost'):
		print('Authenticating ...')
		smtpClient.login(user, password)
	time.sleep(2)
	print('You are successfully connected and logged in [√]\n')
	time.sleep(1)

	while (True):

		choice = input("""
Please choose one of the following options:

Press 1)  To send an email.
Press 2)  To quit.

————> """)

		if (choice == '1'):

			print('\n————————————————————————————————')
			print(f'From: {user}')
			receiver  =  input('To: ')
			subject   =  input("Subject: ")
			print()
			body      =  input()
			print('————————————————————————————————')

			msg      =  f'Subject: {subject}\n\n{body}'

			try:
				smtpClient.sendmail(user, receiver, msg)
			except smtplib.SMTPException:
				print('Failed to send message, please try again.')
			else:
				time.sleep(1)
				print('Message Successfuly Sent [√]')
				time.sleep(2)
				print('\n\n')

		if (choice == '2'):

			smtpClient.quit
			break

	print('Thank you for choosing our services.')
	print('See you next time.')

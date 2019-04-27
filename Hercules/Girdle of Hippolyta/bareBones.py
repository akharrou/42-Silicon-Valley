# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bareBones.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/26 15:43:07 by akharrou          #+#    #+#              #
#    Updated: 2019/04/26 20:45:28 by akharrou         ###   ########.fr        #
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
import os

user         =  os.environ.EMAIL_LOGIN
password     =  os.environ.EMAIL_PASSWD

serverDomain =  os.environ.EMAIL_DOMAIN
serverPort   =  os.environ.EMAIL_PORT

def sendEmail(reciever, msg):
	"""
	Sends an email to 'reciever' containing 'msg' as its content.
	"""

	with smtplib.SMTP_SSL(serverDomain, serverPort) as smtpClient:

		smtpClient.login(user, password)

		try:
			smtpClient.sendmail(user, receiver, msg)
		except smtplib.SMTPException as err:
			raise err
		else:
			print('Message Successfuly Sent [√]')

		smtpClient.quit

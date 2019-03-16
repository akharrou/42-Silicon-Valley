# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.c                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 10:47:35 by akharrou          #+#    #+#              #
#    Updated: 2019/03/15 21:52:17 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

import json
import requests
import os
import sys

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —

try:
	infile = sys.argv[1]
except Exception:
	print('Usage: python3 script.py file')
	sys.exit()

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
# Get an access token with which to call the API.

UID = os.environ.get('APP_UID')
SECRET = os.environ.get('APP_SECRET')
ACCESS_TOKEN_URL = 'https://api.intra.42.fr/oauth/token'

response = requests.post(ACCESS_TOKEN_URL, data = { 'grant_type': 'client_credentials',
                                                    'client_id': UID,
                                                    'client_secret': SECRET })

access_token = json.loads(response.text)['access_token']

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
# Open file. For every intra in that file, return the availablility and location of each student.

with open(infile, 'rt') as fd:

	# Read all Intras from the file. Store all the intras in a list.
	intras = fd.readlines()

	# For every intra in the list of intras...
	for intra in intras:

		intra = intra.rstrip('\n')
		api = f"users/{intra}/locations"
		api_url = f'https://api.intra.42.fr/v2/{api}?access_token={access_token}'

		# Call the API for that Intra
		response = requests.get(api_url)

		# Keep trying again if API isn't responding
		while (response == 500):
			response = requests.get(api_url)
			print('API not responding...')

		# If we make a bad API call
		if (response != 200):
			print(f'Error: API {response}')
			sys.exit()

		# Parse the Received Data and Store it in a Structure
		user_info = json.loads(response.text)

		# Check Availability of student and print out logical response
		try:
			if (user_info[0]['end_at'] != None):
				print(f'{intra} is currently unavailable.')
			else:
				print(f"{intra} is currently available at {user_info[0]['host']}.")

		except IndexError:
			print(f'{intra} is currently unavailable.')

		except KeyError:
			print(f'Invalid intra: {intra}')

# Done
# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —


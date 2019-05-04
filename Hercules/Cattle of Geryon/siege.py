# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    siege.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharrou <akharrou@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 16:07:08 by akharrou          #+#    #+#              #
#    Updated: 2019/05/04 11:09:42 by akharrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import multiprocessing
import requests
import time
import sys

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

def usage():
	print ('Usage: python3 siege.py \033[4mn_clients\033[0m \033[4mn_requests_per_client\033[0m \033[4mserver_address\033[0m')
	sys.exit(-1)

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# User Request Simulator
def Requester(args):

	url, user_id, n_requests = args[0], args[1], args[2]

	times = []
	responses = []

	for i in range(n_requests):

		t1 = time.perf_counter()
		responses.append(requests.get(url).status_code)
		print(f'User {user_id} sent a Request.')
		t2 = time.perf_counter()
		times.append(t2 - t1)

	return tuple(zip(times, responses))

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# Concurrent Requests Simulator
def bombardServer(url, load=10, resquests_per_client=1):

	urls = [url] * load
	user_ids = [i for i in range(load)]
	n_requests = [resquests_per_client] * load

	pool = multiprocessing.Pool(processes=load)

	try:
		results = pool.map(Requester, zip(urls, user_ids, n_requests))
	except requests.exceptions.MissingSchema:
		print('Invalid URL, try again.')
		sys.exit(-1)

	report = []
	for user_results in results:
		report.extend(user_results)

	return report

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

try:

	if (sys.argv[3] == '-h' or sys.argv[3] == '-H' or sys.argv[3] == '--help'):
		usage()

	clients = int(sys.argv[1])
	resquests_per_client = int(sys.argv[2])
	url = sys.argv[3]

except Exception:
	usage()

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# Test
t1 = time.perf_counter()
times, codes = zip(*bombardServer(url, clients, resquests_per_client))
t2 = time.perf_counter()

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# Analytics
load = clients * resquests_per_client
successes = len(list(filter(lambda x: x == 200, codes)))
summed_times = sum(times)
average_times = summed_times / clients / resquests_per_client
total_test_time = t2 - t1

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

# Output
print(f'')
print(f'Successful Requests: 		{successes}/{load}')
print(f'')
print(f'Average Response Time: 		{average_times:.4f}s')
print(f'Summed Response Times: 		{summed_times:.4f}s')
print(f'Elapsed Time of Test: 		{total_test_time:.4f}s')

# — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — 

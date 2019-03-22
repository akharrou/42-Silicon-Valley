

from sys import argv as av
from os import system

test_files = [
	'0test_file.txt',
	'1test_file.txt',
	'2test_file.txt',
	'file',
	'nfile',
	# 'test_main.c',
]

for file in test_files:
	print(f'———————————————————————————————————————————————————————————')
	print(f'[{file}]:\n')
	system(f'time ./a {file}')
print(f'———————————————————————————————————————————————————————————')

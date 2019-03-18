
from os import system
from sys import argv as av

tests = [  '1test-size2',
           '1test-size3',
           '1test-size4',
           '2test-size3-horizontal',
           '2test-size3-vertical',
           '4test-0',
           '4test-1',
           '4test-2',
           '4test-fullboad',
           '5test',
           '6test',
           '7test',
           '8test',
           '9test',
           '10test',
           '11test',
           '12test',
           '13test',
           '14test',
           '15test',
           '16test',
           '17test',
           '18test',
           '19test',
           '21test',
           '22test',
           '23test',
           '24test',
           '25test',
           '26test',
		   'invalid1-size-piece',
           'invalid2-empty',
           'invalid3-newline',
           'invalid4-big-char-full',
           'invalid5-binary-null',
           'invalid6-characters'
           'invalid7-last',
           'invalid8-between_pieces',
           'invalid9-valid_w_newline'  ]

for test in tests:
	system(f'./{av[1]} {test} > output_A')
	system(f'./{av[2]} {test} > output_B')
	system(f'echo ; echo "Test {test}:\n—————————————————————————\n" ; diff output_A output_B ; echo "—————————————————————————\n"')

system('rm output_A output_B')

# for test in tests:
# 	system(f'echo ; echo "Test {test}:\n—————————————————————————\n" ; time ./{av[1]} {test} ; echo')

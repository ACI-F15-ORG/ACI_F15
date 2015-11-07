""" Poem about GIT and suffering """ 

import random, time

WillGITWork = random.randint(1, 10) 
aMiracle = 10


print "Will GIT work.... "

for waiting in range(WillGITWork):
	print "."
	time.sleep(1)

if WillGITWork is aMiracle:
	print "OMG!"
else:
	print "lol"

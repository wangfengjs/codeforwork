# -*- coding:utf-8 -*-

# dp算法求解整数划分
#	一个整数可以由若干个整数的平方和表示，求最小划分。
#	比如
#	1 = 1*1，最小划分为1；
#	2 = 1*1 + 1*1，最小划分为2；
#	4 = 2*2，最小划分为1；
#	5 = 2*2 + 1*1，最小划分为2；
#	给定n，求它的最小划分。
#	要求尽可能低的时间复杂度。

import sys
import math

num = 42

times = [0 for i in range(num + 1)]
t1 = int(math.sqrt(num))

for i in range(1, t1 + 1):
	times[i*i] = 1

for i in range(1, num + 1):
	if times[i] == 0:
	    max1 = i 	# 全由1*1组成，所以最大值为i

	    for j in range(1, int(math.sqrt(i))+1):
	        if times[j*j] + times[i - j*j] < max1:
	            max1 = times[j*j] + times[i - j*j]
	            if max1 == 2:
	                break
	    times[i] = max1

print times[-1]
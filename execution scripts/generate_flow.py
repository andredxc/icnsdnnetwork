import os
import random
from common import *
import statistics
import math
import threading

class GenerateFlow:
	def __init__( self, drones, humans, sensors, vehicles):
		self.assets = {}
		self.assets["drone"] = drones
		self.assets["human"] = humans
		self.assets["sensor"] = sensors
		self.assets["vehicle"] = vehicles
		self.data = []
		self.misses = 0
		self.permissions = {
			"sensor" : [ "sensor" ],
			"drone" : [  "sensor", "drone" ],
			"human" : [ "sensor", "drone", "human" ],
			"vehicle" : [ "sensor", "drone", "human", "vehicle" ]
		}

	def consume( self, command, cached, assetFrom, selectedAsset):
		print "{}{} {}".format(assetFrom, selectedAsset, command)
		if assetFrom != "sensor":
			changeEnvironment( "{}{}".format(assetFrom[0], selectedAsset), False )
		else:
			changeEnvironment( "r{}".format( selectedAsset), False )
		p = execute( command )
		if not cached:
			p.wait()
			output = p.stdout.read()
			for out in output.splitlines():
				if out != '':
					num = int ( out )
					if num < 1000000:
						self.data.append( int( out ) )
						print out
					else:
						self.misses += 1

	def send( self, assetFrom, assetTo, amount, cached):
		for i in range(amount): 
			print "------------------------------------------"
			print "From {} to {}:".format(assetFrom, assetTo)
			print "------------------------------------------"
			data = []
			threads = []
			cachedFlow = -1
			assetAll = False
			if cached: 
				cachedFlow = 0
			if assetFrom == 'all' and assetTo == 'all':
				assetAll = True
				cachedFlow = 0
			else:
				selectedAsset = random.randint(1, self.assets[assetFrom])
			if assetAll:
				assetFrom, assetFromAmount = random.choice(list(self.assets.items()))
				print assetFrom
				assetTo = random.choice(self.permissions[assetFrom])
				selectedAsset = random.randint(1, assetFromAmount)
			if cached:
				cacheRequest = '/home/osboxes/mini-ndn/ndn-cxx/examples/masterwork consumer {} 1 cached &'.format(assetTo)
				threads.append(threading.Thread( target=self.consume, args=[cacheRequest, cached, assetFrom, selectedAsset]))
			command = 'for i in $(seq 1 {}); do /home/osboxes/mini-ndn/ndn-cxx/examples/masterwork consumer {} 1; done'.format(1, assetTo)
			threads.append(threading.Thread( target=self.consume, args=[command, False, assetFrom, selectedAsset]))
			[thread.start() for thread in threads]
			[thread.join() for thread in threads]
			assetFrom = assetTo =  'all'
		print 'Flows sent: {}'.format(len(self.data))
		print 'Mean time: {}'.format(statistics.mean(self.data))
		print 'Standard deviation: {}'.format(statistics.stdev(self.data))
		print 'Misses: {}'.format(self.misses)
		self.data = []



			


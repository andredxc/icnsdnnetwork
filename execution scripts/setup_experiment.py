import subprocess
import os

from common import *


class ExperimentFuncs:
	def __init__( self, drones, humans, sensors, vehicles):
		self.assets = {}
		self.assets["drone"] = []
		self.assets["human"] = []
		self.assets["sensor"] = []
		self.assets["vehicle"] = []

		currIp = 1

		for i in range(1, drones+1):
			self.assets["drone"].append( ( "d{}".format(i), "10.0.0.{}".format(currIp) ) )
			currIp += 1

		for i in range(1, humans+1):
			self.assets["human"].append( ("h{}".format(i), "10.0.0.{}".format(currIp) ) )
			currIp += 1

		for i in range(1, sensors+1):
			self.assets["sensor"].append( ("r{}".format(i), "10.0.0.{}".format(currIp) ) )
			currIp += 1

		for i in range(1, vehicles+1):
			self.assets["vehicle"].append( ( "v{}".format(i), "10.0.0.{}".format(currIp) ) )
			currIp += 1

		self.destinationIp = "10.0.0.{}".format(currIp)


	def faceCreate( self, ip ):
		p = subprocess.Popen('nfdc face create udp://{}'.format(ip), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		p.wait()
		printOutput(p)

	def addRoute( self, routetype, ip ):
		p = subprocess.Popen('nfdc route add prefix {} nexthop udp://{} cost 1'.format(routetype, ip), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		p.wait()
		printOutput(p)

	def addControlRoutes( self ):
		for asset in self.assets:
			p = subprocess.Popen('nfdc route add controladd{}interest udp://{}'.format(asset, self.destinationIp), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
			p.wait()
			printOutput(p)

	def setCacheSize( self, size ):
		p = subprocess.Popen('nfdc cs config capacity {}'.format(size), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		p.wait()
		printOutput(p)

	def activateArp( self, host ):
		p = subprocess.Popen('/home/osboxes/mini-ndn/mininet/util/m {} ping -c 1 10.0.0.1'.format(host), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		p.wait()
		printOutput(p)

	def setupExperiment( self ):
		for index in self.assets:
			for element, ip in self.assets[index]:
				print('----------------------------------------------')
				changeEnvironment( element )
				self.setCacheSize( 3 )
				self.activateArp( element )
				self.faceCreate( self.destinationIp )
				self.addControlRoutes()
				for index_face in self.assets:
					for element_face, ip_face in self.assets[index_face]:
						self.addRoute( index_face+'interest', self.destinationIp )
				print('----------------------------------------------')
		self.activateArp( 'z1' )

	def startServers( self ):
		for index in self.assets:
			for element, ip in self.assets[index]:
				changeEnvironment( element )
				p = subprocess.Popen('/home/osboxes/mini-ndn/ndn-cxx/examples/masterwork producer {} 1 &'.format(index), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
				print 'Server {} initiated.'.format(element)

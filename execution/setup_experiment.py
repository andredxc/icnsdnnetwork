import subprocess
import os


def printOutput( output ):
	print output.stdout.read()

def faceCreate( ip ):
	p = subprocess.Popen('nfdc face create udp://{}'.format(ip), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	print('cmd: nfdc face create udp://{}'.format(ip))
	p.wait()
	printOutput(p)

def addRoute( routetype, ip ):
	print('addRoute start')
	p = subprocess.Popen('nfdc route add {} udp://{}'.format(routetype, ip), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	print('cmd: nfdc route add {} udp://{}'.format(routetype, ip))
	p.wait()
	printOutput(p)
	print('addRoute end')

def addControlRoutes():
	print('addControlRoutes start')
	for asset in assets:
		p = subprocess.Popen('nfdc route add controladd{} udp://10.0.0.7'.format(asset), shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
		print('cmd: nfdc route add controladd{} udp://10.0.0.7'.format(asset))
		p.wait()
		printOutput(p)
	print('addControlRoutes end')

def changeEnvironment( asset ):
	os.environ["HOME"] = "/tmp/minindn/{}/".format(asset)
	print('export HOME=/tmp/minindn/{}/'.format(asset))
	print ("Environment set: ", os.environ["HOME"])


assets = {}

assets["drone"] = [('d1', '10.0.0.1'), ('d2', '10.0.0.2')]
assets["human"] = [('h1', '10.0.0.3'), ('h2', '10.0.0.4')]
assets["sensor"] = [('r1', '10.0.0.5'), ('r2', '10.0.0.6')]
assets["vehicle"] = [('v1', '10.0.0.7')]

for index in assets:
	for element, ip in assets[index]:
		print('----------------------------------------------')
		changeEnvironment( element )
		faceCreate( '10.0.0.7' )
		for index_face in assets:
			for element_face, ip_face in assets[index_face]:
					addRoute( index_face, '10.0.0.7' )
		addControlRoutes()
		print('----------------------------------------------')

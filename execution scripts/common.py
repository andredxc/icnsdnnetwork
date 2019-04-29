import os
import subprocess

def changeEnvironment( asset, printActivated = True):
	os.environ["HOME"] = "/tmp/minindn/{}/".format(asset)
	if printActivated:
		print ("Environment set: ", os.environ["HOME"])

def printOutput( output ):
	print output.stdout.read()

def execute( command ):
	return subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
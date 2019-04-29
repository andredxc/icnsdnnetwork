from setup_experiment import ExperimentFuncs
from generate_flow import GenerateFlow
import sys

def main():
	print 'How many nodes do you have? ',
	nodesAmount = input()
	nodes = { 10: { "drone": 4, "human": 3, "sensor": 2, "vehicle": 1},
			  20: { "drone": 7, "human": 6, "sensor": 5, "vehicle": 2},
			  30: { "drone": 11, "human": 8, "sensor": 9, "vehicle": 2},
			 }
	experiment = ExperimentFuncs( nodes[nodesAmount]["drone"], nodes[nodesAmount]["human"], nodes[nodesAmount]["sensor"], nodes[nodesAmount]["vehicle"] )
	generateFlow = GenerateFlow( nodes[nodesAmount]["drone"], nodes[nodesAmount]["human"], nodes[nodesAmount]["sensor"], nodes[nodesAmount]["vehicle"] )

	print '-------------------------------------------------------------------'
	print 'Choose your option:'
	option = input()
	while True:
		if option == 1:
			experiment.setupExperiment()
			experiment.startServers()
		elif option == 2:
			print 'Asset from:'
			afrom = raw_input()
			print 'Asset to:'
			ato = raw_input()
			print 'Times:'
			times = input()
			print 'Cache enabled:'
			cache = raw_input()

			if cache == 'yes':
				cached = True
			else:
				cached = False
			generateFlow.send(afrom, ato, times, cached)
		elif option == -1:
			sys.exit()
		print '-------------------------------------------------------------------'
		print 'Choose your option:'
		option = input()


	generateFlow.send( "human", "drone", 10 )

if __name__ == "__main__":
	main()
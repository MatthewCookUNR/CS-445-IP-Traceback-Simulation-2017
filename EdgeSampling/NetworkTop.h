#include <vector>
#include "Node.h"

using namespace std;

class NetworkTop
{
	public:
		NetworkTop();
		~NetworkTop();
		void variableRouters();
		void variableBranches();
		void variableProbOneAttacker();
		void variableMult();
		double randomNumberGen();
		void addMarkedPacket( Tuple markedPacket );
		void attackVictim( int attackerPackets );
		void incrementGraphSize();
		bool isInMarkedGraph( Tuple markedPacket );
		void printPossiblePaths();
	private:
		vector<Node*> routers;
		vector<Tuple> pathGraph;
		int graphSize;
		int branches;
		int multFactor;
		float markProb;	
};

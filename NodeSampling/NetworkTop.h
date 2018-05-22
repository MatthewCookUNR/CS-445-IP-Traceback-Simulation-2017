#include <vector>
#include "Node.h"
#include "Tuple.h"

using namespace std;

/*------------------------------------------------
NetworkTop class contains the network topology
and functionality of the simulation
--------------------------------------------------*/
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
		void addMarkedPacket( int routerID );
		void incrementTableSize();
		int getTableSize();
		bool isInMarkedTable( int routerID );
		void printMarkTable();
		void markTableSort();
		void clearTable();
		void attackVictim( int attackerPackets );
	private:
		vector<Node*> routers;
		vector<Tuple> markTable;
		int markTableSize;
		int branches;
		int multFactor;
		float markProb;
		
};

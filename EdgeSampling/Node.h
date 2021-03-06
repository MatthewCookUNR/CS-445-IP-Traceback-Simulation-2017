#include <vector>
#include <iostream>
#include "Tuple.h"

using namespace std;

/*------------------------------------------------
Node class simulates the functionality of a node
in a network
--------------------------------------------------*/
class Node
{
	public:
		Node();
		~Node();
		void setAttacker(bool status);
		void setNormalUser(bool status);
		bool isAttacker();
		bool isNormalUser();
		void pushRouterInPath( int routerID );
		int getNumberOfPathRouters();
		Tuple sendPacketToVictim( double prob );
		double randomNumberGen();
	private:
		vector<int> routePath;
		bool attacker;
		bool normalUser;
};

#include <vector>
#include <iostream>
#include "Tuple.h"

using namespace std;

class Node
{
	public:
		Node();
		~Node();
		void setAttacker(bool status);
		void setNormalUser(bool status);
		//void setVictim();
		bool isAttacker();
		bool isNormalUser();
		void pushRouterInPath( int routerID );
		int getNumberOfPathRouters();
		Tuple sendPacketToVictim( double prob );
		double randomNumberGen();
		//bool isVicim();
		//void setNextNodeInPath(Node* nextNode);
		//Node* getNextNodeInPath();
	private:
		vector<int> routePath;
		bool attacker;
		bool normalUser;
		//bool victim;
};

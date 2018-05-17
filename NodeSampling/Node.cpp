#include "Node.h"
#include <random>

Node::Node()
{
	attacker = false;
	normalUser = false;
}

Node::~Node()
{

}

void Node::setAttacker( bool status )
{
	attacker = status;
}

void Node::setNormalUser( bool status )
{
	normalUser = status;
}
/*
void Node::setVictim()
{
	victim = true;
}
*/
bool Node::isAttacker()
{
	return attacker;
}

bool Node::isNormalUser()
{
	return normalUser;
}

void Node::pushRouterInPath( int routerID )
{
	routePath.push_back( routerID );
}

int Node::getNumberOfPathRouters()
{
	return routePath.size();
}

int Node::sendPacketToVictim( double prob )
{
	int routeSize = routePath.size();
	int markedNodeID = 0;
	double rngProb;
	for ( int i = 0; i < routeSize-1; i++ )
	{
		rngProb = randomNumberGen();
		if( rngProb < prob )
		{
			markedNodeID = routePath[i];
		}
	}
	return markedNodeID;
}

double Node::randomNumberGen()
{
	double randomProb;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> rng(0, 1);
	randomProb = rng(gen);
	return randomProb;
}

/*
bool Node::isVicim()
{
	return victim;
}

void Node::setNextNodeInPath(Node * nextNode)
{
	nextNodeInPath = nextNode;
}

Node* Node::getNextNodeInPath()
{
	return nextNodeInPath;
}
*/

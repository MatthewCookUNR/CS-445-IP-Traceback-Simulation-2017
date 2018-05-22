#include "Node.h"
#include <random>

/*------------------------------------------------
Constructor for the node class
--------------------------------------------------*/
Node::Node()
{
	attacker = false;
	normalUser = false;
}

/*------------------------------------------------
Deconstructor for the network topology class
--------------------------------------------------*/
Node::~Node()
{

}

/*------------------------------------------------
Sets the attacker status
--------------------------------------------------*/
void Node::setAttacker( bool status )
{
	attacker = status;
}

/*------------------------------------------------
Sets normal user status 
--------------------------------------------------*/
void Node::setNormalUser( bool status )
{
	normalUser = status;
}

/*------------------------------------------------
Returns whether or not node is a attacker
--------------------------------------------------*/
bool Node::isAttacker()
{
	return attacker;
}

/*------------------------------------------------
Returns whether or not node is a normal user
--------------------------------------------------*/
bool Node::isNormalUser()
{
	return normalUser;
}

/*------------------------------------------------
Pushes a router to the route path vector
--------------------------------------------------*/
void Node::pushRouterInPath( int routerID )
{
	routePath.push_back( routerID );
}

/*------------------------------------------------
Gets the size of the route path vector
--------------------------------------------------*/
int Node::getNumberOfPathRouters()
{
	return routePath.size();
}

/*------------------------------------------------
Simulates sending a packet to the victim
--------------------------------------------------*/
Tuple Node::sendPacketToVictim( double prob )
{
	int routeSize = routePath.size();
	Tuple markedPacket;
	double rngProb;
	for ( int i = 0; i < routeSize; i++ )
	{
		rngProb = randomNumberGen();
		if( rngProb < prob )
		{
			markedPacket.start = routePath[i];
			markedPacket.distance = 0;
		}
		else
		{
			if( markedPacket.distance == 0 )
			{
				markedPacket.end = routePath[i];
			}
			markedPacket.distance++;
		}
	}
	return markedPacket;
}

/*------------------------------------------------
Randomly generates a number between 0 and 1
--------------------------------------------------*/
double Node::randomNumberGen()
{
	double randomProb;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> rng(0, 1);
	randomProb = rng(gen);
	return randomProb;
}


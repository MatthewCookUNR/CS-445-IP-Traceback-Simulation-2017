#include "NetworkTop.h"
#include <iostream>
#include <random>

/*------------------------------------------------
Constructor for the network topology class
--------------------------------------------------*/
NetworkTop::NetworkTop()
{
	markTableSize = 0;
	int testNum;
	cout << "Node Sampling Test" << endl;
	cout << "Please choose what variable that will be tested" << endl << endl;
	cout << "1 is number of routers, 2 is number of branches, 3 is probability of marking, and 4 is multiplicative factor: ";
	cin >> testNum;
	while( testNum != 1 && testNum != 2 && testNum != 3 && testNum != 4 )
	{
		cout << "Invalid number entered, please try again: ";
		cin >> testNum;
	}
	switch( testNum )
	{
		case 1:
			variableRouters();
			break;
		case 2:
			variableBranches();
			break;
		case 3:
			variableProbOneAttacker();
			break;
		case 4:
			variableMult();
			break;
		default:
			break;
	}
}

/*------------------------------------------------
Deconstructor for the network topology class
--------------------------------------------------*/
NetworkTop::~NetworkTop()
{
	clearTable();
	routers.clear();
	routers.shrink_to_fit();
}

/*------------------------------------------------
Handles running the simulation with varying 
number routers in the network
--------------------------------------------------*/
void NetworkTop::variableRouters()
{
	int numberOfRouters;
	int attackerPackets;

	//Default variable values
	branches = 3;
	multFactor = 1000;
	markProb = 0.4;

	//Branch setup
	routers.resize(branches);
	for(int i = 0; i < branches; i++)
    {
        routers[i] = new Node;
    }

	//Desired probability of marking packets to use for test
	cout << "What number of routers (10, 20, or 30) will be tested: ";
	cin >> numberOfRouters;
	cout << endl;
	while( numberOfRouters != 10 && numberOfRouters != 20 && numberOfRouters != 30 )
	{
		cout << "Invalid number of routers, please try again: ";
		cin >> numberOfRouters;
	}

	//Desired number of packets attackers will send
	cout << "How many packets will the attacker user send: ";
	cin >> attackerPackets;
	cout << endl;
	while( attackerPackets < 0 && attackerPackets > 10000000000 )
	{
		cout << "Invalid number of packets, please try again: ";
		cin >> attackerPackets;
	}

	cout << "Default marking probability: " << markProb << endl;
	cout << "Default multiplicative factor: " << multFactor << endl;
	cout << "Default number of branches: " << branches << endl;
	cout << endl;

	//Router topology setup
	if( numberOfRouters == 10 )
	{
		//Branch 1
		routers[0]->pushRouterInPath(4);
		routers[0]->pushRouterInPath(1);
		routers[0]->pushRouterInPath(0);
		//Branch 2
		routers[1]->pushRouterInPath(4);
		routers[1]->pushRouterInPath(6);
		routers[1]->pushRouterInPath(2);
		routers[1]->pushRouterInPath(0);
		//Branch 3
		routers[2]->pushRouterInPath(5);
		routers[2]->pushRouterInPath(3);
		routers[2]->pushRouterInPath(0);
	}
	else if( numberOfRouters == 20 )
	{
		//Branch 1
		routers[0]->pushRouterInPath(16);
		routers[0]->pushRouterInPath(14);
		routers[0]->pushRouterInPath(11);
		routers[0]->pushRouterInPath(10);
		routers[0]->pushRouterInPath(9);
		routers[0]->pushRouterInPath(7);
		routers[0]->pushRouterInPath(4);
		routers[0]->pushRouterInPath(1);
		routers[0]->pushRouterInPath(0);
		//Branch 2
		routers[1]->pushRouterInPath(16);
		routers[1]->pushRouterInPath(14);
		routers[1]->pushRouterInPath(12);
		routers[1]->pushRouterInPath(10);
		routers[1]->pushRouterInPath(8);
		routers[1]->pushRouterInPath(7);
		routers[1]->pushRouterInPath(5);
		routers[1]->pushRouterInPath(2);
		routers[1]->pushRouterInPath(0);
		//Branch 3
		routers[2]->pushRouterInPath(15);
		routers[2]->pushRouterInPath(13);
		routers[2]->pushRouterInPath(10);
		routers[2]->pushRouterInPath(8);
		routers[2]->pushRouterInPath(6);
		routers[2]->pushRouterInPath(3);
		routers[2]->pushRouterInPath(0);
	}
	else
	{
		//Branch 1
		routers[0]->pushRouterInPath(24);
		routers[0]->pushRouterInPath(23);
		routers[0]->pushRouterInPath(20);
		routers[0]->pushRouterInPath(17);
		routers[0]->pushRouterInPath(16);
		routers[0]->pushRouterInPath(14);
		routers[0]->pushRouterInPath(11);
		routers[0]->pushRouterInPath(10);
		routers[0]->pushRouterInPath(9);
		routers[0]->pushRouterInPath(7);
		routers[0]->pushRouterInPath(4);
		routers[0]->pushRouterInPath(1);
		routers[0]->pushRouterInPath(0);
		//Branch 2
		routers[1]->pushRouterInPath(24);
		routers[1]->pushRouterInPath(23);
		routers[1]->pushRouterInPath(21);
		routers[1]->pushRouterInPath(18);
		routers[1]->pushRouterInPath(16);
		routers[1]->pushRouterInPath(14);
		routers[1]->pushRouterInPath(12);
		routers[1]->pushRouterInPath(10);
		routers[1]->pushRouterInPath(8);
		routers[1]->pushRouterInPath(7);
		routers[1]->pushRouterInPath(5);
		routers[1]->pushRouterInPath(2);
		routers[1]->pushRouterInPath(0);
		//Branch 3
		routers[2]->pushRouterInPath(26);
		routers[2]->pushRouterInPath(25);
		routers[2]->pushRouterInPath(22);
		routers[2]->pushRouterInPath(19);
		routers[2]->pushRouterInPath(15);
		routers[2]->pushRouterInPath(13);
		routers[2]->pushRouterInPath(10);
		routers[2]->pushRouterInPath(8);
		routers[2]->pushRouterInPath(6);
		routers[2]->pushRouterInPath(3);
		routers[2]->pushRouterInPath(0);
	}

	//1 Attacker 1 Normal User
	cout << "Results with 1 Attacker 1 Normal User: " << endl;
	routers[0]->setAttacker( true );
	routers[1]->setNormalUser( true );
	attackVictim( attackerPackets );

	//1 Attacker 2 Normal Users
	cout << "Results with 1 Attacker 2 Normal Users: " << endl;
	routers[2]->setNormalUser( true );
	attackVictim( attackerPackets );

	//2 Attackers 1 Normal User
	cout << "Results with 2 Attackers 1 Normal User: " << endl;
	routers[2]->setNormalUser( false );
	routers[2]->setAttacker( true );
	attackVictim( attackerPackets );
}

/*------------------------------------------------
Handles running the simulation with varying
number of branches in the network
--------------------------------------------------*/	
void NetworkTop::variableBranches()
{
	int attackerPackets;

	//Default variable values
	markProb = 0.4;
	multFactor = 1000;

	//Desired probability of marking packets to use for test
	cout << "What number of branches (3, 4, or 5) will be tested: ";
	cin >> branches;
	cout << endl;
	while( branches != 3 && branches != 4 && branches != 5 )
	{
		cout << "Invalid number of branches, please try again: ";
		cin >> branches;
	}

	//Desired number of packets attackers will send
	cout << "How many packets will the attacker user send: ";
	cin >> attackerPackets;
	cout << endl;
	while( attackerPackets < 0 && attackerPackets > 10000000000 )
	{
		cout << "Invalid number of packets, please try again: ";
		cin >> attackerPackets;
	}

	cout << "Default marking probability: " << markProb << endl;
	cout << "Default multiplicative factor: " << multFactor << endl;
	cout << "Default number of routers: " << 20 << endl;
	cout << endl;

	routers.resize(branches);
	for(int i = 0; i < branches; i++)
	{
		routers[i] = new Node;
	}
	//Network Topology setup
	if( branches == 3 )
	{
		//Branch 1
		routers[0]->pushRouterInPath(16);
		routers[0]->pushRouterInPath(14);
		routers[0]->pushRouterInPath(11);
		routers[0]->pushRouterInPath(10);
		routers[0]->pushRouterInPath(9);
		routers[0]->pushRouterInPath(7);
		routers[0]->pushRouterInPath(4);
		routers[0]->pushRouterInPath(1);
		routers[0]->pushRouterInPath(0);
		//Branch 2
		routers[1]->pushRouterInPath(16);
		routers[1]->pushRouterInPath(14);
		routers[1]->pushRouterInPath(12);
		routers[1]->pushRouterInPath(10);
		routers[1]->pushRouterInPath(8);
		routers[1]->pushRouterInPath(7);
		routers[1]->pushRouterInPath(5);
		routers[1]->pushRouterInPath(2);
		routers[1]->pushRouterInPath(0);
		//Branch 3
		routers[2]->pushRouterInPath(15);
		routers[2]->pushRouterInPath(13);
		routers[2]->pushRouterInPath(10);
		routers[2]->pushRouterInPath(8);
		routers[2]->pushRouterInPath(6);
		routers[2]->pushRouterInPath(3);
		routers[2]->pushRouterInPath(0);

		//1 Attacker 1 Normal User
		cout << "Results with 1 Attacker 1 Normal User: " << endl;
		routers[0]->setAttacker( true );
		routers[1]->setNormalUser( true );
		attackVictim( attackerPackets );

		//1 Attacker 2 Normal Users
		cout << "Results with 1 Attacker 2 Normal Users: " << endl;
		routers[2]->setNormalUser( true );
		attackVictim( attackerPackets );

		//2 Attackers 1 Normal User
		cout << "Results with 2 Attackers 1 Normal User: " << endl;
		routers[2]->setNormalUser( false );
		routers[2]->setAttacker( true );
		attackVictim( attackerPackets );
	}
	else if( branches == 4 )
	{
		//Branch 1
		routers[0]->pushRouterInPath(11);
		routers[0]->pushRouterInPath(10);
		routers[0]->pushRouterInPath(9);
		routers[0]->pushRouterInPath(7);
		routers[0]->pushRouterInPath(4);
		routers[0]->pushRouterInPath(1);
		routers[0]->pushRouterInPath(0);
		//Branch 2
		routers[1]->pushRouterInPath(17);
		routers[1]->pushRouterInPath(11);
		routers[1]->pushRouterInPath(10);
		routers[1]->pushRouterInPath(9);
		routers[1]->pushRouterInPath(7);
		routers[1]->pushRouterInPath(2);
		routers[1]->pushRouterInPath(0);
		//Branch 3
		routers[2]->pushRouterInPath(10);
		routers[2]->pushRouterInPath(8);
		routers[2]->pushRouterInPath(7);
		routers[2]->pushRouterInPath(5);
		routers[2]->pushRouterInPath(0);
		//Branch 4
		routers[3]->pushRouterInPath(15);
		routers[3]->pushRouterInPath(13);
		routers[3]->pushRouterInPath(10);
		routers[3]->pushRouterInPath(8);
		routers[3]->pushRouterInPath(6);
		routers[3]->pushRouterInPath(0);

		//1 Attacker 3 Normal User
		cout << "Results with 1 Attacker 3 Normal Users: " << endl;
		routers[0]->setAttacker( true );
		routers[1]->setNormalUser( true );
		routers[2]->setNormalUser( true );
		routers[3]->setNormalUser( true );
		attackVictim( attackerPackets );

		//2 Attackers 2 Normal User
		cout << "Results with 2 Attackers 2 Normal Users: " << endl;
		routers[2]->setNormalUser( false );
		routers[2]->setAttacker( true );
		attackVictim( attackerPackets );
	}
	else
	{
		//Branch 1
		routers[0]->pushRouterInPath(11);
		routers[0]->pushRouterInPath(10);
		routers[0]->pushRouterInPath(9);
		routers[0]->pushRouterInPath(7);
		routers[0]->pushRouterInPath(4);
		routers[0]->pushRouterInPath(1);
		routers[0]->pushRouterInPath(0);
		//Branch 2
		routers[1]->pushRouterInPath(11);
		routers[1]->pushRouterInPath(10);
		routers[1]->pushRouterInPath(9);
		routers[1]->pushRouterInPath(7);
		routers[1]->pushRouterInPath(2);
		routers[1]->pushRouterInPath(0);
		//Branch 3
		routers[2]->pushRouterInPath(11);
		routers[2]->pushRouterInPath(10);
		routers[2]->pushRouterInPath(8);
		routers[2]->pushRouterInPath(5);
		routers[2]->pushRouterInPath(0);
		//Branch 4
		routers[3]->pushRouterInPath(10);
		routers[3]->pushRouterInPath(8);
		routers[3]->pushRouterInPath(7);
		routers[3]->pushRouterInPath(3);
		routers[3]->pushRouterInPath(0);
		//Branch 5
		routers[4]->pushRouterInPath(15);
		routers[4]->pushRouterInPath(13);
		routers[4]->pushRouterInPath(10);
		routers[4]->pushRouterInPath(8);
		routers[4]->pushRouterInPath(6);
		routers[4]->pushRouterInPath(0);

		//1 Attacker 4 Normal User
		cout << "Results with 1 Attacker 4 Normal Users: " << endl;
		routers[0]->setAttacker( true );
		routers[1]->setNormalUser( true );
		routers[2]->setNormalUser( true );
		routers[3]->setNormalUser( true );
		routers[4]->setNormalUser( true );
		attackVictim( attackerPackets );

		//2 Attacker 3 Normal Users
		cout << "Results with 2 Attackers 3 Normal Users: " << endl;
		routers[3]->setNormalUser( false );
		routers[3]->setAttacker( true );
		attackVictim( attackerPackets );
	}
}

/*------------------------------------------------
Handles running the simulation with varying
probability of marking packets
--------------------------------------------------*/
void NetworkTop::variableProbOneAttacker()
{
	int attackerPackets;

	//Default variable values
	branches = 3;
	multFactor = 1000;

	routers.resize(branches);
	for(int i = 0; i < branches; i++)
    {
        routers[i] = new Node;
    }
	
	//Branch 1
	routers[0]->pushRouterInPath(16);
	routers[0]->pushRouterInPath(14);
	routers[0]->pushRouterInPath(11);
	routers[0]->pushRouterInPath(10);
	routers[0]->pushRouterInPath(9);
	routers[0]->pushRouterInPath(7);
	routers[0]->pushRouterInPath(4);
	routers[0]->pushRouterInPath(1);
	routers[0]->pushRouterInPath(0);
	//Branch 2
	routers[1]->pushRouterInPath(16);
	routers[1]->pushRouterInPath(14);
	routers[1]->pushRouterInPath(12);
	routers[1]->pushRouterInPath(10);
	routers[1]->pushRouterInPath(8);
	routers[1]->pushRouterInPath(7);
	routers[1]->pushRouterInPath(5);
	routers[1]->pushRouterInPath(2);
	routers[1]->pushRouterInPath(0);
	//Branch 3
	routers[2]->pushRouterInPath(15);
	routers[2]->pushRouterInPath(13);
	routers[2]->pushRouterInPath(10);
	routers[2]->pushRouterInPath(8);
	routers[2]->pushRouterInPath(6);
	routers[2]->pushRouterInPath(3);
	routers[2]->pushRouterInPath(0);

	//Desired probability of marking packets to use for test
	cout << "What probability of marking will be tested: ";
	cin >> markProb;
	cout << endl;
	while( markProb < 0 || markProb > 1 )
	{
		cout << "Invalid probability of marking, please try again: ";
		cin >> markProb;
	}

	//Desired number of packets attackers will send
	cout << "How many packets will the attacker user send: ";
	cin >> attackerPackets;
	cout << endl;
	while( attackerPackets < 0 && attackerPackets > 10000000000 )
	{
		cout << "Invalid number of packets, please try again: ";
		cin >> attackerPackets;
	}

	cout << "Default number of branches: " << branches << endl;
	cout << "Default multiplicative factor: " << multFactor << endl;
	cout << "Default number of routers: " << 20 << endl;
	cout << endl;

	//1 Attacker 1 Normal User
	cout << "Results with 1 Attacker 1 Normal User: " << endl;
	routers[0]->setAttacker( true );
	routers[1]->setNormalUser( true );
	attackVictim( attackerPackets );

	//1 Attacker 2 Normal Users
	cout << "Results with 1 Attacker 2 Normal Users: " << endl;
	routers[2]->setNormalUser( true );
	attackVictim( attackerPackets );

	//2 Attackers 1 Normal User
	cout << "Results with 2 Attackers 1 Normal User: " << endl;
	routers[2]->setNormalUser( false );
	routers[2]->setAttacker( true );
	attackVictim( attackerPackets );
}

/*------------------------------------------------
Handles running the simulation with varying
multiplication factors

Example: If multiplication factor is 100, the
attacker sends 100 times more packets than
the normal user
--------------------------------------------------*/
void NetworkTop::variableMult()
{
	int attackerPackets;

	//Default Variable Values
	branches = 3;
	markProb = 0.4;

	//Default Number of Routers (20), Branches (3), and Marking Probability (0.4)
	routers.resize(branches);
	for(int i = 0; i < branches; i++)
    {
        routers[i] = new Node;
    }

	//Branch 1
	routers[0]->pushRouterInPath(16);
	routers[0]->pushRouterInPath(14);
	routers[0]->pushRouterInPath(11);
	routers[0]->pushRouterInPath(10);
	routers[0]->pushRouterInPath(9);
	routers[0]->pushRouterInPath(7);
	routers[0]->pushRouterInPath(4);
	routers[0]->pushRouterInPath(1);
	routers[0]->pushRouterInPath(0);
	//Branch 2
	routers[1]->pushRouterInPath(16);
	routers[1]->pushRouterInPath(14);
	routers[1]->pushRouterInPath(12);
	routers[1]->pushRouterInPath(10);
	routers[1]->pushRouterInPath(8);
	routers[1]->pushRouterInPath(7);
	routers[1]->pushRouterInPath(5);
	routers[1]->pushRouterInPath(2);
	routers[1]->pushRouterInPath(0);
	//Branch 3
	routers[2]->pushRouterInPath(15);
	routers[2]->pushRouterInPath(13);
	routers[2]->pushRouterInPath(10);
	routers[2]->pushRouterInPath(8);
	routers[2]->pushRouterInPath(6);
	routers[2]->pushRouterInPath(3);
	routers[2]->pushRouterInPath(0);

	//Desired probability of marking packets to use for test
	cout << "What multiplicative factor will be tested: ";
	cin >> multFactor;
	cout << endl;
	while( multFactor != 10 && multFactor != 100 && multFactor != 1000 )
	{
		cout << "Invalid multiplicative factor, please try again: ";
		cin >> multFactor;
	}

	//Desired number of packets attackers will send
	cout << "How many packets will the attacker user send: ";
	cin >> attackerPackets;
	cout << endl;
	while( attackerPackets < 0 && attackerPackets > 10000000000 )
	{
		cout << "Invalid number of packets, please try again: ";
		cin >> attackerPackets;
	}

	cout << "Default marking probability: " << markProb << endl;
	cout << "Default number of branches: " << branches << endl;
	cout << "Default number of routers: " << 20 << endl;
	cout << endl;

	//1 Attacker 1 Normal User
	cout << "Results with 1 Attacker 1 Normal User: " << endl;
	routers[0]->setAttacker( true );
	routers[1]->setNormalUser( true );
	attackVictim( attackerPackets );

	//1 Attacker 2 Normal User
	cout << "Results with 1 Attacker 2 Normal Users: " << endl;
	routers[2]->setNormalUser( true );
	attackVictim( attackerPackets );

	//2 Attacker 1 Normal User
	cout << "Results with 2 Attackers 1 Normal User: " << endl;
	routers[2]->setNormalUser( false );
	routers[2]->setAttacker( true );
	attackVictim( attackerPackets );
}

/*------------------------------------------------
Clears the table of marked packets
--------------------------------------------------*/
void NetworkTop::clearTable()
{
	markTable.clear();
	markTable.shrink_to_fit();
	markTableSize = 0;
}

/*------------------------------------------------
Simulates marking packets (using the node sampling
algorithm) during a attack scenario
--------------------------------------------------*/
void NetworkTop::attackVictim( int attackerPackets )
{
	int markedRouterID;
	for( int i = 0; i < branches; i++ )
	{
		//Checks if router is a malicious user
		if(routers[i] -> isAttacker())
		{
			for( int x = 0; x < attackerPackets; x++ )
			{
				markedRouterID =  routers[i] -> sendPacketToVictim( markProb );
				if( markedRouterID != 0 )
				{
					addMarkedPacket( markedRouterID );
				}
			}
		}
		//Checks if router is a normal user
		if(routers[i] -> isNormalUser())
		{
			for( int x = 0; x < attackerPackets/multFactor; x++ )
			{
				markedRouterID =  routers[i] -> sendPacketToVictim( markProb );
				
				//Checks if router was marked
				if( markedRouterID != 0 )
				{
					//Adds marked packet to table
					addMarkedPacket( markedRouterID );
				}
			}
		}
	}
	markTableSort();
	printMarkTable();
	clearTable();
}

/*------------------------------------------------
Increments the number of marked packets for the 
given router id
-------------------------------------------------*/
void NetworkTop::addMarkedPacket( int routerID )
{
	if( isInMarkedTable( routerID ) == false )
	{
		markTable.push_back(Tuple());
		incrementTableSize();
		markTable[markTableSize-1].nodeID = routerID;
		markTable[markTableSize-1].numberMarked = 1;
	}
	else
	{
		for( int i = 0; i < markTableSize; i++ )
		{
			if( markTable[i].nodeID == routerID)
			{
				markTable[i].numberMarked++;
			}
		}
	}
}

/*------------------------------------------------
Prints a table that details how many marked 
packets were recieved from all the routers
-------------------------------------------------*/
void NetworkTop::printMarkTable()
{
	for( int i = 0; i < markTableSize; i++ )
	{
		cout << markTable[i].nodeID << "  " << markTable[i].numberMarked << endl;
	}
	cout << endl;
}

/*------------------------------------------------
increments the size of the marked packet table
-------------------------------------------------*/
void NetworkTop::incrementTableSize()
{
	markTableSize++;
}

/*------------------------------------------------
Gets the size of the marked packet table
-------------------------------------------------*/
int NetworkTop::getTableSize()
{
	return markTableSize;
}

/*------------------------------------------------
Checks to see if a node is already in the marked
packet table
-------------------------------------------------*/
bool NetworkTop::isInMarkedTable( int routerID )
{
	for( int i = 0; i < markTableSize; i++ )
	{
		if( markTable[i].nodeID == routerID )
		{
			return true;
		}
	}
	return false;
}

/*------------------------------------------------
Sorts the marked packet table in order from 
greatest to largest
-------------------------------------------------*/
void NetworkTop::markTableSort()
{
	bool sorted = false;
	int tempID;
	int tempNumberMarked;
	while( sorted == false && markTableSize > 1 )
	{
		sorted = true;
		for( int i = 0; i < markTableSize-1; i++ )
		{
			if(markTable[i].numberMarked < markTable[i+1].numberMarked)
			{
				tempID = markTable[i].nodeID;
				tempNumberMarked = markTable[i].numberMarked;
				markTable[i].nodeID = markTable[i+1].nodeID;
				markTable[i].numberMarked = markTable[i+1].numberMarked;
				markTable[i+1].nodeID = tempID;
				markTable[i+1].numberMarked = tempNumberMarked;
				sorted = false;
			}
		}
	}
}

/*------------------------------------------------
Randomly generates a number between 0 and 1
-------------------------------------------------*/
double NetworkTop::randomNumberGen()
{
	double randomProb;
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> rng(0, 1);
	randomProb = rng(gen);
	return randomProb;
}
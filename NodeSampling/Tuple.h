#include <iostream>

using namespace std;

/*------------------------------------------------
Tuple class is used in the marked packet table to
store node id and number of marked packets
--------------------------------------------------*/
class Tuple
{
	public:
		Tuple();
		~Tuple();
		int nodeID;
		int numberMarked;
};

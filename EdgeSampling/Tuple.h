#include <iostream>
#include <vector>

using namespace std;

/*------------------------------------------------
Tuple class is used by a node to store the start,
end, and distance of another node
--------------------------------------------------*/
class Tuple
{
	public:
		Tuple();
		~Tuple();
		int start;
		int end;
		int distance;
};

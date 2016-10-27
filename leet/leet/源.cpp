//#include "Solution_number.h"
//#include "Solution_vector.h"

//#include "Solution_matrix.h"
//#include "Solution_string.h"
//#include "Solution_point.h"

//#include "TrieNode.h"
//#include "Solution_string_ladder.h"
#include "Solution_tree.h"
//#include "common.h"


int main()
{
	Solution_tree so;
	TreeNode node1 = TreeNode(1);
	TreeNode *root = &node1;
	cout << so.countNodes(root) << endl;

	getchar();
	return 0;
}
/*

*/

#include <ext/pd_ds/assoc_container.hpp>
#include <ext/pd_ds/tree_policy.hpp>

using namespace __gnu_pbds;

//declaration of tree container
template<
	//key type
	typename Key,

	//mapped policy
	typename Mapped,

	//key comparison functor
	typename Cmp_fn = std::less<Key>,

	//specifies which underlying data structure to use
	typename Tag = rb_tree_tag,

	template<
		typename Const_Node_Iterator,
		typename Node_Iterator,
		typename Cmp_Fn_,
		typename Allocator_,>
	//policy for updating node invariants
	class Node_Update = null_node_update,

	//An allocator type
	typename Allocator = std::allocator<char>
>

class tree;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> new_data_set;

Tree Structures
rb_tree_tag     (red-black tree)
splay_tree_tag  (splay tree)
ov_tree_tag     (ordered - vector tree)



//this is the final declaration that we will use

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update,order_set> ;

// find_by_order(k) -> return the iterator to the kth largest element (start function) (logn) time
// order_of_key(k) -> return the number of element in the set which are strictly less than our k.
(logn time)










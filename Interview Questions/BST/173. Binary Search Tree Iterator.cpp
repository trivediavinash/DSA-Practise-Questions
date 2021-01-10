/*
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.
 

Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?


*/

1. 
// S.C.= O(N), FOR STORING INTO AARAY.
// S.C.= O(H), FOR RECURSION CALL STACK,H=HEIGHT OF TREE.
//(H)+(N)=O(N)

// T.C=  O(N) is the time taken by the constructor for the iterator. The problem statement only asks us to analyze the complexity of the two functions, however, when implementing a class, it's important to also note the time it takes to initialize a new object of the class and in this case it would be linear in terms of the number of nodes in the BST
class BSTIterator {

public:
    vector<int>v;
    int i=0;
    BSTIterator(TreeNode* root) {
      
        inorder(root);
        
    }
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    //Note that the new array is used for both the function calls and hence the space complexity for both the calls is         O(N).
    
    int next() {       //  T.C= O(1).  
        i++;
        return v[i-1];
       
        
    }
    
    bool hasNext() {            // T.C= O(1)
        return i<v.size();
        
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

2.
/*
Complexity analysis

Time complexity : The time complexity for this approach is very interesting to analyze. Let's look at the complexities for both the functions in the class:

hasNext is the easier of the lot since all we do in this is to return true if there are any elements left in the stack. Otherwise, we return false. So clearly, this is an O(1)O(1) operation every time. Let's look at the more complicated function now to see if we satisfy all the requirements in the problem statement

next involves two major operations. One is where we pop an element from the stack which becomes the next smallest element to return. This is a O(1)O(1) operation. However, we then make a call to our helper function _inorder_left which iterates over a bunch of nodes. This is clearly a linear time operation i.e. O(N)O(N) in the worst case. This is true.

However, the important thing to note here is that we only make such a call for nodes which have a right child. Otherwise, we simply return. Also, even if we end up calling the helper function, it won't always process N nodes. They will be much lesser. Only if we have a skewed tree would there be N nodes for the root. But that is the only node for which we would call the helper function.

Thus, the amortized (average) time complexity for this function would still be O(1)O(1) which is what the question asks for. We don't need to have a solution which gives constant time operations for every call. We need that complexity on average and that is what we get.

Space complexity: The space complexity is O(N)O(N) (NN is the number of nodes in the tree), which is occupied by our custom stack for simulating the inorder traversal. Again, we satisfy the space requirements as well as specified in the problem statement.

*/
class BSTIterator {

public:
    stack<TreeNode* >s;
    int i=0;
    BSTIterator(TreeNode* root) {
      
       leftmost_inorder(root);
        
    }
    void leftmost_inorder(TreeNode* root){
        TreeNode* p = root;
        while (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        
    }
   
    
    int next() {       //  T.C= O(1).  
       TreeNode* toper=s.top();
        s.pop();
        if(toper->right){
            leftmost_inorder(toper->right);
            
        }
       return toper->val;
        
    }
    
    bool hasNext() {            // T.C= O(1)
        return i<s.size();
        
        
    }
};






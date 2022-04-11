#include <bits/stdc++.h>
using namespace std;
  
 // BST(Binary Search Tree) =  (sorted Binary Tree), (inspired by Binary Search), (O(h)), (Base Case -> pp==NULL) 
 
template <typename T> 
class BinaryTreeNode                                      // class for creating a node of BST                                                                                 
{      public:
	T data;                                            
	BinaryTreeNode *left;                     
	BinaryTreeNode *right;                         
 
	BinaryTreeNode(T d)                                  
	{  data = d;
	   left = NULL;
	   right = NULL;   } 
	   
   ~BinaryTreeNode()                                      
    {  delete left;
       delete right;   }
};     
                                                                          
class BST                                                 // class for creating a BST                      
{
	BinaryTreeNode<int> *root;
	                       
	   public:
	BST()
	{  root = NULL;	 }
	
   ~BST()
    {  delete root;  }
	
	
	   private:  
    BinaryTreeNode<int>* insert(int x, BinaryTreeNode<int> *pp)
    {
   	   if(pp==NULL)
	   {  BinaryTreeNode<int> *np = new BinaryTreeNode<int>(x);
	      return np;  }   
	   
	   if(x < pp->data)
	   pp->left = insert(x, pp->left);
	   else if(x >= pp->data)
	   pp->right = insert(x, pp->right); 
	   
	   return pp;
	}	
	
	    public:                // pp is not a input in these function, so create private helper functions, to apply recursion 
	void insert(int x)
    {  root = insert(x, root);  } 
    
    BinaryTreeNode<int>* findRoot()
    {  return root;	 }
};

         
void makeSortedArrayfromBST(BinaryTreeNode<int> *pp, vector<int> &vtr)             // similar to printing Inorder  
{
    if(pp==NULL)
	return;
	                                                                                               
	makeSortedArrayfromBST(pp->left, vtr);                                                     
	vtr.push_back(pp->data);   	 
	makeSortedArrayfromBST(pp->right, vtr);	                                                               
	
	return;
}     
   
  // use concept of calculating (pairs having sum k) from a (given sorted array)
     
void  printNodePairsHavingSumK(BinaryTreeNode<int> *rp, int k)
{
	vector<int> vtr;
	makeSortedArrayfromBST(rp, vtr);
	 
	for(int i=0,j=vtr.size()-1;  i<j;  )
	{  if(vtr[i]+vtr[j] > k)
	   j--; 
	   else if(vtr[i]+vtr[j] < k)
	   i++;
	   else
	   {  cout<<vtr[i]<<" "<<vtr[j]<<endl;
	      i++,j--;  }    }
	 	
	return;
}
                  
int main()
{
	BST b;                                                // constructing BST using (BST class) & (BinaryTreeNode class)
	 
	int n;
	cout<<"Enter size of BST: ";
	cin>>n; 
	
	cout<<"Enter elements of BST: ";
    for(int i=0; i<n; i++)
    {  int x;
	   cin>>x;
	   b.insert(x);  }                                    // storing BST 
	
	int k;
	cout<<"Enter K: ";
	cin>>k; 
 
	vector<int> vtr;
	BinaryTreeNode<int> *rp = b.findRoot();
	cout<<"\n\n\nAll node pairs having sum K="<<k<<" are\n";
	printNodePairsHavingSumK(rp, k);
	cout<<"\n\n\n";  
	  
    delete &b;                                            // deleting BST                   
}
                                                                         
                                                                                                  
 /*
  
  5 4 2 5 1 3 6     
      
            4           Level 0 
           / \ 
          2   5         Level 1
         /\    
        1  3            Level 2  
	                                             
 */




 // use (recursion) most of the times to solve question related to (tree), considering (current node) as (parent node) 
 
 // BST = (left child data) < (parent data) <= (right child data)
 
 // Balanced BST = (ideal BST), (O(h) = O(logn)), ( |left child BST height - right child BST height| <= 1 )
  
 // (r=root), (rp=rootPointer), (c=child), (cp=childPointer), (p=parent), (pp=parentPointer), (ppList=parentPointerList), (n=noOfChildren)   


                                                        

                                                                                    
















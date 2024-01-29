#include<iostream>
#include<vector>
#include<Queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node* val;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
        val = 0;
        
    }

};
class Info {
    public:
    int mini; 
    int maxi;
    int size;
    bool isBST;

    Info(){

    }

    Info(int a, int b, int c ,bool d) {
        mini = a;
        maxi = b;
        size = c;
        isBST =d;

    }
};


 Node* buildTree() {
    cout<<"enter the value of data "<<endl;
    int data;
    cin>>data;
    if(data == -1)
        return NULL;

        Node* newNode = new Node(data);

        cout<<" Enter the data for left child "<<data<<endl;
        newNode->left = buildTree();

        cout<<" Enter the data for  right child "<<data<<endl;
        newNode->right = buildTree();
        return newNode;
    
 }

 void levelOrderTraversal(Node* &root) {
    queue<Node*>q;
    q.push(root);
    //change no 1
    q.push(NULL);

    while(!q.empty()) {

        // to nikal
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout<<endl;
            //catch here
            if(!q.empty())// still element are present
            q.push(NULL);
        }
    
   
   else {
        
        cout<<front->data<<" ";

        //bacche aa jao
        if(front->left != NULL)
        q.push(front->left);
        if(front->right != NULL)
        q.push(front->right);
    }
 }


 }

 // largest BST in a binary tree

Info solve(Node* root , int &ans) {
    // base case
    if(root == NULL) {
     return {INT_MAX,INT_MIN,0,true};

    }
     
    // solve for left
    Info leftAns = solve(root->left,ans);

    //solve for right
    Info rightAns = solve(root->right,ans);
    
    //create ans for curr node/subtree
    Info curr;

    curr.size = leftAns.size + rightAns.size + 1;
    curr.mini = min(leftAns.mini,root->data);
    curr.maxi = max(rightAns.maxi,root->data);


    if(leftAns.isBST && rightAns.isBST && (root->data > leftAns.maxi && root->data < rightAns.mini)) {
        curr.isBST = true;
    }
    
    else{
        curr.isBST = false;
    }

    // if curr subtree isBTS then update ans
    if(curr.isBST)
    ans = max(ans,curr.size);
    
    // return all values of current subtree to upper level
    return curr;
}

int largestBST(Node* root) {
    int ans = 0;
    solve(root,ans);
    return ans;

}

 int main()
 {
    Node* root = NULL;
    root =  buildTree();
    levelOrderTraversal(root);
    cout<<"size of Largest BST is  "<<largestBST(root)<<endl;
 }
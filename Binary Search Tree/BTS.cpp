#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    

    Node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
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

Node* buildBTS(Node* root, int data) {
    if(root == NULL){
        Node* temp = new Node(data);
        return temp;
    }

    if(data > root->data) {
        root->right = buildBTS(root->right,data);
    }
    else{
        root->left = buildBTS(root->left, data);
    }
    return root;

}

void createBTS(Node* &root){

    cout<<"enter the value for Root Node"<<endl;
    int data;
    cin >> data;

    while(data != -1){
        root = buildBTS(root,data);
        cout<<"Enter The the data for node"<<endl;
        cin >> data;

    }

}

void preOrder(Node* &root)
 {
    //base case
    if(root == NULL)
    return;

    //N
    cout<<root->data<<" ";
    //L
    preOrder(root->left);
    //R
    preOrder(root->right);

 }

 void inOrder(Node* &root)
 {
    //base case
    if(root == NULL)
    return;

    //L
    inOrder(root->left);
    //N
    cout<<root->data<<" ";
    //R
    inOrder(root->right);

 }

 void postOrder(Node* &root)
 {
    //base case
    if(root == NULL)
    return;

    //L
    postOrder(root->left);
    //R
    postOrder(root->right);
    //N
    cout<<root->data<<" ";

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

// Search Node in BST
bool SearchNode (Node* root, int target) {
    if(root == NULL)
    return false;

    if(root->data == target)
    return true;

    if(target < root->data){
        bool leftAns =  SearchNode(root->left,target);
        if(leftAns == true)
        return true;
    }
    else{
        bool rightAns = SearchNode(root->right, target);
        if(rightAns == true)
        return true;
    }
    return false;
}

// delation Node
Node* maxVal(Node* root) {
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteNode(Node* root , int target ) {
     if(root == NULL)
     return  NULL;

     if(root->data == target) {
        // 0 child
        if(root->left == NULL && root->right == NULL)  {
        delete root;
        return NULL;
        }


        // 1 child
        if(root->left != NULL && root->right  == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;

        }

        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;

        }

        // two child
        if(root->left != NULL && root->right != NULL) {
            // get indor pred
            int pred = maxVal(root->left)->data;

            //copy
            root->data = pred;

            //solve bachi hui problem
            root->left = deleteNode(root->left,pred);
            return root;

        }
     }
     else if( target > root ->data) {
        root->right = deleteNode(root->right,target);
     }
     else{
        root->left = deleteNode(root->left, target);
     }
     return root;
}

// Tree is bst or Not
bool checkBST( Node* root,int min,  int max) {
    // base case 
    if(root == NULL)
    return true;

    if(root->data > min && root->data < max) {
        bool leftAns = checkBST(root->left , min ,root->data);
        bool rightAns = checkBST(root->right, root->data, max);
        return leftAns && rightAns;
    }
     return false;
}

Node* LCA( Node* root , Node* p, Node* q) {
    // base case
    if(root == NULL)
    return NULL;

    if(root->data < p->data && root->data < q->data) {
        // node are present right subtree
        return LCA(root->right,p,q);
    }
    if(root->data > p->data && root->data > q->data) {
        // node are present left sub tree
        return LCA(root->left,p,q);
    }

    else{
        return root;
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


    if(leftAns.isBST && rightAns.isBST && (root->data > curr.mini && root->data < curr.maxi)) {
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
    createBTS(root);
    /*
    cout<<"  printing level order traversal is "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"printing  inorder traversal is "<<" ";
    inOrder(root);
    cout<<endl;

    cout<<"printing  preOrder traversal is "<<" ";
    preOrder(root);
    cout<<endl;

    cout<<"posOrder traversal is "<< " ";
    postOrder(root);
    cout<<endl;

    cout<<" Search Node is present or not in BST "<<SearchNode(root,125)<<endl;
    */


   /*
    
    levelOrderTraversal(root);
    int target;
    cout<<"enter the target "<<endl;
    cin>> target;
    cout<< " DeleteNode  BTS is "<< endl;
    Node* root1 = deleteNode(root,target);
    levelOrderTraversal(root);
    */


   levelOrderTraversal(root);


    
}

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


 int height(Node* root) {
    if(root == NULL)
    return 0;

    if(root->left == NULL && root->right == NULL)
    return 0;

    int leftAns = height(root->left);
    int rightAns = height(root->right);
    return 1+max(leftAns,rightAns);
 }
 

int heigth1(Node* root) {
    if(root == NULL)
    return 0;

    return max( heigth1(root->left), heigth1(root->right)) +1 ;
}

int diameter(Node* root) {
    if(root == NULL)
    return 0;

    int option1 = diameter(root->left);
    int option2 = diameter(root->right);
    int option3 = 1 + heigth1(root->left) +heigth1(root->right); 
    return max(option1,max(option2,option3));
    
    
    }

    int diameterOfBinaryTree(Node* root) {
        if(root == NULL)
        return 0;

        return diameter(root) -1;
    }


int height2(Node* root) {
    if(root == NULL)
    return 0;

    return max(height2(root->left),height2(root->right)) +1;
}
bool isBlanced(Node* root) {
    //base case
    if(root == NULL)
    return true;

    bool leftAns = isBlanced(root->left);
    bool rightAns = isBlanced(root->right);

    bool dif = abs(height2(root->left) - height2(root->right))<= 1;

    if(leftAns && rightAns && dif)
    return true;
    else 
    return false;
}

// optimaze solution of Tree is Blanced or not

pair<int,bool>solve(Node* root) {
    if(root == NULL)
    return make_pair(0,true);

    pair<int,bool>leftAns = solve(root->left);
    pair<int,bool>rightAns = solve(root->right);

    int leftHeight = leftAns.first;
    int rightHeigth = rightAns.first;

    bool diff = abs(leftHeight - rightHeigth) <= 1;

    bool leftBlanced = leftAns.second;
    bool rightBlanced = rightAns.second;
    
    if(leftBlanced && rightBlanced && diff) {
        return make_pair(max(leftHeight,rightHeigth)+1,true);
    }
    else{
        return make_pair(max(leftHeight,rightHeigth)+1,false);
    }
}
bool isBlanced2(Node* root) {
    pair<int,bool> ans = solve(root);
    return ans.second;
}

bool solve1(Node* a, Node* b) {

    if( a == NULL && b == NULL)
    return true;

    if(a != NULL && b == NULL)
    return false;

    if(a == NULL && b != NULL)
    return false;

    if(a->val != b->val)
    return false;
    return solve1(a->left, b->right) &&solve1(a->right,b->left);
}

bool isSymmertic(Node* root) {
    return true;
    return solve1(root->left,root->right);
}


bool hasPathSum(Node* root, int targetSum) {
    if(root == NULL)
    return false;
    

    if( root->data  == targetSum && root->left == NULL && root->right == NULL) 
    return true;

    bool leftAns = hasPathSum(root->left, targetSum - root->data);
    bool  rightAns = hasPathSum(root->right, targetSum - root->data);
    return leftAns || rightAns;
}

Node* lowestCommenAncestor(Node* root, Node* p, Node* q) {
    if(root == NULL)
    return NULL;

    if(root == p || root == q)
    return root;
    else
    {
        Node* leftAns = lowestCommenAncestor(root->left,p,q);
        Node* rightAns = lowestCommenAncestor(root->right,p,q);

        if(leftAns != NULL &&  rightAns != NULL)
        return root;
        else if(leftAns == NULL)
        return rightAns;
        else{
            return leftAns;
        }
    }
}

pair<int,bool>Solve3(Node* root) {
    //Base case
    if(root == NULL)
    return make_pair(0,true);

    // base case
    if(root->left == NULL && root->right ==NULL) 
    return make_pair(root->data,true);

    pair<int,bool>leftAns =  Solve3(root->left);
    pair<int,bool>rightAns = Solve3(root->right);
    
    if((leftAns.second && rightAns.second) && (root->data == leftAns.first + rightAns.first))
    return make_pair(2 * root->data,true);
    else{
        return make_pair(root->data + leftAns.first + rightAns.first, false);
    }
}
bool sumTree(Node* root){
     pair<int,bool> ans = Solve3(root);
     return ans.second;
}

int  ans = 0;
int count = 0;
void Solve4(Node* root,int target, int sum) {
    
    if(root== NULL)
    return;

    if(target == sum)
    count++;

   if(root->left != NULL)
    Solve4(root->left, target, sum + root->left->data);

    if(root->right != NULL)
    Solve4(root->right, target, sum+ root->right->data);

}
int pathSum(Node* root, int targetSum) {
    if(root == NULL)
    return 0;
    
    //jis Node par ho use starting mankar solve karne ka try karna
    Solve4(root,targetSum,root->data);

    pathSum(root->left,targetSum);
    pathSum(root->right,targetSum);
    return count;
}




//  concrut tree from InOrder and pre Order
int position(vector<int> inorder, int key, int start, int end){
for(int i = start; i <= end; i++){
if(inorder[i] == key)
return i;
}
return -1;
}

Node* buildFromPreorderInorder(vector<int>& preorder, vector<int>& inorder, int &preIndex, int inStart, int inEnd){
    //base case
    if(preIndex >= preorder.size() || inStart > inEnd){
        return NULL;
    }
    
    int element = preorder[preIndex++];
    //creating node...
    Node* root = new Node(element);
    //searching element in inorder array....
    int pos = position(inorder, element, inStart, inEnd);
    
    root->left = buildFromPreorderInorder(preorder, inorder, preIndex, inStart, pos-1);
    root->right = buildFromPreorderInorder(preorder, inorder, preIndex, pos+1, inEnd);
    return root;
      
}

//  concrut tree from InOrder and post Order


Node* buildFromPostorderInorder(vector<int>& postorder, vector<int>& inorder, int &postIndex, int inStart, int inEnd){
    //base case
    if(postIndex < 0 || inStart >inEnd){
        return NULL;
    }
    
    int element = postorder[postIndex--];
    //creating node...
    Node* root = new Node(element);
    //searching element in inorder array....
    int pos = position(inorder, element, inStart, inEnd);

   root->right = buildFromPostorderInorder(postorder, inorder, postIndex, pos+1, inEnd); 
    root->left = buildFromPostorderInorder(postorder, inorder, postIndex, inStart, pos-1);
    return root;
      
}


     

int main()
{


    /*

    Node* root =  NULL;
    root = buildTree();
    cout<<endl;

   cout<<"Printing preOrder "<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"Printing inOrder "<<endl;
    inOrder(root);
    cout<<endl;

    cout<<"printing  postOrder "<<endl;
    postOrder(root);
    cout<<endl;

    cout<<"printing  levelOrderTraversal "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

cout<<"Hieght of tree is "<<height(root)<<endl;


cout<<"Diameter of binary tree is : "<<diameterOfBinaryTree(root)<<endl;

cout<<"Blanced tree or not  : "<<isBlanced(root)<<endl;
cout<<"Blanced tree or not  Optmize solve : "<<isBlanced2(root)<<endl;

cout<<"is symmetric tree or not " <<isSymmertic(root)<<endl;
cout<<"hasPathSum in tree "<<hasPathSum(root,15)<<endl;

//cout<<"Lowest comment encestor in a Binary tree is "<<lowestCommenAncestor(root)<<endl;


cout<<"Sum tree or not "<<sumTree(root)<<endl;
cout<<"path Sumtree 3 is :  "<<pathSum(root,5)<<endl;


*/

vector<int>inOrder = {3,1,4,0,5,2};
/*
inOrder.push_back(3);
inOrder.push_back(1);
inOrder.push_back(4);
inOrder.push_back(0);
inOrder.push_back(5);
inOrder.push_back(2);
*/

vector<int>preOrder ={0,1,3,4,2,5};
/*preOrder.push_back(0);
preOrder.push_back(1);
preOrder.push_back(3);
preOrder.push_back(4);
preOrder.push_back(2);
preOrder.push_back(5);

*/


cout<<" construct tree form inorder and pre order "<<endl;
int index = 0;
Node* root = buildFromPreorderInorder(preOrder, inOrder, index, 0, 5);
 levelOrderTraversal(root);

//0
// 1 2
// 3 4 5


vector<int>inOrder1 = {4,8,2,5,1,6,3,7};
vector<int>postOrder = {8,4,5,2,6,7,3,1};
int index1 =  postOrder.size()-1;
cout<<"construct tree from inorder and post order "<<endl;
Node* root1 = buildFromPostorderInorder(postOrder,inOrder1,index1,0,7);
levelOrderTraversal(root1);
// 1
// 2 3
// 4 5 6 7
//8
}

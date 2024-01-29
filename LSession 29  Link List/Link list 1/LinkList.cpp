#include<iostream>
using namespace std;

class Node{
    public:
    // data member
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
       this->data= data;
       this->next = NULL;
    }
};

void insertAtHead(Node* &Head , int d)
    {    
        // step1 : create a node
        Node* newNode = new Node(d);
        //step 2:set next ptr to head more
        newNode->next = Head;
        //step 3: head update
        Head = newNode;
    }
void insertAtTail(Node* &Tail, int d)
    {    
        // step1 : create a node
        Node* newNode = new Node(d);
        //step 2:set next ptr to head more
        Tail->next = newNode;
        //step 3: head update
        Tail = newNode;
    }

    void inserAtPosition(Node* &Head, int pos,int d)
    {
        //ToDo:  tail updation, while inserting at the end
        //ToDo: validate that position should be atmax 1 more than current length of linl list66
        if(pos == 1)
        {
           insertAtHead(Head,d);
        }
        else{

            // step 1: creation of new Node
            Node* newNode =  new Node(d);
            
            //step 2: traverse k-1 node
            Node* prev = Head;
            int t = pos-2;
            while(t--)
            {
                prev = prev->next;
            }

            // step3 : connection of update
            newNode->next = prev->next;
            prev->next = newNode;

        }
    }


void traverse(Node* &Head){
        Node*temp = Head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;


        }
        cout <<endl;


    }

void DeleteNodebyPosition(Node* &Head, int target, int pos)
{

    // empty list

    if(Head == NULL)
    {
        return;
    }
    Node* temp = Head;
    Node*prev = NULL;

    if(target == temp->data && pos == 1)
    {
        Head = Head->next;
        temp->next =NULL;
        delete temp;

    }
    else{
        while(temp != NULL && temp->data != target)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout<< "Element is not find in lnklist"<<endl;
            return;
        }
         // here we asumming that we have found element
        prev->next =temp->next;
        temp->next = NULL;
        delete temp;
    }


}

int GetLength(Node*Head)
{
    Node*temp = Head;
    int len =0;
    while(temp != NULL)
    {
        len++;
        temp= temp->next;
    }
    return len;
}


Node* reverse(Node* &Head)
{

    if (Head == NULL)
    {
        cout<<" List is empty"<<endl;
    }
    Node* curr = Head;
    Node* prev = NULL;

    while( curr != NULL)
    {
        // to keep track to list headof curr Node
        Node* next = curr->next;
         // change curr link and connected in prev link
        curr->next = prev;
        //age bado
        prev = curr;
        curr =  next;

    }
    return prev;


}

Node* reverseRec(Node* &curr, Node* prev)
{
if(curr == NULL)
{
    return prev;
}

// conection change kana hai- 1 case solve
Node* next = curr->next;
curr->next = prev;

// baki recurrsion sambhal lege
 return reverseRec(next,curr);

}
    

    
    // tortoice approch
    Node * getmiddle(Node* Head)
    {
        Node* slow =Head;
        Node* fast = Head;

        while(fast != NULL &&  fast->next != NULL)
        {
            // 2 step fast chalange
            fast = fast->next->next;
            // 1 sep fast challange
            slow = slow->next;

        }
        return slow;
    }

     
    


   
bool  isCerculer(Node* &Head) 
   {  
        Node* temp = Head;
       
       //to traverse ll in normal case
        while(temp != NULL)
        {  

            //in case list is curcular
            if(temp->next == Head)
            {
                return true;
            }
            //move on node ahead
            temp = temp->next;
        } 

        // it means we traverse the intire list, retun false
        return false;

    }
    
    

Node* Kreverse(Node* &Head, int k)
{
    // empty list 
    if(Head ==NULL)
    return NULL;

    Node* curr = Head;
    Node* next = NULL;
    Node* prev  =NULL;
    int count  = 0;
     
     //step:1  reverse first k nodes
    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;


        prev = curr;
        curr = next;
        count ++;

    }

     // next pointer will be pointing at the head of remaining ll
    
    if(next != NULL)
    // step2 : recursain will get ans for remaining list
     //step 3 : connection list in step 1 and step 3;
      Head->next  = Kreverse(next,k);

      
      
    //step 4: return entire Head of entire list
      return prev;

}

int KNodeofEndll(Node* &Head, int k){
    // base case
    if(Head == NULL)
    return 0;

    int cnt = KNodeofEndll(Head->next,k)+1;

    if(cnt == k)
     cout<<" kth end Node is "<< Head->data <<endl;
     return cnt;
     
}

//bool 
Node* DetectLoop(Node* &Head)
{
    if(Head == NULL)
    return NULL;
   // return false;

    Node* slow = Head;
    Node* fast = Head;

    while(fast  != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
           // return true;
           return slow;
        }

    }
   // return false;
   return NULL;
}



bool DetectAndDelete(Node* &Head)
{

    if(Head == NULL)
    {
        return false;
    }
    // step1 :detect if  loop preasent or not
    Node* fast = DetectLoop(Head);


    // step2 : Detect Beginning Node are present or Not
    Node* slow = Head;

    if(fast == NULL)
    {
        cout<< " loop is Not Preasent "<<endl;
    }

    while(fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node* BeginningNode = fast;
    // step 3 remove Node connection
    Node* temp = BeginningNode;

    while(temp->next != BeginningNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return true;

    
}

    
    

int main()
{
    // object creation 
   Node* first = new Node(3);
   Node* Head  = first;
   Node* Tail = first;

   //cout<< first->data<<endl;
   //cout<<first->next<<endl;

  // insertAtHead(Head,5);
  // insertAtHead(Head,7);
  // insertAtHead(Head,9);
   //insertAtHead(Head,11);

 //  traverse(Head);



insertAtTail(Tail,5);
insertAtTail(Tail,7);
insertAtTail(Tail,9);
Node* temp = Tail;
insertAtTail(Tail,11);
insertAtTail(Tail,14);
insertAtTail(Tail,18);
Tail->next  = temp;


    //cout << " Loop present or not "<<DetectLoop(Head);
    cout<<DetectAndDelete(Head)<<endl;
    traverse(Head);

 
 //traverse(Head);
 //Head = Kreverse(Head,4);
 //traverse(Head);


 //traverse(Head);
 //KNodeofEndll(Head,2);

 



 

//inserAtPosition(Head,6,12);
 //traverse(Head);
 

 //Node*Head2 =NULL;

 //DeleteNodebyPosition(Head,12,1);
 //traverse(Head);

 // Node* newHead = reverse(Head);
 //traverse(newHead);
 //Node* newHead1 = reverseRec(Head,NULL);
 //traverse(newHead1);

 // Node* middle = getmiddle(Head);
  // cout<<"MIddle is "<<middle->data<<endl;
 




 //cout<< "Length is "<<GetLength(Head)<<endl;

// to make circular
//Head->next = Head;
 //cout<<"iscurcular or not "<<isCerculer(Head)<<endl;
  }

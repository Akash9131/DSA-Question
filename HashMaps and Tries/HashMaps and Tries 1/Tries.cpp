#include<iostream>
#include<vector>
using namespace std;
class TrieNode {
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char d) {
        this->data = d;
        isTerminal = false;

        for(int i = 0; i<26; i++) {
            children[i] = NULL;
        }
    }

};

class Trie {
    public:
    TrieNode * root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode* root, string word) {
        // Base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        // crurrent char fetch
        char ch = word[0];
        //mapping character to an index intger
        int index = ch - 'a';

        TrieNode* child;
        // two cases is exist
        //the alfabet is already present
        // alfabet is absent

        if(root->children[index]  != NULL) {
            // present case ->child par phuch jao
            child = root->children[index];
        }
        else {
            // absent case
            child = new TrieNode(ch);
            root->children[index] = child;
        }
        //recursion will take care of insertion of remaining string
        insertHelper(child, word.substr(1));

    }
    

    void insert(string word) {
        insertHelper(root,word);
        cout<<" code -> insert is sussesfull "<<endl;
    }

    bool searchHelper(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            return root->isTerminal;
        }


        // fect current charecter
        char ch = word[0];

        // mapping char to an index integer
        int index = ch - 'a';

        TrieNode* child;
        // two cases is exist
        //the alfabet is already present
        // alfabet is absent

        if(root->children[index]  != NULL) {
            // present case ->child par phuch jao
            child = root->children[index];
        }
        else {
            
            return false;
        }
        //recursion 
      return  searchHelper(child, word.substr(1));

    
    }

    bool Search(string word) {
        return searchHelper(root,word);
    }

    int getChildCount(TrieNode* temp) {
        int count = 0;

        for(int i =0; i< 26; i++) {
            if(temp->children[i] != NULL)
            count++;
        }
        return count;
    }


    void largestCommenPrefix(string input, string & res) {
        TrieNode* temp = root;
          // traverse over  input string
            for(int i =0; i<input.length();i++) {
                //fetch current character
                char ch = input[i];


                if(getChildCount(temp) == 1 && temp->isTerminal == false) {
                    //include charecter in ans string
                    res.push_back(ch);

                    //root ko age badao
                    int index = ch -'a';
                    temp = temp->children[index];
                }
                else {
                    break;
                }
                if(temp->isTerminal) {
                    break;
                }

            }
    }

    void getNames(TrieNode* curr, string prefix, vector<string>& temp) {
        // base case
        if(curr->isTerminal) {
            temp.push_back(prefix);
        }
        for(char ch = 'a'; ch<='z'; ch++) {
            TrieNode* next = curr->children[ch- 'a'];

            // found case
            if(next != NULL) {
                prefix.push_back(ch);
                //recursion sambal lega
                getNames(next,prefix,temp);
                //back track
                prefix.pop_back();
            }
        }

    }


    vector<vector<string> >getAnswer(string word) {
        TrieNode* prev = root;
        vector<vector<string> > Answer;
        string prefix = "";

        for(int i= 0; i<word.length();i++) {
          char lastCh = word[i];
          prefix.push_back(lastCh);

          TrieNode* curr = prev->children[lastCh - 'a'];

          // not found case
          if(curr == NULL) {
            break;
          }
          //found
          else {
            vector<string> tempAns;
            getNames(curr,prefix,tempAns);


            Answer.push_back(tempAns);
            prev = curr;
          }

        }
        return Answer;

    }
};

vector<vector<string>>phoneDir(vector<string> &contactList, string query) {
    // step1 : trie creation
    Trie* t = new Trie();

    // step 2: insert all contact in trie
    /*for(int i = 0; i<contactList.size(); i++) {
        string str = contactList[i];
        t->insert(str);

    }
    or
    */
    for(auto str : contactList) {
        t -> insert(str);
    }

    // step 3 : getAns
    return t->getAnswer(query);

}
int main()
{
/*
    Trie* trie = new Trie();

   // trie->insert("co");
    trie->insert("code");
    trie->insert("coding");
    trie->insert("codemonk");
    trie->insert("coder");
    trie->insert("codee");

   
   /*cout<<trie->Search("code")<<endl;
   cout<<trie->Search("coding")<<endl;
   cout<<trie->Search("codemonk")<<endl;
   cout<<trie->Search("coder")<<endl;
   cout<<trie->Search("codee")<<endl;
   cout<<trie->Search("codi")<<endl;
   cout<<trie->Search("cody")<<endl;
   */

/*
   string res = "";
   trie->largestCommenPrefix("code", res);
   cout<<" result is  : "<< res << endl;
   */

  vector<string>contacts;


    contacts.push_back("dipak");
    contacts.push_back("dipu");
    contacts.push_back("dipa");
    contacts.push_back("dipsha");
    contacts.push_back("didi");
    contacts.push_back("dishu");
    contacts.push_back("dipuka");

    string query = "dipi";

    vector<vector<string>> answer = phoneDir(contacts,query);

    cout<<endl<<"printing the answer "<<endl;

    for(int i= 0; i<answer.size(); i++) {
        for(int j = 0; j<answer[i].size(); j++) {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }



}
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution{
    public:
    Node* addOne(Node *head) {
        string s = "";
        Node* inc = (struct Node*)malloc(sizeof(Node*));
        inc->next = head;
        Node* currNode = (struct Node*)malloc(sizeof(Node*));
        currNode = head;
        while (currNode != nullptr){
            if (currNode->data != 9) inc = currNode;
            currNode = currNode->next;
        }
        if (inc->next == head){
            inc->data = 1;
            head = inc;
        } else{
            inc->data++;
        }
        inc = inc->next;
        while (inc != nullptr){
            inc->data = 0;
            inc = inc->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
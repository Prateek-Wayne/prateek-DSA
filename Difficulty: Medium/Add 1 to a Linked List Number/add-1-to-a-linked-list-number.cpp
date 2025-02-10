//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

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

class Solution {
  public:
 
Node *reverse(Node *head)
{

    Node *temp = head, *prev = NULL;
    while (temp)
    {
        Node *forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
    }
    return prev;
}
Node *addOne(Node *head)
{

    int carry = 1;
    head = reverse(head);
    Node *temp = head;
    while (temp)
    {
        temp->data = temp->data + carry;
        carry = 0;
        if (temp->data > 9)
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    temp = reverse(head);
    if (carry == 1)
    {
        Node *newData = new Node(carry);
        newData->next = temp;
        return newData;
    }
    return temp;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
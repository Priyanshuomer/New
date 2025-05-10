#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Node{
    public:
   char ch;
   int occur;
   Node* left;
   Node* right;

   Node(char cp, int val)
   {
    ch = cp;
    occur = val;
    left = NULL;
    right = NULL;
   }
};

void solve(Node* root, string& s, unordered_map<char,string>& mp)
{
    if(root == NULL)
     return ;

     if(root->ch != '#')
     mp[root->ch] = s;

    string temp = s;
    s += '0';
    solve(root->left,s,mp);
    
    temp += '1';
    solve(root->right,temp,mp);

    return ;
}
int main()
{
    int n;
    cout << "Enter total  number of characters used : ";
    cin >> n;

     priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;

    for(int i=0; i<n; i++)
    {
        int occur;
        char ch;

        cout << "Enter character : ";
        cin >> ch;

        cout << "Enter number of occurrences of " << ch << " : ";
        cin >> occur;

         Node* curr = new Node(ch,occur);
         pq.push({occur,curr});
    }
    
    for(int i=0; i<n; i++)
    {
        auto leftPart = pq.top();
        pq.pop();

        auto rightPart = pq.top();
        pq.pop();

        int val = leftPart.first + rightPart.first;

        Node* newNode = new Node('#',val);
        newNode->left = leftPart.second;
        newNode->right = rightPart.second;

        pq.push({val,newNode});
    }

     unordered_map<char,string> mp;

      Node* temp = pq.top().second;
      pq.pop();

      string s = "";
      solve(temp,s,mp);

      cout << "Huffman Encoding is : \n";

      for(auto op : mp)
      {
         cout << op.first << " -> ";
         cout << op.second;
         cout << endl;
      }
    return 0;
}

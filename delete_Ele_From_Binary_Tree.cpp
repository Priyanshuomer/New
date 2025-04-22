#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    Node* search(Node* root, int v)
    {
        Node* ans = root;
        while(ans)
        {
            if(ans->val == v)
             return ans;

            //  cout << "Jhjhhtg "<<endl;

             if(ans->val > v)
             ans = ans->left;
             else
             ans = ans->right;
        }

    

        return ans;
    }

    Node* FindSucc(Node* h)
    {
            Node* temp = h->right;
            while(temp->left)
             temp = temp->left;

            return temp;   
    }
};

int main()
{
    int v;
    cout << "Enter the value of root" << endl;
    cin >> v;

    if(!v)
    {
        cout << "Invalid Tree" <<endl;
        return 0;
    }

    Node* root = new Node(v);
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
      auto a = q.front();
       q.pop();

      cout << "Enter left children of "<<a->val<<endl;
      cin >> v;

      if(!v)
      a->left = NULL;
      else{
        Node* newNode = new Node(v);
        a->left = newNode;
        newNode->parent = a;
        q.push(newNode);
      }

      cout << "Enter right children of "<<a->val<<endl;
      cin >> v;

      if(!v)
      a->right = NULL;
      else{
        Node* newNode = new Node(v);
        a->right = newNode;
        newNode->parent = a;
        q.push(newNode);
      }
    }

     cout << "Tree :"<<endl;
     q.push(root);

     while(!q.empty())
     {
     int size = q.size();

     for(int i=0; i<size; i++)
     {
       Node* temp = q.front();
       q.pop();

        if(temp->parent)
        cout << temp->parent->val << "-> "<<temp->val<<endl;
        else
        cout << "-1 -> "<<temp->val<<endl;

        if(temp->left)
         q.push(temp->left);
       
          if(temp->right)
           q.push(temp->right);
     }


     }

     cout << endl;

          int rem;
    
    cout << "Enter the Value , you want to remove from tree :  ";
    cin >> rem;

   
   Node* find = root->search(root,rem);

   if(!find)
   {
    cout << "Value Not Present";
    return 0;
   }


  //  cout << "\n hello ::  ";

  //  cout << find->val << endl;

   if(find->left == NULL && find->right == NULL)
   {
      if(find->parent == NULL)
       cout << "0"<<endl;
       else
       {
        if(find->parent->left == find)
         find->parent->left = NULL;
         else
         find->parent->right = NULL;
       }

       q.push(root);

       while(!q.empty())
       {
       int size = q.size();
 
       for(int i=0; i<size; i++)
       {
         Node* temp = q.front();
         q.pop();
 
          if(temp->parent)
          cout << temp->parent->val << "-> "<<temp->val<<endl;
          else
          cout << "-1 -> "<<temp->val<<endl;
 
          if(temp->left)
           q.push(temp->left);
         
            if(temp->right)
             q.push(temp->right);
       }
 
 
       }
       return 0;
   }

   if(find == root)
   {
      if(find->right == NULL)
      {
          root = root->left;
          root->parent = NULL;
      }
      else{
        Node* succ = root->FindSucc(find);

        cout << succ->val << endl;
   
        find->val = succ->val;
        if(succ->parent->left == succ)
        succ->parent->left = succ->right;
        else
        succ->parent->right = succ->right;
      }
   }
    else { if(find->right == NULL)
     {
         if(find->parent->left == find)
        find->parent->left = find->left;
        else
        find->parent->right = find->left;

        find->left->parent = find->parent;  

         find->parent = NULL;
         find->left = NULL;
     }
      else{
        Node* succ = root->FindSucc(find);

        cout << succ->val << endl;
   
        find->val = succ->val;
        succ->parent->left = succ->right;
      }}

       queue<Node*> qp;

       q = qp;

      q.push(root);

      while(!q.empty())
      {
      int size = q.size();

      for(int i=0; i<size; i++)
      {
        Node* temp = q.front();
        q.pop();

         if(temp->parent)
         cout << temp->parent->val << "-> "<<temp->val<<endl;
         else
         cout << "-1 -> "<<temp->val<<endl;

         if(temp->left)
          q.push(temp->left);
        
           if(temp->right)
            q.push(temp->right);
      }


      }


    return 0;

}
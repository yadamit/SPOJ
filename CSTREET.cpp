#include<iostream>
#include<vector>
using namespace std;

typedef struct Node{
  int v;
  int len;
  // int parent;
  struct Node* next;
} Node;

Node* createNode(int v, int len){
  Node* tmp = (Node*)calloc(1,sizeof(Node));
  tmp->v = v;
  tmp->len = len;
  return tmp;
}

Node* insertNode(Node* root, int v, int len){
  Node* tmp = createNode(v,len);
  tmp->next = root;
  return tmp;
}

int deletemin(vector<int> Q){
  int min=0;
  int i=0;
  for(i=0;i<Q.size();i++){
    if(Q[i] < Q[min]){
      min = i;
    }
  }
  return min;
}

A


int main(){
  int t,price,V,st,v1,v2,len; //t: testcases, V: #buildings, st: #streets
  int i;
  int inf = 99999;
  cin>>t;
  int x;
  for(x=0;x<t;x++){
    cin>>price>>V>>st;

    vector<Node*>adj(V,NULL); //Adjacency list

    //Create Adjacency list
    for(i=0;i<st;i++){
      cin>>v1>>v2>>len;
      v1--; v2--; //Since adj_list starts from 0, but buildings are numbered from 1
      adj[v1] = insertNode(adj[v1],v2,len);
      adj[v2] = insertNode(adj[v2],v1,len);
    }

    // for(i=0;i<V;i++){
    //   Node*t = adj[i];
    //   cout<<i<<" :    ";
    //   while(t!=NULL){
    //     cout<<t->v<<" ";
    //     t=t->next;
    //   }
    //   cout<<endl;
    //
    // }

    int start = 0;
    // int prev = -1;
    int cost=0;
    int count=0;
    vector<int>Q(V,inf);
    vector<int>pi(V,-1); //stores parents
    Q[start] = 0;

    while(count != V){
      int s = deletemin(Q);
      // cout<<" s= "<<s<<endl;
      cost = cost + Q[s];
      // cout<<" cost = "<<cost<<endl;
      Q[s] = inf+1;
      count++;

      // cout<<count<<endl;
      Node* tmp = adj[s];
      while(tmp!=NULL){
        //Updating Q values
        int v = tmp->v;
        int len = tmp->len;
        if(len < Q[v]){
          Q[v] = len;
          pi[v] = s;
        }


        //deleteing the visited street
        Node* X = adj[v];
        if(X->v == s){
          Node* t = X->next;
          free(X);
          adj[v] = t;
        }
        else{
          while(X->next->v != s){
            X=X->next;
          }
          Node* t= X->next;
          X->next = X->next->next;
          free(t);
        }
        tmp = tmp->next;
      }
    }

    cout<<cost*price<<endl;
  }









}

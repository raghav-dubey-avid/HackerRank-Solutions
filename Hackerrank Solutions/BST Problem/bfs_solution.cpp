BFS

#include<iostream>
#include<list>
#include<queue>
#include<cstring>
#include<climits>
using namespace std;

list<int> *G=new list<int> [1001];
bool visited[1001];
long long dis[1001];


void BFS(list<int> *G,int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    int rem;
    list<int>:: iterator i;
    while(!q.empty())
    {
        rem=q.front();
       
       q.pop();
     
        for(i=G[rem].begin();i!=G[rem].end();i++)
        {
            if(!visited[*i] )
            {
                visited[*i]=true;
                q.push(*i);
                dis[*i]=dis[rem]+1;
            }
        }


    }
}



int main()
{

   int t,n,edges,u,v,s,i;
   cin>>t;
   while(t--)
   {
      for(i=1;i<=1000;i++)
        dis[i]=-1;

      memset(visited,false,1001);
      cin>>n>>edges;
     
      for(i=0;i<=1000;i++)
        G[i].clear();
      while(edges--)
      {
          cin>>u>>v;
          G[u].push_back(v);
          G[v].push_back(u);
      }
       cin>>s;
        dis[s]=0;
        BFS(G,s);

        for(i=1;i<=n;i++)
        {
            if(i!=s)
               {
                if(dis[i]!=-1)
                 cout<<(dis[i]*6)<<" ";
                else
                  cout<<-1<<" ";
               }
        }
        cout<<endl;

   }

}
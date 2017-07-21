#include "cstdio"
#include "cstring"
#include "string"
#include "iostream"
#include "queue"
using namespace std;
char map[85][85];
int T,n,m,sx,sy,vis[85][85][4],dir[4][2]={-1,0,1,0,0,-1,0,1},route[4][4]={2,3,0,1,3,2,1,0,1,0,2,3,0,1,3,2};
struct status
{
    int x,y,dep,dir;
    status(int x,int y,int dep,int dir):x(x),y(y),dep(dep),dir(dir) {}
};
int bfs(int x,int y)
{
    queue<status> Q;
    for(int i=0;i<4;i++)
    {
        vis[x][y][i]=true;
        Q.push(status(x,y,0,i));
    }
    while(!Q.empty())
    {
        status t=Q.front();Q.pop();
        bool direct=true;
        for(int s=0;s<3;s++)
        {
            if(s>=2&&!direct) break;
            int X=t.x+dir[route[t.dir][s]][0],Y=t.y+dir[route[t.dir][s]][1];
            if(X<1||X>n||Y<1||Y>m||map[X][Y]=='#') continue;
            if(s==0||s==1) direct=false;
            if(vis[X][Y][route[t.dir][s]]) continue;
            vis[X][Y][route[t.dir][s]]=true;
            if(X==1||Y==1||X==n||Y==m) {return t.dep+1;}
            Q.push(status(X,Y,t.dep+1,route[t.dir][s]));
        }
    }
    return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>T;
    string tt;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>tt;
            for(int j=0;j<tt.size();j++)
            {
                map[i][j+1]=tt[j];
                if(tt[j]=='@') {sx=i;sy=j+1;}
            }
        }
        if(sx==1||sx==n||sy==1||sy==m) cout<<"0"<<endl;
        else cout<<bfs(sx,sy)<<endl;
    }
}
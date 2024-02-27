#include<vector>
#include<queue>
using namespace std;
int game[101][101]={0,};
int checked[101][101]={0,};
typedef pair<int,int> ii;
int r[4]={1,-1,0,0};
int c[4]={0,0,1,-1};

void bfs(int s, int e, int n, int m, vector<vector<int>> &maps, queue<ii> &q){
    q.push({s,e});
    checked[s][e]=1;
    game[s][e]=1;
    while(!q.empty()){
        int cr=q.front().first;
        int cc=q.front().second;
        if(cr==n&&cc==m){
            break;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int nr=cr+r[i];
            int nc=cc+c[i];
            if(nr<=0||nr>n||nc<=0||nc>m||maps[nr-1][nc-1]==0||checked[nr][nc]==1){
                continue;
            }
            checked[nr][nc]=1;
            game[nr][nc]=game[cr][cc]+1;
            q.push({nr,nc});
        }
    }
    return;
}

int solution(vector<vector<int> > maps)
{
    int n=maps.size();
    int m=maps[0].size();
    queue<ii>q;
    bfs(1,1,n,m,maps,q);
    if(game[n][m]==0)
        return -1;
    return game[n][m];
}
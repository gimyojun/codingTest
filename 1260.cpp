#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


	int N;

    int M;
    int V;
    vector<int> graph[1001];
    int d_visited[1001]={0,};
    int b_visited[1001]={0,};


    queue<int> q;

void bfs(int x){

    q.push(x);
    b_visited[x]=true;

    while(!q.empty()){
        int y = q.front();
        q.pop();
        printf("%d ", y);
        for(int i=0;i<graph[y].size();i++){
            int tmp = graph[y][i];

            if(!b_visited[tmp]){
                q.push(tmp);
                b_visited[tmp]=true;
            }


        }



    }




    

}

void dfs(int x){

    d_visited[x]=true;
    printf("%d ", x);
    for(int i=0;i<graph[x].size();i++){
        int y = graph[x][i];

        if(!d_visited[y]){
            dfs(y);
        }
            

    }




}

int main(){


    scanf("%d %d %d", &N, &M, &V);
    
    for(int i=0;i<M;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0;i<=N;i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    
    printf("\n");

    bfs(V);

    return 0;
}



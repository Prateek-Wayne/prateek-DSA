class Solution {
public:
int n;
pair<int,int> getCoordinates(int num)
{
    int rowfromtop=(num-1)/n;
    int rowfrombottom=(n-1)-rowfromtop;

    int col=(num-1)%n;
    if((n%2==0 and rowfrombottom%2==0) or (n%2==1 and rowfrombottom%2==1)) //means right to left
    {
        col=(n-1)-col;
    }
    return {rowfrombottom,col};

}
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        int steps=0;
        queue<int>q;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[n-1][0]=true; //starting from 1
        q.push(1);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int x=q.front();
                q.pop();
                if(x==n*n) return steps; //if reached
                for(int k=1;k<=6;k++)
                {
                  int val=x+k;  
                  if(val>n*n) break;
                  pair<int,int>coord=getCoordinates(val);
                  int r=coord.first;
                  int c=coord.second;
                  if(vis[r][c]==true) continue;
                  vis[r][c]=true; //mark 
                  if(board[r][c]==-1) q.push(val);
                  else q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};

/*
Row from top=(num-1)/n
Row from bottom=(n-1)-(row from top)
Col=(num-1)%n
right to left=(n-1)-col
we are moving letf to right and then right to left
right to left jaayenge agar row aur n dono even yaa odd honge otherwise 
left to right
*/
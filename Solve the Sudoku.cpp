bool isSafe(int grid[N][N],int row,int col,int num){
    for(int i=0;i<N;i++){
        if(grid[row][i]==num){
            return false;
        }
    }
    
    for(int i=0;i<N;i++){
        if(grid[i][col]==num){
            return false;
        }
    }
    
    int rowStart=row-row%3;
    int colStart=col-col%3;
    for(int i=rowStart;i<rowStart+3;i++){
        for(int j=colStart;j<colStart+3;j++){
            if(grid[i][j]==num){
                return false;
            }
        }
    }
    return true;
}

bool SolveSudoku(int grid[N][N]){
    int row=-1,col=-1;
    bool isEmpty=false;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                isEmpty=true;
                break;
            }
        }
        if(isEmpty==true){
            break;
        }
    }
    
    if(isEmpty==false){
        return true;
    }
    
    for(int num=1;num<=N;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(SolveSudoku(grid)){
                return true;
            }
            else{
                grid[row][col]=0;
            }
        }
    }
    return false;
}

void printGrid(int grid[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
    }
}

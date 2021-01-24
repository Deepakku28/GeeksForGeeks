struct graph{
    int v;
    vector<int>* adj;
    graph(int K){
        v=K;
        adj= new vector<int>[K];
    }
};

class Solution{
    public:
    void add_edge(graph* root,int src,int dest){
        root->adj[src].push_back(dest);
    }
    
    void topological_sort_until(int curr,vector<bool>& visited,vector<int>& result,graph* root){
        visited[curr]=true;
        for(auto it:root->adj[curr]){
            if(visited[it]==false){
                topological_sort_until(it,visited,result,root);
            }
        }
        result.push_back(curr);
    }
    
    string topological_sort(graph* root){
        vector<bool> visited(root->v,false);
        vector<int> result;
        for(int i=0;i<root->v;i++){
            if(visited[i]==false){
                topological_sort_until(i,visited,result,root);
            }
        }
        string ans="";
        for(int i=result.size()-1;i>=0;i--){
            ans+=(result[i]+'a');
        }
        return ans;
    }
    
    string findOrder(string dict[], int N, int K){
        graph* root=new graph(K);
        for(int i=0;i<N-1;i++){
            string first=dict[i];
            string second=dict[i+1];
            for(int j=0;j<min(first.length(),second.length());j++){
                if(first[j]!=second[j]){
                    add_edge(root,first[j]-'a',second[j]-'a');
                    break;
                }
            }
        }
        string ans=topological_sort(root);
        //cout<<ans<<endl;
        return ans;
    }
};

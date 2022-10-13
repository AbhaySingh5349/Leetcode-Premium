Question Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/


// Approach :                                            
class Solution {
public:
    
    int find(int n, vector<int> &parent){
        if(parent[n]==n) return n;
        return parent[n]=find(parent[n],parent);
    }
    
    void merge(int u, int v, vector<int> &rk, vector<int> &parent){
        if(rk[u]>=rk[v]){
            rk[u]++;
            parent[v]=u;
        }else{
            rk[v]++;
            parent[u]=v;
        }
    }
    
    bool update(int pu, int pv, int &grp_cnt, vector<int> &rk, vector<int> &parent){
        if(pu!=pv){
            merge(pu,pv,rk,parent);
            grp_cnt--;
            return true;
        }
        return false;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(),edges.rend()); // giving preference for 'type 3' as it connects for both
        
        vector<int> rk_alice(n+1,1), rk_bob(n+1,1), parent_alice(n+1,-1), parent_bob(n+1,-1);
        for(int i=0;i<n+1;i++){
            parent_alice[i]=i;
            parent_bob[i]=i;
        }
        
        int grp_alice=n, grp_bob=n;
        int remove=0;
        for(int i=0;i<edges.size();i++){
            int type=edges[i][0], u=edges[i][1], v=edges[i][2];
            
            int pu_alice=find(u,parent_alice), pv_alice=find(v,parent_alice);
            int pu_bob=find(u,parent_bob), pv_bob=find(v,parent_bob);
            
            if(type==1){
                remove += !update(pu_alice, pv_alice, grp_alice, rk_alice, parent_alice);
            }else if(type==2){
                remove += !update(pu_bob, pv_bob, grp_bob, rk_bob, parent_bob);
            }else{
                bool b1=update(pu_alice, pv_alice, grp_alice, rk_alice, parent_alice);
                bool b2=update(pu_bob, pv_bob, grp_bob, rk_bob, parent_bob);
                
                remove += (!b1 && !b2);
            }
        }
        return ((grp_alice==1 && grp_bob==1 ) ? remove:-1);
    }
};

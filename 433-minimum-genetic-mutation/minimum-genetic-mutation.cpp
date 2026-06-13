class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>geneBank(bank.begin(),bank.end());
        if(geneBank.find(endGene)==geneBank.end()){
            return -1;
        }
        char mutations[]={'A','C','G','T'};
        int cnt=0;
        queue<string>q;
        q.push(startGene);
        while(!q.empty()){
            // level wise becoz cnt is there
            int level=q.size();
            for(int i=0;i<level;i++){
                string gene=q.front();
                q.pop();
                if(gene==endGene) return cnt;
                for(int i=0;i<8;i++){
                    char org=gene[i];
                    for(char ch:mutations){
                        if(ch==org) continue;
                        gene[i]=ch;
                        // like check for vis in bfs
                        if(geneBank.count(gene)){
                            q.push(gene);
                            geneBank.erase(gene);
                        }
                    }
                    gene[i]=org;
                }
            }
            cnt++;
        }
        return -1;
    }
};
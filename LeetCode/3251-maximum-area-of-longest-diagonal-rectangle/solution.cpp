class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int MaxArea = 0;
        int MaxDiagonal = 0;
        for (auto it : dimensions) {
            int l = it[0] ; 
            int w = it[1] ; 
            int  tempd = l * l + w * w;
            if (tempd >= MaxDiagonal) {
               if(tempd == MaxDiagonal) MaxArea = max(MaxArea,l * w);
               else MaxArea = l*w;
                MaxDiagonal = tempd;
            }
        }
    
        return MaxArea;
    }
};

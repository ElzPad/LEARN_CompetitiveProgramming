class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size()==1)    return 1;
        
        int res=0, seqCount=1, seqDim=0, seqVal=0;
        char prev = chars[0];

        for (int i=1; i<chars.size(); i++) {
            if (chars[i]==prev) {
                seqCount++;
            } else {
                chars[res++] = prev;

                prev = chars[i];
                if (seqCount > 1) {
                    seqDim = 1;
                    while ( int(seqCount/pow(10,seqDim))!=0 ) seqDim++;

                    while ( seqDim > 0) {
                        seqVal = (seqCount%int(pow(10, seqDim))) / pow(10, seqDim-1);
                        chars[res++] = seqVal + '0';
                        seqDim--;
                    }
                }
                seqCount = 1;
            }
        }

        chars[res++] = prev;
        if (seqCount > 1) {
            seqDim = 1;
            while ( int(seqCount/pow(10,seqDim))!=0 ) seqDim++;

            while ( seqDim > 0) {
                seqVal = (seqCount%int(pow(10, seqDim))) / pow(10, seqDim-1);
                chars[res++] = seqVal + '0';
                seqDim--;
            }
        }
        return res;
    }
};
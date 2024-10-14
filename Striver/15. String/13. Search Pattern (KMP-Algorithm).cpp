// Link: https://www.geeksforgeeks.org/problems/search-pattern0205/1

vector <int> search(string pat, string txt)
        {
            //code here
            vector<int> kq;
            int lenPat = pat.size();
            int lenTxt = txt.size();
            vector<int>kmp(lenPat,0);
            int k = 0;
            for(int i = 1; i < lenPat; ++i) {
                while(k > 0 && pat[k] != pat[i]) k = kmp[k-1];
                if (pat[k] == pat[i]) {
                    kmp[i] = k+1;
                    ++k;
                }
                else {
                    kmp[i] = 0;
                }
            }

            int q = 0;
            for(int i = 0 ; i < lenTxt; ++i) {
                while(q > 0 && pat[q] != txt[i]) q = kmp[q-1];
                if(pat[q] == txt[i]) {
                    if((q+1) == lenPat) {
                        kq.push_back(i-lenPat+2);
                    }
                    ++q;
                }
            }
            if (kq.empty()) {
                kq.push_back(-1); // Trả về -1 nếu không tìm thấy mẫu trong văn bản
            }
            return kq;



// 2. 

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int i=0;
            vector<int> res;
            while(i<=txt.size()-pat.size()){
                int index = txt.find(pat, i);
                if(index!=string::npos){
                    res.push_back(index+1);
                    i=index+1;
                }else{
                    break;
                }
            }
            return res;
        }
};


// 3. vector <int> search(string pat, string txt)
        {
            vector<int> v;
             // iterate till the input string txt contains enough characters to compare
            for(int i = 0;i< txt.length();i++){
                int start = 0;
                int c = i;
                while(start != pat.length() && txt[c] == pat[start]){
                    c++;
                    start++;
                }
                if( start == pat.length()){
                    v.push_back(i+1);
                }
            }
            return v;
        }
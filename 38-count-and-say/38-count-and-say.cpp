class Solution {
public:
    void print_vector(vector<string> v){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    string countAndSay(int n) {
        string s = "1";
        for(int j = 1;j<n;j++){
            vector<char> ds;
            vector<string> cs;
            char c = s[0];
            int count = 1;
            for(int i = 1;i<s.length();i++){
                if(s[i]==c)count++;
                else{
                    ds.push_back(c);
                    cs.push_back(to_string(count));
                    c = s[i];
                    count = 1;
                }
            }
            
            ds.push_back(c);
            cs.push_back(to_string(count));
            // print_vector(ds);
            // print_vector(cs);
            string a = "";
            for(int i = 0;i<ds.size();i++){
                a+=cs[i];
                a+=ds[i];
            }
            s = a;
        }
        return s;
        
    }
};
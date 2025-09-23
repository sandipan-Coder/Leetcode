class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n1 = version1.length();
        int n2 = version2.length();
        int i = 0;
        int j = 0;
        vector<int> ver1;
        vector<int> ver2;

        while(i < n1){
            int num = 0;
            while(i < n1 && version1[i] != '.'){
                num = (num * 10) + (version1[i] - '0');
                i++;
            }
            ver1.push_back(num);
            i++;
        }
       
        while(j < n2){
            int num = 0;
            while(j < n2 && version2[j] != '.'){
                num = (num * 10) + (version2[j] - '0');
                j++;
            }
            ver2.push_back(num);
            j++;
        }

        i = 0, j = 0;

        while(i < ver1.size() && j < ver2.size()){
            
            if(ver1[i] < ver2[j])
                return -1;
            else if(ver1[i] > ver2[j])
                return 1;
            i++;
            j++;
        }

        while(i < ver1.size()){
            if(ver1[i] > 0)
                return 1;
            i++;
        }

        while(j < ver2.size()){
            if(ver2[j] > 0)
                return -1;
            j++;
        }

        return 0;
    }
};
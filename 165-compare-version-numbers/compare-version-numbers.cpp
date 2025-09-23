class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int n1 = version1.length();
        int n2 = version2.length();
        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            int num1 = 0;
            while(i < n1 && version1[i] != '.'){
                num1 = (num1 * 10) + (version1[i] - '0');
                i++;
            }

            int num2 = 0;
            while(j < n2 && version2[j] != '.'){
                num2 = (num2 * 10) + (version2[j] - '0');
                j++;
            }

            if(num1 > num2)
                return 1;
            else if(num1 < num2)
                return -1;

            i++;
            j++;
        }
       
        while(i < n1){
            int num1 = 0;
            while(i < n1 && version1[i] != '.'){
                num1 = (num1 * 10) + (version1[i] - '0');
                i++;
            }

            if(num1)
                return 1;
            i++;
        }

        while(j < n2){
            int num2 = 0;
            while(j < n2 && version2[j] != '.'){
                num2 = (num2 * 10) + (version2[j] - '0');
                j++;
            }

            if(num2)
                return -1;
            j++;
        }

        return 0;
    }
};
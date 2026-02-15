class Solution {
public:
    int reverse(int x) {
        long long lastdigit , reversedigit=0;
    
        while (x!=0){
        lastdigit = x % 10;
        reversedigit = reversedigit*10 + lastdigit;
         if (reversedigit > INT_MAX || reversedigit < INT_MIN) {
                return 0;
         }
        x=x/10;
    }
   return reversedigit;
    }
   
   
};
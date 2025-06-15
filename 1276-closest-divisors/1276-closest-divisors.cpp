class Solution {
public:
    vector<int> closestDivisors(int num) {
        for(int z=sqrt(num+2);z>0; --z)
        {
            if((num+1) % z==0){
                return{z,(num+1)/z};
            }
                if((num+2)% z==0){
                    return{z,(num+2)/z};
                }
              
            
        }  
        return{};
    }
};
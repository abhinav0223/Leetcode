// class Solution {
// public:
//     bool doesAliceWin(string s) {
//         string vowels="aeiou";
//         int vowelCount=0;
//         for (char c:s){
//             if(vowels.find(c)!=string::npos)
//             {
//                 vowelCount++;
//             }
//         }
//         if(vowelCount==0)
//         return false;
//         return vowelCount%2==1;
        
//     }
// };

class Solution {
 public:
     bool doesAliceWin(string s) {
        for(char c:s){
            if(c=='a' || c=='e' ||c=='i' || c=='o' || c=='u')
            {
            return true;
        }
     } 
     return false;
}
};
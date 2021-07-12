public class lastword
{
    public static void main(String[] args) 
    {
        Solution s = new Solution();

        System.out.println(s.lengthOfLastWord("   "));
    }


}

class Solution
{
    public int lengthOfLastWord(String s)
{
    int len = s.length();

    int count = 0;

    int i = len-1;

    while(s.charAt(i) == ' ' && i>0)
        i--;
    
    if(i == 0)
        return count;

    while(i >= 0)
    {
        if(s.charAt(i) != ' ')
            count++;

        else
            return count;

        i--;
    }

    return count;
}

}
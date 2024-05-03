import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        ArrayList<Integer> a=new ArrayList<Integer>();
        for(int i=0;i<commands.length;i++){
            for(int j=commands[i][0];j<=commands[i][1];j++){
                a.add(array[j-1]);
            }
            Collections.sort(a);
            answer[i]=a.get(commands[i][2]-1);
            a.clear();
        }
        return answer;
    }
}
import java.util.*;

class Solution {
    public int solution(int[][] sizes) {
        
        int lmax =0; 
        int rmax=0;
        for(int[] g : sizes){
            //순서 바꾸깅
            if(g[0] < g[1]){
                //순서 바꾸깅
                int c = g[0];
                g[0] = g[1];
                g[1] = c;
            }
            //find lMax
            if(lmax < g[0]){
                lmax = g[0];
            }
            //find rmax
            if(rmax <g[1]){
                rmax = g[1];
            }
            
        }
        return lmax*rmax;
    }
}
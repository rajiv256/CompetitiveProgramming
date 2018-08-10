import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.PriorityQueue ; 

public class dijkstra {
	
	public class Edge implements Comparable<Edge>{
		int w ; int dst ;
		public Edge(int ww, int dsst){
			this.w = ww ; 
			this.dst = dsst ; 
		}
		
		@Override
		public int compareTo(Edge e) {
			return (this.w-e.w);
		} 
		
	}
	
    public static void main(String[] args) {
        
    	Scanner in = new Scanner(System.in); 
    	int t ; t = Integer.valueOf(in.nextLine()) ; 
    	while (t != 0){
    		int n , m ; 
    		String aa = in.nextLine() ; 
    		String[] aaa = new String[2] ; 
    		aaa = aa.split(" ") ; 
    		
    		n = Integer.valueOf(aaa[0]) ;  
    		m = Integer.valueOf(aaa[1]) ;  
    		
    		ArrayList<LinkedList<Integer> > adj = new ArrayList<LinkedList<Integer>> () ; 
    		for (int i = 0 ; i < n ; i++){
    			adj.add(new LinkedList<Integer>()) ; 
    		}
    		int [][] wt = new int[3000][3000] ; 
    		int a , b , w ; 
    		while (m != 0){
    			String sss = in.nextLine() ;
    			sss.trim();
    			//System.out.println(sss);
    			String[] ss = new String[3] ; 
    			ss = sss.split(" ") ; 
    			a = Integer.valueOf(ss[0].trim()) ; a-=1 ; 
    			b = Integer.valueOf(ss[1].trim()) ; b-=1 ; 
    			w = Integer.valueOf(ss[2].trim())  ; 
    			//System.out.println(a + " " + b);
    			adj.get(a).add(b) ; adj.get(b).add(a) ; 
    			if (wt[a][b] == 0){
    				wt[a][b] = w  ; 
    				wt[b][a] = w ; 
    			}
    			else{
    				if (w < wt[a][b]){
    					wt[a][b] = w ; 
    					wt[b][a] = w ; 
    				}
    			}
    			//wt[a][b] = w ; wt[b][a] = w ; 
    			
    			
    			m -= 1 ;
    		}
    		/*for (int i = 0 ; i < n ; i++){
    			for (int j = 0 ; j < n ; j++){
    				System.out.print(wt[i][j] +" ");
    			}
    			System.out.println();
    		}*/
    		int[] dist = new int[n] ; 
			boolean [] visited = new boolean[n] ; 
			for(int i = 0 ; i < n ; i++){
				dist[i] = 100000 ;
			}
    		String p = in.nextLine() ;
    		int s = Integer.valueOf(p) ; s -= 1 ; 
			dist[s] = 0 ;
			//System.out.println("Each time");
			dijkstra(s,adj,wt,dist,visited,n) ; 
    		for (int i = 0 ; i < n ; i++){
    			
    			if (i == s)
    				continue ; 
    			if (dist[i] == 100000){
    				System.out.print("-1 ");
    			}
    			else{
    				System.out.print(dist[i]+" ");
    			}
    		}
    		System.out.println();
    		t -= 1; 
    	}
    	
    	
    	
    	
    	
    }
    
	private static void dijkstra(int s, ArrayList<LinkedList<Integer>> adj,	int[][] wt, int[] dist,boolean[] visited, int n) {
		PriorityQueue<Edge> pq = new PriorityQueue<Edge>() ; 
		gdijkstra ss = new gdijkstra() ; 
		//System.out.println(s);
		Edge e = ss.new Edge(0, s) ; 
		pq.add(e) ; 
		while (!pq.isEmpty()){
			s = pq.poll().dst ;
		
			//System.out.println(s);
			for (int i = 0 ; i < adj.get(s).size() ; i++){
				
				if (!visited[adj.get(s).get(i)]){
					//System.out.println(s +" @ " + adj.get(s).get(i) +" " +dist[s]+ "+" +wt[s][adj.get(s).get(i)]+" <--> "+dist[adj.get(s).get(i)]);
					if (dist[s]+wt[s][adj.get(s).get(i)] < dist[adj.get(s).get(i)]){
						dist[adj.get(s).get(i)] = dist[s]+wt[s][adj.get(s).get(i)] ; 
						//System.out.print(adj.get(s).get(i)+" ");
						Edge e1 = ss.new Edge(dist[adj.get(s).get(i)],adj.get(s).get(i)) ; 
						pq.add(e1) ; 
					}
				}
			}
			//pq.poll() ; 
			visited[s] = true ;
			//System.out.println("\n"+s + " Marked!");
			//pq.poll()  ;
			 
			
		}
		
	}
}
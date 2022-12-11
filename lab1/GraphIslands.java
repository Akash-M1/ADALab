package lab1;

public class GraphIslands {
	
	public static int Islands(int [][] graph) {
		int n=graph.length;
		int m=graph[0].length;
		
		DisjointUnionSets s1=new DisjointUnionSets(n*m);
		
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(graph[i][j]==0) {
					continue;
				}
				
				if((i-1>=0) && (j-1>=0) && graph[i-1][j-1]==1) {
					s1.union(i*m+j, (i-1)*m+(j-1));
				}
				
				if((i-1>=0) && graph[i-1][j]==1) {
					s1.union(i*m+j, (i-1)*m+(j));
				}
				
				if((i-1>=0) && (j+1<n) && graph[i-1][j+1]==1) {
					s1.union(i*m+j, (i-1)*m+(j+1));
				}
				
				if((j-1>=0) && graph[i][j-1]==1) {
					s1.union(i*m+j, (i)*m+(j-1));
				}
				
				if((j+1<n) && graph[i][j+1]==1) {
					s1.union(i*m+j, (i)*m+(j+1));
				}
				
				if((i+1<n) && (j-1>=n) && graph[i+1][j-1]==1) {
					s1.union(i*m+j, (i+1)*m+(j-1));
				}
				
				if((i+1<n) && graph[i+1][j]==1) {
					s1.union(i*m+j, (i+1)*m+(j));
				}
				
				if((i+1<n) && (j+1<n) && graph[i+1][j+1]==1) {
					s1.union(i*m+j, (i+1)*m+(j+1));
				}
				
			}
		}
		
		
		int c[]=new int[n*m];
		int findFrequency=0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++){
				if(graph[i][j]==1) {
					int x=s1.find((i*m+j));
					
					if(c[x]==0) {
						c[x]++;
						findFrequency++;
					}
					
					else {
						c[x]++;
					}
				}
			}
		}
		
		return findFrequency;
	}

	public static void main(String[] args) {
		
		int graph[][]=new int[][]{{1, 1, 0, 0, 0},
            					  {0, 1, 0, 0, 1},
                                  {1, 0, 0, 1, 1},
                                  {0, 0, 0, 0, 0},
                                  {1, 0, 1, 0, 1}
           };
		
		System.out.println("Number of Islands in the given graph is"+" "+Islands(graph));
		System.out.println("Hello");
	}

}

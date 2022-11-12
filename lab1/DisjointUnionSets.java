package lab1;

public class DisjointUnionSets {
	public int parent[];
	public int rank[];
	public DisjointUnionSets(int n) {
		this.parent=new int[n];
		this.rank=new int[n];
		makeSet();
	}
	private void makeSet() {
		for(int i=0;i<parent.length;i++) {
			parent[i]=i;
		}
		
	}
	
	public int find(int x)
	{
		if (parent[x] != x)
		{
			parent[x]=find(parent[x]);
		}

		return parent[x];
	}

	
	public void union(int x,int y) {
		int parent1=find(x);
		int parent2=find(y);
		
		if(parent1 == parent2) {
			return;
		}
		
		if(rank[x]>rank[y]) {
			parent[parent2]=parent1;
		}
		
		else if(rank[y]>rank[x]) {
			parent[parent1]=parent2;
		}
		
		else {
			parent[parent2]=parent1;
			rank[parent1]++;
		}
	}
	
	
}

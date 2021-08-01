//Union Find Algorithm Almost O(1) for reasonable size N. O(log*N) to be precise
struct UnionFind {
	int n;
	vector<int> size;
	vector<int> parent;
	// store other info as required
	UnionFind(int n) {
		size.resize(n)
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			size[i]=1 ;
		}
	}
	int get(int a) {
		return parent[a] = (parent[a] == a ? a : get(parent[a]));
	}
	void merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return;
		}
		if (rank[a] >= rank[b]) {
			parent[b]=a ;
			size[a]+=size[b];
		}
		else {
			parent[a]=b ;
			size[b]+=size[a];
		}
	}
};

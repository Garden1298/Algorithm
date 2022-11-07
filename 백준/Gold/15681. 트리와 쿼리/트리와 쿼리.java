import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	
	static int dp[];
	static ArrayList<Integer> tree[];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int nodeCnt = Integer.parseInt(st.nextToken());//트리 정점의 수 N
		int rootCnt = Integer.parseInt(st.nextToken());//루트의 번호 R
		int queryCnt = Integer.parseInt(st.nextToken());//쿼리의 수 Q
		
		dp = new int[nodeCnt+1];
		
		tree = new ArrayList[nodeCnt+1];
		for(int i = 1; i<=nodeCnt; i++)
		{
			tree[i] = new ArrayList<>();
		}
		
		for(int i = 0; i<nodeCnt-1; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			int nodeA = Integer.parseInt(st.nextToken());
			int nodeB = Integer.parseInt(st.nextToken());
			
			tree[nodeA].add(nodeB);
			tree[nodeB].add(nodeA);
		}
		
		dfs(rootCnt);
		
		for(int i = 0; i< queryCnt; i++)
		{
			int input = Integer.parseInt(br.readLine());
			System.out.println(dp[input]);
		}
	}

	private static int dfs(int node) {
		
		//방문했던 노드라면
		if(dp[node]!=0)
		{
			return 0;
		}
		
		dp[node] = 1;
		
		for(int i = 0; i<tree[node].size(); i++)
		{
			dp[node] += dfs(tree[node].get(i));
		}
		
		return dp[node];
	}

}

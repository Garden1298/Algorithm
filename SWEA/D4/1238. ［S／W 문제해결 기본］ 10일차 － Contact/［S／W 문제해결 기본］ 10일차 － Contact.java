import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	static class Node
	{
		int num;
		int level;
		
		public Node(int num, int level) {
			super();
			this.num = num;
			this.level = level;
		}
		
		@Override
		public String toString() {
			return "Node [num=" + num + ", level=" + level + "]";
		}
	}
	
	static int graph[][] = new int[101][101];
	static int direction[][] = {{-1,0},{1,0},{0,-1},{0,1}};
	static int maxNum = 0;

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int tc = 1; tc <= 10; tc++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());

			int dataLength = Integer.parseInt(st.nextToken());
			int startNode = Integer.parseInt(st.nextToken());
			graph = new int[101][101];
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i< dataLength/2; i++)
			{
				
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				
				graph[from][to] = 1;
			}
			
			bfs(startNode);
			System.out.println("#"+tc+" "+maxNum);
			
		}
	}

	private static void bfs(int startNode) 
	{
		Queue<Node> queue = new LinkedList<>();
		boolean isVisited[] = new boolean[101];
		int level = 1;
		
		isVisited[startNode] = true;
		queue.offer(new Node(startNode, 1));
		
		while(!queue.isEmpty())
		{
			Node cur = queue.poll();
			if(cur.level == level)
			{
				maxNum = Math.max(maxNum, cur.num);
			}
			else
			{
				//System.out.println("next level");
				level++;
				maxNum = cur.num;
			}
			
			for(int i = 0; i< 101; i++)
			{
				if(!isVisited[i] && graph[cur.num][i] == 1)
				{
					isVisited[i] = true;
					//System.out.println("currentNode : " + i);
					queue.offer(new Node(i, cur.level+1));
				}		
				
			}
			
		}

	}

}

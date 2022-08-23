import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

import javax.print.attribute.HashAttributeSet;

public class Solution {
	
	static class Edge
	{
		int from;
		int to;
		
		public Edge(int from, int to) {
			super();
			this.from = from;
			this.to = to;
		}
	}
	
	static int[] parents;//서로소 집합을 트리로 유지하기 위한 배열
	static int V,E;//정점의 개수, 간선의 개수
	static Edge[] edgeList;//간선 리스트
	
	static void make(int N)//크기가 1인 서로소 집합 생성
	{
		parents = new int[N+1];
		for (int i = 1; i <= N; i++) {//모든 노드가 자신을 부모로 하는(대표자) 집합으로 만듦
			parents[i] = i;
		}
	}
	
	static int find(int a)//a의 대표자 찾기
	{
		if(parents[a] == a)//나의 부모가 나라면
		{
			return a;//내가 우리 집합의 대표자다
		}
		
		return parents[a] = find(parents[a]);//우리의 대표자를 나의 부모로 : path compression
	}
	
	static boolean union(int a, int b)// 리턴 값 : true ==> union 성공, 
	{
		int aRoot = find(a);
		int bRoot = find(b);
		
		if(aRoot == bRoot)//가족이었다면 합칠 수 없으니 false 반환
		{
			return false;
		}
		
		parents[bRoot] = aRoot;
		return true;
	}
	
	public static void main(String[] args) throws IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc<= T; tc++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());		
			
			make(N);
			
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				
				union(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			
			Set<Integer> set = new HashSet<>();
			for(int i = 1; i<=N; i++)
			{
				set.add(find(i));
			}
			System.out.println("#"+tc+" "+set.size());
		}
	}
}

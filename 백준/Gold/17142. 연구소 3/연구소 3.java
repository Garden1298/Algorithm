
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static class Virus{
		int posA, posB, time = 0;

		public Virus(int posA, int posB, int time) {
			super();
			this.posA = posA;
			this.posB = posB;
			this.time = time;
		}

		@Override
		public String toString() {
			return "Virus [posA=" + posA + ", posB=" + posB + ", time=" + time + "]";
		}
	}

	static int map[][];
	static int virusChoose[];
	static int mapSize, virusCnt, leftPlace = 0, virusTotalCnt = 0, minTime = Integer.MAX_VALUE;
	static List<Virus> virus = new ArrayList<>();
	static Queue<Virus> queue = new LinkedList<>();
	static int direction[][] = {{0,-1},{0,1},{-1,0},{1,0}};
	static boolean isVisited[][];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		mapSize = Integer.parseInt(st.nextToken());
		virusCnt = Integer.parseInt(st.nextToken());
		
		map = new int[mapSize][mapSize];
		virusChoose = new int[virusCnt];

		for(int i = 0; i<mapSize; i++)
		{
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j<mapSize; j++)
			{
				int input = Integer.parseInt(st.nextToken());
				map[i][j] = input;
				
				if(input == 0) leftPlace+=1;
				else if(input == 2)
				{
					virus.add(new Virus(i, j, 0));
				}
			}
		}
		
		if(leftPlace==0)
		{
			System.out.println(0);
			return;
		}
		
		virusTotalCnt=virus.size();
		
		chooseVirus(0,0);
		
		if(minTime==Integer.MAX_VALUE)
		{
			System.out.println(-1);
		}
		else
		{			
			System.out.println(minTime+1);
		}
	}

	private static void chooseVirus(int cnt, int start) 
	{
		if(cnt == virusCnt)
		{
			queue = new LinkedList<>();
			isVisited = new boolean[mapSize][mapSize];
			
			for(int i = 0; i<virusCnt; i++)
			{
				Virus getVirus = virus.get(virusChoose[i]);
				isVisited[getVirus.posA][getVirus.posB] = true;
				queue.offer(getVirus);
			}
			spreadVirus();
			return;
		}
		
		for(int i = start; i<virusTotalCnt; i++)
		{
			virusChoose[cnt] = i;
			chooseVirus(cnt+1, i+1);
		}
	}
	
	private static void spreadVirus() {
		
		int left = leftPlace;
		int lastTime = 0;
		
		while(!queue.isEmpty())
		{
			if(left == 0)
			{
				minTime = Math.min(minTime, lastTime);
				return;
			}

			Virus curVirus = queue.poll();
			
			int curA = curVirus.posA;
			int curB = curVirus.posB;
			int curTime = curVirus.time;
			
			lastTime = curTime;
			
			for(int dir = 0; dir<4; dir++)
			{
				int nextA = curA + direction[dir][0];
				int nextB = curB + direction[dir][1];
				
				if(nextA<0||nextB<0||nextA>=mapSize||nextB>=mapSize) continue;
				if(isVisited[nextA][nextB]) continue;
				if(map[nextA][nextB]==1) continue;
				
				isVisited[nextA][nextB] = true;
				if(map[nextA][nextB]==0) left-=1;
				queue.offer(new Virus(nextA, nextB, curTime+1));
			}
		}
		
	}

}

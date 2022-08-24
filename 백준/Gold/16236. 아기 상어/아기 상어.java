import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
    static class Fish implements Comparable<Fish>
    {
        int posX;
        int posY;
        int distance;
        
		public Fish(int posX, int posY, int distance) 
		{
			super();
			this.posX = posX;
			this.posY = posY;
			this.distance = distance;
		}

		@Override
		public int compareTo(Fish o) 
		{
			if(this.distance == o.distance)
			{
				if(this.posX == o.posX) return this.posY - o.posY;
				else return this.posX-o.posX;
			}
			else return this.distance - o.distance;
		}

		@Override
		public String toString() 
		{
			return "Fish [posX=" + posX + ", posY=" + posY + ", distance=" + distance + "]";
		}
    }

    static int N, totalDistance = 0; 
    static int map[][];
    static boolean isVisited[][];
    static int direction[][] = {{-1,0},{1,0},{0,-1},{0,1}};
    
    static Fish shark;
    static int sharkSize = 2, sharkEaten = 0;
    static List<Fish> fishWaiting = new ArrayList<>();
    
    public static void main(String[] args) throws NumberFormatException, IOException {
    	
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        map = new int[N][N];
        
        for(int i = 0; i < N; i++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++)
            {
                int input = Integer.parseInt(st.nextToken());
                if(input == 0) continue;
                else if(input == 9) { shark = new Fish(i, j, 0); map[i][j] = 0; }
                else { map[i][j] = input; }
            }
        }
        
        while(true)
        {
        	bfs();
        	
        	
            if(!fishWaiting.isEmpty())
            {
            	Collections.sort(fishWaiting);
//            	System.out.println("================");
//            	System.out.println("먹을 예정인 물고기들");
//            	for(Fish f : fishWaiting)
//            	{
//            		System.out.println(f.toString());
//            	}
//            	System.out.println("================");
            	
            	Fish fish2eat = fishWaiting.get(0);      	
            	
            	sharkEaten++;
            	if(sharkEaten == sharkSize)
            	{
            		sharkSize++;
            		sharkEaten = 0;
            		//System.out.println("상어 레벨업! 현재 상어의 사이즈 : "+ sharkSize);
            	}
            	
            	shark.posX = fish2eat.posX;
            	shark.posY = fish2eat.posY;
            	map[shark.posX][shark.posY] = 0;
            	
            	totalDistance += fish2eat.distance;
            	
//            	System.out.println(fish2eat.posX+", "+ fish2eat.posY +" 물고기를 먹었습니다! 현재 지나간 거리 :"+fish2eat.distance+"->"+totalDistance);
//            	for(int i = 0; i<N; i++)
//            	{
//            		for(int j = 0; j<N; j++)
//            		{
//            			System.out.print(map[i][j]);
//            		}
//            		System.out.println();
//            	}
            }
            else break;
        }
        
        System.out.println(totalDistance);

    }
    

    static void bfs()
    {
    	isVisited = new boolean[N][N];
    	fishWaiting = new ArrayList<>();
    	
    	Queue<Fish> queue = new LinkedList<>();
    	queue.offer(new Fish(shark.posX, shark.posY, shark.distance));
    	isVisited[shark.posX][shark.posY] = true;
    	
    	while(!queue.isEmpty())
    	{
	    	Fish current = queue.poll();
	    	int distance = current.distance;
	    	
	    	for(int i = 0; i<direction.length; i++)
	    	{
	    		int nextA = current.posX + direction[i][0];
	    		int nextB = current.posY + direction[i][1];
	    		
	    		if(nextA<0 || nextA>=N || nextB<0 || nextB>=N || isVisited[nextA][nextB]) continue;
	    		
		    	if(map[nextA][nextB]!=0 && map[nextA][nextB]<sharkSize)//다음 위치에 물고기가 있고, 그 물고기가 상어의 크기보다 작다면
		    	{
		    		fishWaiting.add(new Fish(nextA, nextB, distance+1));//먹을 물고기 추가
		    		queue.offer(new Fish(nextA, nextB, distance+1));
		    		isVisited[nextA][nextB] = true;
		    	}
		    	
		    	if(map[nextA][nextB]==0||map[nextA][nextB]==sharkSize)//다음 위치에 물고기가 없거나 물고기가 상어의 크기와 같으면
		    	{
		    		queue.offer(new Fish(nextA, nextB, distance+1));
		    		isVisited[nextA][nextB] = true;
		    	}
		    	
	    	}
    	}
    }
}
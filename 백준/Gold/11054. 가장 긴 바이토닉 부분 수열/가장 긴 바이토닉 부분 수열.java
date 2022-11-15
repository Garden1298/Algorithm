import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		int Num = Integer.parseInt(br.readLine());
		int Nums[] = new int[Num];
		int Increse[] = new int[Num];
		int Decrese[] = new int[Num];
		int maxProfit = 0;
		
		Arrays.fill(Increse, 1);
		Arrays.fill(Decrese, 1);
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i<Num; i++)
		{
			Nums[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 1; i<Num; i++)
		{
			for(int j = i-1; j>=0; j--)
			{
				//System.out.print("i:"+i+" j:"+j+" ");
				//System.out.println("Nums[i]:"+Nums[i]+" Nums[j]:"+Nums[j]);
				//이전 값에서 자기보다 작은 값 탐색
				if(Nums[i]>Nums[j])
				{
					Increse[i] = Math.max(Increse[i], Increse[j]+1);
				}
			}
		}
		
		for(int i = Num-1; i>=0; i--)
		{
			for(int j = i+1; j<Num; j++)
			{
//				System.out.print("i:"+i+" j:"+j+" ");
//				System.out.println("Nums[i]:"+Nums[i]+" Nums[j]:"+Nums[j]);
				//이전 값에서 자기보다 큰 값 탐색
				if(Nums[i]>Nums[j])
				{
//					System.out.println("더 큰 값을 찾았습니다!");
					Decrese[i] = Math.max(Decrese[i], Decrese[j]+1);
				}
			}
//			System.out.println("=====");
		}
		
//		System.out.println("increase: "+Arrays.toString(Increse));
//		System.out.println("decrease: "+Arrays.toString(Decrese));
		
		for(int i = 0; i<Num; i++)
		{
			int curProfit = Increse[i] + Decrese[i];
			maxProfit = Math.max(maxProfit, curProfit);
		}
		
		System.out.println(maxProfit-1);
		
	}

}

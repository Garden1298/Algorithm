import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int left;
	static int right;
	static int num[][] = new int[30][30];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 0; tc<T; tc++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			left = Integer.parseInt(st.nextToken());
			right = Integer.parseInt(st.nextToken());
			
			num = new int[30][30];
			
			System.out.println(nCr(right, left));
		}
	}
	
	private static int nCr(int N, int R)
	{		
		if(N==R||R==0) return num[N][R] = 1;
		
		if(num[N][R]!=0)
		{
				return num[N][R];
		}
		
		return num[N][R] = nCr(N-1,R-1) + nCr(N-1,R);
	}
}

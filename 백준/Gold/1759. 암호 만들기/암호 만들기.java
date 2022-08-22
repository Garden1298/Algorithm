import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int length, charNum;
	static char arr[];
	static char combOutput[];

	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		length = Integer.parseInt(st.nextToken());
		charNum = Integer.parseInt(st.nextToken());
		
		arr = new char[charNum];
		combOutput = new char[length];
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i<charNum;i++)
		{
			arr[i] = st.nextToken().charAt(0);
		}
		
		Arrays.sort(arr);
		
		comb(0, 0);

	}
	
	static void comb(int cnt, int start)
	{
		if(cnt == length)
		{
			int vowel = 0;//모음
			int consonant = 0;//자음
			
			for(int i = 0; i<length; i++)
			{
				char currentChar = combOutput[i];
				if(currentChar == 'a' ||currentChar == 'e' ||currentChar == 'i' ||currentChar == 'o' ||currentChar == 'u')
				{
					vowel++;
				}
				else
				{
					consonant++;
				}
			}
			
			if(vowel>=1 && consonant >=2)
			{
				for(int i = 0; i< combOutput.length; i++)
				{
					System.out.print(combOutput[i]);
				}
				System.out.println();
			}
			
			return;
		}
		
		for(int i = start; i<charNum; i++)
		{
			combOutput[cnt] = arr[i];
			comb(cnt+1, i+1);
		}
		
	}

}

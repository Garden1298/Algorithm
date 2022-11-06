import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        
        int leftDay = Integer.parseInt(br.readLine());//퇴사하기까지 남은 기간
        int arr[][] = new int[leftDay+2][2];//[0]상담을 완료하는데 걸리는 기간, [1]받을 수 있는 금액
        int dp[] = new int[leftDay+2];//최대 금액 배열
        int maxMoney = 0;//최대 이익
        
        for(int i = 1; i<=leftDay; i++)
        {
            st = new StringTokenizer(br.readLine());
            
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        
        for(int i = 1; i<leftDay+2; i++)
        {
//        	System.out.println("day:" + i);
        	
        	int workDate = arr[i][0];//상담 소요 시간
        	int money = arr[i][1];//상담을 마치면 받을 수 있는 돈
        	
        	int workFin = workDate+i;//상담 끝나는 날짜
        	maxMoney = Math.max(maxMoney, dp[i]);//현재 날짜까지의 최대 이익

        	if(workFin<leftDay+2)
            {
        		dp[workFin] = Math.max(dp[workFin], money+maxMoney);
            }
//          else
//          {
//              System.out.println("날짜를 넘음");
//          }

        }
        
        System.out.println(maxMoney);

    }
}
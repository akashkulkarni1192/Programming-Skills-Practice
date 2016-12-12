import java.util.Scanner;


class MainClass {
	int array[][] = new int[10][10];
	public static void main(String args[]){
		MainClass rider = new MainClass();
		rider.start();
		
	}
	public void start(){
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter order of matrix :");
		int m = scan.nextInt();
		int n = scan.nextInt();
		System.out.println("Enter Matrix Contents :");
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				array[i][j]=scan.nextInt();
			}
		}
		int max=0;
		int left,right,up,down,a1=0,a2=0,b1=0,b2=0;
		int[] temp = new int[10];
		for(left=0;left<=n-1;left++){
			for(right=left;right<=n-1;right++){
				for(int x=0;x<n;x++)
					temp[x]=0;
				for(int i=0;i<m;i++){
					for(int j=left;j<=right;j++){
						temp[i]+=array[i][j];
					}
				}
				int sum=0;
				for(int i=0;i<m;i++){
					for(int u=0;u<=m-i-1;u++){
						for(int d=u;d<=u+i;d++){
							sum+=temp[d];
						}
						if(sum>max && !(u==0 && left==0 && u+i==m-1 && right==n-1 )){
							max=sum;
							a1=u;
							a2=left;
							b1=u+i;
							b2=right;
						}
						sum=0;
					}
				}
			}
		}
		System.out.println("Input Matrix :");
		for(int x=0;x<m;x++){
			for(int y=0;y<n;y++){
				System.out.format("%5d  ",array[x][y]);
			}
			System.out.println();
		}
		System.out.println("Biggest Matrix is :");
		
		for(int x=a1;x<=b1;x++){
			for(int y=a2;y<=b2;y++){
				System.out.format("%5d\t",array[x][y]);
			}
			System.out.println();
		}
		
		System.out.println("Max Sum :"+max);
	}
}
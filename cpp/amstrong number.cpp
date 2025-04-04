#include<stdio.h>
#include<math.h>
int main(void){
	int n,d,k,p=0,sum=0;
	printf("write the number..........\n");
	scanf("%d",&n);
	k=n;

	while(n!=0){
		n=n/10;
		p++;
	}
	n=k;
	while(n!=0){
		//extracting the digit of the number
		//ex-123----> 123%10=3
		d=n%10;
	
		sum=sum+pow(d,p);
		n=n/10;
		//finding the resultant word
		
	};
	if (sum==k){
		printf("this is amstrong number..........\n");
	}
	else{
		printf("this is not amstrong number..........\n");
	};
	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void hesapla(char str[],int sayac){
	
	int *dizi,temp,temp2,i,j=0;
	dizi=(int *) malloc(sizeof(int));
	for(i=sayac-2;i>=0;i--){
		switch(str[i]){
			case '*':{
				j=j-2;
				temp=dizi[j];
				dizi[j]=dizi[j+1]*temp;
				j++;
				break;
			}
			case '/':{
				j=j-2;
				temp=dizi[j];
				dizi[j]=dizi[j+1]/temp;
				j++;
				break;
			}
			case '-':{
				j=j-2;
				temp=dizi[j];
				dizi[j]=dizi[j+1]-temp;
				j++;
				break;
			}
			case '+':{
				j=j-2;
				temp=dizi[j];
				dizi[j]=temp+dizi[j+1];
				j++;
				break;
			}
			default:{
				if(isdigit(str[i]) && !isspace(str[i])){
				  
					if(isspace(str[i-1])!=0)dizi[j]=str[i]-'0';
					if(!isspace(str[i-1]) && !isspace(str[i]-2)){
						dizi[j]=((str[i]-'0')+(str[i-1]-'0')*10);i--;
					
				   }
				   
				    j++;
				}
				
				
				
				break;
			} 
			
		}
		
	}
	printf("\nSonuc: %d\n",dizi[0]);
	free(dizi);
}

int main(){
	char input[50],s[30];
	int i,j=0,temp1,temp2,kon=0;
	
	while(1){
		
		temp1=0;temp2=0,j=0;
		printf("Postfix giriniz Or:* + * + 1 2 + 3 4 5 6 (Cikmak icin: E): "); fgets(input, sizeof(input), stdin);
		if('e'==input[0] || 'E'==input[0])break;
		if(isdigit(input[0]))printf("Yanlis ifade!\n");
		else{
			for(i=0;input[i]!=NULL;i++){
				
				if(isdigit(input[i])){
					if(isspace(input[i+1])==0){
						temp2++;
						i++;
					
					}else temp2++;
				}
				if(input[i]=='+' || input[i]=='*' ||input[i]=='-' || input[i]=='/')temp1++;
				if(input[i+1]==NULL)
					if(isdigit(input[i-1]))kon=0;
					else kon=1;
				
				
	   		}
	   		for(i=0;input[i]!=NULL;i++)j++;
			    
			if(temp1+1==temp2 && kon==0) 
				hesapla(input,j);
			else printf("Yanlis ifade!\n");
			
		}
		
	}
	
	return 0;
}

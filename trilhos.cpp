#include<stdio.h>
int tam,cont=1,k,i,j;
int main(){
    while(1==1){
        inicio:
        k=0;cont=1;tam=0;
        int trem[100100],pos[100100],n,x;
        scanf("%d",&n);
        if(n==0)break;
        while(1==1){
            k=0;cont=1;tam=0;
            for(i=0;i<n;i++){
                tam++;
                scanf("%d",&pos[tam]);
                if(pos[tam]==0)goto inicio;
                trem[i+1]=i+1;
            }
            k=1;
            for(i=1;i<=n;i++){
                if(trem[i]==pos[k]){
                    k++;
                    cont++;
                    j=i;
                    trem[j]=-1;
                    while(1==1){
                        j--;
                        if(j<=0)break;
                        while(trem[j]==-1){
                            j--;
                            if(j<=0){
                                j++;
                                break;
                            }
                        }
                        if(trem[j]==pos[k]){
                            cont++;
                            k++;
                        }
                        else break;
                    }
                }
            }
            if(cont-1==n)printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}

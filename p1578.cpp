#include <cstdio>
#include <cstring>
#include <algorithm>

const int size = 10000+10;

int n,m,num,maxy,miny,s,maxs,dx,dy;

struct node {
	int x,y;
}point[size];

inline bool cmp1(node a,node b) {
	return a.x<b.x;
}

inline bool cmp2(node a,node b) {
	return a.y<b.y;
}

int main() {
	scanf("%d%d%d",&n,&m,&num);
	if(num==0) {
		printf("%d\n",n+m);
		return 0;
	}
	for(int i=1;i<=num;i++) 
		scanf("%d%d",&point[i].x,&point[i].y);
	sort(point+1,point+num+1,cmp);  
    for (i=1;i<=num;i++)  
     {  
        miny=0;  maxy=m;  s=0;  
        for (j=i+1;j<=num;j++)  
         {  
             dx=point[j].x-point[i].x; dy=maxy-miny; s=dx*dy;  
             maxs=max(maxs,s);  
             if (point[j].y<=point[i].y&&point[j].y>miny)  
              miny=point[j].y;  
             if (point[j].y>=point[i].y&&point[j].y<maxy)  
              maxy=point[j].y;  
         }  
        dx=n-point[i].x;  
        dy=maxy-miny;  
        s=dx*dy;  
        maxs=max(maxs,s);  
     }  
    for (i=num;i>0;i--)  
     {  
        miny=0; maxy=m; s=0;  
        for (j=i-1;j>0;j--)  
         {  
             dx=point[i].x-point[j].x; dy=maxy-miny; s=dx*dy;  
             maxs=max(maxs,s);  
             if (point[j].y<=point[i].y&&point[j].y>miny)  
              miny=point[j].y;  
             if (point[j].y>=point[i].y&&point[j].y<maxy)  
              maxy=point[j].y;  
         }  
        dx=point[i].x; dy=maxy-miny;  
        s=dx*dy;  
        maxs=max(maxs,s);  
     }  
    sort(point+1,point+num+1,cmp1);  
    for (i=1;i<=num;i++)  
     {  
        if (i==1)  dy=point[i].y,s=n*dy,maxs=max(maxs,s);  
        if (i==num) dy=m-point[i].y,s=n*dy,maxs=max(maxs,s);  
        if (i-1>0)  
         {  
            dy=point[i].y-point[i-1].y;  
            s=n*dy;  
            maxs=max(maxs,s);  
         }   
     }  
    printf("%d",maxs);  
}  
}

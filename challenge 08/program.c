#include<stdio.h>
int main()
{
int a[6][6],n,t;
int i,j,rowSum,colSum;
int maxRow=-1,maxCol=-1,maxRisk=-1;
int count=0,mainDiagonal=0,secondaryDiagonal=0;
int boundarySum=0,hotspotCount=0;

do{
printf("Enter grid size (3 to 6): ");
scanf("%d",&n);
if(n<3||n>6)
printf("Invalid size!\n");
}while(n<3||n>6);

printf("Enter risk scores:\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
do{
printf("Enter value [%d][%d]: ",i+1,j+1);
scanf("%d",&a[i][j]);
if(a[i][j]<0||a[i][j]>100)
printf("Invalid score!\n");
}while(a[i][j]<0||a[i][j]>100);
}
}

do{
printf("Enter threshold (1 to 100): ");
scanf("%d",&t);
if(t<1||t>100)
printf("Invalid threshold!\n");
}while(t<1||t>100);

printf("\n---GRIDWATCH---\n");
for(i=0;i<n;i++){
for(j=0;j<n;j++)
printf("%4d",a[i][j]);
printf("\n");
}

for(i=0;i<n;i++){
rowSum=0;
for(j=0;j<n;j++)
rowSum+=a[i][j];
printf("Row %d total=%d\n",i+1,rowSum);
if(rowSum>maxRow)
maxRow=rowSum;
}

printf("Highest row total=%d\n",maxRow);
printf("Highest row number(s): ");
for(i=0;i<n;i++){
rowSum=0;
for(j=0;j<n;j++)
rowSum+=a[i][j];
if(rowSum==maxRow)
printf("%d ",i+1);
}

for(j=0;j<n;j++){
colSum=0;
for(i=0;i<n;i++)
colSum+=a[i][j];
printf("\nColumn %d total=%d",j+1,colSum);
if(colSum>maxCol)
maxCol=colSum;
}

printf("\nHighest column total=%d\n",maxCol);
printf("Highest column number(s): ");
for(j=0;j<n;j++){
colSum=0;
for(i=0;i<n;i++)
colSum+=a[i][j];
if(colSum==maxCol)
printf("%d ",j+1);
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][j]>maxRisk)
maxRisk=a[i][j];
if(a[i][j]>=t)
count++;
}
}

printf("\nHighest risk score=%d",maxRisk);
printf("\nMaximum score position(s): ");
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][j]==maxRisk)
printf("(%d,%d) ",i+1,j+1);
}
}
printf("\nCells meeting threshold=%d",count);

for(i=0;i<n;i++){
mainDiagonal+=a[i][i];
secondaryDiagonal+=a[i][n-1-i];
}

printf("\nMain diagonal sum=%d",mainDiagonal);
printf("\nSecondary diagonal sum=%d",secondaryDiagonal);

if(mainDiagonal==secondaryDiagonal)
printf("\nDiagonal totals are balanced.");
else
printf("\nDiagonal totals are not balanced.");

for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(i==0||i==n-1||j==0||j==n-1)
boundarySum+=a[i][j];
}
}
printf("\nBoundary total=%d",boundarySum);

printf("\nLocal hotspots:\n");
for(i=1;i<n-1;i++){
for(j=1;j<n-1;j++){
if(a[i][j]>a[i-1][j]&&
a[i][j]>a[i+1][j]&&
a[i][j]>a[i][j-1]&&
a[i][j]>a[i][j+1]&&
a[i][j]>=t){
printf("Hotspot at (%d,%d),value=%d\n",i+1,j+1,a[i][j]);
hotspotCount++;
}
}
}

if(hotspotCount==0)
printf("No local hotspots found.\n");

printf("\n---FINAL DECISION---\n");
if(hotspotCount>0)
printf("CRITICAL\n");
else if(count>=n)
printf("WARNING\n");
else
printf("NORMAL\n");

return 0;
}

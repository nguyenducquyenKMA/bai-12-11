#include"stdio.h"
#include"conio.h"
int a[100][100];
int m,n,tk,x;

void nhapMaTran(int x[100][100], int &m, int &n)
{
    do
    {
        printf("\nnhap vao so dong m : ");
        scanf("%d",&m);
        printf("nhap vao so cot n : ");
        scanf("%d",&n);
    }
    while(m<=0 || n<=0);

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("x[%d][%d]=", i, j);
            scanf("%d", &x[i][j]);
        }
    }
}

void xuatMaTran(int x[100][100], int m, int n)
{
    printf("\nMang: \n");
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
int timKiem(int x[100][100], int m, int n, int tk)
{
    int kq = 0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(x[i][j]==tk)
                kq=1;
        }
    }
    return kq;
}
void thucHienTimKiem(int x[100][100], int m, int n)
{
    int tk;
    printf("\nNhap gia tri can tim : ");
    scanf("%d", &tk);
    int kq = timKiem(x, m, n, tk);
    if(kq)
    {
        printf("\nTim thay gia tri can tim kiem trong ma tran!\n");
    }
    else
    {
        printf("\nKhong tim thay gia tri can tim kiem trong ma tran!\n");
    }

}
int checkchan(int a[100][100],int m, int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]%2!=0)
                return -1;
        }
    }
    return 1;
}
int tongdong(int a[][100], int m, int n,int &x)
{
    do
    {
        printf("\nNhap dong can tinh la : ");
        scanf("%d",&x);
    }
    while(x<=0);
    int sum=0;
    for(int j=1; j<=n; j++)
        sum=sum+a[x][j];
    return sum;
}
int tongcot(int a[][100], int m, int n,int &x)
{
    do
    {
        printf("\nNhap cot can tinh la : ");
        scanf("%d",&x);
    }
    while(x<=0);
    int sum=0;
    for(int i=1; i<=m; i++)
        sum=sum+a[i][x];
    return sum;
}
int tongmatran(int a[100][100], int m, int n)
{
    int sum=0;
    for(int i=1 ; i<=m; i++)
    {
        for(int j=1; j<n; j++)
        {
            sum=sum+a[i][j];
        }
    }
    return sum;
}
int tongduongcheochinh(int a[100][100],int m, int n)
{
    int sum=0;
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i == j)
                sum = sum + a[i][j];
        }
    }
    return sum;
}
int tongnuaduoi(int a[100][100], int m, int n)
{
    int sum=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
                sum=sum+a[i][j];
        }
    }
    return sum;
}
int tongnuatren(int a[100][100], int m, int n)
{
    int sum=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i<=j)
                sum=sum+a[i][j];
        }
    }
    return sum;
}
int timMin(int a[100][100],int m, int n)
{
    int min=a[1][1];
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(min>a[i][j])
                min=a[i][j];
        }
    }
    return min;
}
int timMax(int a[100][100],int m,int n)
{
    int max=a[1][1];
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(max<a[i][j])
                max=a[i][j];
        }
    }
    return max;
}
int main()
{
    char gt;
    do
    {
        printf("\n1-Nhap mang/Xuat mang");
        printf("\n2-Tim phan tu");
        printf("\n3-");
        printf("\n4-Cac phep toan ma tran");
        printf("\n5-Gia tri MIN/MAX");
        printf("\nx-Thoat");
        printf("\nVui long lua chon : ");
        scanf(" %c",&gt);
        if(gt=='1')
        {
            nhapMaTran(a, m, n);
            xuatMaTran(a, m, n);
        }
        else if(gt=='2')
        {
            thucHienTimKiem(a,m,n);
        }
        else if(gt=='3'){
             if(checkchan(a,m,n)==1){
                printf("Mang toan chan");
             }else{
                printf("Mang khong toan chan");
             }
        }
        else if(gt=='4')
        {
            int t=tongdong(a,m,n,x);
            printf("Tong dong %d la: %d\n",x,t);
            int s=tongcot(a,m,n,x);
            printf("Tong cot %d la : %d\n",x,s);
            int k=tongmatran(a,m,n);
            printf("\nTong ma tran la : %d\n",k);
            printf("\nTong duong cheo chinh la : %d\n ",tongduongcheochinh(a,m,n));
            printf("\nTong nua duoi cua ma tran la : %d\n",tongnuaduoi(a,m,n));
            printf("\nTong nua tren cua ma tran la : %d\n",tongnuatren(a,m,n));
        }
        else if(gt=='5')
        {
            printf("\nGia tri nho nhat cua ma tran la : %d ",timMin(a,m,n));
            printf("\nGia tri lon nhat cua ma tran la : %d \n",timMax(a,m,n));
        }
    }
    while(gt!='x');
}
